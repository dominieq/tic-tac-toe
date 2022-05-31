#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "../Board.h"
#include <string>

/**
 * A class that participates in a tic-tac-toe game by performing moves on a board.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class Player {

public:
	/**
	 * Create an instance with player's name and sign (X or O).
	 *
	 * @param InName The player's name.
	 * @param InSign The player's sign (X or O).
	 */
	Player(std::string InName, BoardContent InSign);

	virtual ~Player();

	/**
	 * A player should examine the given board and infer their next move.
	 *
	 * @param InBoard The current state of a tic-tac-toe board.
	 */
	virtual void PerformMove(Board*& InBoard) = 0;

	const std::string& GetName() const;

protected:
	std::string Name;
	BoardContent Sign;
};


#endif //TICTACTOE_PLAYER_H
