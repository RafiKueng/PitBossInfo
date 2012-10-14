// testing.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <string>
#include <map>


using namespace std;



static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}


int _tmain(int argc, _TCHAR* argv[])
{
/*
	using namespace std;
 
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
				cout << "unknown argument: " << buf[1];
				error = true;
			}
		}


	}

	if (error || count>0 )
	{
		cout << "use: -h help \n";
		cout << "     -p output path without extension\n";
		cout << "     -t refresh timer (in min, use 15)\n";
		cout << "     -l language of pitboss (use 2 chars, de, en)\n";
		cout << "     -n name of the game (pitboss title)\n";
		return 0;
	}

	
	char buf[255];

	wcstombs(buf, argv[p_at],255);
	string cl_path = string(buf);

	wcstombs(buf, argv[t_at],255);
	int    cl_time = atoi(buf);

	wcstombs(buf, argv[l_at],255);
	string cl_lang = string(buf);

	wcstombs(buf, argv[n_at],255);
	string cl_name = string(buf);

	cout << "p:" << cl_path.c_str() << endl;
	cout << "t:" << cl_time << endl;
	cout << "l:" << cl_lang.c_str() << endl;
	cout << "n:" << cl_name.c_str() << endl;


	*/


	string line;
	map<string, string> settings;

	ifstream configfile ("testing.config");
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

			/*
			if (DEBUG==2) {
				cout << "config: key  : "<<line.substr(0,pos_eq) << endl;
				cout << "config: value: " << line.substr(pos_eq+1,string::npos) << endl;
			}
			*/
		}
		configfile.close();
	}

	else { cout << "Unable to open config file";  }


	return 0;
}

