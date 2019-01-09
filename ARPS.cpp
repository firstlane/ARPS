// RPS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include <windows.h>
#include <iomanip>
#include <conio.h>  
#include <stdio.h>

using namespace std;

player player1 = player::player();
player player2 = player::player();
int comp_move;
char timed;
int rps_timer;

void init(player p1, player p2) {
	// Decide streak
	std::string streak_player = "-";
	int streak_num = 0;
	char streak_move = '-';
	if (p1.r_consecutive != 0) {
		streak_player = p1.name;
		streak_num = p1.r_consecutive;
		streak_move = 'r';
	}
	else if (p1.p_consecutive != 0) {
		streak_player = p1.name;
		streak_num = p1.p_consecutive;
		streak_move = 'p';
	}
	else if (p1.s_consecutive != 0) {
		streak_player = p1.name;
		streak_num = p1.s_consecutive;
		streak_move = 's';
	}
	else if (p2.r_consecutive != 0) {
		streak_player = p2.name;
		streak_num = p2.r_consecutive;
		streak_move = 'r';
	}
	else if (p2.p_consecutive != 0) {
		streak_player = p2.name;
		streak_num = p2.p_consecutive;
		streak_move = 'p';
	}
	else if (p2.s_consecutive != 0) {
		streak_player = p2.name;
		streak_num = p2.s_consecutive;
		streak_move = 's';
	}

	cout << "|=============================|" << endl;
	cout << "|         Advanced RPS        |" << endl;
	cout << "|=============================|" << endl;
	cout << "| Player  |Points | R | P | S |" << endl;
	cout << "|=============================|" << endl;
	cout << "| " << std::left << std::setw(8) << p1.name << "|   " << p1.score << "   | " << p1.r_win << " | " << p1.p_win << " | " << p1.s_win << " |" << endl;
	cout << "| " << std::left << std::setw(8) << p2.name << "|   " << p2.score << "   | " << p2.r_win << " | " << p2.p_win << " | " << p2.s_win << " |" << endl;
	cout << "|=============================|" << endl;
	cout << "|Current streak: " << std::left << std::setw(8) << streak_player << "(" << streak_move << " " << streak_num << ")|" << endl;
	cout << "|=============================|" << endl;

}

void printRock() {
	cout << "     -------------------" << endl;
	cout << "    /  =                \\" << endl;
	cout << "   /   ==      =         \\" << endl;
	cout << "  /   = =             =   \\" << endl;
	cout << " /                  ===    \\" << endl;
	cout << " \\    =                    /" << endl;
	cout << "  \\  ==     ====          /" << endl;
	cout << "   \\          =          /" << endl;
	cout << "    \\                   /" << endl;
	cout << "     -------------------" << endl;
}

void printPaper() {
	cout << " ----------" << endl;
	cout << "|         |" << endl;
	cout << " \\        \\" << endl;
	cout << "  \\        \\" << endl;
	cout << "  |        |" << endl;
	cout << " /         /" << endl;
	cout << " ----------" << endl;
}

void printScissors() {
	cout << "   ----" << endl;
	cout << " /      \\                 ----" << endl;
	cout << " \\      / ---          ---" << endl;
	cout << "   ----      ---    ---" << endl;
	cout << "                ----" << endl;
	cout << "   ----      ---    ---" << endl;
	cout << " /      \\ ---          ---" << endl;
	cout << " \\      /                 ----" << endl;
	cout << "   ----" << endl;
}

void compareMoves(player &p1, player &p2) {
	cout << player1.name << " played:" << endl;
	Sleep(1000);
	switch (p1.move) {
	case 'r':
		printRock();
		Sleep(1000);
		cout << player2.name << " played:" << endl;
		Sleep(1000);
		switch (p2.move) {
		case 'r':
			printRock();
			Sleep(1000);
			cout << endl << "It's a tie!" << endl;
			break;
		case 'p':
			printPaper();
			Sleep(1000);
			cout << endl << p2.name << " wins!" << endl;
			p1.lose();
			p2.win(p2.move);
			break;
		case 's':
			printScissors();
			Sleep(1000);
			cout << endl << p1.name << " wins!" << endl;
			p1.win(p1.move);
			p2.lose();
			break;
		}
		break;
	case 'p':
		printPaper();
		Sleep(1000);
		cout << player2.name << " played:" << endl;
		Sleep(1000);
		switch (p2.move) {
		case 'r':
			printRock();
			Sleep(1000);
			cout << endl << p1.name << " wins!" << endl;
			p1.win(p1.move);
			p2.lose();
			break;
		case 'p':
			printPaper();
			Sleep(1000);
			cout << endl << "It's a tie!" << endl;
			break;
		case 's':
			printScissors();
			Sleep(1000);
			cout << endl << p2.name << " wins!" << endl;
			p1.lose();
			p2.win(p2.move);
			break;
		}
		break;
	case 's':
		printScissors();
		Sleep(1000);
		cout << player2.name << " played:" << endl;
		Sleep(1000);
		switch (p2.move) {
		case 'r':
			printRock();
			Sleep(1000);
			cout << endl << p2.name << " wins!" << endl;
			p1.lose();
			p2.win(p2.move);
			break;
		case 'p':
			printPaper();
			Sleep(1000);
			cout << endl << p1.name << " wins!" << endl;
			p1.win(p1.move);
			p2.lose();
			break;
		case 's':
			printScissors();
			Sleep(1000);
			cout << endl << "It's a tie!" << endl;
			break;
		}
		break;
	}
}

int getMove(player &p1, player p2, int timer) {
	for (int i = timer; i > 0; i--) {
		cout << p1.name << ": Select a move (r/p/s) (" << i << "): ";
		if (!_kbhit()) {
			Sleep(1000);
			system("CLS");
			init(p1, p2);
		}
		else {
			p1.move = _getch();
			break;
		}
	}
	if (p1.move != 'r' && p1.move != 'p' && p1.move != 's') {
		cout << "Time's up! (+1) for " << p2.name << "!" << endl;
		Sleep(3000);
		return 1;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter name for player1: ";
	cin >> player1.name;
	cout << "Enter name for player2: ";
	cin >> player2.name;
	cout << "Timed or Untimed (t/u): ";
	cin >> timed;
	if (timed == 't') {
		cout << "Enter time (s): ";
		cin >> rps_timer;
	}

	system("CLS");
	while (player1.score < 10 && player2.score < 10) {
		if (timed == 't') {
			init(player1, player2);
			if (getMove(player1, player2, rps_timer) == 0) {
				system("CLS");
				init(player1, player2);
				if (getMove(player2, player1, rps_timer) == 0) {
					system("CLS");
					init(player1, player2);
					compareMoves(player1, player2);
					player1.move = ' ';
					player2.move = ' ';
					Sleep(2500);
				}
				else {
					player1.score++;
				}
			}
			else {
				player2.score++;
			}
		}
		else if (timed == 'u') {
			init(player1, player2);
			cout << player1.name << ": Select a move (r/p/s): ";
			cin >> player1.move;
			system("CLS");
			init(player1, player2);
			cout << player2.name << ": Select a move (r/p/s): ";
			cin >> player2.move;
			system("CLS");
			init(player1, player2);

			// decide computer's move
			/*srand (time(NULL));
			comp_move = rand() % 3;
			if (comp_move == 0)
			computer.move = 'r';
			else if (comp_move == 1)
			computer.move = 'p';
			else
			computer.move = 's';
			cout << "\nComputer's move: " << computer.move << endl << endl;*/

			compareMoves(player1, player2);
			Sleep(2500);
		}
		if (player1.score < 10 && player2.score < 10)
			system("CLS");
	}

	if (player1.score >= 10)
		cout << "VICTORY FOR " << player1.name << "!" << endl;
	else
		cout << "VICTORY FOR " << player2.name << "!" << endl;
	system("pause");
	return 0;
}

