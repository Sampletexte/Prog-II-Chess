//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_PAWN_H
#define PROG_II_CHESS_PAWN_H

#include "../ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(); // Default contructor - Precalculates all of the possible moves
};


#endif //PROG_II_CHESS_PAWN_H
