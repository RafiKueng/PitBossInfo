#pragma once
#include "Game.h"

class OutputModule
{
public:
	OutputModule() {};
	OutputModule(Game *game) {};
	virtual ~OutputModule(void) {};
	virtual void setup(std::string args) {};
	virtual void write() {};

private:
	Game game;
};

