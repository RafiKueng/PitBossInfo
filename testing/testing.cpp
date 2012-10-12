// testing.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
#include <curl/curl.h>


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


	//------------------------
	// libcurl testing 
	//------------------------




 

  CURL *curl_handle;
  static const char *headerfilename = "head.out";
  FILE *headerfile;
  static const char *bodyfilename = "body.out";
  FILE *bodyfile;
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* init the curl session */ 
  curl_handle = curl_easy_init();
 
  /* set URL to get */ 
  curl_easy_setopt(curl_handle, CURLOPT_URL, "http://www.google.com");
 
  /* no progress meter please */ 
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
 
  /* send all data to this function  */ 
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
 
  /* open the files */ 
  headerfile = fopen(headerfilename,"w");
  if (headerfile == NULL) {
    curl_easy_cleanup(curl_handle);
    return -1;
  }
  bodyfile = fopen(bodyfilename,"w");
  if (bodyfile == NULL) {
    curl_easy_cleanup(curl_handle);
    return -1;
  }
 
  /* we want the headers to this file handle */ 
  curl_easy_setopt(curl_handle,   CURLOPT_WRITEHEADER, headerfile);
 
  /*
   * Notice here that if you want the actual data sent anywhere else but
   * stdout, you should consider using the CURLOPT_WRITEDATA option.  */ 
 
  /* get it! */ 
  curl_easy_perform(curl_handle);
 
  /* close the header file */ 
  fclose(headerfile);
 
  /* cleanup curl stuff */ 
  curl_easy_cleanup(curl_handle);
 

  //--------------------------------------------

    return 0;
}

