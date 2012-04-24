#include "StdAfx.h"
#include "Game.h"


Game::Game(void) {
}


Game::~Game(void) {
}



void Game::update() {

}


GameStatus* Game::getStatus() {
	return &this->gameStatus;
}


void Game::getEvents() {

}

bool Game::initSuccessful(){
	//check if everythin is alright
	//if (this is not good){return false;}
	//...

	return true;
}