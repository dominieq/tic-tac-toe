#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "player/HumanPlayer.h"
#include "player/MaximizerPlayer.h"

class Game {

	Player* Player_1;
	Player* Player_2;
	Board* GameBoard;

	int Moves = 0;

public:
	explicit Game(const std::string& Name);

	Game(const std::string& Name_1, const std::string& Name_2);

	virtual ~Game();

	void PlayGame();

private:
	BoardContent PerformMove(Player*& Player);
};


#endif //TICTACTOE_GAME_H
