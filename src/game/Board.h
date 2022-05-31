#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <ostream>

/**
 * A numeric representation of tic-tac-toe signs.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
enum BoardContent : int {
	EMPTY = 0,
	X_SIGN = -9,
	O_SIGN = 9
};

/**
 * A tic-tac-toe board.
 *
 * @author Dominik Szmyt
 * @since 1.0.0
 */
class Board {

	BoardContent **Content;

public:
	static const int BoardSize = 3;

	/**
	 * Initialize this Board's content.
	 */
	Board();

	/**
	 * Initialize this Board's content using another Board.
	 *
	 * @param Other Another Board that is to be copied and then destroyed.
	 */
	Board(const Board &Other);

	/**
	 * Destroy this Board's content.
	 */
	virtual ~Board();

	friend std::ostream &operator<<(std::ostream &OS, const Board &InBoard);

	BoardContent *&operator[](int Index) const;

	BoardContent *&operator[](int Index);

	Board &operator=(const Board &Other);

	/**
	 * Checks this Board for a winner.
	 * If a winner can't be determined, returns empty sign.
	 *
	 * @return A winner or empty otherwise.
	 */
	BoardContent DetermineWinner();

	/**
	 * Checks the board for any empty fields.
	 *
	 * @return true if a player can perform next move, otherwise false.
	 */
	bool AnyMovesLeft();

protected:
	/**
	 * Converts tic-tac-toe signs from numeric representations to character representations.
	 *
	 * @param Element A value from board.
	 * @return A character representation of a value.
	 */
	static char BoardContentToChar(const BoardContent &Element);
};


#endif //TICTACTOE_BOARD_H
