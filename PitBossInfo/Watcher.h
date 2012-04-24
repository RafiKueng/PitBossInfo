#pragma once
class Watcher
{
public:
	Watcher(void);
	void init();
	void update();
	~Watcher(void);

private:

	static int childCount;

	static void Readout(HWND mainH);
	static BOOL CALLBACK ReadoutPlayers(HWND hwnd, LPARAM lparam);
	static void printHandleInfo(HWND hwnd); //debug function

};

