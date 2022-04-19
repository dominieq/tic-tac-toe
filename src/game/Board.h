#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <ostream>

enum BoardContent : int {
	EMPTY = 0,
	X_SIGN = -9,
	O_SIGN = 9
};

class Board {

	BoardContent **Content;

public:
	static const int BoardSize = 3;

	Board();

	Board(const Board &Other);

	virtual ~Board();

	friend std::ostream &operator<<(std::ostream &OS, const Board &InBoard);

	BoardContent *&operator[](int Index) const;

	BoardContent *&operator[](int Index);

	Board &operator=(const Board &Other);

	BoardContent DetermineWinner();

	bool AnyMovesLeft();

protected:
	static char BoardContentToChar(const BoardContent &Element);
};


#endif //TICTACTOE_BOARD_H
