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

#include "opendnp3/gen/GroupVariation.h"
#include "opendnp3/gen/PointClass.h"
#include "opendnp3/app/PointIndexes.h"

namespace opendnp3
{

/**
* Interface used to dispatch miscelaneous functions from application code to a master
*/
class IFunctionProcessor
{
public:

	/**
	* Sends the function Assign Class that assigns points in the specified object to the specified class
	* @param gvId object group (always variation 0) to assign points from
	* @param points collection of point indexes to assign
	* @param clazz point class to assign the indexes
	*/
  	virtual void AssignClass(GroupVariation gvId, const PointIndexes* points, const PointClass clazz) = 0;
};

}

#endif
