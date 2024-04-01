//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_CHESSPIECE_H
#define PROG_II_CHESS_CHESSPIECE_H

#define BLACK -1
#define NO_PIECE 0
#define WHITE 1

#include <vector>
<<<<<<< HEAD
#include "../Board/Board.h" // I am worried about a circular dependency error here
#include <string>
=======
//#include "../Board/Board.h" // I am worried about a circular dependency error here
>>>>>>> fae0fb0794604feaa45d2093e1cdec65a5df88fe


struct RelativeActions {
    std::vector< int[2] > pnts;
};


// The base class for all chess pieces
class ChessPiece {
protected:
    std::string name = "empty";
    int side = NO_PIECE;
public:
    void setSide( int side ) { this->side = side; };
    int getSide() { return side; };

    //virtual RelativeActions getPossibleMoves(Board *board, int x, int y) = 0; // Will be defined in the child classes if not no piece.
};


#endif //PROG_II_CHESS_CHESSPIECE_H
