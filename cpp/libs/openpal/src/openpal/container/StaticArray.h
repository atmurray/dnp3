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
#ifndef __STATIC_ARRAY_H_
#define __STATIC_ARRAY_H_

#include "Indexable.h"

namespace openpal
{

// A statically sized buffer of a certain type
template <class ValueType, class IndexType, IndexType N>
class StaticArray : public HasSize<IndexType>
{

public:

	StaticArray() : HasSize<IndexType>(N)
	{}

	inline Indexable<ValueType, IndexType> ToIndexable()
	{
		return Indexable<ValueType, IndexType>(buffer, N);
	}

	inline ValueType const* Buffer() const
	{
		return buffer;
	};

	inline ValueType* Buffer()
	{
		return buffer;
	};

	inline ValueType& operator[](IndexType index)
	{
		assert(index < N);
		return buffer[index];
	}

	inline const ValueType& operator[](IndexType index) const
	{
		assert(index < N);
		return buffer[index];
	}

protected:
	ValueType buffer[N];

private:
	StaticArray(const StaticArray&);
	StaticArray& operator= (const StaticArray&);
};

}

#endif
