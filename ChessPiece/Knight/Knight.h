//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_KNIGHT_H
#define PROG_II_CHESS_KNIGHT_H

#include "../ChessPiece.h"

class Knight : public ChessPiece {
public:
    Knight(); // Default contructor - Precalculates all of the possible moves
    Knight(int side) : ChessPiece( side ) { setName('n'); };
    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY) { return std::vector<Point>{}; };;
};


#endif //PROG_II_CHESS_KNIGHT_H
