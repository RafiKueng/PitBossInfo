/********************************************************************************************
* PBI - PitBossInfo
*
* author:		rafael kueng <rafi.kueng@gmx.ch>
* license:		DTFYWWI - do the fuck you want with it (but please give me credit)
* version:		v0.1
* timestamp:	2012-04-23--22:45
*********************************************************************************************/

#include "stdafx.h"
#include <conio.h>

#include "Spy.h"
#include "Game.h"
#include "Logger.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// old stuff for testing
	Spy * mySpy = new Spy();
	cout << *mySpy->getWindowList();


	// new part, starting from here

	Game *thisGame = new Game();
	OutputModule *logger = new Logger(thisGame);

	if (thisGame->initSuccessful()){
		cout << "game inti not sucessful, aborting"<<endl;
		return 0;
	}

	while (true) {
		cout << "in loop, checking"<<endl;
		if (_kbhit()){
			char key = _getch();
			if (key == 27) {
				cout << "Pressed esc, EXITING PROGRAM"<<endl;
				break;
			}
			else {
				cout << "to stop the program, please press esc and not: " << _getch() << endl;
			}
		}

		// doing the stuff
		thisGame->update();

		//updateing the outputs
		logger->write();
		//dbWriter.writeToDB(thisGame->getEvents())


		// waiting some time
		cout << "getting some sleep (2s)"<<endl;
		Sleep(2000);	//using the winapi sleep to not overheat my server...
	}


	return 0;
}

