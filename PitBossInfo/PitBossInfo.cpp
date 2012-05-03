/********************************************************************************************
* PBI - PitBossInfo
*
* author:		rafael kueng <rafi.kueng@gmx.ch>
* license:		DWYWWI - do whatever you want with it (but please give me credit)
* version:		v1.0 beta1
* timestamp:	2012-04-23--22:45
*********************************************************************************************/

#include "stdafx.h"
#include <conio.h>

#include "Spy.h"
#include "Game.h"
#include "Logger.h"
#include "Watcher.h"

#include "Lang.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	// old stuff for testing
	//-----------------------------------------------------

	//Spy * mySpy = new Spy();
	//cout << *mySpy->getWindowList();

	/* test complete watcher
	Watcher::init();
	GameStatus *gs = Watcher::getStatus();
	cout << gs->toString();
	*/

	/* time fcn testing
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "Current local time and date: %s", asctime (timeinfo) );
	*/

	/*testing translation
	cout << Lang::TXT_GET_C(_DE, TXT_PITBOSS_TITLE, "NAAMMEE")<<endl;
	wcout<<Lang::TXT_GET(_DE, TXT_PITBOSS_TITLE, _T("NAAMMEE"))<<endl;
	wcout<<Lang::TXT_GET(_DE, TXT_PITBOSS_TITLE)<<endl;
	*/

	/* testing gamename parser
	wchar_t *test = L"Testname - with dash - 4000 BC";
	string name;// = new string();
	int year; // = new int(0);
	Watcher::parseNameYear(test, name, year);
	cout << name;
	cout << year;
	*/

	/* parse timer test
	wchar_t *test = L"1:15:30";
	time_t t, end;
	Watcher::parseTimer(test, t, end);
	struct tm * timeinfo = localtime ( end );
	printf ( "timer: %i, endtime: %s", t, asctime(timeinfo) );
	*/

	/* test playerparser
	wchar_t *test = L"Hans";
	string name;
	bool fin;
	Watcher::parsePlayer(test, name, fin);
	cout << name << (fin?" finished":" not finished");
	*/


	// main programm / main loop
	// -----------------------------------------------------------------------------------

	Game *thisGame = new Game();
	OutputModule *logger = new Logger(thisGame);
	logger->setup(new string("D:\\civlog.txt"));
	
	OutputModule *logger2 = new HtmlLogger(thisGame);
	logger2->setup(new string("D:\\civlog.html"));

	if (!thisGame->initSuccessful()){
		println(0,L"game init not sucessful, aborting");
		return 0;
	}

	println (0, L"Init successfull, starting mainloop");
	println (0, L"to stop, please press 'ESC'");

	while (true) {
		println(1,L"in mainloop, checking for key");
		if (_kbhit()){
			char key = _getch();
			if (key == 27) {
				println(0,L"Pressed esc, EXITING PROGRAM");
				break;
			}
			else {
				println(0,L"to stop the program, please press esc and not: %i", _getch());
			}
		}

		// doing the stuff
		thisGame->update();

		//updateing the outputs
		logger->write();
		logger2->write();
		//dbWriter.writeToDB()


		// waiting some time
		println(2,L"getting some sleep (%i ms)", SLEEPTIME);
		Sleep(SLEEPTIME);	//using the winapi sleep to not overheat my server...
	}


	return 0;
}

