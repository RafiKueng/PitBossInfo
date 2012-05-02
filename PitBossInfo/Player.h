#pragma once

class Player
{
public:
	string name;
	bool finishedTurn;
	Status status;
	int score;

	Player(void);
	Player(string &name, bool &finishedTurn, Status &status, int &score);

	~Player(void);

	string toString();

private:

};

