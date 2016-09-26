/**
 * Copyright 2013 Automatak, LLC
 *
 * Licensed to Automatak, LLC (www.automatak.com) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. Automatak, LLC
 * licenses this file to you under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#include "MasterApplicationAdapter.h"

#include "../jni/JCache.h"

using namespace opendnp3;
	
void MasterApplicationAdapter::OnReceiveIIN(const IINField& iin)
{
	const auto env = JNI::GetEnv();
	const auto jiin = jni::JCache::IINField.init2(env, iin.LSB, iin.MSB);
	jni::JCache::MasterApplication.onReceiveIIN(env, proxy, jiin);
}

void MasterApplicationAdapter::OnTaskStart(MasterTaskType type, TaskId id)
{
	const auto env = JNI::GetEnv();
	const auto jtasktype = jni::JCache::MasterTaskType.fromType(env, static_cast<jint>(type));
	const auto jtaskid = jni::JCache::TaskId.init2(env, id.GetId(), id.IsDefined());
	jni::JCache::MasterApplication.onTaskStart(env, proxy, jtasktype, jtaskid);
}

void MasterApplicationAdapter::OnTaskComplete(const TaskInfo& info)
{
	const auto env = JNI::GetEnv();
	const auto jtype = jni::JCache::MasterTaskType.fromType(env, static_cast<jint>(info.type));
	const auto jresult = jni::JCache::TaskCompletion.fromType(env, static_cast<jint>(info.result));	
	const auto jtaskid = jni::JCache::TaskId.init2(env, info.id.GetId(), info.id.IsDefined());

	auto jinfo = jni::JCache::TaskInfo.init3(env, jtype, jresult, jtaskid);
	jni::JCache::MasterApplication.onTaskComplete(env, proxy, jinfo);
}

bool MasterApplicationAdapter::AssignClassDuringStartup()
{
	const auto env = JNI::GetEnv();
	return !!jni::JCache::MasterApplication.assignClassDuringStartup(env, proxy);	
}

void MasterApplicationAdapter::ConfigureAssignClassRequest(const WriteHeaderFunT& fun)
{
	const auto env = JNI::GetEnv();
	const auto jiterable = jni::JCache::MasterApplication.getClassAssignments(env, proxy);

	auto write = [&](jobject assigment) {
		// TODO convert the assignment and write the header
	};

	JNI::Iterate(env, jiterable, write);
}
