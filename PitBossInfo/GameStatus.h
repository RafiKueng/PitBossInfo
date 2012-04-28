#pragma once

#include "Player.h"

class GameStatus
{
public:

	string name;
	int year;
	time_t nextRound;
	int nPlayer;
	Player * player;


	GameStatus(void);
	GameStatus(string name, int year, time_t nextRound, int nPlayer);

	~GameStatus(void);

	void setPlayer(int id, Player &p);
	void setPlayer(int id, string name, bool finishedTurn, Status status, int score);

	string toString();


};

