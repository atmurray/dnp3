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
#ifndef __ASSIGN_CLASS_TASK_H_
#define __ASSIGN_CLASS_TASK_H_

#include "opendnp3/master/NullResponseTask.h"

#include "opendnp3/gen/FunctionCode.h"

#include "opendnp3/master/IFunctionProcessor.h"
#include "opendnp3/master/CommandSequence.h"
#include "opendnp3/ErrorCodes.h"

#include <openpal/logging/Logger.h>
#include <openpal/Configure.h>
#include <openpal/container/StaticArray.h>
#include <openpal/container/StaticQueue.h>
#include <openpal/container/Pair.h>
#include <assert.h>

namespace opendnp3
{

/**
* Base class for tasks that only require a single response
*/
class AssignClassTask : public NullResponseTask, IFunctionProcessor
{	

public:	

	AssignClassTask(openpal::Logger* pLogger_);
    
  	virtual void AssignClass(GroupVariation gvId, const PointIndexes* points, const PointClass clazz) override final;

	virtual char const* Name() const override final { return "Assign Class"; }

	virtual void BuildRequest(APDURequest& request, const MasterParams& params, uint8_t seq) override final;	

	//virtual bool Enabled(const MasterParams& params) override final;

private:

	virtual void OnSuccess(const MasterParams& params, IMasterScheduler& scheduler) override final {}

	virtual void OnTimeoutOrBadControlOctet(const MasterParams& params, IMasterScheduler& scheduler) override final;
        
	ICommandSequence* pActiveSequence;
    
    void AddDataObjectHeaders(HeaderWriter& writer, GroupVariationID gvId, const PointIndexes* gvRanges);

    void Assign(openpal::StaticArray<const PointIndexes*, uint8_t, 4>& target, const PointIndexes* points, const PointClass clazz) {
        switch(clazz)
        {
            case(PointClass::Class0):
                target[0] = points;
                break;
            case(PointClass::Class1):
                target[1] = points;
                break;
            case(PointClass::Class2):
                target[2] = points;
                break;
            case(PointClass::Class3):
                target[3] = points;
                break;
        }
        if (!points->IsEmpty()) classes.Set(clazz);
    };
    
    ClassField classes;
    
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> binaryInputClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> doubleBinaryInputClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> analogInputClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> frozenAnalogInputClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> counterClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> frozenCounterClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> binaryOutputStatusClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> binaryOutputCommandClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> analogOutputStatusClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> analogOutputCommandClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> fileClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> octetStringClasses;
    openpal::StaticArray<const PointIndexes*, uint8_t, 4> virtualTerminalClasses;
};

} //end ns


#endif
