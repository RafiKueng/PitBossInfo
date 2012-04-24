#pragma once

#ifndef _HELPER_H
#define _HELPER_H

#include <cstdarg>


using std::string;

namespace Helper
{

	//void println(int lvl, string str);
	//void print(int lvl, string str);

	// general function
	void print(int lvl, const char* Format, ...);
	void println(int lvl, const char* Format, ...);

	void printHandleInfo();
};

#endif