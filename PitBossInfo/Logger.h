#pragma once
#include <iostream>
#include <fstream>
#include "outputmodule.h"

using namespace std;

class Logger :
	public OutputModule
{
public:
	Logger();
	Logger(Game *_game);
	~Logger(void);

	void connect(Game *_game);
	void setup(string path);
	void write();

private:
	Game *game;
	string path;
	//ofstream file;
};

