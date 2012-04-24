#pragma once

#include <windows.h>



class Spy
{
	


public:
	Spy(void);
	std::string* getWindowList();
	~Spy(void);


	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);


	


private:
	static int childrenCount;
	void printHandleInfo(HWND hwnd);
	

	

};

