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

#include "AssignClassTask.h"

#include "opendnp3/app/APDUBuilders.h"

#include "MasterTasks.h"

namespace opendnp3
{

AssignClassTask::AssignClassTask(openpal::Logger* pLogger_) :
    NullResponseTask(pLogger_)
{
    auto SetEmptyIndexes = [](const PointIndexes*& p){p = &PointIndexes::EMPTYINDEXES;};
    binaryInputClasses.ToIndexable().foreach(SetEmptyIndexes);
    doubleBinaryInputClasses.ToIndexable().foreach(SetEmptyIndexes);
    analogInputClasses.ToIndexable().foreach(SetEmptyIndexes);
    frozenAnalogInputClasses.ToIndexable().foreach(SetEmptyIndexes);
    counterClasses.ToIndexable().foreach(SetEmptyIndexes);
    frozenCounterClasses.ToIndexable().foreach(SetEmptyIndexes);
    binaryOutputStatusClasses.ToIndexable().foreach(SetEmptyIndexes);
    binaryOutputCommandClasses.ToIndexable().foreach(SetEmptyIndexes);
    analogOutputStatusClasses.ToIndexable().foreach(SetEmptyIndexes);
    analogOutputCommandClasses.ToIndexable().foreach(SetEmptyIndexes);
}

void AssignClassTask::BuildRequest(APDURequest& request, const MasterParams& params, uint8_t seq)
{
    if (classes.HasAnyClass())
	{
        request.SetFunction(FunctionCode::ASSIGN_CLASS);
        request.SetControl(AppControlField::Request(seq));
        
        auto writer = request.GetWriter();
        
        if (classes.HasClass0())
        {
            // write class object header to specify the class to assign points to
            writer.WriteHeader(GroupVariationID(60,0), QualifierCode::ALL_OBJECTS);
            // write data object headers to specify the points to assign
            AddDataObjectHeaders(writer, GroupVariationID(1,0), binaryInputClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(3,0), doubleBinaryInputClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(30,0), analogInputClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(31,0), frozenAnalogInputClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(20,0), counterClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(21,0), frozenCounterClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(10,0), binaryOutputStatusClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(12,0), binaryOutputCommandClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(40,0), analogOutputStatusClasses[0]);
            AddDataObjectHeaders(writer, GroupVariationID(41,0), analogOutputCommandClasses[0]);
        }
        
        if (classes.HasClass1())
        {
            // write class object header to specify the class to assign points to
            writer.WriteHeader(GroupVariationID(60,1), QualifierCode::ALL_OBJECTS);
            // write data object headers to specify the points to assign
            AddDataObjectHeaders(writer, GroupVariationID(1,0), binaryInputClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(3,0), doubleBinaryInputClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(30,0), analogInputClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(31,0), frozenAnalogInputClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(20,0), counterClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(21,0), frozenCounterClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(10,0), binaryOutputStatusClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(12,0), binaryOutputCommandClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(40,0), analogOutputStatusClasses[1]);
            AddDataObjectHeaders(writer, GroupVariationID(41,0), analogOutputCommandClasses[1]);
        }
        
        if (classes.HasClass2())
        {
            // write class object header to specify the class to assign points to
            writer.WriteHeader(GroupVariationID(60,2), QualifierCode::ALL_OBJECTS);
            // write data object headers to specify the points to assign
            AddDataObjectHeaders(writer, GroupVariationID(1,0), binaryInputClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(3,0), doubleBinaryInputClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(30,0), analogInputClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(31,0), frozenAnalogInputClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(20,0), counterClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(21,0), frozenCounterClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(10,0), binaryOutputStatusClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(12,0), binaryOutputCommandClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(40,0), analogOutputStatusClasses[2]);
            AddDataObjectHeaders(writer, GroupVariationID(41,0), analogOutputCommandClasses[2]);
        }
        
        if (classes.HasClass3())
        {
            // write class object header to specify the class to assign points to
            writer.WriteHeader(GroupVariationID(60,3), QualifierCode::ALL_OBJECTS);
            // write data object headers to specify the points to assign
            AddDataObjectHeaders(writer, GroupVariationID(1,0), binaryInputClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(3,0), doubleBinaryInputClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(30,0), analogInputClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(31,0), frozenAnalogInputClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(20,0), counterClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(21,0), frozenCounterClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(10,0), binaryOutputStatusClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(12,0), binaryOutputCommandClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(40,0), analogOutputStatusClasses[3]);
            AddDataObjectHeaders(writer, GroupVariationID(41,0), analogOutputCommandClasses[3]);
        }
	}
}

//bool AssignClassTask::Enabled(const MasterParams& params)
//{
//	return params.disableUnsolOnStartup;
//}

void AssignClassTask::OnTimeoutOrBadControlOctet(const MasterParams& params, IMasterScheduler& scheduler)
{
	scheduler.SetBlocking(*this, params.taskRetryPeriod);
}
    
void AssignClassTask::AddDataObjectHeaders(HeaderWriter& writer, GroupVariationID gvId, const PointIndexes* gvRanges)
{
    if (gvRanges->IsEmpty()) return;
    if (gvRanges->IsFull())
    {
        writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS);
    }
    else
    {
        for (uint16_t i = 0; i < gvRanges->ranges.Size(); i++)
        {
            writer.WriteRangeHeader<openpal::UInt16>(QualifierCode::UINT16_START_STOP, gvId, gvRanges->ranges[i].start, gvRanges->ranges[i].stop);
        }
    }
}


} //end ns

