#include "StdAfx.h"
#include "Game.h"
#include "Watcher.h"


Game::Game(void) {
	_initSuccessful = false;
	Watcher::init();
	_initSuccessful = true;
}


Game::~Game(void) {
	//delete _gameStatus;
}



void Game::update() {
	GameStatus newStatus = Watcher::getStatus();

	Event * e;
	time_t currentTime;
  	time ( &currentTime );
	
	
	// new round has begun
	if (newStatus.year != _gameStatus.year) {
		
		

	}

	for (int i = 0; i < newStatus.nPlayer; ++i) {
		//for each player
		Player * pn = &(newStatus.player[i]); //new status player
		Player * po = &(_gameStatus.player[i]); //old status player

		//name change
		if (pn->name.compare(po->name) != 0) {
			e = new Event(NAME_CHANGE, i, currentTime);
			newEvents.push_back(e);
			thisYearsEvents.push_back(e);	
		}
		
		
		//status changed
		if (pn->status != po->status) {

			//TODO: ausfuellen
		}


		//player finished turn
		if (!po->finishedTurn && pn->finishedTurn) {
			e = new Event(FINISH_TURN, i, currentTime, newStatus.nPlayerFinished);
			newEvents.push_back(e);
			thisYearsEvents.push_back(e);	
		}


		//score changed
		if (pn->score < po->score) {
			e = new Event(SCORE_DECR, i, currentTime, po->score-pn->score);
			newEvents.push_back(e);
			thisYearsEvents.push_back(e);
		}
		else if (pn->score > po->score) {
			e = new Event(EventType::SCORE_INCR, i, currentTime, pn->score-po->score);
			newEvents.push_back(e);
			thisYearsEvents.push_back(e);
		}
	}



	_gameStatus = newStatus;
}


GameStatus* Game::getStatus() {
	return &(this->_gameStatus);
}


void Game::getEvents() {

}

bool Game::initSuccessful(){
	//check if everythin is alright
	//if (this is not good){return false;}
	//...

	return _initSuccessful;
}