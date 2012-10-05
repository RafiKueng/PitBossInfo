#pragma once
class Event
{
public:
	Event(void);
	Event(EventType eventType, time_t time, void * data);
	~Event(void);

	string toString();

	EventType type;
	time_t timestamp;
	void * args;
};

