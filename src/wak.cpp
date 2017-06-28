//============================================================================
// Name        : wak.cpp
// Author      : Philippe Payant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Tests.hpp"

int wakMain() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TestCase::runAllTests();
	return 0;
}
