#pragma once
#include <string>

class player
{
public:
	std::string name;
	int score;
	char move;
	bool r_win;
	bool p_win;
	bool s_win;
	bool trip_bonus;
	int r_consecutive;
	int p_consecutive;
	int s_consecutive;
	player(void);
	void lose(void);
	void win(char move);
};
