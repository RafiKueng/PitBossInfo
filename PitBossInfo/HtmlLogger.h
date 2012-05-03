#pragma once
#include <iostream>
#include <fstream>
#include "outputmodule.h"

using namespace std;

class HtmlLogger :
	public OutputModule
{
public:
	HtmlLogger();
	HtmlLogger(Game *_game);
	~HtmlLogger(void);

	void connect(Game *_game);
	void setup(string path);
	void write();

private:
	Game *game;
	string path;
};

