/*
 * Exception.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once

#include "Str.hpp"

class Exception
{
public:
	Exception();
	Exception(Str msg);

	Str message;

	Str str();
};

