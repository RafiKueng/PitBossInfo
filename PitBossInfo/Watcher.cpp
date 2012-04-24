#include "StdAfx.h"
#include "Watcher.h"


namespace Watcher {

	void init(){
		childCount = 0;
		nPlayer = 0;

		HWND nameyearH = 0;
		HWND timeH = 0;
		HWND playerpanelH = 0;

		//PlayerHWND PlayerH[MAX_PLAYER];
	}

	void setHandles(HWND mainH){

		//getting game name and year
		print(1,"getting handle - name and year: ");
		nameyearH = GetWindow(mainH, GW_CHILD);
		if (nameyearH!=0){println(1, "DONE");}
		else {
			println(1,"FAIL");
			assert(nameyearH);
		}
		
		// getting timer
		print(1,"getting handle - time: ");
		timeH = GetWindow(nameyearH, GW_HWNDNEXT); //skipping the roundtimer button
		timeH = GetWindow(timeH, GW_HWNDNEXT);
		if (timeH!=0){println(1, "DONE");}
		else {
			println(1,"FAIL");
			assert(timeH);
		}
		
		//getting player panel
		print(1,"getting handle - playerpanel : ");
		playerpanelH = GetWindow(timeH, GW_HWNDNEXT);
		if (playerpanelH!=0){println(1, "DONE");}
		else {
			println(1,"FAIL");
			assert(playerpanelH);
		}

		//getting each player
		childCount = 0;
		println(1,"getting handle - players: ");
		EnumChildWindows(playerpanelH, setPlayerHandles, 0);
		childCount /= 8; //there are 8 elements per player
		println(1, "   found #children: ", childCount);
	}




	BOOL CALLBACK setPlayerHandles(HWND hwnd, LPARAM lparam) {
		int playerNr = childCount/8; //there are 8 window - children per player
		int childType = childCount%8;
		switch (childType) {
			case 0:
				println(1,"   - found handle - player nr", playerNr, ": [");
			case 2: //player name
				PlayerH[playerNr].nameH = hwnd;
				print(1,"name: DONE");
				break;
			case 4: //ping
				PlayerH[playerNr].pingH = hwnd;
				print(1,"; ping: DONE");
				break;
			case 6: //score
				PlayerH[playerNr].scoreH = hwnd;
				print(1,"; score: DONE]   DONE");
				break;
			default:
				break;
		}

		/*
		wchar_t class_name[80];
		wchar_t title[80];
		GetClassName(hwnd,class_name, sizeof(class_name));
		GetWindowText(hwnd,title,sizeof(title));
		cout << "   Child nr: "<< childCount++;
		wcout <<"      Window title: "<<title<<endl;
		wcout <<"      Class name: "<<class_name<<endl;

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

		*/
		return TRUE;
	}


	void printHandleInfo(HWND hwnd){
		/*
		wchar_t class_name[80];
		wchar_t title[80];
		GetClassName(hwnd,class_name, sizeof(class_name));
		GetWindowText(hwnd,title,sizeof(title));
		wcout <<"   Window title: "<<title<<endl;
		wcout <<"   Class name: "<<class_name<<endl;
		*/
	}
}
