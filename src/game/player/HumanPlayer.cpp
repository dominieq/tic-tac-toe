#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(const std::string& InName, BoardContent InSign)
		: Player(InName, InSign) {}

void HumanPlayer::PerformMove(Board*& InBoard) {
	PerformMove(InBoard, cin, cout);
}

void HumanPlayer::PerformMove(Board*& InBoard, istream& StdInput, ostream& StdOutput) {
	int row, column;

	while (true) {
		row = column = 3;

		while (row < 0 || row > 2) {
			StdOutput << "Enter row: ";
			StdInput >> row;
			if (row < 0 || row > 2) StdOutput << "Row must be between 0 and 2." << endl;
		}

		while (column < 0 || column > 2) {
			StdOutput << "Enter column: ";
			StdInput >> column;
			if (column < 0 || column > 2) StdOutput << "Column must be between 0 and 2." << endl;
		}

		if ((*InBoard)[row][column] != EMPTY) {
			StdOutput << "Position's already taken. Choose again." << endl;
			continue;
		}

		(*InBoard)[row][column] = Sign;
		break;
	}
}
