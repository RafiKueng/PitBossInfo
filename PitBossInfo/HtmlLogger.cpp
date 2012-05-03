#include "StdAfx.h"
#include "Logger.h"
#include "time.h"

/*****
write the status as a HTML file
******/

HtmlLogger::HtmlLogger(Game *_game) {
	this->game = _game;
}


HtmlLogger::~HtmlLogger(void)
{
	delete this->path;
}



void HtmlLogger::setup(string * _path) {
	this->path = path;
	//this->path = new string("D:\\civstat.html") ;
}


void HtmlLogger::write() {

	GameStatus *stat = game->getStatus();

	cout << *path;
	fstream file(*path, ios_base::out | ios_base::trunc); //output and overwrite the file
	
	stringstream buf = stringstream();
	time_t rawCurrenttime;
	struct tm * timeinfo;
	time ( &rawCurrenttime );
	
	
	buf << "<html><body>";
	
	buf << "<h1>Gamestatus</h1>\n";
	
	// some generic infos about the game
	buf << "<ul id='gamestatus'>"; 
	buf << "<li>name: "+name << "</li>\n";
	
	
	char bufff[MAX_CHAR_LEN];
	sprintf(bufff,"%d",year);
	buf << "<li>year: " + string(bufff) << "</li>\n";
	
	buf << "<li>nextRound: "; buf << asctime(localtime(&nextRound)) << "</li>\n"; 
	
	  	
	
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
	
	for (int i =0; i<nPlayer;++i){
		buf << "<td>P"<<i<<"</td>";
		
		
		buf << "<td>";
		if (player[i].finishedTurn)	{buf<<"*, ";}
		else						{buf<<"_, ";}
		buf << "</td>";
		
		
		buf << "<td>"<<player[i].name<<"</td>\n";
		
		
		buf << "<td>";
		switch (player[i].status) {
			case ONLINE:	buf<<"onln, "; break;
			case DISC:		buf<<"disc, "; break;
			case AI:		buf<<"ai  , "; break;
			case DEFEAT:	buf<<"dead, "; break;
			case UNCLAIMED:	buf<<"uncl, "; break;
		}
		buf << "</td>";
		
		buf << "<td>"<<player[i].score<<"</td>\n";
		
	}

	buf << "\n</tbody>\n</table>\n";
	buf << "</body></html>";
	
	file << buf.str();
	file.close();

}