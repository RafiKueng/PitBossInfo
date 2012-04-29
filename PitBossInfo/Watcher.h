#pragma once

#include "GameStatus.h"

using std::string;

namespace Watcher {

	
	struct PlayerHWND {
		PlayerHWND() : nameH(0), pingH(0), scoreH(0) {}
		HWND nameH;
		HWND pingH;
		HWND scoreH;
	} ;

	

	static PlayerHWND PlayerH[MAX_PLAYER];
	static int nPlayer;
	static int childCount;
	static HWND pitbossH, nameyearH, timeH, playerpanelH;
	

	void init();
	void setHandles();
	BOOL CALLBACK setPlayerHandles(HWND hwnd, LPARAM lparam);
	void printHandleInfo(HWND hwnd); //debug function

	GameStatus* getStatus();

	//parser functions, each gets input str and sets differen output
	void parseNameYear(wchar_t *str, string &name, int &year);
	void parseTimer(wchar_t *str, time_t &timer, time_t &end);
	void parsePlayer(wchar_t *str, string &name, bool &finished);
	void parsePing(wchar_t *str, Status &status);
	void parseScore(wchar_t *str, int &score);




};

