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
#include "FreezeTask.h"


#include <openpal/logging/LogMacros.h>

#include "opendnp3/app/APDUParser.h"

#include "opendnp3/objects/Group12.h"
#include "opendnp3/objects/Group41.h"

#include "opendnp3/LogLevels.h"

#include "opendnp3/app/APDUBuilders.h"

using namespace openpal;

namespace opendnp3
{


FreezeTask::FreezeTask(openpal::Logger* pLogger_)  :
    CallbackTaskBase(pLogger_),
	pFunctionCode(FunctionCode::UNKNOWN)
{

}

void FreezeTask::ImmediateFreeze(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback)
{
    this->pFunctionCode = FunctionCode::IMMED_FREEZE;
    this->pGroupVar = gvId;
    this->pPoints = points;
    this->SetCallback(callback);
}

void FreezeTask::FreezeClear(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback)
{
    this->pFunctionCode = FunctionCode::FREEZE_CLEAR;
    this->pGroupVar = gvId;
    this->pPoints = points;
    this->SetCallback(callback);
}

void FreezeTask::BuildRequest(APDURequest& request, const MasterParams& params, uint8_t seq)
{
	if (pFunctionCode != FunctionCode::UNKNOWN)
	{
		request.SetFunction(pFunctionCode);
		request.SetControl(AppControlField::Request(seq));
        build::AddDataObjectHeaders(request, pGroupVar, pPoints);
	}
}

} //end ns
