/*
 * TestList.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#include "Tests.hpp"
#include "List.hpp"
#include "nil.hpp"

class TestList : public TestCase
{
public:
	virtual void run()
	{
		defaultConstruction();
		initializerConstruction();
		emptyConstruction();
		copyConstruction();
		copy();
		assign();
		forLoop();
		append();
		nil();
		slice();
	}

	void defaultConstruction()
	{
		List<int> x;
		check( x.len() == 0 );
	}

	void initializerConstruction()
	{
		List<int> x{1,2,3};
		check( x.len() == 3 );
		check( x[0] == 1 );
		check( x[1] == 2 );
		check( x[2] == 3 );
	}

	void emptyConstruction()
	{
		List<int> x(3);
		check( x.len() == 3 );
		check( x[0] == 0 );
		check( x[1] == 0 );
		check( x[2] == 0 );

		List<int> y;
		check( y.len() == 0 );
	}

	void copyConstruction()
	{
		List<int> y{1,2,3};
		List<int> x(y);
		check( x.len() == 3 );
		check( x[0] == 1 );
		check( x[1] == 2 );
		check( x[2] == 3 );
	}

	void copy()
	{
		List<int> y{1,2,3};
		List<int> x;
		x = y;
		check( x.len() == 3 );
		check( x[0] == 1 );
		check( x[1] == 2 );
		check( x[2] == 3 );
	}

	void assign()
	{
		List<int> v{1,2,3};
		List<int> x;
		x = v;
		check( x[0] == 1 );
		check( x[1] == 2 );
		check( x[2] == 3 );
	}

	void forLoop()
	{
		List<double> x{11., 12., 13.};
		double sum = 0;
		for(auto v: x) sum += v;
		check( sum == 36 );
	}

	void append()
	{
		List<int> x{1,2};
		x.append(3);
		check( x.len() == 3 );
		check( x[0] == 1 );
		check( x[1] == 2 );
		check( x[2] == 3 );
	}

	void nil()
	{
		auto v = List<int>::nil;
		check( isNil( v ) );
	}

	void find()
	{
		List<int> x{1,2,3};
		check( x.find(1) == 0 );
		check( x.find(14) == nilDist );
	}

	void slice()
	{
		List<int> x{1,2,3,4};
		check( x.slice(0, 4) == List<int>{1,2,3,4} );
		check( x.slice(0, 2) == List<int>{1,2} );
		check( x.slice(2, 4) == List<int>{3,4} );
		check( x.slice(4, 4) == List<int>{} );
		check( x.slice(0, 0) == List<int>{} );
		check( x.slice(1, 1) == List<int>{} );
		check( x.slice(1, 0) == List<int>{} );
	}

	static TestList test;
};

TestList TestList::test;
