#pragma once
#include "GameStatus.h"
#include "Event.h"

class Game
{
public:
	Game(_TCHAR*);
	~Game(void);

	void update();
	GameStatus * getStatus();
	void getEvents();
	bool initSuccessful();

	bool isNewRound();

private:
	GameStatus _gameStatus;
	bool _initSuccessful;
	vector<Event*> newEvents; //new events since last update
	vector<Event*> thisYearsEvents;
	vector<Event*> lastYearsEvents; //complete collection, gets saves for one update cycle then the event elements get deleted..
};

