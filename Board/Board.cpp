//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"

Board::Board()  {
//    // Initialize a pointer array of chess pieces. Each index corresponds to a number on the gameboard.
//    boardKey =
}


/**
 *
 * @param x - the x coordinate of the chess piece
 * @param y - the y coordinate of the chess piece
 * @return - nullptr when no piece is found. A chess piece when a piece is found.
 */
ChessPiece* Board::getPieceatPos(int x, int y)
{
    if( (x >= 0 && x < size[0]) && (y >= 0 && y < size[1])) { // in bounds
        int boardVal = gameboard[y][x];
        ChessPiece *piece = (boardKey[boardVal]);
        piece->setSide(boardVal);
        return piece;
    } else {
        return nullptr;
    }
};

