#include "StdAfx.h"
#include "Helper.h"

#include <cstdarg>

using namespace std;

namespace Helper {

	void print (int lvl, LPCTSTR lpOutputString, ... )
	{
		if (lvl <= VERBOSE_LEVEL){
			va_list argptr;
			va_start(argptr, lpOutputString);

			vwprintf(lpOutputString, argptr);

			va_end(argptr);
		}
	}


	void println (int lvl, LPCTSTR lpOutputString, ... )
	{
		if (lvl <= VERBOSE_LEVEL){
			va_list argptr;
			va_start(argptr, lpOutputString);

			vwprintf(lpOutputString, argptr);
			cout << endl;

			va_end(argptr);
		}
	}


} //end namespace Helper