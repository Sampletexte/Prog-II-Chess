//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"

Board::Board()  {}  // Remove later


ChessPiece* Board::getPieceatPos( int x, int y ) {
    ChessPiece* piece = gameboard[y][x];
    piece->setPos(Point{x,y});
    return piece;
};

