/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: This file is the header file for the Pawn chess piece.
*/

#ifndef PROG_II_CHESS_PAWN_H
#define PROG_II_CHESS_PAWN_H


#include "../ChessPiece.h"

class Pawn : public ChessPiece {
protected:
    bool hasTakenMove = false;
public:
    Pawn(); // Default contructor
    Pawn(int side) : ChessPiece( side ) { setName('p'); };

    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY);
    void sethasTakenMove(){ hasTakenMove = true;};
};


#endif //PROG_II_CHESS_PAWN_H
