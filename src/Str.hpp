/*
 * Str.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once

#include "List.hpp"
 
class Str : public List<Char>
{
public:
	Str();
	Str(char const * const s);
	Str(wchar_t const * const s);
	Str(Str rhs);
};
