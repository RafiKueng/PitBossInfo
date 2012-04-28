#include "StdAfx.h"
#include "Lang.h"

namespace Lang {

	TCHAR* en[] = {
		_T("'%s' successfully saved\""),

		_T("BC"),
		_T("AD"),

		_T("Unclaimed"),
		_T("AI"),
		_T("Unclaimed"),
		_T("Disconnected"),
		_T("???")
	};


	TCHAR* de[] = {
		_T("'%s' erfolgreich gespeichert\""),

		_T("v. Chr."),
		_T("n. Chr."),

		_T("???"),
		_T("KI"),
		_T("???"),
		_T("???"),
		_T("???")
	};



	// the following are for convinience, but nor really used... using TXT_GET() in code...
	const TCHAR * EN (ID id) { return TXT_GET (_EN, id);}
	const TCHAR * EN (ID id, TCHAR * str) { return TXT_GET (_EN, id, str);}

	const TCHAR * DE (ID id) { return TXT_GET (_DE, id);}
	const TCHAR * DE (ID id, TCHAR * str) { return TXT_GET (_DE, id, str);}




	const TCHAR * TXT_GET (LANG lang, ID id)
	{
		TCHAR **table;
		switch (lang) {
			case _EN: table = en; break;
			case _DE: table = de; break;
		}

		return table[id];
	}

	const TCHAR * TXT_GET (LANG lang, ID id, TCHAR * str)
	{/*
		TCHAR **table;
		switch (lang) {
			case _EN: table = en; break;
			case _DE: table = de; break;
		}

		TCHAR buffer [256];
		wsprintf(buffer, table[id], str);*/

		TCHAR * buffer = new TCHAR [MAX_CHAR_LEN]; //this is a memoryleak...
		wsprintf(buffer, TXT_GET(lang, id), str);
		return buffer;
	}

	const char * TXT_GET_C (LANG lang, ID id)	{
		char *cstr = new char [MAX_CHAR_LEN];
		wcstombs(cstr, TXT_GET(lang, id), MAX_CHAR_LEN);
		return cstr;
	}

	const char * TXT_GET_C (LANG lang, ID id, char * str){
		char *cstr = new char [MAX_CHAR_LEN];
		wcstombs(cstr, TXT_GET(lang, id), MAX_CHAR_LEN);
		
		char *buf = new char [MAX_CHAR_LEN];
		sprintf(buf, cstr, str);
		delete [] cstr;
		return buf;
	}

}
