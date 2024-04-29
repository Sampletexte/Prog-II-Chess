/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: This file provides the code for the board class.
*/

#include "Board.h"

/**
 * This default constructor set the position variables of the kings so checkmate and check can be calculated for each piece.
 */
Board::Board()  {
    // Set the king positions
    // Set the black king's position
    ChessPiece* piece = gameboard[0][4];
    (dynamic_cast<King *> (piece))->setPos(4,0);

    // Set the black king's position
    piece = gameboard[7][4];
    (dynamic_cast<King *> (piece))->setPos(4,7);
}


/**
 * This function replaces the destination position with the given chesspiece, updating the position variable too if the
 * piece is a king.
 * @param piece - The piece to add to the gameboard
 * @param x - The position of the piece
 * @param y - The position of the piece
 */
void Board::setPieceatPos( ChessPiece* piece, int x, int y) {
    gameboard[y][x] = piece;
    if( piece->getName() == 'k') {  // If the piece is a king then update the king's position, so it's position can be used when checking for check
        dynamic_cast<King *> (piece)->setPos( x, y);    // Update the king's position
    }
};

