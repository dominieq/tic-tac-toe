#ifndef TICTACTOE_AIPLAYER_H
#define TICTACTOE_AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {

public:
	AIPlayer(const std::string &InName, BoardContent InSign);

protected:
	virtual int Minmax(Board*& InBoard, int depth, bool IsMax) = 0;
};


#endif //TICTACTOE_AIPLAYER_H
