#include "Board.h"
#include "../Utils.h"

Board::Board() {
	Content = new BoardContent *[BoardSize];

	for (int i = 0; i < BoardSize; i++) {
		Content[i] = new BoardContent[BoardSize];

		for (int j = 0; j < BoardSize; j++) {
			Content[i][j] = BoardContent::EMPTY;
		}
	}
}

Board::Board(const Board &Other) {
	Content = new BoardContent *[BoardSize];

	for (int i = 0; i < BoardSize; i++) {
		Content[i] = new BoardContent[BoardSize];

		for (int j = 0; j < BoardSize; j++) {
			Content[i][j] = Other.Content[i][j];
		}

		delete[] Other.Content[i];
	}

	delete[] Other.Content;
}

Board::~Board() {
	for (int i = 0; i < BoardSize; i++) {
		delete[] Content[i];
	}

	delete[] Content;
}

std::ostream &operator<<(std::ostream &OS, const Board &InBoard) {
	OS << std::endl;
	for (int i = 0; i < Board::BoardSize + 2; i++) {
		for (int j = 0; j < Board::BoardSize + 2; j++) {
			if (IS_EVEN(i)) {
				if (IS_EVEN(j)) {
					OS << Board::BoardContentToChar(InBoard.Content[i / 2][j / 2]);
				} else {
					OS << '|';
				}
			} else {
				if (IS_EVEN(j)) {
					OS << '_';
				} else {
					OS << '.';
				}
			}
		}
		OS << std::endl;
	}
	OS << std::endl;
	return OS;
}

BoardContent *&Board::operator[](int Index) {
	return Content[Index];
}

BoardContent *&Board::operator[](int Index) const {
	return Content[Index];
}

Board &Board::operator=(const Board &Other) {
	if (this == &Other) return *this;

	auto **NewContent = new BoardContent *[BoardSize];

	for (int i = 0; i < BoardSize; i++) {
		NewContent[i] = new BoardContent[BoardSize];

		for (int j = 0; j < BoardSize; j++) {
			NewContent[i][j] = Other.Content[i][j];
		}
		delete[] Content[i];
	}

	delete[] Content;
	Content = NewContent;
	return *this;
}

BoardContent Board::DetermineWinner() {
	for (int i = 0; i < BoardSize; i++) {
		// Check rows
		if (Content[i][0] != EMPTY &&
			Content[i][0] == Content[i][1] &&
			Content[i][1] == Content[i][2]) {

			return Content[i][0];
		}

		// Check columns
		if (Content[0][i] != EMPTY &&
			Content[0][i] == Content[1][i] &&
			Content[1][i] == Content[2][i]) {

			return Content[0][i];
		}
	}

	// Check diagonal from left to right
	if (Content[0][0] != EMPTY &&
		Content[0][0] == Content[1][1] &&
		Content[1][1] == Content[2][2]) {

		return Content[0][0];
	}

	// Check diagonal from right to left
	if (Content[0][2] != EMPTY &&
		Content[0][2] == Content[1][1] &&
		Content[1][1] == Content[2][0]) {

		return Content[0][2];
	}

	return EMPTY;
}

bool Board::AnyMovesLeft() {
	for (int i = 0; i < BoardSize; i++) {
		for (int j = 0; j < BoardSize; j++) {
			if (Content[i][j] == EMPTY) return true;
		}
	}

	return false;
}

char Board::BoardContentToChar(const BoardContent &Element) {
	switch (Element) {
		case BoardContent::X_SIGN:
			return 'x';
		case BoardContent::O_SIGN:
			return 'o';
		case BoardContent::EMPTY:
		default:
			return ' ';
	}
}
