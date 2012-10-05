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
#define VERBOSE_LEVEL 2 /*verbose level: -1 print nothing, 0: normal runtime, 1: standart debug, 2: debug every detail*/

#define LANGUAGE _EN


//system settings (no need to change unless you know exactly what you do...
#define MAX_CHAR_LEN 255 /*maximum length of some chars*/


// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.
#include "Helper.h"
#include "Lang.h"

//namespaces
using std::string;
using std::vector;
using namespace Helper;
using namespace Lang;


//enums
enum Status {ONLINE, DISC, UNCLAIMED, DEFEAT, AI};
enum EventType {	// the passed argument args is a struct of the type...
	NEW_TURN,				// a new year begun. __years
	PLAYER_STATUS_CHANGE,	// a player changed his status, __status
	PLAYER_SCORE_CHANGE,	// a player changed his score, __scores
	PLAYER_NAME_CHANGE		// a player changed his name, __names
};

enum PlayerStatusChange {
	_ON_ON,
	LOGIN,				// DISC->ONLINE
	CLAIMED_1ST,		// UNCLAIIMED->ONLINE a empty player has been claimed
	_DE_ON,
	CLAIM_AI,			// AI->ONLINE a player claimed an ai

	LOGOUT,				// ONLINE->DISC
	_DI_DI,
	_UN_DI,
	_DE_DI,
	_AI_DI,

	_ON_UN,
	_DI_UN,
	_UN_UN,
	_DE_UN,
	_AI_UN,

	KILLED_ON,			// ONLINE->DEFEAT player has been killed while online
	ELIMINATED,			// DISC->DEFEAT player has been killed while offline
	_UN_DE,
	_DE_DE,
	ELIMINATED_AI,		// AI->DEFEAT an ai player has been killed

	RETIRED,			// ONLINE->AI a player pressed retire / has been kicked from admin
	KICKED,				// DISC->AI  a player has been kicked by a admin
	_UN_AI,
	_DE_AI,
	_AI_AI,

	FINISHED_TURN		// a player finished his turn
};

// structs used to give details to an event
struct __years { int from; int to;};
struct __scores{ int player; int from; int to;};
struct __status{ int player; PlayerStatusChange status;};
struct __names { int player; string from; string to;};