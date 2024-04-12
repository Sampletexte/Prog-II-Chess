//
// Created by sochin1519 on 3/25/2024.
//

#include "Pawn.h"

Pawn::Pawn() : ChessPiece() {

};


std::vector<Point> Pawn::getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY) {
    std::vector<Point> posMovs;
    int attackX[2] = {-1,1}; // To the left and right of the pawn

    // Check for attack options
    for( auto attX: attackX) {  // Side will determine attack direction
        if( !(posY-side < 0 || posY-side > 7) && !(posX+attX < 0 || posX+attX > 7) ) {  // If in bounds
            ChessPiece *piece = (*gameboard)[posY - side][posX + attX];
            if (piece->getSide() != side && piece->getSide() != NO_PIECE) {
                Point pnt{posX - attX, posY - side};
                posMovs.push_back(pnt);
            }
        }
    }

    // Check if it can move forward
    if(posY-side <= 7) {  // If in bounds. Only positive movement so only need to check high bound
        ChessPiece *piece = (*gameboard)[posY - side][posX];
        if (piece->getSide() == NO_PIECE) {
            Point pnt{posX, posY - side};
            posMovs.push_back(pnt);
        }
    }
    return posMovs;
}