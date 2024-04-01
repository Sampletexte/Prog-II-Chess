//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"

Board::Board()  {}  // Remove later

void Board::setPieceatPos( ChessPiece* piece, int x, int y) {
    gameboard[ std::distance(boardKey, std::find(boardKey, boardKey+7, piece)) * piece->getSide()]; // boardKey has a size of 7
}

void Board::MovePiece(int old_x, int old_y, int new_x, int new_y) {
    ChessPiece* piece = getPieceatPos( old_x, old_y);

    ChessPiece * no_piece = boardKey[0];   // Empty piece
    setPieceatPos(no_piece, old_x, old_y);

    setPieceatPos(piece, new_x, new_y);
};


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

