#include "StdAfx.h"
#include "GameStatus.h"
#include "time.h"

#include <sstream>


GameStatus::GameStatus(void)
{
}

GameStatus::GameStatus(string _name, int _year, time_t _nextRound, int _nPlayer)
{
	name = _name;
	year = _year;
	nextRound = _nextRound;
	nPlayer = _nPlayer;

	player.resize(nPlayer);

}

GameStatus::~GameStatus(void)
{
}



void GameStatus::setPlayer(int id, Player &p){
	player[id] = p;
}

void GameStatus::setPlayer(int id, string name, bool finishedTurn, Status status, int score){

	player[id] = Player(name, finishedTurn, status, score);
}


string GameStatus::toString(){
	
	stringstream buf = stringstream();
	
	time_t rawCurrenttime;
  	time ( &rawCurrenttime );

	buf << "\n G A M E S T A T U S:\n";
	buf << "--------------------------------------------------\n\n";
	buf << "  name:       "+name << "\n";

	char bufff[MAX_CHAR_LEN];
	sprintf(bufff,"%d",year);
	buf << "  year:       " + string(bufff) << "\n";

	buf << "  nextRound:  "; buf << asctime(localtime(&nextRound)) << "\n"; 
	buf << "  updated:    "; buf << asctime(localtime(&rawCurrenttime)) << "\n";

	for (int i =0; i<nPlayer;++i){
		char bufid[3];
		sprintf(bufid,"%2.2d",i);
		buf << "  P"<<bufid<<": "<<player[i].toString()<<"\n"; 
	}
	
	return buf.str();
}