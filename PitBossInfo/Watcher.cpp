#include "StdAfx.h"
#include "Watcher.h"

#include "GameStatus.h"


namespace Watcher {

	/*
	struct PlayerHWND {
		PlayerHWND() : nameH(0), pingH(0), scoreH(0) {}
		HWND nameH;
		HWND pingH;
		HWND scoreH;
	} PlayerH[MAX_PLAYER];

	int nPlayer;
	int childCount;
	HWND pitbossH, nameyearH, timeH, playerpanelH;
	*/

	void init(){
		print(0, L"init Watcher...");

		
		childCount = 0;
		nPlayer = 0;

		pitbossH = 0;
		nameyearH = 0;
		timeH = 0;
		playerpanelH = 0;
		

		print(1, _T("seeking pitboss main window: "));
		pitbossH = FindWindow(NULL, TXT_GET(LANGUAGE, TXT_PITBOSS_TITLE, _T(GAME_NAME)));

		if (pitbossH != 0){
			println(1, L"DONE");
			setHandles();
		}
		else {
			println(1, L"FAIL (need to change the title from ger to eng??)");
			assert(pitbossH);
		}

		//PlayerHWND PlayerH[MAX_PLAYER];
	}

	void setHandles(){

		//getting game name and year
		print(1,L"getting handle - name and year: ");
		nameyearH = GetWindow(pitbossH, GW_CHILD);
		if (nameyearH!=0){println(1, L"DONE");}
		else {
			println(1, L"FAIL");
			assert(nameyearH);
		}
		
		// getting timer
		print(1, L"getting handle - time: ");
		timeH = GetWindow(nameyearH, GW_HWNDNEXT); //skipping the roundtimer button
		timeH = GetWindow(timeH, GW_HWNDNEXT);
		if (timeH!=0){println(1, L"DONE");}
		else {
			println(1, L"FAIL");
			assert(timeH);
		}
		
		//getting player panel
		print(1,L"getting handle - playerpanel : ");
		playerpanelH = GetWindow(timeH, GW_HWNDNEXT);
		if (playerpanelH!=0){println(1, L"DONE");}
		else {
			println(1, L"FAIL");
			assert(playerpanelH);
		}

		//getting each player
		childCount = 0;
		println(1, L"getting handle - players: ");
		EnumChildWindows(playerpanelH, setPlayerHandles, 0);
		childCount /= 8; //there are 8 elements per player
		println(1, L"   found #children: ", childCount);
	}




	BOOL CALLBACK setPlayerHandles(HWND hwnd, LPARAM lparam) {
		int playerNr = childCount/8; //there are 8 window - children per player
		int childType = childCount%8;
		switch (childType) {
			case 0:
				print(1, L"   - found handle - player nr %i: [", playerNr);
				break;
			case 2: //player name
				PlayerH[playerNr].nameH = hwnd;
				print(1,L"name: DONE");
				break;
			case 4: //ping
				PlayerH[playerNr].pingH = hwnd;
				print(1,L"; ping: DONE");
				break;
			case 6: //score
				PlayerH[playerNr].scoreH = hwnd;
				println(1,L"; score: DONE]   DONE");
				break;
			default:
				break;
		}
		childCount++;
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


	GameStatus* getStatus() {

		return new GameStatus();
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
