#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(const std::string &InName, BoardContent InSign)
: Player(InName, InSign) {}

void HumanPlayer::PerformMove(Board*& Board) {
	int row, column;

	while (true) {
		row = column = 4;

		while (row > 3) {
			cout << "Enter row: ";
			cin >> row;
			if (row > 3) cout << "Row must be lower than 4." << endl;
		}

		while (column > 3) {
			cout << "Enter column: ";
			cin >> column;
			if (column > 3) cout << "Column must be lower than 4." << endl;
		}

		if ((*Board)[row][column] != EMPTY) {
			cout << "Position's already taken. Choose again." << endl;
			continue;
		}

		(*Board)[row][column] = Sign;
		break;
	}
}
