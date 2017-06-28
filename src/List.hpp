/*
 * List.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once

#include "BasicTypes.hpp"
#include "internal/algos.hpp"
#include "nil.hpp"

#include <initializer_list>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class List
{
public:
	List() {}

	List(std::initializer_list<T> const & il) : data_{il}
	{}

	List(List<T> rhs) : data_(rhs.data_) {}

	List(Size sz)
	{
		data_.resize(sz);
	}

//	template <typename It>
//	List(It * first, It * last)
//	{
//		len_ = distance(first, last);
//		data_ = new T[len_];
//		copy(first, last, data_);
//	}
	virtual ~List() {}

	Size len() { return data_.size(); }

	bool operator == ( List<T> rhs ) { return data_ == rhs.data_; }
	bool operator != ( List<T> rhs ) { return data_ == rhs.data_; }

	T & operator [] (Dist p) { return data_[p]; }

	class Iter
	{
	public:
		Iter(List<T> & self, Dist p)
		: self_(self), i_(p)
		{}

		T & operator *() { return self_[i_]; }
		Iter & operator ++() { ++i_; return *this; }
		bool operator !=(Iter & other) { return i_ != other.i_; }
	protected:
		List<T> & self_;
		Dist i_{};
	};

	Iter begin() { return Iter(*this, 0); }
	Iter end() { return Iter(*this, len()); }

//	List slice(Distance from, Distance to)
//	{
//		return List( data_+from, data_+to );
//	}

	// List(other);
	// operator =
	// operator ==

	List<T> & append(T v)
	{
		data_.push_back(v);
		return *this;
	}

	Dist find(T v)
	{
		typename std::vector<T>::iterator it;
		it = std::find(data_.begin(), data_.end(), v);

		if( it == data_.end() ) return nilDist;
		return std::distance(data_.begin(), it);
	}

	List<T> slice(Dist first, Dist last)
	{
		if( last <= first ) return List<T>();

		List<T> r(last-first);

		std::copy(data_.begin() + first, data_.end() + last,
				r.data_.begin());

		return r;
	}

	static List<T> nil;

protected:
	bool isNil_{false};

	static List<T> getNilList()
	{
		List<T> x;
		x.isNil_ = true;
		return x;
	}

	std::vector<T> data_;
};

template <typename T>
List<T> List<T>::nil = List<T>::getNilList();
