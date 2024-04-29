/*
 * Created by sochin1519 on 3/25/2024.
 * Desc: This file is the header file for the board class that stores the gameboard state.
*/

#ifndef PROG_II_CHESS_BOARD_H
#define PROG_II_CHESS_BOARD_H



#include <algorithm>

#include "../ChessPiece/ChessPiece.h"
#include "../ChessPiece/Pawn/Pawn.h"
#include "../ChessPiece/King/King.h"
#include "../ChessPiece/Queen/Queen.h"
#include "../ChessPiece/Bishop/Bishop.h"
#include "../ChessPiece/Knight/Knight.h"
#include "../ChessPiece/Rook/Rook.h"


class Board {
private:
    int size[2] = {8, 8};
    std::vector<std::vector<ChessPiece*>> gameboard = {
        { new Rook(-1), new Knight(-1), new Bishop(-1), new Queen(-1), new King(-1), new Bishop(-1), new Knight(-1), new Rook(-1)},
        { new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1) },
        { new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0) },
        { new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0) },
        { new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0) },
        { new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0), new ChessPiece(0) },
        { new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1) },
        { new Rook(1), new Knight(1), new Bishop(1), new Queen(1), new King(1), new Bishop(1), new Knight(1), new Rook(1) }
    };

public:
    Board();

    ChessPiece* getPieceatPos( int x, int y ) { return gameboard[y][x]; };
    void setPieceatPos( ChessPiece* piece, int x, int y);

    std::vector<std::vector<ChessPiece *>> * getGameboard() { return &gameboard; };
};


#endif //PROG_II_CHESS_BOARD_H
