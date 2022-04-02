#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <ostream>

enum BoardContent : int {
    EMPTY,
    X_SIGN,
    O_SIGN
};

class Board {

    BoardContent** Content;

public:
    static const int BoardSize = 3;

    Board();
    virtual ~Board();

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

protected:
    static char BoardContentToChar(const BoardContent& Element);
};


#endif //TICTACTOE_BOARD_H
