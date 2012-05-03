#include "StdAfx.h"
#include "Watcher.h"


#include <sstream>
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
		println(0, L"Watcher : Init...");
				
		childCount = 0;
		nPlayer = 0;

		pitbossH = 0;
		nameyearH = 0;
		timeH = 0;
		playerpanelH = 0;
		

		print(1, _T("Watcher : seeking pitboss main window: "));
		const TCHAR * windowname = TXT_GET_WS(LANGUAGE, TXT_PITBOSS_TITLE, _T(GAME_NAME));
		pitbossH = FindWindow(NULL, windowname);
		delete [] windowname;

		if (pitbossH != 0){
			println(1, L"DONE");
			setHandles();
		}
		else {
			println(1, L"FAIL (need to change the title from ger to eng??)");
			assert(pitbossH);
		}

		//PlayerHWND PlayerH[MAX_PLAYER];
		println(0, L"Watcher : Init successful: (found %2i players)",childCount);
	}

	void setHandles(){

		//getting game name and year
		print(2,L"getting handle - name and year: ");
		nameyearH = GetWindow(pitbossH, GW_CHILD);
		if (nameyearH!=0){println(1, L"DONE");}
		else {
			println(2, L"FAIL");
			assert(nameyearH);
		}
		
		// getting timer
		print(2, L"getting handle - time: ");
		timeH = GetWindow(nameyearH, GW_HWNDNEXT); //skipping the roundtimer button
		timeH = GetWindow(timeH, GW_HWNDNEXT);
		if (timeH!=0){println(2, L"DONE");}
		else {
			println(2, L"FAIL");
			assert(timeH);
		}
		
		//getting player panel
		print(2,L"getting handle - playerpanel : ");
		playerpanelH = GetWindow(timeH, GW_HWNDNEXT);
		if (playerpanelH!=0){println(2, L"DONE");}
		else {
			println(2, L"FAIL");
			assert(playerpanelH);
		}

		//getting each player
		childCount = 0;
		print(2, L"getting handle - players:    ");
		EnumChildWindows(playerpanelH, setPlayerHandles, 0);
		childCount /= 8; //there are 8 elements per player
		println(2, L"DONE\n     (found #players: %i)", childCount);
		nPlayer = childCount; 
	}




	BOOL CALLBACK setPlayerHandles(HWND hwnd, LPARAM lparam) {
		int playerNr = childCount/8; //there are 8 window - children per player
		int childType = childCount%8;
		switch (childType) {
			case 0:
				print(1, L"\n   - found handle - player nr %2i: [", playerNr);
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
				print(1,L"; score: DONE]   DONE");
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


	GameStatus getStatus() {

		string name;
		int year;
		time_t timer, nextRound;

		wchar_t nameyearstr[MAX_CHAR_LEN];
		wchar_t timestr[MAX_CHAR_LEN];

		GetWindowText(nameyearH,nameyearstr,sizeof(nameyearstr));
		GetWindowText(timeH,timestr,sizeof(timestr));

		parseNameYear(nameyearstr, name, year);
		parseTimer(timestr, timer, nextRound);

		GameStatus gs = GameStatus(name, year, nextRound, nPlayer);


		for (int i = 0; i<nPlayer; ++i) {
			string pname;
			bool finishedTurn;
			Status status;
			int score;

			wchar_t * playerstr = new wchar_t[MAX_CHAR_LEN];
			wchar_t * pingstr = new wchar_t[MAX_CHAR_LEN];
			wchar_t * scorestr = new wchar_t[MAX_CHAR_LEN];
		
			GetWindowText(PlayerH[i].nameH,  playerstr, MAX_CHAR_LEN);
			GetWindowText(PlayerH[i].pingH,  pingstr,   MAX_CHAR_LEN);
			GetWindowText(PlayerH[i].scoreH, scorestr,  MAX_CHAR_LEN);

			parsePlayer(playerstr, pname, finishedTurn);
			parsePing(pingstr, status);
			parseScore(scorestr, score, status);

			delete[] playerstr;
			delete[] pingstr;
			delete[] scorestr;

			//Player p = new Player(pname, finishedTurn, status, score);
			gs.setPlayer(i, pname, finishedTurn, status, score);



		}

		return gs;
	}



	void parseNameYear(wchar_t *wcstr, string &name, int &year) {

		int len = 0;
		int pos = -1;

		//convert to narrow char string
		char *cstr = new char[MAX_CHAR_LEN];
		wcstombs(cstr, wcstr, MAX_CHAR_LEN);
		string str = string(cstr);
		delete[] cstr; cstr = NULL;

		//find the last dash and str length
		pos = str.find_last_of('-');

		//string *name = new string();
		//string *year = new string();

		name = str.substr(0, pos-1);

		//get the pos after the year number
		int pos2;
		for (pos2 = pos+2; str[pos2] != ' '; ++pos2) {
			//cout << str[pos2]<<"\n";
		}

		string yearstr = str.substr(pos+2, pos2-pos-2);

		stringstream sstr(yearstr);
		sstr >> year;
		//year = -5000;

		string suffix = str.substr(pos2+1, str.size());
		const char * tmp = TXT_GET_C(LANGUAGE, TXT_YEAR_BC);
		if (suffix.compare(tmp) == 0){
			year *= -1;
		}
		//delete [] tmp;

	}

	void parseTimer(wchar_t *wcstr, time_t &timer, time_t &end) {

		char *cstr = new char[MAX_CHAR_LEN];
		wcstombs(cstr, wcstr, MAX_CHAR_LEN);
		string str = string(cstr);
		delete[] cstr; cstr = NULL;

		int h=0, m=0, s=0;
		stringstream sstr;
		int offset = str.length()-6; //how many digits has the first number? *:XX:XX
		
		string h_str = str.substr(0, offset);
		sstr = stringstream(h_str);
		sstr >> h;

		string m_str = str.substr(offset+1, 2);
		sstr = stringstream(m_str);
		sstr >> m;

		string s_str = str.substr(offset+4, 2);
		sstr = stringstream(s_str);
		sstr >> s;

		end = time(0) + h*60*60+m*60+s;
		timer = h*60*60+m*60+s;
	}

	void parsePlayer(wchar_t *wcstr, string &name, bool &finished) {
		
		char *cstr = new char[MAX_CHAR_LEN];
		wcstombs(cstr, wcstr, MAX_CHAR_LEN);
		string str = string(cstr);
		delete[] cstr; cstr = NULL;

		if (str[0]=='*'){
			name = str.substr(1,str.length()-1);
			finished = true;
		}
		else {
			name = str;
			finished = false;
		}

	}

	void parsePing(wchar_t *wcstr, Status &status) {

		char *cstr = new char[MAX_CHAR_LEN];
		wcstombs(cstr, wcstr, MAX_CHAR_LEN);
		string str = string(cstr);
		delete[] cstr; cstr = NULL;

		if		(str.compare(TXT_GET_C(LANGUAGE, TXT_UNCLAIMED)) == 0)	{status = UNCLAIMED;}
		else if (str.compare(TXT_GET_C(LANGUAGE, TXT_AI)) == 0)			{status = AI;}
		else if (str.compare(TXT_GET_C(LANGUAGE, TXT_DISC)) == 0)		{status = DISC;}
		//else if (str.compare(TXT_GET_C(LANGUAGE, TXT_DEFEAT)) == 0)		{status = DEFEAT;}
		else															{status = ONLINE;}
	}

	void parseScore(wchar_t *wcstr, int &score, Status &status) {
		char *cstr = new char[MAX_CHAR_LEN];
		wcstombs(cstr, wcstr, MAX_CHAR_LEN);
		stringstream ss = stringstream(cstr);
		ss >> score;
		delete[] cstr; cstr = NULL;
		
		if (score == 0) {status = DEFEAT;}

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
