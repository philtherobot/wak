
#include "Tests.hpp"

#include "BasicTypes.hpp"

class TestBasicTypes : public TestCase
{
public:
	virtual void run()
	{
		check( sizeof(Char) == 4 );
	}

	static TestBasicTypes test;
};

TestBasicTypes TestBasicTypes::test;
