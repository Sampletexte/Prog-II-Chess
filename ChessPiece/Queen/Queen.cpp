/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: The purpose of this file is to generate the possible moveset of the Queen chess piece.
*/

#include "Queen.h"


Queen::Queen():ChessPiece() {}

/**
 * The Queen moveset is the merger between the rook and the bishop
 * @param gameboard - The current gameboard
 * @param posX - The x position of the chess piece
 * @param posY - The y position of the chess piece
 * @return - All of the possible moves for the queen
 */

std::vector<Point> Queen::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> posMovs;
    Bishop bishop(side);
    std::vector<Point> movs = bishop.getPossibleMoves(gameboard, posX, posY);
    posMovs.insert(std::end(posMovs), std::begin(movs), std::end(movs)); // Add the bishops moveset to the Queen moveset

    Rook rook(side);
    movs = rook.getPossibleMoves(gameboard, posX, posY);
    posMovs.insert(std::end(posMovs), std::begin(movs), std::end(movs)); // Add the rook moveset to the Queen moveset
    return posMovs;
}
