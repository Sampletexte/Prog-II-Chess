//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_KING_H
#define PROG_II_CHESS_KING_H

#include "../ChessPiece.h"

class King : public ChessPiece {
protected:
    bool hasTakenMove = false;
public:
    King(); // Default contructor - Precalculates all of the possible moves
    King(int side) : ChessPiece( side ) { setName('k'); };
    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY);
};


#endif //PROG_II_CHESS_KING_H
