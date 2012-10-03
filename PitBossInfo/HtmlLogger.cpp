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

	println(0,L"HtmlLogger  : setup: setting output path to: %s", buf);
	this->path = _path;
}


void HtmlLogger::write() {

	GameStatus *stat = game->getStatus();

	//cout << *path;
	fstream file(path, ios_base::out | ios_base::trunc); //output and overwrite the file
	
	stringstream buf = stringstream();
	time_t rawCurrenttime;
	time ( &rawCurrenttime );
	
	buf << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n";
	buf << "<html><head>\n";
	buf << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n";
	buf << "<meta http-equiv=\"refresh\" content=\"120\"> \n";
	buf << "<link type=\"text/css\" rel=\"stylesheet\" href=\"stats.css\">\n";
	buf << "<title>Gamestatus "<< stat->name <<"</title>\n";
	buf << "<script src=\"sorttable.js\"></script>\n";
	buf << "</head>\n\n<body>\n";
	
	buf << "<h1>Gamestatus</h1>\n";
	
	// some generic infos about the game
	buf << "<ul id='gamestatus'>"; 
	buf << "<li>name: " << stat->name << "</li>\n";
	
	
	char buf_year[MAX_CHAR_LEN];
	sprintf(buf_year,"%d",stat->year);
	buf << "<li>year: " + string(buf_year) << "</li>\n";
	
	buf << "<li>nextRound: "; buf << asctime(localtime(&(stat->nextRound))) << "</li>\n"; 
	
	// when was this output file generated?
	buf << "<li>updated: "; buf << asctime(localtime(&rawCurrenttime)) << "</li>\n";
	
	buf << "</ul><br/><br/>";
	
	
	// player stats in a table
	buf << "\n<table border='0' id='playerinfo' class=\"sortable\">\n<thead>\n<tr>\n";
	buf << "<th>Nr</th>";
	buf << "<th>Turn</th>";
	buf << "<th>Player</th>";
	buf << "<th>Status</th>";
	buf << "<th>Score</th>";
	buf << "</tr>\n</thead>\n<tbody>\n";
	
	for (int i =0; i<stat->nPlayer;++i){
		buf << "<tr style='background-color: " << ( i%2==0 ? "#eee" : "#fff" ) << ";'>\n";
		
		
		buf << "<td class=\"col1\">P"<<i<<"</td>\n";
		
		
		buf << "<td class=\"col2\">";
		if (stat->player[i].finishedTurn)	{buf<<"*";}
		else {buf<<"_";}
		buf << "</td>\n";
		

		buf << "<td class=\"col3\">";
		buf << stat->player[i].name;
		buf << "</td>\n";
		
		
		buf << "<td class=\"col4\">";
		switch (stat->player[i].status) {
			case ONLINE:	buf<<"online"; break;
			case DISC:		buf<<"discconnected"; break;
			case AI:		buf<<"ai"; break;
			case DEFEAT:	buf<<"defeated"; break;
			case UNCLAIMED:	buf<<"unclaimed"; break;
		}
		buf << "</td>\n";
		

		buf << "<td class=\"col5\">";
		buf << stat->player[i].score;
		buf << "</td>\n</tr>\n";
	}

	buf << "\n</tbody>\n</table>\n";
	buf << "</body></html>";
	
	file << buf.str();
	file.close();
}