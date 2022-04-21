#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(const std::string &InName, BoardContent InSign)
: Player(InName, InSign) {}

void HumanPlayer::PerformMove(Board*& InBoard) {
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

		if ((*InBoard)[row][column] != EMPTY) {
			cout << "Position's already taken. Choose again." << endl;
			continue;
		}

		(*InBoard)[row][column] = Sign;
		break;
	}
}
