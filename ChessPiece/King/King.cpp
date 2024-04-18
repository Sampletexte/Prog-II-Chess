//
// Created by sochin1519 on 3/25/2024.
//

#include "King.h"

King::King() {
    name = 'k';
}

std::vector<Point> King::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> posMovs;

    // Iterate around the king
    for(int yOffset = -1; yOffset <= 1; ++yOffset) {
        for(int xOffset = -1; xOffset <= 1; ++xOffset) {
            if( !(posY+yOffset < 0 || posY+yOffset > 7) && !(posX+xOffset < 0 || posX+xOffset > 7) ) {  // If in bounds
                ChessPiece *piece = (*gameboard)[posY+yOffset][posX+xOffset];
                if (piece->getSide() != side) { // If the piece is not on the same side then it is a possible move
                    Point pnt{posX+xOffset, posY+yOffset};
                    posMovs.push_back(pnt);
                }
            }
        }
    }

    return posMovs;
};

