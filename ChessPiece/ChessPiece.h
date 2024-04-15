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

struct Point {
    int x, y;
};


// The base class for all chess pieces
class ChessPiece {
protected:
    int side = NO_PIECE;
    char name = 'e';
    Point pos;
public:
    ChessPiece() {};
    ChessPiece( int side ) { this->side = side; };

    Point getPos() { return pos; }
    void setPos(Point pos) { this->pos = pos;}

    char getName() { return name; };
    void setName(char name) { this->name = name; };

    void setSide( int side ) { this->side = side; };
    int getSide() { return side; };

    virtual std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY) { return std::vector<Point>{}; };   // You will have ot pass in the gameboard
};


#endif //PROG_II_CHESS_CHESSPIECE_H
