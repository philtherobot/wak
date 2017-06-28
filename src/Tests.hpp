
#pragma once


class TestCase
{
public:
	TestCase();
	virtual void run() = 0;
	void check( bool expr );
	
	static void runAllTests();
	
private:
	static void record(TestCase * tc);
	TestCase * next_{};
	static TestCase * head_;
};

