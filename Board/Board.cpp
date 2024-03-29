//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"


/**
 *
 * @param x - the x coordinate of the chess piece
 * @param y - the y coordinate of the chess piece
 * @return - 0 when no piece is found. A chess piece when a piece is found.
 */
ChessPiece Board::getPieceatPos(int x, int y)
{
    if( (x >= 0 && x < size[0]) && (y >= 0 && y < size[1])) // in bounds check
        return boardKey[ gameboard[y][x] ];
    else
        return 0;
};

