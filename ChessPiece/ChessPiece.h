//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_CHESSPIECE_H
#define PROG_II_CHESS_CHESSPIECE_H

#define BLACK -1
#define NO_PIECE 0
#define WHITE 1

#include <vector>
#include <string>

// The base class for all chess pieces
class ChessPiece {
protected:
    int side = NO_PIECE;
    std::string name;
public:
    ChessPiece() {};
    ChessPiece( int side ) { this->side = side; };
    void setSide( int side ) { this->side = side; };
    int getSide() { return side; };

};


#endif //PROG_II_CHESS_CHESSPIECE_H
