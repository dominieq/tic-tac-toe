#ifndef TICTACTOE_HUMANPLAYER_H
#define TICTACTOE_HUMANPLAYER_H

#include "Player.h"

/**
 * Represents a player that performs moves via the standard input (console).
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class HumanPlayer : public Player {

public:
	/**
	 * Create an instance with player's name and sign (X or O).
	 *
	 * @param InName The player's name.
	 * @param InSign The player's sign (X or O).
	 */
	HumanPlayer(const std::string& InName, BoardContent InSign);

	/**
	 * Performs a move by selecting a row and column via the standard input (console).
	 *
	 * @param InBoard The current state of a tic-tac-toe board.
	 */
	void PerformMove(Board*& InBoard) override;
};


#endif //TICTACTOE_HUMANPLAYER_H
