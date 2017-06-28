/*
 * Str.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */
#include "Str.hpp"

#include <cstring>
#include <cwchar>

namespace
{

template <typename CharType>
List<Char> fromCharArray(CharType const * s, Size sz)
{
	List<Char> v(sz);
	Dist i{};
	while( *s )
	{
		v[i] = *s;
		++i; ++s;
	}
	return v;
}

template <typename CharType>
List<Char> fromCharArray(CharType const * s)
{
	return fromCharArray(s, strlen(s) );
}

template <>
List<Char> fromCharArray(wchar_t const * s)
{
	return fromCharArray(s, wcslen(s) );
}

}


Str::Str()
{}

Str::Str(char const * s) : List<Char>( fromCharArray(s) )
{}

Str::Str(wchar_t const * s) : List<Char>( fromCharArray(s) )
{}

Str::Str(Str rhs) : List<Char>(rhs)
{}


