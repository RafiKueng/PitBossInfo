#pragma once

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






};

