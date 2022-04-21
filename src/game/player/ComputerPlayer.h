#ifndef TICTACTOE_COMPUTERPLAYER_H
#define TICTACTOE_COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {

public:
	ComputerPlayer(const std::string& InName, BoardContent InSign);

	void PerformMove(Board*& InBoard) override;

protected:
	int Minmax(Board*& InBoard, int Depth, bool IsMax);
};


#endif //TICTACTOE_COMPUTERPLAYER_H
