#include "Bishop.h"
// Created by sochin1519 on 3/25/2024.
//

//    RelativeActions getPossibleMoves(Board *board, int x, int y);

Bishop::Bishop() {};


std::vector<Point> Bishop::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> validMoves;
    // Check diagonally (up-right)
    for (int i = 1; posX + i < 8 && posY - i >= 0; i++) {
        if ( (*gameboard)[posX + i][posY - i]->getName() == 0 ) {
            validMoves.push_back(Point{posX + i, posY - i});
        } else if ((*gameboard)[posY - i][posX + i]->getName() < 0) { // Opponent piece
            validMoves.push_back(Point{posX + i, posY - i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    // Check diagonally (up-left)
    for (int i = 1; posX - i >= 0 && posY - i >= 0; i++) {
        ChessPiece *piece = (*gameboard)[posY - i][posX - i];
        if ( piece->getName() == 0) {
            validMoves.push_back(Point{posX - i, posY - i});
        } else if ((*gameboard)[posY - i][posX - i]->getSide() != side) { // Opponent piece
            validMoves.push_back(Point{posX - i, posY - i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    // Check diagonally (down-right)
    for (int i = 1; posX + i < 8 && posY + i < 8; i++) {
        if ( (*gameboard)[posY + i][posX + i]->getName() == 0) {
            validMoves.push_back(Point{posX + i, posY + i});
        } else if ((*gameboard)[posY + i][posX + i]->getName() < 0) { // Opponent piece
            validMoves.push_back(Point{posX + i, posY + i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    // Check diagonally (down-left)
    for (int i = 1; posX - i >= 0 && posY + i < 8; i++) {
        if ( (*gameboard)[posY + i][posX - i]->getName() == 0) {
            validMoves.push_back(Point{posX - i, posY + i});
        } else if ( (*gameboard)[posY + i][posX - i]->getName() < 0) { // Opponent piece
            validMoves.push_back(Point{posX - i, posY + i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    return validMoves;
};
