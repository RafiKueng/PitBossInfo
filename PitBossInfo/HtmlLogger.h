#pragma once
#include <iostream>
#include <fstream>
#include "outputmodule.h"

using namespace std;

class HtmlLogger :
	public OutputModule
{
public:
	HtmlLogger(Game *_game);
	~HtmlLogger(void);

	void setup(string *path);
	void write();

private:
	Game *game;
	string *path;
	//ofstream file;
};

