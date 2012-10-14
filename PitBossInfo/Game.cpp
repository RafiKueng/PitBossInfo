#include "StdAfx.h"
#include "Game.h"
#include "Watcher.h"


Game::Game(_TCHAR* gamename) {
	this->_initSuccessful = false;
	cout << "in game.cpp, got ganemname" << *gamename;
	Watcher::init(gamename);

	//_thisYearsEvents = vector<Event*>();
	//_lastYearsEvents = vector<Event*>();

	this->_initSuccessful = true;
	this->_firstRun = true;

}


Game::~Game(void) {
	//delete _gameStatus;
}



void Game::update() {
	//make the first run work to :)
	if (_firstRun) {
		this->_gameStatus = Watcher::getStatus();
		this->_firstRun = false;
	}

	GameStatus * newStatus = Watcher::getStatus();

	Event * e;
	time_t currentTime;
  	time ( &currentTime );
	
	//reset newEvents
	_newEvents = vector<Event*>();
	
	// new round has begun
	if (newStatus->year != _gameStatus->year) {
		/*
		//clean up and delete old events
		vector<Event*>::iterator it;
		for ( it = _lastYearsEvents.begin(); it != _lastYearsEvents.end(); ) {
			//delete * it; //TODO: BUG HERE
			it = _lastYearsEvents.erase(it);
		}
		for (it = _thisYearsEvents.begin();it != _thisYearsEvents.end(); it++) {
			_lastYearsEvents.push_back(*it);
		}
		_thisYearsEvents.clear();
		*/
		//create new turn event
		__years * yr = new __years(); //will be deleted on event destruction
		yr->from = _gameStatus->year;
		yr->to = newStatus->year;
		e = new Event(NEW_TURN, currentTime, yr);
		_newEvents.push_back(e);
		//_thisYearsEvents.push_back(e);
	}


	//check each player for changes in his status
	for (int i = 0; i < newStatus->nPlayer; ++i) {
		
		Player * pn = &(newStatus->player[i]); //new status player
		Player * po = &(_gameStatus->player[i]); //old status player

		//name change
		if (pn->name.compare(po->name) != 0) {
			__names * na = new __names();
			na->player = i;
			na->from = string(po->name);
			na->to = string(pn->name);

			e = new Event(PLAYER_NAME_CHANGE, currentTime, na);

			_newEvents.push_back(e);
			//_thisYearsEvents.push_back(e);	
		}
		
		
		//status changed
		if (pn->status != po->status) {
			__status * st = new __status();
			st->player = i;
			st->status = PlayerStatusChange(po->status + 5*pn->status); //check the table in /docs/status.ods

			e = new Event(PLAYER_STATUS_CHANGE, currentTime, st);
			_newEvents.push_back(e);
			//_thisYearsEvents.push_back(e);	
		}


		//player finished turn
		if (!po->finishedTurn && pn->finishedTurn) {
			__status * st = new __status();
			st->player = i;
			st->status = PlayerStatusChange::FINISHED_TURN;

			e = new Event(PLAYER_STATUS_CHANGE, currentTime, st);

			_newEvents.push_back(e);
			//_thisYearsEvents.push_back(e);	
		}


		//score changed
		if (pn->score != po->score) {
			__scores * sc = new __scores();
			sc->player = i;
			sc->from = po->score;
			sc->to = pn->score;

			e = new Event(PLAYER_SCORE_CHANGE, currentTime, sc);
			_newEvents.push_back(e);
			//_thisYearsEvents.push_back(e);
		}
	}

	println(2,L"got the following events:");
	for(vector<Event*>::iterator it = _newEvents.begin(); it != _newEvents.end(); ++it) {
		cout<<"  "<<(*it)->toString() <<endl;
	}

	delete _gameStatus;
	_gameStatus = newStatus;
}


GameStatus* Game::getStatus() {
	return this->_gameStatus;
}


void Game::getEvents() {

}

bool Game::initSuccessful(){
	//check if everythin is alright
	//if (this is not good){return false;}
	//...

	return _initSuccessful;
}