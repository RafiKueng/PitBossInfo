#include "StdAfx.h"
#include "Spy.h"

using namespace std;


// STATIC STUFF
///////////////////////////////


int Spy::childrenCount = 0;

BOOL CALLBACK Spy::EnumWindowsProc(HWND hwnd, LPARAM counter) {
	wchar_t class_name[80];
	wchar_t title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
	cout << "   Child nr: "<< Spy::childrenCount++;
    wcout <<"      Window title: "<<title<<endl;
    wcout <<"      Class name: "<<class_name<<endl;
	return TRUE;
}


// NON STATIC STUFF
///////////////////////////////

Spy::Spy(void){
	Spy::childrenCount = 0;
}

std::string* Spy::getWindowList(){
	std::string* s1 = new std::string("'Luemmelparty 6' erfolgreich gespeichert\"");

	cout << "looking for: ";
	cout << *s1 << endl;
	HWND main, nameyear, time, playerpanel;
	
	main = FindWindow(NULL,_T("'Luemmelparty 6' erfolgreich gespeichert\""));
	if (main != 0){
		cout << "got the window!" << endl;

		//getting game name and year
		cout << "getting name and year: ";
		nameyear = GetWindow(main, GW_CHILD);
		if (nameyear!=0){ printHandleInfo(nameyear);}
		else {cout<<"nameyear not found!!";}
		
		// getting timer
		cout << "getting time: ";
		time = GetWindow(nameyear, GW_HWNDNEXT); //skipping the roundtimer button
		time = GetWindow(time, GW_HWNDNEXT);
		if (time!=0){ printHandleInfo(time);}
		else {cout<<"nameyear not found!!";}		
		
		//getting player stats
		cout << "getting playerpanel / children of it: ";
		playerpanel = GetWindow(time, GW_HWNDNEXT);
		Spy::childrenCount = 0;
		EnumChildWindows(playerpanel, EnumWindowsProc, 0);
		childrenCount /= 8; //there are 8 elements per player
		cout << "   found #children: "<<Spy::childrenCount<<endl;
	}

	else {
		cout << "could not find the main window" << endl;
	}

	return s1;
}

void Spy::printHandleInfo(HWND hwnd){
	wchar_t class_name[80];
	wchar_t title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
    wcout <<"   Window title: "<<title<<endl;
    wcout <<"   Class name: "<<class_name<<endl;
}



Spy::~Spy(void)
{
}
