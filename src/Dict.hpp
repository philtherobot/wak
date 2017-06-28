/*
 * Dict.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once

template <typename K, typename V>
class Dict
{
public:
	Dict() {}

	V & operator [](K & k);
	bool has(K & k);
	V del(K & k);

	class Iter;
	Iter begin();
	Iter end();

	Str str();
};
