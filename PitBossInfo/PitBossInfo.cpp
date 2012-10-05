/********************************************************************************************
* PBI - PitBossInfo
*
* author:		rafael kueng <rafi.kueng@gmx.ch>
*				beat durrer <the.holy.farmer@gmx.ch> (HTML logger)
* license:		DWYWWI - do whatever you want with it (but please give us credit)
* version:		v1.1
* timestamp:	2012-07-20--13:45
* changelog:	rc1: fixed memory leaks, formatted output
*				rc2: added htmllogger (bdurrer)
*				rc3: added stylesheet to html logger; w3c valid html, css (bdurrer, rafik)
*				rc4: fixed "*MOD*" status issue, fixed "defeated, " issue
*				1.1: removed hardcoded stuff, added commandline parsing
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


	// ---------------------
	// parse command line
	// ---------------------

    cout << "There are " << argc << " arguments:" << endl;
 
    // Loop through each argument and print its number and value

	bool error = false;
	int p_at, t_at, l_at, n_at;
	int count = 4;

    for (int nArg=1; nArg < argc; nArg++){
		//cout << nArg << " ";
		char buf[255];
		wcstombs(buf, argv[nArg],255);

		if (buf[0]=='-') {
			switch (buf[1])
			{
			case 'p': //path (without extension)
				p_at = nArg+1;
				count--;
				break;
			case 't': //refreshtime
				t_at = nArg+1;
				count--;
				break;
			case 'l': //language
				l_at = nArg+1;
				count--;
				break;
			case 'n': //name
				n_at = nArg+1;
				count--;
				break;
			case 'h': //help
				error=true;
				break;
			default:
				cout << "unknown argument: " << buf[1] << endl;
				error = true;
			}
		}
	}

	if (error || count>0 )
	{
		cout << "use: -h help \n";
		cout << "     -p output path without extension\n";
		cout << "     -t refresh timer (in sec, use 15)\n";
		cout << "     -l language of pitboss (use 2 chars, de, en)\n";
		cout << "     -n name of the game (pitboss title)\n";
		return 0;
	}

	
	char buf[255];

	//save input in strings
	wcstombs(buf, argv[p_at],255);
	string cl_path = string(buf);
	wcstombs(buf, argv[t_at],255);
	int    cl_time = atoi(buf);
	wcstombs(buf, argv[l_at],255);
	string cl_lang = string(buf);
	wcstombs(buf, argv[n_at],255);
	string cl_name = string(buf);

	// keep the Tchar arrays to..
	_TCHAR* cl_path_ = argv[p_at];
	_TCHAR* cl_lang_ = argv[l_at];
	_TCHAR* cl_name_ = argv[n_at];


	cout << "out.path : " << cl_path.c_str() << endl;
	cout << "timeout  : " << cl_time << endl;
	cout << "language : " << cl_lang.c_str() << endl;
	cout << "win.name : " << cl_name.c_str() << endl;



	// --- end parsing -------------------------------

	string txt_uri = string(cl_path);
	string html_uri = string(cl_path);


	Lang::init();

	Game *thisGame = new Game(cl_name_);

	OutputModule *txt_logger = new Logger(thisGame);
	//string txt_uri = string(OUTPATH);
	//txt_uri.append(FILENAME);
	txt_uri.append(".txt");
	txt_logger->setup(txt_uri);
		//string("I:\\www\\htdocs\\civ4_pb_status\\lp6.txt"));
    
    OutputModule *html_logger = new HtmlLogger(thisGame);
	//string html_uri = string(OUTPATH);
	//html_uri.append(FILENAME);
	html_uri.append(".html");
	html_logger->setup(html_uri);
		//string("I:\\www\\htdocs\\civ4_pb_status\\lp6.html"));

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
		println(2,L"getting some sleep (%i ms)", cl_time*1000);
		Sleep(cl_time*1000);	//using the winapi sleep to not overheat my server...
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

