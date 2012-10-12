#pragma once
#include <iostream>
#include <fstream>
#include "outputmodule.h"

using namespace std;

class HtmlGETSender :
	public OutputModule
{
public:
	HtmlGETSender();
	HtmlGETSender(Game *_game);
	~HtmlGETSender(void);

	void connect(Game *_game);
	void setup(string path);
	void write();

private:
	Game *game;
	string url;
};

