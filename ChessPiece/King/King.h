//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_KING_H
#define PROG_II_CHESS_KING_H

#include "../ChessPiece.h"

class King : public ChessPiece {
public:
    King(); // Default contructor - Precalculates all of the possible moves
    King(int side) : ChessPiece( side ) {};
//    RelativeActions getPossibleMoves(Board *board, int x, int y);
};


#endif //PROG_II_CHESS_KING_H
