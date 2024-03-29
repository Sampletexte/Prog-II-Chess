//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_BOARD_H
#define PROG_II_CHESS_BOARD_H


#include "../ChessPiece/Pawn/Pawn.h"
#include "../ChessPiece/King/King.h"
#include "../ChessPiece/Queen/Queen.h"
#include "../ChessPiece/Bishop/Bishop.h"
#include "../ChessPiece/Knight/Knight.h"
#include "../ChessPiece/Rook/Rook.h"


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
        };
    ChessPiece* boardKey[7] {
        0,      // 0 | No piece
        &Pawn,   // 1
        &Rook,   // 2
        &Knight, // 3
        &Bishop, // 4
        &King,   // 5
        &Queen   // 6
    };

public:
    ChessPiece getPieceatPos( int x, int y);
    void setPieceatPos( ChessPiece* piece, int side, int x, int y) {
        board[ std::distance(boardKey, std::find(boardKey, boardKey+7, Piece)) * side]; // boardKey has a size of 7
    }
};


#endif //PROG_II_CHESS_BOARD_H
