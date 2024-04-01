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
    char name = 'e';
public:
    ChessPiece() {};
    ChessPiece( int side ) { this->side = side; };

    char getName() { return name; };
    void setName(char name) { this->name = name; };

    void setSide( int side ) { this->side = side; };
    int getSide() { return side; };

};


#endif //PROG_II_CHESS_CHESSPIECE_H
