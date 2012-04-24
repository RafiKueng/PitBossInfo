#pragma once

using std::string;

namespace Watcher {

	struct PlayerHWND {
		PlayerHWND() : nameH(0), pingH(0), scoreH(0) {}
		HWND nameH;
		HWND pingH;
		HWND scoreH;
	} PlayerH[MAX_PLAYER];

	int nPlayer;
	int childCount;
	HWND nameyearH, timeH, playerpanelH;


	void setHandles(HWND mainH);
	BOOL CALLBACK setPlayerHandles(HWND hwnd, LPARAM lparam);
	void printHandleInfo(HWND hwnd); //debug function






};

