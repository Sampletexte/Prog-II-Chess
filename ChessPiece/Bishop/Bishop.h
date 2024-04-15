//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_BISHOP_H
#define PROG_II_CHESS_BISHOP_H

#include "../ChessPiece.h"

class Bishop : public ChessPiece {
public:
    Bishop(); // Default contructor - Precalculates all of the possible moves
    Bishop(int side) : ChessPiece( side ) { setName('b'); };
    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY) { return std::vector<Point>{}; };;
};


#endif //PROG_II_CHESS_BISHOP_H
