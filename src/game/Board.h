#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <ostream>

enum BoardContent : int {
	EMPTY,
	X_SIGN,
	O_SIGN
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

protected:
	static char BoardContentToChar(const BoardContent &Element);
};


#endif //TICTACTOE_BOARD_H
