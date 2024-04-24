//
// Created by sochin1519 on 3/25/2024.
//
#include "Knight.h"

Knight::Knight():ChessPiece() {}

std::vector<Point> Knight::getPossibleMoves(std::vector<std::vector<ChessPiece *>> * gameboard, int posX, int posY) {
    std::vector<Point> posMovs;

    // Define all possible knight moves relative to the current position
    int possibleMoves[8][2] = {
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
            {1, -2}, {2, -1}, {2, 1}, {1, 2}
    };

    // Check each possible move
    for (auto move : possibleMoves) {
        int newX = posX + move[0];
        int newY = posY + move[1];

        // Verify if the move is within the board boundaries
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            ChessPiece *piece = (*gameboard)[newX][newY];
            // Add the move to validMoves if the destination is empty or contains an opponent's piece
            if (piece->getName() == 0 || piece->getSide() != side) {
                posMovs.push_back(Point{newX, newY});
            }
        }
    }

    return posMovs;
}

//RelativeActions Knight::getPossibleMoves(Board *board, int x, int y) {};