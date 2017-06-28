/*
 * Tests.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#include "Tests.hpp"
#include "Exception.hpp"

TestCase * TestCase::head_{};

TestCase::TestCase()
{
	record(this);
}

void TestCase::check(bool expr)
{
	if( !expr ) throw Exception(Str("test failure"));
}

void TestCase::runAllTests()
{
	TestCase * tc = head_;
	while( tc )
	{
		tc->run();
		tc = tc->next_;
	}
}

void TestCase::record(TestCase * tc)
{
	tc->next_ = head_;
	head_ = tc;
}
