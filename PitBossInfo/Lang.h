#pragma once

using namespace std;

namespace Lang
{
	enum ID {
		TXT_PITBOSS_TITLE,
		TXT_BLABLA
	};

	enum LANG {
		_std, _EN, _DE };




	const TCHAR * EN (ID id);
	const TCHAR * EN (ID id, TCHAR * str);

	const TCHAR * DE (ID id);
	const TCHAR * DE (ID id, TCHAR * str);




	const TCHAR * TXT_GET (LANG lang, ID id);
	const TCHAR * TXT_GET (LANG lang, ID id, TCHAR * str);
}

