#pragma once

using namespace std;

namespace Lang
{
	enum ID {
		TXT_PITBOSS_TITLE,
		
		TXT_YEAR_BC,
		TXT_YEAR_AD,
		
		TXT_UNCLAIMED,
		TXT_AI,
		TXT_LOGIN,
		TXT_DISC,
		TXT_DEFEAT
	};

	enum LANG {
		_std, _EN, _DE };




	const TCHAR * EN (ID id);
	const TCHAR * EN (ID id, TCHAR * str);

	const TCHAR * DE (ID id);
	const TCHAR * DE (ID id, TCHAR * str);




	const TCHAR * TXT_GET (LANG lang, ID id);
	const TCHAR * TXT_GET (LANG lang, ID id, TCHAR * str);
	const char * TXT_GET_C (LANG lang, ID id);
	const char * TXT_GET_C (LANG lang, ID id, char * str);

}

