#include "stdafx.h"
#include "player.h"
#include <iostream>

player::player(void)
{
	score = 0;
	r_win = false;
	p_win = false;
	s_win = false;
	trip_bonus = false;
	r_consecutive = 0;
	p_consecutive = 0;
	s_consecutive = 0;
}

void player::lose(void)
{
	r_consecutive = 0;
	p_consecutive = 0;
	s_consecutive = 0;
}

void player::win(char move)
{
	score++;
	switch (move) {
	case 'r':
		r_consecutive++;
		p_consecutive = 0;
		s_consecutive = 0;
		r_win = true;
		if (r_consecutive > 1) {
			std::cout << "Consecutive bonus for (+" << r_consecutive << ")!" << std::endl;
			score += r_consecutive - 1;
		}
		if (p_win == true && s_win == true && trip_bonus == false)
		{
			std::cout << "Triple bonus (+3)!" << std::endl;
			score += 2;
			trip_bonus = true;
		}
		break;
	case 'p':
		p_consecutive++;
		r_consecutive = 0;
		s_consecutive = 0;
		p_win = true;
		if (p_consecutive > 1) {
			std::cout << "Consecutive bonus for (+" << p_consecutive << ")!" << std::endl;
			score += p_consecutive - 1;
		}
		if (r_win == true && s_win == true && trip_bonus == false)
		{
			std::cout << "Triple bonus (+3)!" << std::endl;
			score += 2;
			trip_bonus = true;
		}
		break;
	case 's':
		s_consecutive++;
		p_consecutive = 0;
		r_consecutive = 0;
		s_win = true;
		if (s_consecutive > 1) {
			std::cout << "Consecutive bonus for (+" << s_consecutive << ")!" << std::endl;
			score += s_consecutive - 1;
		}
		if (r_win == true && p_win == true && trip_bonus == false)
		{
			std::cout << "Triple bonus (+3)!" << std::endl;
			score += 2;
			trip_bonus = true;
		}
		break;
	}
}
