#include "StdAfx.h"
#include "Event.h"

#include <sstream>

Event::Event(void)
{
}

Event::Event(EventType et, int player, time_t time, int arg=-1)
{
	this->type = et;
	this->playerid = player;
	this->timestamp = time;
	this->arg = arg;
}

Event::~Event(void)
{
}


string Event::toString()
{
	stringstream buf = stringstream();
	
	buf << "Event: ";

	switch (this->type){
		case LOGIN:			buf << "Login"; break;
		case LOGOUT:		buf << "Logout"; break;
		case SCORE_INCR:	buf << "Score incr"; break;
		case SCORE_DECR:	buf << "Score decr"; break;
		case FINISH_TURN:	buf << "Finished Turn"; break;
		case NEW_TURN:		buf << "New Turn"; break;
		case NAME_CHANGE:	buf << "Name change"; break;
		case RETIRE:		buf << "Retire"; break;
		case CLAIM_AI:		buf << "Claim AI"; break;
		case ELIMINATED:	buf << "Eliminated"; break;
	}
	if (this->playerid!=-1){buf << ", playerid: "<<this->playerid;}

	buf << " (" << asctime(localtime(&this->timestamp)) << ")";

	return buf.str();
}