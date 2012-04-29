#include "StdAfx.h"
#include "Game.h"
#include "Watcher.h"


Game::Game(void) {
	_initSuccessful = false;
	_gameStatus = 0;
	Watcher::init();
	_gameStatus = Watcher::getStatus();
	_initSuccessful = true;
}


Game::~Game(void) {
}



void Game::update() {
	delete _gameStatus;
	_gameStatus = Watcher::getStatus();
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