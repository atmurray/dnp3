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
#ifndef __I_FUNCTION_PROCESSOR_H_
#define __I_FUNCTION_PROCESSOR_H_

#include "opendnp3/master/ICommandCallback.h"
#include "opendnp3/gen/GroupVariation.h"
#include "opendnp3/app/GroupVariationID.h"
#include "opendnp3/gen/PointClass.h"
#include "opendnp3/app/PointIndexes.h"
#include "opendnp3/app/ClassField.h"

namespace opendnp3
{

/**
* Interface used to dispatch miscelaneous functions from application code to a master
*/
class IFunctionProcessor
{
public:

    /*
     Function Codes 7 (0x07) and 8 (0x08) Immediate Freeze and Immediate Freeze – No Acknowledgement
     Function Codes 9 (0x09) and 10 (0x0A) Freeze-and-Clear and Freeze-and-Clear – No Acknowledgment
     Function Codes 11 (0x0B) and 12 (0x0C) Freeze-at-Time and Freeze-at-Time – No Acknowledgement
     Function Codes 13 (0x0D) and 14 (0x0E) Cold Restart and Warm Restart
     */
	/**
     * Function Code 7 Immediate Freeze
     * @param command command to operate
     * @param index index of the command
     * @param pCallback callback that will be invoked upon completion or failure
     */
	virtual void ImmediateFreeze(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback) = 0;

	/**
     * Function Code 9 Freeze and Clear
     * @param command command to operate
     * @param index index of the command
     * @param pCallback callback that will be invoked upon completion or failure
     */
	virtual void FreezeClear(GroupVariationID gvId, const PointIndexes* points, ICommandCallback& callback) = 0;

	/**
     * Function Code 20 Enable Unsolicited Responses
     * Enables unsolicited responses for the specified classes
     * @param classes point classes to enable unsolicted responses
     */
    virtual void EnableUnsolicited(const ClassField& classes) = 0;

	/**
     * Function Code 21 Disable Unsolicited Responses
     * Disables unsolicited responses for the specified classes
     * @param classes point classes to disable unsolicted responses
     */
    virtual void DisableUnsolicited(const ClassField& classes) = 0;
    
	/**
	* Function Code 22 Assign Class
    * Sends the function Assign Class that assigns points in the specified object to the specified class
	* @param gvId object group (always variation 0) to assign points from
	* @param points collection of point indexes to assign
	* @param clazz point class to assign the indexes
	*/
  	virtual void AssignClass(GroupVariation gvId, const PointIndexes* points, const PointClass clazz) = 0;
    virtual void AssignClassExecute(ICommandCallback& callback) = 0;
   
};

}

#endif
