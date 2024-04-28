//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"

Board::Board()  {
    // Set the king positions
    // Set the black king's position
    ChessPiece* piece = gameboard[0][4];
    (dynamic_cast<King *> (piece))->setPos(4,0);

    // Set the black king's position
    piece = gameboard[7][4];
    (dynamic_cast<King *> (piece))->setPos(4,7);
}



void Board::setPieceatPos( ChessPiece* piece, int x, int y) {
    gameboard[y][x] = piece;
    if( piece->getName() == 'k') {  // If the piece is a king then update the king's position, so it's position can be used when checking for check
        dynamic_cast<King *> (piece)->setPos( x, y);    // Update the king's position
    }
};

