/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: This file provides the skeleton of the rook chess piece claas.
*/

#ifndef PROG_II_CHESS_ROOK_H
#define PROG_II_CHESS_ROOK_H

#include "../ChessPiece.h"

class Rook : public ChessPiece {
public:
    Rook(); // Default contructor - Precalculates all of the possible moves
    Rook(int side) : ChessPiece( side ) { setName('r'); };
    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY);
};


#endif //PROG_II_CHESS_ROOK_H
