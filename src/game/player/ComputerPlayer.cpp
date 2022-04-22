#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(const std::string& InName, BoardContent InSign)
		: Player(InName, InSign) {
}

void ComputerPlayer::PerformMove(Board*& InBoard) {

	const bool IsMax = Sign == O_SIGN;
	int MaxScore = IsMax ? -1000 : 1000;
	int MaxRow = -1;
	int MaxColumn = -1;

	for (int i = 0; i < Board::BoardSize; i++) {
		for (int j = 0; j < Board::BoardSize; j++) {

			if ((*InBoard)[i][j] == EMPTY) {

				(*InBoard)[i][j] = Sign;
				auto MoveScore = Minmax(InBoard, 0, !IsMax);
				(*InBoard)[i][j] = EMPTY;

				if (IsMax) {
					if (MoveScore > MaxScore) {
						MaxScore = MoveScore;
						MaxRow = i;
						MaxColumn = j;
					}
				} else {
					if (MoveScore < MaxScore) {
						MaxScore = MoveScore;
						MaxRow = i;
						MaxColumn = j;
					}
				}
			}
		}
	}

	(*InBoard)[MaxRow][MaxColumn] = Sign;
}

int ComputerPlayer::Minmax(Board*& InBoard, int Depth, bool IsMax) {

	BoardContent Score = InBoard->DetermineWinner();

	if (Score != EMPTY) return Score;
	if (!InBoard->AnyMovesLeft()) return 0;

	int BestScore;

	if (IsMax) {
		BestScore = -1000;

		for (int i = 0; i < Board::BoardSize; i++) {
			for (int j = 0; j < Board::BoardSize; j++) {

				if ((*InBoard)[i][j] == EMPTY) {

					(*InBoard)[i][j] = O_SIGN;
					BestScore = max(BestScore, Minmax(InBoard, Depth + 1, !IsMax));
					(*InBoard)[i][j] = EMPTY;
				}
			}
		}
	} else {
		BestScore = 1000;

		for (int i = 0; i < Board::BoardSize; i++) {
			for (int j = 0; j < Board::BoardSize; j++) {

				if ((*InBoard)[i][j] == EMPTY) {

					(*InBoard)[i][j] = X_SIGN;
					BestScore = min(BestScore, Minmax(InBoard, Depth + 1, !IsMax));
					(*InBoard)[i][j] = EMPTY;
				}
			}
		}
	}

	return BestScore;
}
