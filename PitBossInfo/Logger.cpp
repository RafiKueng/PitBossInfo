#include "StdAfx.h"
#include "Logger.h"


Logger::Logger() {
}

Logger::Logger(Game * _game) {
	this->game = _game;
}

Logger::~Logger(void)
{
}

void Logger::connect(Game *_game) {
	this->game = _game;
}

void Logger::setup(string _path) {
	
	wchar_t buf[255];
	mbstowcs(buf, _path.c_str(),255);

	println(0,L"Logger  : setup: setting output path to: %s", buf);
	this->path = _path;
}


void Logger::write() {

	GameStatus *stat = game->getStatus();

	//cout << this->path << "\n";

	fstream file(this->path, ios_base::out | ios_base::trunc); //output and overwrite the file
	file << stat->toString();
	file.close();
}