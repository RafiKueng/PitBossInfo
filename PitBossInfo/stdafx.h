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


//settings
#define MAX_PLAYER 32
#define VERBOSE_LEVEL 1 /*verbose level: -1 print nothing, 0: normal runtime, 1: standart debug, 2: debug every detail*/

#define GAME_NAME "Luemmelparty 6"
#define LANGUAGE _EN
#define MAX_CHAR_LEN 80 /*maximum length of some chars*/


// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include "Helper.h"
#include "Lang.h"


//namespaces
using std::string;
using namespace Helper;
using namespace Lang;


enum Status {ONLINE, DISC, AI, DEFEAT, UNCLAIMED};
