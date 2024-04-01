//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_KNIGHT_H
#define PROG_II_CHESS_KNIGHT_H

#include "../ChessPiece.h"

class Knight : public ChessPiece {
public:
    Knight(); // Default contructor - Precalculates all of the possible moves
    Knight(int side) : ChessPiece( side ) {};
//    RelativeActions getPossibleMoves(Board *board, int x, int y);
};


#endif //PROG_II_CHESS_KNIGHT_H
