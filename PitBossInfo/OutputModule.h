#pragma once
#include "Game.h"

class OutputModule
{
public:
	OutputModule() {};
	//virtual OutputModule(Game *game) {};
	virtual ~OutputModule(void) {};
	virtual void connect(Game *game) {};
	virtual void setup(std::string args) {};
	virtual void write() {};

private:
	Game *game;
};

