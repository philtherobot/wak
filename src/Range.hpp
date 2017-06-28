/*
 * Range.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#ifndef RANGE_HPP_
#define RANGE_HPP_


template <typename T>
class Range
{
public:
	Range() {}

	template <typename It>
	Range(It first, It last) : beg{first}, en{last} {}

	T * begin() { return beg; }
	T * end() { return en; }

protected:
	T
};


#endif /* RANGE_HPP_ */
