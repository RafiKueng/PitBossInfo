/********************************************************************************************
* PBI - PitBossInfo
*
* author:		rafael kueng <rafi.kueng@gmx.ch>
*				beat durrer <the.holy.farmer@gmx.ch> (HTML logger)
* license:		DWYWWI - do whatever you want with it (but please give us credit)
* version:		v1.0 RC2
* timestamp:	2012-05-03--02:30
* changelog:	rc1: fixed memory leaks, formatted output
*				rc2: added htmllogger (bdurrer)
*********************************************************************************************/

#include "stdafx.h"
#include <conio.h>

#include "Game.h"
#include "Watcher.h"
#include "Lang.h"

#include "Logger.h"
#include "HtmlLogger.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// main programm / init stuff
	// -----------------------------------------------------------------------------------

	//_CrtSetBreakAlloc(299);

	Lang::init();

	Game *thisGame = new Game();

	OutputModule *txt_logger = new Logger(thisGame);
	txt_logger->setup(string("I:\\www\\htdocs\\civ4_pb_status\\stat.txt"));
    
    OutputModule *html_logger = new HtmlLogger(thisGame);
	html_logger->setup(string("I:\\www\\htdocs\\civ4_pb_status\\stat.html"));

	if (!thisGame->initSuccessful()){
		println(0,L"Main    : game init not sucessful, aborting");
		return 0;
	}

	println (0, L"------------------------------------------------");
	println (0, L"Main    : Init successfull, starting mainloop...");
	println (0, L"------------------------------------------------\n\n");
	println (0, L"To stop, please press 'ESC' and wait for a while...");

	// main programm / main loop
	// -----------------------------------------------------------------------------------

	while (true) {

		println(2,L"in mainloop, checking for key");
		if (_kbhit()){
			char key = _getch();
			if (key == 27) {
				println(0,L"Pressed 'ESC', EXITING PROGRAM...");
				break;
			}
			else {
				println(0,L"to stop the program, please press 'ESC'\n      ... and not: %c (charcode: %i)", _getch(), _getch());
			}
		}

		// doing the stuff
		thisGame->update();

		//updateing the outputs
		txt_logger->write();
		html_logger->write();
		//db_logger.writeToDB()


		// waiting some time
		println(2,L"getting some sleep (%i ms)", SLEEPTIME);
		Sleep(SLEEPTIME);	//using the winapi sleep to not overheat my server...
	}

	print(0,L"\nShutting down....               ");

	Lang::cleanUp();

	delete thisGame;
	delete txt_logger;
	delete html_logger;

	//show memory leak report
	//_CrtDumpMemoryLeaks();
	println(0,L"DONE");

	return 0;
}

