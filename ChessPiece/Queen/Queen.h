/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: This file is a skeleton of the main implentation file that call the rook and bishop class files to use their movesets
 * for the Queen.
*/

#ifndef PROG_II_CHESS_QUEEN_H
#define PROG_II_CHESS_QUEEN_H

#include "../ChessPiece.h"
#include "../Bishop/Bishop.h"
#include "../Rook/Rook.h"



// The Queen moveset is a combination of the Rook and Bishop.
class Queen : public ChessPiece {
public:
    Queen(); // Default contructor
    Queen(int side) : ChessPiece( side ) { setName('q'); };

    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY);
};


#endif //PROG_II_CHESS_QUEEN_H
