/*
 * StackTrace.cpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#include <stdio.h>
#include <execinfo.h>
//#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <cxxabi.h>
#include <string.h>

using namespace std;

#include "StackTrace.hpp"
#include "utility.hpp"

namespace
{
char * find(char c, char * s)
{
	while( *s )
	{
		if( *s == c ) return s;
		++s;
	}
	return 0;
}
}

StackTrace::StackTrace()
{
	nb_frames_ = backtrace(frames_, countOf(frames_));

	getSymbols();
/*
	for(auto s: symbols_)
	{
		auto p = s.find('(') + 1;
		auto u = s.find('+');
		auto function = s.slice(p, u);
	}
*/
	symbols_ = backtrace_symbols(frames_, nb_frames_);
	for(int i=0; i < nb_frames_; ++i)
	{
		char * symbol = symbols_[i];
		char * p = find( '(', symbol) + 1;
		char * u = find( '+', p);
		char function[1024];
		strncpy(function, p, u-p);
		function[u-p] = 0;
		//fprintf(stderr, "%s\n", n);
		int status;
		char * name = abi::__cxa_demangle(function,0 ,0, &status);
		if( !name ) continue;
		fprintf(stderr, "%s\n", name);
		free(name);
	}
}

StackTrace::~StackTrace()
{}

void StackTrace::getSymbols()
{
	char ** symbols = backtrace_symbols(frames_, nb_frames_);
	for(int i=0; i < nb_frames_; ++i)
	{
		symbols2_.append( Str(symbols[i]) );
	}

	free(symbols);
}
/*
Str StackTrace::demangle(Str function)
{
	int status;
	char * name = abi::__cxa_demangle( function.cstr(), 0 ,0, &status );
	if( !name ) return Opt<Str>();
	free(name);
	return Str(name);
}
*/
