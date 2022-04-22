#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "../Board.h"
#include <string>

class Player {

public:
	Player(std::string InName, BoardContent InSign);

	virtual ~Player();

	virtual void PerformMove(Board*& InBoard) = 0;

	const std::string& GetName() const;

protected:
	std::string Name;
	BoardContent Sign;
};


#endif //TICTACTOE_PLAYER_H
