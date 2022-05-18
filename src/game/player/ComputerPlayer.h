#ifndef TICTACTOE_COMPUTERPLAYER_H
#define TICTACTOE_COMPUTERPLAYER_H

#include "Player.h"

/**
 * Represents a "Computer" player that responds to opponent's actions <br/>
 * by analyzing a tic-tac-toe board with the
 * <a href="https://en.wikipedia.org/wiki/Minimax" target="_blank">Minimax algorithm</a>.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class ComputerPlayer : public Player {

public:
	/**
	 * Create an instance with player's name and sign (X or O).
	 *
	 * @param InName The player's name.
	 * @param InSign The player's sign (X or O).
	 */
	ComputerPlayer(const std::string& InName, BoardContent InSign);

	/**
	 * Performs a move by executing the Minimax algorithm.
	 *
	 * @param InBoard The current state of a tic-tac-toe board.
	 */
	void PerformMove(Board*& InBoard) override;

protected:
	/**
	 * Carries out the actual Minimax algorithm.
	 *
	 * @param InBoard The current state of a tic-tac-toe board.
	 * @param Depth   The current level of a minimax tree.
	 * @param IsMax   Whether we are estimating for a "max" player.
	 * @return The minimax evaluation for the given arguments.
	 */
	int Minimax(Board*& InBoard, int Depth, bool IsMax);
};


#endif //TICTACTOE_COMPUTERPLAYER_H
