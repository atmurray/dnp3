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
#ifndef __FUNCTION_MARSHALLER_H_
#define __FUNCTION_MARSHALLER_H_

#include "IFunctionProcessor.h"

#include <openpal/executor/IExecutor.h>

namespace opendnp3
{

/**
* Marshalls commands from any thread to an executor
*/
class FunctionMarshaller : public IFunctionProcessor
{
	
public:

	FunctionMarshaller(openpal::IExecutor& executor, IFunctionProcessor& proxyTo);
   
    // Implement the IFunctionProcessor interface
	virtual void ImmediateFreeze(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback) override final;
	virtual void FreezeClear(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback) override final;
    virtual void EnableUnsolicited(const ClassField& classes) override final;
    virtual void DisableUnsolicited(const ClassField& classes) override final;
    virtual void AssignClass(GroupVariation gvId, const PointIndexes* points, const PointClass clazz) override final;
    virtual void AssignClassExecute(ICommandCallback& callback) override final;

private:

	openpal::IExecutor* pExecutor;
	IFunctionProcessor* pProxyTo;
	
};

}

#endif

