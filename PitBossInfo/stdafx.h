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


//settings
#define MAX_PLAYER 32
#define VERBOSE_LEVEL 1 //verbose level: -1 print nothing, 0: normal runtime, 1: standart debug, 2: debug every detail

// TODO: Hier auf zus�tzliche Header, die das Programm erfordert, verweisen.
#include "Helper.h"


//namespaces
using std::string;
using Helper::print;
using Helper::println;