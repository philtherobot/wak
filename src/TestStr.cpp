/*
 * TestStr.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */


#include "Tests.hpp"
#include "Str.hpp"

class TestStr : public TestCase
{
public:
	virtual void run()
	{
		defaultConstruction();
		charPointerConstruction();
		wCharPointerConstruction();
		copyConstruction();
		find();
		nil();
	}

	void defaultConstruction()
	{
		Str x;
		check( x.len() == 0 );
		Str y{};
		check( y.len() == 0 );
	}

	void charPointerConstruction()
	{
		Str x{"plain char array"};
		check( x.len() == 16 );
	}

	void wCharPointerConstruction()
	{
		Str x{L"plain char array"};
		check( x.len() == 16 );
	}

	void copyConstruction()
	{
		Str other("plain char array");
		Str x{other};
		check( x.len() == 16 );
	}

	void find()
	{
		Str x{"plain char array"};
		check( x.find('l') == 1 );
		check( x.find('y') == 15 );
		check( x.find('s') == nilDist );
	}

	void nil()
	{
		auto v = Str::nil;
		check( isNil( v ) );
	}

	static TestStr test;
};

TestStr TestStr::test;
