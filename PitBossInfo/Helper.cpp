#include "StdAfx.h"
#include "Helper.h"

#include <cstdarg>

using namespace std;

namespace Helper {


	/*
	void print(int lvl, string str){
		if (lvl >= VERBOSE_LEVEL){
			cout << str;
		}
	}

	void println(int lvl, string str){
		if (lvl >= VERBOSE_LEVEL){
			cout << str << endl;
		}
	}
	*/
	void print(int lvl, const char* Format, ...){
		if (lvl >= VERBOSE_LEVEL){
			va_list Arguments;
			va_start(Arguments, Format);
			double FArg;
			int IArg;
			for(int i = 0; Format[i] != '\0'; ++i )
			{
				cout << "formatcode: "<<Format[i];

				if (Format[i] == 'f')
				{
					FArg=va_arg(Arguments, double);
					printf("Caught a float : %.3lf\n",FArg);
				}
				else if (Format[i] == 'i')
				{
					IArg=va_arg(Arguments, int);
					printf("Caught an integer : %d\n",IArg);
				}
			}
			va_end(Arguments);
		}
	}

	void println(int lvl, const char* Format, ...){
		if (lvl >= VERBOSE_LEVEL){
			va_list Arguments;
			va_start(Arguments, Format);
			double FArg;
			int IArg;
			for(int i = 0; Format[i] != '\0'; ++i )
			{
				cout << "formatcode: "<<Format[i];

				if (Format[i] == 'f')
				{
					FArg=va_arg(Arguments, double);
					printf("Caught a float : %.3lf\n",FArg);
				}
				else if (Format[i] == 'i')
				{
					IArg=va_arg(Arguments, int);
					printf("Caught an integer : %d\n",IArg);
				}
			}
			va_end(Arguments);
		}
	}

	void printHandleInfo(){

	}


} //end namespace Helper