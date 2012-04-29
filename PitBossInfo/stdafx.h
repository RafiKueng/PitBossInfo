// stdafx.h : Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <assert.h>
#include <time.h>


//settings
#define MAX_PLAYER 32
#define VERBOSE_LEVEL 2 /*verbose level: -1 print nothing, 0: normal runtime, 1: standart debug, 2: debug every detail*/

#define GAME_NAME "long name - special chars"
#define LANGUAGE _EN


//system settings (no need to change unless you know exactly what you do...
#define MAX_CHAR_LEN 255 /*maximum length of some chars*/
#define SLEEPTIME 2000

// TODO: Hier auf zus�tzliche Header, die das Programm erfordert, verweisen.
#include "Helper.h"
#include "Lang.h"


//namespaces
using std::string;
using namespace Helper;
using namespace Lang;


//enums
enum Status {ONLINE, DISC, AI, DEFEAT, UNCLAIMED};
