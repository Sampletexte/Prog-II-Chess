//
// Created by sochin1519 on 3/25/2024.
//

#ifndef PROG_II_CHESS_KING_H
#define PROG_II_CHESS_KING_H

#include "../ChessPiece.h"
#include <map>          // std::map
#include <algorithm>    // std::find


class King : public ChessPiece {
protected:
    Point pos;
    bool hasTakenMove = false;
public:
    King(); // Default contructor
    King(int side) : ChessPiece( side ) { setName('k'); };

    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard);    // Uses the internal pos
    std::vector<Point> getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY);
    std::vector<Point> getAllMoves(std::vector<std::vector<ChessPiece *>> *gameboard);

    bool isInCheck(std::vector<std::vector<ChessPiece *>> *gameboard);

    // Setter and getter for the position
    Point getPos() { return pos; };
    void setPos( int x, int y) { pos = Point{x,y}; };


    void removePoints(std::vector<Point> &pointLst, std::vector<Point> &pointsToRem);

    void removeDuplicates(std::vector<Point> &pointLst);
};


#endif //PROG_II_CHESS_KING_H
