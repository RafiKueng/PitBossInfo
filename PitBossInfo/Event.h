#pragma once
class Event
{
public:
	Event(void);
	Event(EventType, int, time_t, int arg = -1);
	~Event(void);

	string toString();

	EventType type;
	int playerid;
	time_t timestamp;
	int arg;
};

