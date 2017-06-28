/*
 * nil.hpp
 *
 *  Created on: 2017-06-18
 *      Author: philippe
 */

#pragma once

template <typename T>
bool isNil(T v)
{
	return v == T::nil;
}
