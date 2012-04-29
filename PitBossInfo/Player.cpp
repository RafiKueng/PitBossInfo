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

Player::Player(string _name, bool _finishedTurn, Status _status, int _score) {
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
	struct tm * timeinfo;

	buf << name<<" (";
	switch (status) {
		case ONLINE:	buf<<"onln, "; break;
		case DISC:		buf<<"disc, "; break;
		case AI:		buf<<"ai  , "; break;
		case DEFEAT:	buf<<"dead, "; break;
		case UNCLAIMED:	buf<<"uncl, "; break;
	}
	if (finishedTurn)	{buf<<"*, ";}
	else				{buf<<"_, ";}

	buf << score<<")";

	return buf.str();
}