//
// Created by sochin1519 on 3/25/2024.
//

#include "Pawn.h"

Pawn::Pawn() {};


//RelativeActions Pawn::getPossibleMoves(Board *board, int x, int y) {};
//    RelativeActions posMovs;
//    int attackX[2] = {-1,1}; // To the left and right of the pawn
//
//    // Check for attack options
//    for( auto attX: attackX) {  // Side will determine attack direction
//        ChessPiece *piece = board->getPieceatPos(x+attX, y+side);
//        if( piece->getSide() != side && piece->getSide() != NO_PIECE) {
//            int pnt[2] = { x+attX, y+side };
//            posMovs.pnts.push_back( pnt );
//        }
//    }
//
//    // Check if it can move
//    ChessPiece *piece = board->getPieceatPos(x, y+side);
//    if( piece->getSide() == NO_PIECE ) {
//        int pnt[2] { x, y+side };
//        posMovs.pnts.push_back( pnt );
//    }
//    return posMovs;
//}