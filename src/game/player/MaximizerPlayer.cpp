#include "MaximizerPlayer.h"

using namespace std;

MaximizerPlayer::MaximizerPlayer(const std::string& inName, BoardContent inSign)
: AIPlayer(inName, inSign) {
}

void MaximizerPlayer::PerformMove(Board*& InBoard) {

	int MaxScore = -1000;
	int MaxRow = -1;
	int MaxColumn = -1;

	for (int i = 0; i < Board::BoardSize; i++) {
		for (int j = 0; j < Board::BoardSize; j++) {

			if ((*InBoard)[i][j] == EMPTY) {

				(*InBoard)[i][j] = Sign;
				auto MoveScore = Minmax(InBoard, 0);
				(*InBoard)[i][j] = EMPTY;

				if (MoveScore > MaxScore) {
					MaxScore = MoveScore;
					MaxRow = i;
					MaxColumn = j;
				}
			}
		}
	}

	if (MaxScore >= 0) {
		(*InBoard)[MaxRow][MaxColumn] = Sign;
	}
}

int MaximizerPlayer::Minmax(Board*& InBoard, int depth) {

	BoardContent Score = InBoard->DetermineWinner();

	if (Score == Sign) return Score - depth;
	if (!InBoard->AnyMovesLeft()) return 0;

	int BestScore = -1000;

	for (int i = 0; i < Board::BoardSize; i++) {
		for (int j = 0; j < Board::BoardSize; j++) {

			if ((*InBoard)[i][j] == EMPTY) {

				(*InBoard)[i][j] = Sign;
				BestScore = max(BestScore, Minmax(InBoard, depth + 1));
				(*InBoard)[i][j] = EMPTY;
			}
		}
	}

	return BestScore;
}
