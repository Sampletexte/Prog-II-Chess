//
// Created by sochin1519 on 3/25/2024.
//

#include "Board.h"

ChessPiece Board::getPieceatPos(int x, int y)
{
    if( (x >= 0 && x < size[0]) && (y >= 0 && y < size[1])) // in bounds
        return boardKey[ gameboard[y][x] ];
    else
        return 0;
};

Point Board::calculatePossibleMoves(ChessPiece piece, int x, int y) {
    Point posMoves = piece.getPossibleMoves();  // List of the precalculated moves
    Point validMoves; // List of the moves that are possible

    for( int i=0; i < posMoves.dx.length(); ++i ) {
        ChessPiece item = getPieceatPos( posMoves.dx[i]+x, posMoves.dy[i]+y );
        if(item && item.side == NO_PIECE) {
            validMoves.dx.push_back(posMoves.dx[i] + x);
            validMoves.dy.push_back(posMoves.dy[i] + y);
        }
    // List of precalculated attacks
    posMoves = piece.getPossibleAttacks();
    for( int i=0; i < posMoves.dx.length(); ++i ) {
        ChessPiece item = getPieceatPos( posMoves.dx[i]+x, posMoves.dy[i]+y);
        if( item && item.side == !piece.side ) {
            validMoves.dx.push_back(posMoves.dx[i] + x);
            validMoves.dy.push_back(posMoves.dy[i] + y);
        }

    return validMoves;
}