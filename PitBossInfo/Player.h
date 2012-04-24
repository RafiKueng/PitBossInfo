#pragma once
class Player
{
public:
	int nr;
	std::string name;
	bool finishedTurn;
	int ping;
	int score;

	Player *next; //make it a singly linked list


	Player(void);
	Player(int _nr, std::string _name, bool _finishedTurn, int _ping, int _score);
	Player(int nr, std::string name, bool finishedTurn, int ping, int score, Player *next);

	~Player(void);

private:

};

