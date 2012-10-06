#include "StdAfx.h"
#include "Event.h"

#include <sstream>

Event::Event(void)
{
}

Event::Event(EventType et, time_t time, void* args)
{
	this->type = et;
	this->timestamp = time;
	this->args = args;
}

Event::~Event(void)
{
	//clean up the data: either
	delete this->args;
	//or the complicated way:
	switch (this->type){
	case NEW_TURN              : {__years  * ptr = (__years*)args;  delete ptr; break;}
	case PLAYER_STATUS_CHANGE  : {__status * ptr = (__status*)args; delete ptr; break;}
	case PLAYER_SCORE_CHANGE   : {__scores * ptr = (__scores*)args; delete ptr; break;}
	case PLAYER_NAME_CHANGE    : {__names  * ptr = (__names*)args;  delete ptr; break;}
	};
}


string Event::toString()
{
	stringstream buf = stringstream();

	buf << "Event: ";

	switch (this->type) {
	case NEW_TURN: // a new year begun. __years
		buf << "NEW TURN [from " << ((__years*)this->args)->from 
			<< " to " << ((__years*)this->args)->to
			<<"]";
		break;

	case PLAYER_STATUS_CHANGE: {// a player changed his status, __status
		
		//todo: assign correct string here
		string str = string("blabla");

		buf << "STATUSCHANGE [pid: " << ((__status*)this->args)->player
			<< " nStat: " << ((__status*)this->args)->status
			<< " (" << str << ")"
			<< "]";
		break;}

	case PLAYER_SCORE_CHANGE: // a player changed his score, __scores
		buf << "SCORECHANGE  [pid: "<< ((__scores*)this->args)->player
			<< ", from: " << ((__scores*)this->args)->from
			<< " to " << ((__scores*)this->args)->to
			<< "]";
		break;

	case PLAYER_NAME_CHANGE: // a player changed his name, __names
		buf << "NAMECHANGE   [pid: "<< ((__names*)this->args)->player
			<< ", from: " << ((__names*)this->args)->from
			<< " to: " << ((__names*)this->args)->to
			<< "]";
		break;
	}

	buf << " {@" << string(asctime(localtime(&this->timestamp))).substr(0,23) << "}";

	return buf.str();
}