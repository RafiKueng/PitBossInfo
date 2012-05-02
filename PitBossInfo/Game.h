#pragma once
#include "GameStatus.h"

class Game
{
public:
	Game(void);
	~Game(void);

	void update();
	GameStatus * getStatus();
	void getEvents();
	bool initSuccessful();

private:
	GameStatus _gameStatus;
	bool _initSuccessful;

};

