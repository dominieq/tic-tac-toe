#ifndef TICTACTOE_HUMANPLAYER_H
#define TICTACTOE_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {

public:
	HumanPlayer(const std::string& InName, BoardContent InSign);

	void PerformMove(Board*& InBoard) override;
};


#endif //TICTACTOE_HUMANPLAYER_H
