/*
 * P.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once


template <typename T>
class P
{
public:
	P() {}

	template <typename U>
	P(U * u)
	{
		holder = new Holder;
		holder->nrefs = 1;
		holder->obj = u;
	}

	P(P & o)
	{
		holder = o.holder;
		++holder->nrefs;
	}

	~P()
	{
		--holder->nrefs;
		if( !holder->nrefs )
		{
			delete holder->obj;
			delete holder;
		}
	}

	T * operator -> ()
	{
		return holder->obj;
	}

	size_t refcount() { return holder->nrefs; }

protected:
	class Holder
	{
	public:
		size_t nrefs{};
		T * obj{};
	};
	Holder * holder{};
};
