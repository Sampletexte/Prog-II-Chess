//
// Created by sochin1519 on 3/25/2024.
//

#ifndef SFMLCMAKETST_BOARD_H
#define SFMLCMAKETST_BOARD_H

#include "../ChessPiece/ChessPiece.h"


class Board {
private:
    int size[2] = {8,8};
    int gameboard[8][8] = {
            {-2, -3, -4, -6, -5, -4, -3, -2},
            {-1, -1, -1, -1, -1, -1, -1, -1,},
            {0, 0, 0, 0, 0, 0, 0, 0,},
            {0, 0, 0, 0, 0, 0, 0, 0,},
            {0, 0, 0, 0, 0, 0, 0, 0,},
            {0, 0, 0, 0, 0, 0, 0, 0,},
            {2, 3, 4, 6, 5, 4, 3, 2,},
            {1, 1, 1, 1, 1, 1, 1, 1,}
        }

    chessPiece boardKey[7] {

    };

public:
    ChessPiece getPieceatPos( int x, int y);
    void setPieceatPos( ChessPiece piece, int side, int x, int y) {
        board[ std::distance(boardKey, std::find(boardKey, boardKey+7, Piece)) * side]; // boardKey has a size of 7
    }

    vector<Point> calculatePossibleMoves(ChessPiece piece, int x, int y);
};


#endif //SFMLCMAKETST_BOARD_H
