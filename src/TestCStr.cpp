/*
 * TestCStr.cpp
 *
 *  Created on: 2017-06-18
 *      Author: philippe
 */

#include "Tests.hpp"
#include "CStr.hpp"
#include "Str.hpp"
#include <cstring>

class TestCStr : public TestCase
{
public:
	virtual void run()
	{
		construction();
		access();
	}

	void construction()
	{
		CStr bydefault;
		check( bydefault.len() == 0 );

		CStr fromZeroArray("plain c string");

		Str str("from Str");
		CStr fromStr(str);
	}

	void access()
	{
//		CStr x("plain c string");
//		check( x.len() == 14 );
//		char * p = x;
//		check( 0 == std::strcmp(p, "plain c string") );
	}

	static TestCStr test;
};

TestCStr TestCStr::test;

