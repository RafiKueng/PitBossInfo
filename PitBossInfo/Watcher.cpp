#include "StdAfx.h"
#include "Watcher.h"

using namespace std;


Watcher::Watcher(void)
{
}

Watcher::~Watcher(void)
{
}

void Watcher::init(void)
{
}

void Watcher::update(void)
{
}



// STATIC STUFF
int Watcher::childCount = 0;

void Watcher::Readout(HWND mainH){
	
	struct PlayerHandles {
		HWND name;
		HWND ping;
		HWND score;
	};

	HWND nameyearH, timeH, playerpanelH;
	PlayerHandles playerH[] = {0,0,0};


	//getting game name and year
	cout << "getting name and year: ";
	nameyearH = GetWindow(mainH, GW_CHILD);
	if (nameyearH!=0){
		
		printHandleInfo(nameyearH);
	
	}
	else {cout<<"nameyear not found!!";}
		
	// getting timer
	cout << "getting time: ";
	timeH = GetWindow(nameyearH, GW_HWNDNEXT); //skipping the roundtimer button
	timeH = GetWindow(timeH, GW_HWNDNEXT);
	if (timeH!=0){
		
		printHandleInfo(timeH);
	
	}
	else {cout<<"nameyear not found!!";}		
		
	//getting player stats
	cout << "getting playerpanel / children of it: ";
	playerpanelH = GetWindow(timeH, GW_HWNDNEXT);
	childCount = 0;
	EnumChildWindows(playerpanelH, ReadoutPlayers, 0);
	childCount /= 8; //there are 8 elements per player
	cout << "   found #children: "<<childCount<<endl;
}




BOOL CALLBACK Watcher::ReadoutPlayers(HWND hwnd, LPARAM lparam) {
	wchar_t class_name[80];
	wchar_t title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
	cout << "   Child nr: "<< childCount++;
    wcout <<"      Window title: "<<title<<endl;
    wcout <<"      Class name: "<<class_name<<endl;

	int playerNr = childCount/8; //there are 8 window - children per player
	int childType = childCount%8;
	switch (childType) {
		case 2: //player name
			//get name
			//get status
			break;
		case 4: //ping
			//if this is a number -> logged in, set to ping
			// if not, set to -1
			break;
		case 6: //score
			//cast to int and save
			break;

		default:
			break;
	}

	return TRUE;
}


void Watcher::printHandleInfo(HWND hwnd){
	wchar_t class_name[80];
	wchar_t title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
    wcout <<"   Window title: "<<title<<endl;
    wcout <<"   Class name: "<<class_name<<endl;
}
