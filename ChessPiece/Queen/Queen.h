//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_QUEEN_H
#define PROG_II_CHESS_QUEEN_H

#include "../ChessPiece.h"

class Queen : public ChessPiece {
public:
    Queen(); // Default contructor - Precalculates all of the possible moves
};


#endif //PROG_II_CHESS_QUEEN_H
