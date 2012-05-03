#include "StdAfx.h"
#include "HtmlLogger.h"

#include <sstream>

/*****
write the status as a HTML file
******/

HtmlLogger::HtmlLogger() {
}


HtmlLogger::HtmlLogger(Game *_game) {
	this->game = _game;
}


HtmlLogger::~HtmlLogger(void)
{
}


void HtmlLogger::connect(Game *_game) {
	this->game = _game;
}


void HtmlLogger::setup(string _path) {

	wchar_t buf[255];
	mbstowcs(buf, _path.c_str(),255);

	println(0,L"Logger  : setup: setting output path to: %s", buf);
	this->path = _path;
}


void HtmlLogger::write() {

	GameStatus *stat = game->getStatus();

	//cout << *path;
	fstream file(path, ios_base::out | ios_base::trunc); //output and overwrite the file
	
	stringstream buf = stringstream();
	time_t rawCurrenttime;
	//struct tm * timeinfo;
	time ( &rawCurrenttime );
	
	
	buf << "<html><body>";
	
	buf << "<h1>Gamestatus</h1>\n";
	
	// some generic infos about the game
	buf << "<ul id='gamestatus'>"; 
	buf << "<li>name: "+stat->name << "</li>\n";
	
	
	char buf_year[MAX_CHAR_LEN];
	sprintf(buf_year,"%d",stat->year);
	buf << "<li>year: " + string(buf_year) << "</li>\n";
	
	buf << "<li>nextRound: "; buf << asctime(localtime(&(stat->nextRound))) << "</li>\n"; 
	
	// when was this output file generated?
	buf << "<li>updated: "; buf << asctime(localtime(&rawCurrenttime)) << "</li>\n";
	
	buf << "</ul><br/><br/>";
	
	
	// player stats in a table
	buf << "\n<table border='0' id='playerinfo'><thead>";
	buf << "<th>Nr</th>";
	buf << "<th>Turn</th>";
	buf << "<th>Player</th>";
	buf << "<th>Status</th>";
	buf << "<th>Score</th>";
	buf << "</thead>\n<tbody>\n";
	
	for (int i =0; i<stat->nPlayer;++i){
		buf << "<td>P"<<i<<"</td>";
		

		buf << "<td>";
		if (stat->player[i].finishedTurn)	{buf<<"*";}
		else {buf<<"_";}
		buf << "</td>";
		

		buf << "<td>"<<stat->player[i].name<<"</td>\n";
		
		
		buf << "<td>";
		switch (stat->player[i].status) {
			case ONLINE:	buf<<"online"; break;
			case DISC:		buf<<"discconnected"; break;
			case AI:		buf<<"ai"; break;
			case DEFEAT:	buf<<"defeated, "; break;
			case UNCLAIMED:	buf<<"unclaimed"; break;
		}
		buf << "</td>";
		

		buf << "<td>"<<stat->player[i].score<<"</td>\n";
	}

	buf << "\n</tbody>\n</table>\n";
	buf << "</body></html>";
	
	file << buf.str();
	file.close();
}