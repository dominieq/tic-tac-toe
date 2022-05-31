#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "player/HumanPlayer.h"
#include "player/ComputerPlayer.h"

/**
 * A class that represents a game of tic-tac-toe between two players.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class Game {

	Player* Player_1;
	Player* Player_2;
	Board* GameBoard;

	int Moves = 0;

public:
	/**
	 * Create an instance with a player against an AI.
	 *
	 * @param Name The player's name.
	 */
	explicit Game(const std::string& Name);

	/**
	 * Create an instance with two players against each other.
	 *
	 * @param Name_1 The first player's name.
	 * @param Name_2 The second player's name.
	 */
	Game(const std::string& Name_1, const std::string& Name_2);

	/**
	 * Destroy both players and the board.
	 */
	virtual ~Game();

	/**
	 * Starts a game between two players.
	 * Keep in mind, the board isn't cleared between games.
	 * In order, to start a game on an empty board one should create a new instance of Game.
	 *
	 * @param StdOutput An output stream. Preferably the <code>cout</code>.
	 */
	void PlayGame(std::ostream& StdOutput);

private:
	/**
	 * Decorates player's move with some additional actions such as: <br/>
	 * displaying the current state of a board, checking whether a winner can be determined.
	 *
	 * @param Player    A player that is to perform their move.
	 * @param StdOutput An output stream. Preferably the <code>cout</code>.
	 * @return The outcome of a tic-tac-toe game.
	 */
	BoardContent PerformMove(Player*& Player, std::ostream& StdOutput);
};


#endif //TICTACTOE_GAME_H
