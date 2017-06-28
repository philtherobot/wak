/*
 * TestNil.cpp
 *
 *  Created on: 2017-06-18
 *      Author: philippe
 */

#include "Tests.hpp"
#include "nil.hpp"

namespace
{
class UserType
{
public:
	UserType(bool is_nil = false) : is_nil_{is_nil} {}

	bool operator ==(UserType rhs) const { return is_nil_ == rhs.is_nil_; }
	bool operator !=(UserType rhs) const { return is_nil_ != rhs.is_nil_; }

	bool is_nil_;

	static UserType nil;
};
} /// anonymous

UserType UserType::nil{true};

class TestNil : public TestCase
{
public:
	virtual void run()
	{
		check( UserType()     == UserType() );
		check( UserType()     != UserType(true) );
		check( UserType(true) == UserType(true) );

		check( ! UserType().is_nil_ );
		check( UserType::nil.is_nil_ );

		check( ! isNil( UserType() ) );
		check(   isNil( UserType(true) ) );
		check(   isNil( UserType::nil ) );
	}

	static TestNil test;
};

TestNil TestNil::test;
