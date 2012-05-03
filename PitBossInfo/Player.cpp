/*****

represents one of the players in the game
is also a sinlgy linked list (pointing to the next player)




TODO:
- use initialisers

******/

#include "StdAfx.h"
#include "Player.h"

#include <sstream>

Player::Player(void) {
}

Player::Player(string &_name, bool &_finishedTurn, Status &_status, int &_score) {
	name = _name;
	finishedTurn = _finishedTurn;
	status = _status;
	score = _score;
}

Player::~Player(void)
{
}

string Player::toString(){
	
	stringstream buf = stringstream();
	//struct tm * timeinfo;

	if (finishedTurn)	{buf<<"[X] ";}
	else				{buf<<"[ ] ";}

	char * tmpname = new char[16];//{". . . . . . . ."};
	sprintf(tmpname, "%-15.15s", name.c_str());
	buf << 	tmpname << " (";
	delete [] tmpname;

	switch (status) {
		case ONLINE:	buf<<"online      , "; break;
		case DISC:		buf<<"disconnected, "; break;
		case AI:		buf<<"ai          , "; break;
		case DEFEAT:	buf<<"defeated    , "; break;
		case UNCLAIMED:	buf<<"unclaimed   , "; break;
	}
	
	char *tmpscore = new char[6]; //one additional \0 at the end...
	sprintf(tmpscore, "%5i", score);
	buf << tmpscore << ")";
	delete[] tmpscore;


	return buf.str();
}