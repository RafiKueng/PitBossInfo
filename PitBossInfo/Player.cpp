/*****

represents one of the players in the game
is also a sinlgy linked list (pointing to the next player)




TODO:
- use initialisers

******/

#include "StdAfx.h"
#include "Player.h"


Player::Player(void) {
	nr = -1;
	name = "";
	finishedTurn = false;
	ping = -1;
	score = -1;
	next = NULL;
}

Player::Player(int _nr, std::string _name, bool _finishedTurn, int _ping, int _score, Player *_next) {
	nr = _nr;
	name = _name;
	finishedTurn = _finishedTurn;
	ping = _ping;
	score = _score;
	next = _next;
}

Player::Player(int _nr, std::string _name, bool _finishedTurn, int _ping, int _score) {
	nr = _nr;
	name = _name;
	finishedTurn = _finishedTurn;
	ping = _ping;
	score = _score;
	next = NULL;
}

Player::~Player(void)
{
}
