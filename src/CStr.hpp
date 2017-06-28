/*
 * CStr.hpp
 *
 *  Created on: 2017-06-18
 *      Author: philippe
 */

#pragma once

#include "List.hpp"
#include "Str.hpp"
#include <iterator>
#include <algorithm>

class CStr : public List<char>
{
public:
	CStr() {}
	CStr(char const * const s)
	{
		char const * p = s;
		while( *p ) ++p;
		++p;
		auto sz = std::distance(s, p);
		data_.resize(sz);
		std::copy(s, p, data_.begin());
	}
	CStr(Str s)
	{
		data_.resize(s.len()+1);
		Dist d=0;
		for(auto c: s)
		{
			data_[++d] = c;
		}
		data_[d] = 0;
	}

	operator char * () { return data_.data(); }
};
