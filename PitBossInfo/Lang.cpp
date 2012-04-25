#include "StdAfx.h"
#include "Lang.h"

namespace Lang {

	TCHAR* en[] = {
		_T("'%s' successfully saved\""),
		_T("blabla_en")
	};


	TCHAR* de[] = {
		_T("'%s' erfolgreich gespeichert\""),
		_T("blabla_de")
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

		TCHAR * buffer = new TCHAR [256]; //this is a memoryleak...
		wsprintf(buffer, TXT_GET(lang, id), str);
		return buffer;
	}

}
