#ifndef TICTACTOE_MAXIMIZERPLAYER_H
#define TICTACTOE_MAXIMIZERPLAYER_H

#include "AIPlayer.h"

class MaximizerPlayer : public AIPlayer {

public:
	MaximizerPlayer(const std::string& inName, BoardContent inSign);

	void PerformMove(Board*& InBoard) override;

protected:
	int Minmax(Board*& InBoard, int depth, bool IsMax) override;
};


#endif //TICTACTOE_MAXIMIZERPLAYER_H
