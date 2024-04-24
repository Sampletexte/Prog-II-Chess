//
// Created by sochin1519 on 3/25/2024.
//

#include "Queen.h"

Queen::Queen():ChessPiece() {}

std::vector<Point> Queen::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> posMovs;

    // Check horizontally and vertically (up, down, left, right)
    for (int i = 1; posX + i < 8; i++) {
        if ((*gameboard)[posX + i][posY]->getName() == 0) {
            posMovs.push_back(Point{posX + i, posY});
        } else if ((*gameboard)[posX + i][posY]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX + i, posY});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posX - i >= 0; i++) {
        if ((*gameboard)[posX - i][posY]->getName() == 0) {
            posMovs.push_back(Point{posX - i, posY});
        } else if ((*gameboard)[posX - i][posY]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX - i, posY});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posY + i < 8; i++) {
        if ((*gameboard)[posX][posY + i]->getName() == 0) {
            posMovs.push_back(Point{posX, posY + i});
        } else if ((*gameboard)[posX][posY + i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX, posY + i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posY - i >= 0; i++) {
        if ((*gameboard)[posX][posY - i]->getName() == 0) {
            posMovs.push_back(Point{posX, posY - i});
        } else if ((*gameboard)[posX][posY - i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX, posY - i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }

    // Check diagonally (up-right, up-left, down-right, down-left)
    for (int i = 1; posX + i < 8 && posY - i >= 0; i++) {
        if ((*gameboard)[posX + i][posY - i]->getName() == 0) {
            posMovs.push_back(Point{posX + i, posY - i});
        } else if ((*gameboard)[posX + i][posY - i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX + i, posY - i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posX - i >= 0 && posY - i >= 0; i++) {
        if ((*gameboard)[posX - i][posY - i]->getName() == 0) {
            posMovs.push_back(Point{posX - i, posY - i});
        } else if ((*gameboard)[posX - i][posY - i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX - i, posY - i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posX + i < 8 && posY + i < 8; i++) {
        if ((*gameboard)[posX + i][posY + i]->getName() == 0) {
            posMovs.push_back(Point{posX + i, posY + i});
        } else if ((*gameboard)[posX + i][posY + i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX + i, posY + i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }
    for (int i = 1; posX - i >= 0 && posY + i < 8; i++) {
        if ((*gameboard)[posX - i][posY + i]->getName() == 0) {
            posMovs.push_back(Point{posX - i, posY + i});
        } else if ((*gameboard)[posX - i][posY + i]->getSide() != side) { // Opponent piece
            posMovs.push_back(Point{posX - i, posY + i});
            break;
        } else { // Own piece blocking the way
            break;
        }
    }

    return posMovs;
}


//RelativeActions Queen::getPossibleMoves(Board *board, int x, int y) {};