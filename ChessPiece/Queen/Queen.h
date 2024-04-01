//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_QUEEN_H
#define PROG_II_CHESS_QUEEN_H

#include "../ChessPiece.h"

// The Queen moveset is a combination of the Rook and Bishop.
class Queen : public ChessPiece {
public:
    Queen(); // Default contructor
//    RelativeActions getPossibleMoves(Board *board, int x, int y);
};


#endif //PROG_II_CHESS_QUEEN_H
