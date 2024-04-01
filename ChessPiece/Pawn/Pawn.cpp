//
// Created by sochin1519 on 3/25/2024.
//

#include "Pawn.h"

Pawn::Pawn() {
    name = "pawn";
};


RelativeActions Pawn::getPossibleMoves(Board *board, int x, int y) {
    RelativeActions posMovs;
    int attackX[2] = {-1,1}; // To the left and right of the pawn

    // Check for attack options
    for( auto attX: attackX) {  // Side will determine attack direction
        ChessPiece *piece = board->getPieceatPos(x+attX, y+side);
        if( piece->getSide() != side && piece->getSide() != NO_PIECE)
            posMovs.pnts.push_back( { x+attX, y+side } );
    }

    // Check if it can move
    ChessPiece *piece = board->getPieceatPos(x, y+side);
    if( piece->getSide() == NO_PIECE )
        posMovs.pnts.push_back( { x, y+side } );
    
    return posMovs;
}