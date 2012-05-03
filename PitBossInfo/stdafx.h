// stdafx.h : Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
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
#include <vector>

//memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//remap new for the memleak detect to work
#ifdef _DEBUG
   #ifndef DBG_NEW
      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
      #define new DBG_NEW
   #endif
#endif  // _DEBUG



//settings
#define MAX_PLAYER 32
#define VERBOSE_LEVEL 0 /*verbose level: -1 print nothing, 0: normal runtime, 1: standart debug, 2: debug every detail*/

#define GAME_NAME "Luemmelparty 6"
#define LANGUAGE _DE


//system settings (no need to change unless you know exactly what you do...
#define MAX_CHAR_LEN 255 /*maximum length of some chars*/
#define SLEEPTIME 15000 /*timeout between checks in ms*/



// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include "Helper.h"
#include "Lang.h"


//namespaces
using std::string;
using std::vector;
using namespace Helper;
using namespace Lang;


//enums
enum Status {ONLINE, DISC, AI, DEFEAT, UNCLAIMED};
