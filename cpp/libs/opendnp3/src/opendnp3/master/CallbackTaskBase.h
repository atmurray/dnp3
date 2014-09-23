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
#ifndef __CALLBACK_TASK_BASE_H_
#define __CALLBACK_TASK_BASE_H_


#include "opendnp3/gen/FunctionCode.h"

#include "opendnp3/master/SingleResponseTask.h"
#include "opendnp3/master/CommandResponse.h"
#include "opendnp3/master/ICommandCallback.h"
#include "opendnp3/master/ICommandProcessor.h"
#include "opendnp3/master/CommandSequence.h"

#include <openpal/logging/Logger.h>
#include <openpal/Configure.h>
#include <assert.h>

namespace opendnp3
{

// Base class with machinery for performing command operations and optionally call a callback on null response
class CallbackTaskBase : public SingleResponseTask
{
	
public:	

	CallbackTaskBase(openpal::Logger* pLogger_);

	virtual char const* Name() const = 0;
    
    virtual void SetCallback(opendnp3::ICommandCallback &callback);
	
protected:
	openpal::Logger* pLogger;
    
private:
    
    TaskStatus OnSingleResponse(const APDUResponseHeader& response, const openpal::ReadOnlyBuffer& objects, const MasterParams& params, IMasterScheduler& scheduler) override final;
	virtual void OnLowerLayerClose() override final;
	virtual void OnTimeoutOrBadControlOctet(const MasterParams& params, IMasterScheduler& scheduler) override final;
    
	void Callback(const CommandResponse& cr);

	ICommandCallback* pCallback;

};


} //ens ns

#endif
