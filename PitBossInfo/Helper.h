#pragma once

#ifndef _HELPER_H
#define _HELPER_H

#include <cstdarg>

namespace Helper
{

	//void println(int lvl, string str);
	//void print(int lvl, string str);

	// general function
	void print(int lvl,LPCTSTR lpOutputString, ... );
	void println(int lvl,LPCTSTR lpOutputString, ... );

	void printHandleInfo();
};

#endif