/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#include "LinkLayerRouter.h"

#include <assert.h>

#include <openpal/logging/LogMacros.h>
#include <openpal/channel/IPhysicalLayer.h>

#include "opendnp3/LogLevels.h"
#include "ILinkContext.h"
#include "LinkFrame.h"

using namespace std;
using namespace openpal;

namespace opendnp3
{

LinkLayerRouter::LinkLayerRouter(	openpal::LogRoot& root,
									openpal::IExecutor& executor,
                                    IPhysicalLayer* pPhys,
                                    openpal::TimeDuration minOpenRetry,
                                    openpal::TimeDuration maxOpenRetry,
									IChannelStateListener* pStateHandler_,                                    
									IOpenDelayStrategy& strategy,
									LinkChannelStatistics* pStatistics_) :

	PhysicalLayerMonitor(root, executor, pPhys, minOpenRetry, maxOpenRetry, strategy),
	pStateHandler(pStateHandler_),	
	pStatistics(pStatistics_),
	parser(logger, pStatistics_),
	isTransmitting(false)
{}

void LinkLayerRouter::SetShutdownHandler(const Action0& action)
{
	this->shutdownHandler = action;
}

bool LinkLayerRouter::IsRouteInUse(const LinkRoute& route)
{
	auto pNode = records.FindFirst([route](const Record & record)
	{
		return record.route == route;
	});
	return (pNode != nullptr);
}

bool LinkLayerRouter::AddContext(ILinkContext* pContext, const LinkRoute& route)
{
	assert(pContext != nullptr);

	if (IsRouteInUse(route))
	{
		return false;
	}
	else
	{
		auto pNode = records.FindFirst([pContext](const Record & record)
		{
			return record.pContext == pContext;
		});

		if (pNode)
		{
			SIMPLE_LOG_BLOCK(logger, flags::ERR, "Context cannot be bound - stack route already in use on channel");
			return false;
		}
		else
		{
			// record is always disabled by default
			Record(pContext, route);
			if (records.Add(Record(pContext, route)))
			{
				return true;
			}
			else
			{
				SIMPLE_LOG_BLOCK(logger, flags::ERR, "Context cannot be bound - maximum number of stacks on channel");
				return false;
			}
		}
	}
}

bool LinkLayerRouter::Enable(ILinkContext* pContext)
{
	auto isMatch = [pContext](const Record & rec) { return rec.pContext == pContext; };
	auto pNode = records.FindFirst(isMatch);

	if(pNode)
	{
		if(pNode->value.enabled)
		{
			// already enabled
			return true;			
		}
		else
		{
			pNode->value.enabled = true;

			if (this->IsOnline())
			{
				pNode->value.pContext->OnLowerLayerUp();
			}

			this->Start(); // idempotent call to start router

			return true;
		}
		
	}
	else
	{
		return false;
	}
}

bool LinkLayerRouter::Disable(ILinkContext* pContext)
{
	auto pNode = records.FindFirst([pContext](const Record & rec)
	{
		return rec.pContext == pContext;
	});

	if (pNode)
	{
		if (pNode->value.enabled)
		{
			pNode->value.enabled = false;

			if (this->IsOnline())
			{
				pNode->value.pContext->OnLowerLayerDown();
			}

			if (!this->HasEnabledContext())
			{
				this->Suspend();
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool LinkLayerRouter::Remove(ILinkContext* pContext)
{
	auto pNode = records.RemoveFirst([pContext](const Record & rec)
	{
		return rec.pContext == pContext;
	});

	if(pNode)
	{
		if (this->GetState() == ChannelState::OPEN && pNode->value.enabled)
		{
			pNode->value.pContext->OnLowerLayerDown();
		}

		// if no contexts are enabled, suspend the router
		if (!HasEnabledContext())
		{
			this->Suspend();
		}

		return true;
	}
	else
	{
		return false;
	}
}

ILinkContext* LinkLayerRouter::GetEnabledContext(const LinkRoute& route)
{
	auto find = [route](const Record & rec) { return rec.enabled && (rec.route == route); };	
	auto pNode = records.FindFirst(find);
	return pNode ? pNode->value.pContext : nullptr;
}


ILinkContext* LinkLayerRouter::GetDestination(uint16_t aDest, uint16_t aSrc)
{
	LinkRoute route(aSrc, aDest);

	ILinkContext* pDest = GetEnabledContext(route);

	if(pDest == nullptr)
	{
		FORMAT_LOG_BLOCK_WITH_CODE(logger, flags::WARN, DLERR_UNKNOWN_ROUTE, "Frame w/ unknown route: %i to %i", route.remote, route.local);
	}

	return pDest;
}

//////////////////////////////////////////////////////
// IFrameSink Implementation
//////////////////////////////////////////////////////

void LinkLayerRouter::Ack(bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)
{
		ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->Ack(aIsMaster, aIsRcvBuffFull, aDest, aSrc);
}
void LinkLayerRouter::Nack(bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->Nack(aIsMaster, aIsRcvBuffFull, aDest, aSrc);
}
void LinkLayerRouter::LinkStatus(bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->LinkStatus(aIsMaster, aIsRcvBuffFull, aDest, aSrc);
}
void LinkLayerRouter::NotSupported (bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->NotSupported(aIsMaster, aIsRcvBuffFull, aDest, aSrc);
}
void LinkLayerRouter::TestLinkStatus(bool aIsMaster, bool aFcb, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->TestLinkStatus(aIsMaster, aFcb, aDest, aSrc);
}
void LinkLayerRouter::ResetLinkStates(bool aIsMaster, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->ResetLinkStates(aIsMaster, aDest, aSrc);
}
void LinkLayerRouter::RequestLinkStatus(bool aIsMaster, uint16_t aDest, uint16_t aSrc)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->RequestLinkStatus(aIsMaster, aDest, aSrc);
}
void LinkLayerRouter::ConfirmedUserData(bool aIsMaster, bool aFcb, uint16_t aDest, uint16_t aSrc, const ReadOnlyBuffer& arBuffer)
{
	ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->ConfirmedUserData(aIsMaster, aFcb, aDest, aSrc, arBuffer);
}
void LinkLayerRouter::UnconfirmedUserData(bool aIsMaster, uint16_t aDest, uint16_t aSrc, const ReadOnlyBuffer& arBuffer)
{
            ILinkContext* pDest = GetDestination(aDest, aSrc);
	if(pDest) pDest->UnconfirmedUserData(aIsMaster, aDest, aSrc, arBuffer);
}

void LinkLayerRouter::OnReceive(const openpal::ReadOnlyBuffer& input)
{
	// The order is important here. You must let the receiver process the byte or another read could write
	// over the buffer before it is processed	
	parser.OnRead(input.Size(), this); //this may trigger callbacks to the local ILinkContext interface
	if(pPhys->CanRead())   // this is required because the call above could trigger the layer to be closed
	{
		auto buff = parser.WriteBuff();
		pPhys->BeginRead(buff); //start another read
	}	
}

void LinkLayerRouter::QueueTransmit(const openpal::ReadOnlyBuffer& buffer, ILinkContext* pContext, bool primary)
{
	if (this->IsOnline())
	{
		Transmission tx(buffer, pContext, primary);

		if (this->transmitQueue.Enqueue(tx))
		{
			this->CheckForSend();
		}
		else
		{
			auto lambda = [pContext, primary]() { pContext->OnTransmitResult(primary, false); };
			pExecutor->PostLambda(lambda);
		}
	}
	else
	{
		SIMPLE_LOG_BLOCK(logger, flags::ERR, "Router received transmit request while offline");
	}
}

void LinkLayerRouter::OnStateChange(ChannelState state)
{
	if (this->pStateHandler)
	{
		pStateHandler->OnStateChange(state);
	}
}

void LinkLayerRouter::OnShutdown()
{
	shutdownHandler.Apply();	
}

bool LinkLayerRouter::HasEnabledContext()
{
	auto pNode = records.FindFirst([](const Record & rec)
	{
		return rec.enabled;
	});
	return (pNode != nullptr);
}

void LinkLayerRouter::OnSendResult(bool result)
{
	assert(transmitQueue.IsNotEmpty());
	assert(isTransmitting);
	isTransmitting = false;

	auto pTx = transmitQueue.Pop();
	pTx->pContext->OnTransmitResult(pTx->primary, result);
	this->CheckForSend();
}

void LinkLayerRouter::CheckForSend()
{
	if (transmitQueue.IsNotEmpty() && !isTransmitting && pPhys->CanWrite())
	{
		if (pStatistics) ++pStatistics->numLinkFrameTx;
		auto pTransmission = transmitQueue.Peek();
		isTransmitting = true;
		pPhys->BeginWrite(pTransmission->buffer);
	}
}

void LinkLayerRouter::OnPhysicalLayerOpenSuccessCallback()
{
	if(pPhys->CanRead())
	{		
		auto buff = parser.WriteBuff();
		pPhys->BeginRead(buff);
	}

	records.Foreach(
	    [](const Record & rec)
	{
		if (rec.enabled)
		{
			rec.pContext->OnLowerLayerUp();
		}
	}
	);

}

void LinkLayerRouter::OnPhysicalLayerCloseCallback()
{	
	// reset the state of receiver
	parser.Reset();

	// Drop frames queued for transmit and tell the contexts that the router has closed
	isTransmitting = false;
	transmitQueue.Clear();

	auto disable = [](const Record & rec)
	{
		if (rec.enabled)
		{
			rec.pContext->OnLowerLayerDown();
		}
	};

	records.Foreach(disable);
}

}


