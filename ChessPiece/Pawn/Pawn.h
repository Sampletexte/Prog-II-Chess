//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_PAWN_H
#define PROG_II_CHESS_PAWN_H

#include "../ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(); // Default contructor
    RelativeActions Pawn::getPossibleMoves(Board *board, int x, int y);
};


#endif //PROG_II_CHESS_PAWN_H
