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

#define LANGUAGE _EN


// -- NOT USED ANYMORE ----
//#define OUTPATH "I:\\www\\htdocs\\civ4_pb_status\\"
//settings for particular game
//#include "game_lp6.h"
//#include "game_lp7.h"
//#include "game_pclp1.h"
//#include "game_pclp2.h"




//system settings (no need to change unless you know exactly what you do...
#define MAX_CHAR_LEN 255 /*maximum length of some chars*/
//#define SLEEPTIME 15000 /*timeout between checks in ms - OUTDATED - set in command line now*/



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
enum EventType {LOGIN, LOGOUT, SCORE_INCR, SCORE_DECR, FINISH_TURN, NEW_TURN, NAME_CHANGE, RETIRE, CLAIM_AI, ELIMINATED};
