//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_ROOK_H
#define PROG_II_CHESS_ROOK_H

#include "../ChessPiece.h"

class Rook : public ChessPiece {
public:
    Rook(); // Default contructor - Precalculates all of the possible moves
    Rook(int side) : ChessPiece( side ) { setName('r'); };
//    RelativeActions getPossibleMoves(Board *board, int x, int y);
};


#endif //PROG_II_CHESS_ROOK_H
