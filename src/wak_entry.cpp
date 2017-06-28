/*
 * wak_entry.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#include <iostream>
using namespace std;

#include "Exception.hpp"


int wakMain();

int main(int argc, char ** argv)
{
	try
	{
		return wakMain();
	}
	catch(Exception & ex)
	{
		cout << "caught Exception\n";
	}
	catch(...)
	{
		cout << "caught unknown type\n";
	}
	return 1;
}

