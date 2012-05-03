#include "StdAfx.h"
#include "Lang.h"

namespace Lang {

	TCHAR* en[] = {
		_T("'%s' successfully saved\""),

		_T("BC"),
		_T("AD"),

		_T("Unclaimed"),
		_T("AI"),
		_T("Online"),
		_T("Disconnected"),
		_T("Defeat")
	};


	TCHAR* de[] = {
		_T("'%s' erfolgreich gespeichert\""),

		_T("v. Chr."),
		_T("n. Chr."),

		_T("Leer"),
		_T("KI"),
		_T("Online"),
		_T("Unterbrochen"),
		_T("Besiegt")
	};

	char *** cstr; //this table holds the char strings for each language
		//cstr[langID][elementID]

	// cerates / converts the lookuptable in std chars
	void init() {
		cstr = new char**[_N_LANG];
		TCHAR **table;

		for (int i = 0; i<_N_LANG; ++i){
			cstr[i] = new char*[TXT_N_ENTRIES];
			
			switch (i) {
				case _EN: table = en; break;
				case _DE: table = de; break;
			}

			for (int j = 0; j < TXT_N_ENTRIES; ++j){
				cstr[i][j] = new char [MAX_CHAR_LEN];
				wcstombs(cstr[i][j], table[j], MAX_CHAR_LEN);
				//cout << cstr[i][j];
			}
		}
	}

	void cleanUp(){
		for (int i = 0; i<_N_LANG; ++i){
			for (int j = 0; j < TXT_N_ENTRIES; ++j){
				delete [] cstr[i][j];
			}
			delete [] cstr[i];
		}
		delete [] cstr;
	}



	// the following are for convinience, but nor really used... using TXT_GET() in code...
	/*
	const TCHAR * EN (ID id) { return TXT_GET (_EN, id);}
	const TCHAR * EN (ID id, TCHAR * str) { return TXT_GET (_EN, id, str);}

	const TCHAR * DE (ID id) { return TXT_GET (_DE, id);}
	const TCHAR * DE (ID id, TCHAR * str) { return TXT_GET (_DE, id, str);}
	*/


	// get a wchar_t string, no need to deallocate
	const TCHAR * TXT_GET_W (LANG lang, ID id)
	{
		TCHAR **table;
		switch (lang) {
			case _EN: table = en; break;
			case _DE: table = de; break;
		}

		return table[id];
	}

	// get a wchar_t string, with substitution, NEED to deallocate yourself
	const TCHAR * TXT_GET_WS (LANG lang, ID id, TCHAR * str)
	{/*
		TCHAR **table;
		switch (lang) {
			case _EN: table = en; break;
			case _DE: table = de; break;
		}

		TCHAR buffer [256];
		wsprintf(buffer, table[id], str);*/

		TCHAR * buffer = new TCHAR [MAX_CHAR_LEN]; //this is a memoryleak...
		wsprintf(buffer, TXT_GET_W(lang, id), str);
		return buffer;
	}

	// get a wchar_t string, no need to deallocate
	const char * TXT_GET_C (LANG lang, ID id)	{
		return cstr[lang][id];
	}

	// get a char string, with substitution, NEED to deallocate yourself
	const char * TXT_GET_CS (LANG lang, ID id, char * str){
		char *buf = new char [MAX_CHAR_LEN];
		sprintf(buf, cstr[lang][id], str);
		delete [] cstr, str;
		return buf;
	}

}
