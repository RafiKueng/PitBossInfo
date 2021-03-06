// testing.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{

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

		//cout << buf << endl;
/*		int i=0;
		while (argv[nArg]>0){ 
	        cout << argv[nArg];
			i++;
		}
		cout << endl;
		*/
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


    return 0;
}

