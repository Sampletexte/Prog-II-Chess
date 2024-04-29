/*
 * Created by sochin1519 on 3/25/2024.
 * This file provides the code for the generation of the moves that the rook can make given its current situation.
*/

#include "Rook.h"

Rook::Rook():ChessPiece() {
    name = 'r';
}

/**
 * This file calculates all of the moves that a the chess piece can do at a specific location.
 * @param gameboard - The current chess board
 * @param posX - The piece position
 * @param posY - The piece position
 * @return - An array of points that refer to the move possible by that chess piece
 */
std::vector<Point> Rook::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> posMovs; // Array of all possible moves

    int iter_dir[2] = {-1,1}; // The iteration directions for the vertical and horizontal sides of the Rook

    // Check the vertical row
    bool hitNonEmptyPiece = true;   // Flag variable that turns true when a non-empty piece is reached
    for( auto itr_chg : iter_dir ){
        hitNonEmptyPiece = true;    // Reset the flag
        for (int itr = posY + itr_chg; (itr >= 0 && itr < 8) && hitNonEmptyPiece; itr += itr_chg) {  // Check below/above the rook depending on the itr_chg variable
            ChessPiece *piece = (*gameboard)[itr][posX];
            if (piece->getSide() != NO_PIECE) {
                hitNonEmptyPiece = false;
                if (piece->getSide() == -side) {    // If the piece is the opposite side
                    Point pnt{posX, itr};   // add the enemy piece as a possible move
                    posMovs.push_back(pnt);
                }
            } else {    // Add the empty square as a possible move
                Point pnt{posX, itr};
                posMovs.push_back(pnt);
            }
        };
    }

    // Check the horizontal row
    for( auto itr_chg : iter_dir ){
        hitNonEmptyPiece = true;   // Reset the flag
        for (int itr = posX + itr_chg; (itr >= 0 && itr < 8) && hitNonEmptyPiece; itr += itr_chg) {  // Check below/above the rook depending on the itr_chg variable
            ChessPiece *piece = (*gameboard)[posY][itr];
            if (piece->getSide() != NO_PIECE) {
                hitNonEmptyPiece = false;
                if (piece->getSide() == -side) {    // If the piece is the opposite side
                    Point pnt{itr, posY};   // add the enemy piece as a possible move
                    posMovs.push_back(pnt);
                }
            } else {    // Add the empty square as a possible move
                Point pnt{itr, posY};
                posMovs.push_back(pnt);
            }
        };
    }

    return posMovs;
};


