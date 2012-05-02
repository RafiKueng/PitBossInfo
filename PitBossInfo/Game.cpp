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
	_gameStatus = Watcher::getStatus();
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