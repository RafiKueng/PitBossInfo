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
*				1.2: changed to get settings from ini file provided with comand line switch
*						removed unicode support, all in ansi now.
*********************************************************************************************
* TODO:			-	finish conversion from unicode to ansi (stuck somewhere between game.cpp
*					and watcher.h)
*
*********************************************************************************************/

#include "stdafx.h"
#include <conio.h>
#include <map>

#include "Game.h"
#include "Watcher.h"
//#include "Lang.h"

#include "Logger.h"
#include "HtmlLogger.h"
#include "HtmlGETSender.h"

using namespace std;

int main(int argc, char * argv[])
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
	int c_at;
	bool gotConfig = false;

    for (int nArg=1; nArg < argc; nArg++){
		//cout << nArg << " ";
		//char buf[MAX_CHAR_LEN];
		//wcstombs(buf, argv[nArg],MAX_CHAR_LEN);

		if (argv[nArg][0]=='-') {
			switch (argv[nArg][1])
			{
			case 'c': //path to config file
				c_at = nArg+1;
				gotConfig=true;
				break;
			case 'h': //help
				error=true;
				break;
			case 'p': //list leader / player ids
				error=true;
				break;
			default:
				cout << "unknown argument: " << argv[nArg][1] << endl;
				error = true;
			}
		}
	}

	if (error || !gotConfig)
	{
		cout << "use: -h help \n";
		cout << "     -c config file path\n";
		cout << "     -p list nations/leader ids\n";
		return 0;
	}

	
	char buf[MAX_CHAR_LEN];

	//save input in strings
	//wcstombs(buf, argv[c_at],MAX_CHAR_LEN);
	string cl_configfile = string(argv[c_at]);
	cout << "config file : " << cl_configfile << endl;


	// --- end parsing -------------------------------



	// --- READ CONFIG FILE ----------------------------

	string line;
	map<string, string> settings;

	ifstream configfile (cl_configfile);
	if (configfile.is_open())
	{
		while ( configfile.good() )
		{
			getline (configfile,line);
			if (line.substr(0,1).compare("#")==0) { continue; } //a commenting line
			if (line.empty()) { continue; } //a commenting line
			int pos_eq = line.find("=");

			settings.insert(pair<string,string>(
				line.substr(0,pos_eq), line.substr(pos_eq+1,string::npos)));

			
			if (VERBOSE_LEVEL==2) {
				cout << "config: key  : "<<line.substr(0,pos_eq) << endl;
				cout << "config: value: " << line.substr(pos_eq+1,string::npos) << endl;
			}
		}
		configfile.close();
	}

	else {
		cout << "Unable to open config file, aborting";
		return 1;
	}

	// --- end reading config file


	Lang::init();

	string gamename = settings.find("game.name")->second;
	Game *thisGame = new Game(gamename);

	/*
	OutputModule *txt_logger = new Logger(thisGame);
	string txt_uri = string(cl_path);
	txt_uri.append(".txt");
	txt_logger->setup(txt_uri);

    
    OutputModule *html_logger = new HtmlLogger(thisGame);
	string html_uri = string(cl_path);
	html_uri.append(".html");
	html_logger->setup(html_uri);


	OutputModule *htmlGET_sender = new HtmlGETSender(thisGame);
	string post_url = string("http://civ4stats.appspot.com/civ4stats?s=event&");
	htmlGET_sender->setup(post_url);
	*/


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
		//txt_logger->write();
		//html_logger->write();
		//db_logger.writeToDB()


		// waiting some time
		//println(2,L"getting some sleep (%i ms)", cl_time*1000);
		//Sleep(cl_time*1000);	//using the winapi sleep to not overheat my server...
	}

	print(0,L"\nShutting down....               ");

	Lang::cleanUp();

	delete thisGame;
	//delete txt_logger;
	//delete html_logger;

	//show memory leak report
	//_CrtDumpMemoryLeaks();
	println(0,L"DONE");

	return 0;
}

