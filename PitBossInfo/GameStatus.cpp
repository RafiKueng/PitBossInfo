#include "StdAfx.h"
#include "GameStatus.h"

#include <sstream>

int GameStatus::counter = 0;


GameStatus::GameStatus(void)
{
}


GameStatus::GameStatus(string _name, int _year, time_t _nextRound, int _nPlayer)
{
	name = _name;
	year = _year;
	nextRound = _nextRound;
	nPlayer = _nPlayer;

	//player = new Player[nPlayer];
	player.resize(nPlayer);

	counter++;
	cout << "cre gamestatus obj. nr: " << counter <<"\n";
}

GameStatus::~GameStatus(void)
{
	cout << "delete gamestatus obj. "<<counter<<"\n";
	--counter;
	//delete[] player;
}



void GameStatus::setPlayer(int id, Player &p){
	player[id] = p;
}

void GameStatus::setPlayer(int id, string name, bool finishedTurn, Status status, int score){
	/*
	Player *p = new Player(name, finishedTurn, status, score);
	player[id] = *p;
	*/
	/*
	player[id].name = name;
	player[id].finishedTurn = finishedTurn;
	player[id].status = status;
	player[id].score = score;
	*/
	player[id] = Player(name, finishedTurn, status, score);
}


string GameStatus::toString(){
	
	stringstream buf = stringstream();
	//struct tm * timeinfo;

	buf << " G A M E S T A T U S:\n";
	buf << "--------------------------------------------------\n\n";
	buf << "  name:       "+name << "\n";
	//buf << "  year: "+year << "\n";
	char bufff[MAX_CHAR_LEN];
	sprintf(bufff,"%d",year);
	buf << "  year:       " + string(bufff) << "\n";
	//buf << "  nextRound: " + nextRound << "\n";
	buf << "  nextRound:  "; buf << asctime(localtime(&nextRound)) << "\n"; 

	for (int i =0; i<nPlayer;++i){
		char bufid[3];
		sprintf(bufid,"%2.2d",i);
		buf << "  P"<<bufid<<": "<<player[i].toString()<<"\n"; 
	}
	
	//delete timeinfo;
	return buf.str();
}