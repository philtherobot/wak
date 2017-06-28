/*
 * Set.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */


template <typename T>
class Set
{
public:
	Set() {}

	void add(T & t)
	bool has(T & t);
	void del(T & t);

	class Iter;
	Iter begin();
	Iter end();
};
