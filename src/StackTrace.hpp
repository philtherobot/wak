/*
 * StackTrace.hpp
 *
 *  Created on: 2017-06-17
 *      Author: philippe
 */

#pragma once

#include "Str.hpp"

class StackTrace
{
public:
	StackTrace();
	virtual ~StackTrace();

protected:
	void getSymbols();

	void * frames_[50];
	int nb_frames_{};
	char ** symbols_{};
	List<Str> symbols2_{};
};
