/*
 * algorithms.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#ifndef ALGORITHMS_HPP_
#define ALGORITHMS_HPP_



template <typename ItSrc, typename ItDst>
void copy(ItSrc first, ItSrc last, ItDst to)
{
	while( first != last )
	{
		*to = *first;
		++first;
		++to;
	}
}



#endif /* ALGORITHMS_HPP_ */
