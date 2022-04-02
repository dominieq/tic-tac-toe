#include "Board.h"
#include "../Utils.h"

Board::Board() {
    Content = new BoardContent*[BoardSize];

    for (int i = 0; i < BoardSize; i++) {
        Content[i] = new BoardContent[BoardSize];

        for (int j = 0; j < BoardSize; j++) {
            Content[i][j] = BoardContent::EMPTY;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < BoardSize; i++) {
        delete[] Content[i];
    }

    delete[] Content;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    os << std::endl;
    for (int i = 0; i < Board::BoardSize + 2; i++) {
        for (int j = 0; j < Board::BoardSize + 2; j++) {
            if (IS_EVEN(i)) {
                if (IS_EVEN(j)) {
                    os << Board::BoardContentToChar(board.Content[i / 2][j / 2]);
                } else {
                    os << '|';
                }
            } else {
                if (IS_EVEN(j)) {
                    os << '_';
                } else {
                    os << '.';
                }
            }
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

char Board::BoardContentToChar(const BoardContent &Element) {
    switch (Element) {
        case BoardContent::X_SIGN:
            return 'x';
        case BoardContent::O_SIGN:
            return 'o';
        case BoardContent::EMPTY:
        default:
            return ' ';
    }
}
