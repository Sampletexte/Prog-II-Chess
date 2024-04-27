#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Board/Board.h"
#include <cmath>


void drawboard();

int main() {

    sf::Texture board, wp, wr, wb, wn, wq, wk, bp, br, bb, bn, bq, bk;
    board.loadFromFile("Sprites/board.png");
    wp.loadFromFile("Sprites/Chess_plt45.svg.png");
    wr.loadFromFile("Sprites/Chess_rlt45.svg.png");
    wb.loadFromFile("Sprites/Chess_blt45.svg.png");
    wn.loadFromFile("Sprites/Chess_nlt45.svg.png");
    wq.loadFromFile("Sprites/Chess_qlt45.svg.png");
    wk.loadFromFile("Sprites/Chess_klt45.svg.png");
    bp.loadFromFile("Sprites/Chess_pdt45.svg.png");
    br.loadFromFile("Sprites/Chess_rdt45.svg.png");
    bb.loadFromFile("Sprites/Chess_bdt45.svg.png");
    bn.loadFromFile("Sprites/Chess_ndt45.svg.png");
    bq.loadFromFile("Sprites/Chess_qdt45.svg.png");
    bk.loadFromFile("Sprites/Chess_kdt45.svg.png");


    // Initialize class gameboard for use; set scale and proper background for gameboard
    Board gameboard;
    sf::Sprite chessBoard;
    chessBoard.setTexture(board);
    chessBoard.setScale(.68493150684, .68610634648);
    sf::Sprite pawntest;
    pawntest.setTexture(wp);
    pawntest.setScale(.125, .125);


//Create Sprites for everything
    sf::Sprite whitePawn;
    whitePawn.setTexture(wp);
    sf::Sprite whiteBishop;
    whiteBishop.setTexture(wb);
    sf::Sprite whiteRook;
    whiteRook.setTexture(wr);
    sf::Sprite whiteKing;
    whiteKing.setTexture(wk);
    sf::Sprite whiteQueen;
    whiteQueen.setTexture(wq);
    sf::Sprite whiteKnight;
    whiteKnight.setTexture(wn);

    sf::Sprite blackPawn;
    blackPawn.setTexture(bp);
    sf::Sprite blackBishop;
    blackBishop.setTexture(bb);
    sf::Sprite blackRook;
    blackRook.setTexture(br);
    sf::Sprite blackKing;
    blackKing.setTexture(bk);
    sf::Sprite blackQueen;
    blackQueen.setTexture(bq);
    sf::Sprite blackKnight;
    blackKnight.setTexture(bn);

    //Create SFML Window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess 2: The Sequel", sf::Style::Default);
    sf::Event event;

    // Declaring varaibles needed for game loop
    bool isSelected = false;
    ChessPiece *selectPiece = nullptr;
    int xPosOrig;
    int yPosOrig;
    bool hasTurn = true; // White = T, Black = F
    ChessPiece *whiteSideKing;
    ChessPiece *blackSideKing;
    //Main game Logic, constant polling for events
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //Function to locate White King and Black King
             for(int y_ind = 0; y_ind < 8; y_ind++) {
                for (int x_ind = 0; x_ind < 8; x_ind++) {
                    ChessPiece *tempPiece = gameboard.getPieceatPos(x_ind,y_ind);
                    if(tempPiece->getName() == 'k' && tempPiece->getSide() == WHITE){
                        whiteSideKing = tempPiece;
                    }
                    if(tempPiece->getName() == 'k' && tempPiece->getSide() == BLACK){
                        blackSideKing = tempPiece;
                    }
                }
             }

            for(int y_ind = 0; y_ind < 8; y_ind++) {
                for (int x_ind = 0; x_ind < 8; x_ind++) {
                    ChessPiece *tempPiece = gameboard.getPieceatPos(x_ind, y_ind);
                    std::vector<Point> tempPiecePossibleMoves = tempPiece->getPossibleMoves(gameboard.getGameboard(),
                                                                                            x_ind, y_ind);
                    for (int y_again = 0; y_again < 8; y_again++) {
                        for (int x_again = 0; x_again < 8; x_again++) {
                            Point checkHere ={x_again,y_again};
                            for(int i = 0; i < tempPiecePossibleMoves.size(); i++) {
                                if(checkHere.x == tempPiecePossibleMoves[i].x && checkHere.y == tempPiecePossibleMoves[i].y){
                                    gameboard.getPieceatPos(x_again,y_again)->setIsUnderAttack(1);
                                }
                            }
                        }
                    }
                }
            }





            //If the user selects a square after selecting a piece
            if (event.type == sf::Event::MouseButtonPressed && isSelected == true) {
                //std::cout << "log2";
                int xPosNew = floor(sf::Mouse::getPosition(window).x / 100);
                int yPosNew = floor(sf::Mouse::getPosition(window).y / 100);
                // get the point of the user click
                Point moveSelect{xPosNew, yPosNew};
                //Get square that user selected
                ChessPiece *confirmSelect = gameboard.getPieceatPos(xPosNew, yPosNew);
                //Look at valid moveset for that piece
                std::vector<Point> validSelect = selectPiece->getPossibleMoves(gameboard.getGameboard(), xPosOrig, yPosOrig);


                //Check for the 4 castling scenarios.

                //Scenario 1: WHITE SIDE -- KING SIDE
                if(selectPiece->getName() == 'k' && selectPiece->getSide()== WHITE && !selectPiece->getHasTakenMove() && gameboard.getPieceatPos(7, 7)->getSide() == WHITE && gameboard.getPieceatPos(7, 7)->getName() == 'r' &&
                   !gameboard.getPieceatPos(7, 7)->getHasTakenMove() && gameboard.getPieceatPos(6, 7)->getName() == 'e' && gameboard.getPieceatPos(5, 7)->getName() == 'e' && moveSelect.y == 7 && moveSelect.x == 6){
                    //Then Castle King Side for White
                    gameboard.setPieceatPos(selectPiece,xPosNew, yPosNew);
                    gameboard.setPieceatPos(new Rook(1), 5, 7);
                    gameboard.setPieceatPos(new ChessPiece(0), xPosOrig, yPosOrig);
                    gameboard.setPieceatPos(new ChessPiece(0), 7, 7);
                    //Reset Variables
                    hasTurn = !hasTurn;
                    isSelected = false; // Deselect the piece
                    //Resets Pieces Under Attack
                    for(int y_ind = 0; y_ind < 8; y_ind++){
                        for(int x_ind = 0; x_ind <8; x_ind++){
                            gameboard.getPieceatPos(x_ind,y_ind)->setIsUnderAttack(0);
                        }
                    }

                }
                //Scenario 2: WHITE SIDE -- QUEEN SIDE
                if(selectPiece->getName() == 'k' && selectPiece->getSide()== WHITE && !selectPiece->getHasTakenMove() && gameboard.getPieceatPos(0, 7)->getSide() == WHITE && gameboard.getPieceatPos(0, 7)->getName() == 'r' &&
                   !gameboard.getPieceatPos(0, 7)->getHasTakenMove() && gameboard.getPieceatPos(3, 7)->getName() == 'e' && gameboard.getPieceatPos(2, 7)->getName() == 'e' && gameboard.getPieceatPos(1, 7)->getName() == 'e' && moveSelect.y == 7 && moveSelect.x == 2){
                    //Then Castle Queen Side for White
                    gameboard.setPieceatPos(selectPiece,xPosNew, yPosNew);
                    gameboard.setPieceatPos(new Rook(1), 3, 7);
                    gameboard.setPieceatPos(new ChessPiece(0), xPosOrig, yPosOrig);
                    gameboard.setPieceatPos(new ChessPiece(0), 0, 7);
                    //Reset Variables
                    hasTurn = !hasTurn;
                    isSelected = false; // Deselect the piece
                    //Resets Pieces Under Attack
                    for(int y_ind = 0; y_ind < 8; y_ind++){
                        for(int x_ind = 0; x_ind <8; x_ind++){
                            gameboard.getPieceatPos(x_ind,y_ind)->setIsUnderAttack(0);
                        }
                    }

                }
                //Scenario 3: BLACK SIDE -- KING SIDE
                else if(selectPiece->getName() == 'k' && selectPiece->getSide()== BLACK && !selectPiece->getHasTakenMove() && gameboard.getPieceatPos(7, 0)->getSide() == BLACK && gameboard.getPieceatPos(7, 0)->getName() == 'r' &&
                   !gameboard.getPieceatPos(7, 0)->getHasTakenMove() && gameboard.getPieceatPos(6, 0)->getName() == 'e' && gameboard.getPieceatPos(5, 0)->getName() == 'e' && moveSelect.y == 0 && moveSelect.x == 6) {
                    //Then Castle King Side for Black
                    gameboard.setPieceatPos(selectPiece, xPosNew, yPosNew);
                    gameboard.setPieceatPos(new Rook(-1), 5, 0);
                    gameboard.setPieceatPos(new ChessPiece(0), xPosOrig, yPosOrig);
                    gameboard.setPieceatPos(new ChessPiece(0), 7, 0);
                    //Reset Variables
                    hasTurn = !hasTurn;
                    isSelected = false; // Deselect the Piece
                    //Resets Pieces Under Attack
                    for(int y_ind = 0; y_ind < 8; y_ind++){
                        for(int x_ind = 0; x_ind <8; x_ind++){
                            gameboard.getPieceatPos(x_ind,y_ind)->setIsUnderAttack(0);
                        }
                    }
                }
                //Scenario 4: BLACK SIDE -- QUEEN SIDE
                else if(selectPiece->getName() == 'k' && selectPiece->getSide()== BLACK && !selectPiece->getHasTakenMove() && gameboard.getPieceatPos(0, 0)->getSide() == BLACK && gameboard.getPieceatPos(0, 0)->getName() == 'r' &&
                    !gameboard.getPieceatPos(0, 0)->getHasTakenMove() && gameboard.getPieceatPos(1, 0)->getName() == 'e' && gameboard.getPieceatPos(2, 0)->getName() == 'e' && gameboard.getPieceatPos(3, 0)->getName() == 'e' && moveSelect.y == 0 && moveSelect.x == 2) {
                    //Then Castle Queen Side for Black
                    gameboard.setPieceatPos(selectPiece, xPosNew, yPosNew);
                    gameboard.setPieceatPos(new Rook(-1), 3, 0);
                    gameboard.setPieceatPos(new ChessPiece(0), xPosOrig, yPosOrig);
                    gameboard.setPieceatPos(new ChessPiece(0), 0, 0);
                    //Reset Variables
                    hasTurn = !hasTurn;
                    isSelected = false; // Deselect the Piece
                    //Resets Pieces Under Attack
                    for(int y_ind = 0; y_ind < 8; y_ind++){
                        for(int x_ind = 0; x_ind <8; x_ind++){
                            gameboard.getPieceatPos(x_ind,y_ind)->setIsUnderAttack(0);
                        }
                    }
                }


                // If not one of the 4 Castle Scenarios
                // Compares valid moveset to desired move, commiting the move if it is valid
                else {
                    for (int i = 0; i < validSelect.size(); i++) {

                        if (moveSelect.x == validSelect[i].x && moveSelect.y == validSelect[i].y) {
                            gameboard.setPieceatPos(selectPiece, xPosNew, yPosNew);
                            gameboard.setPieceatPos(new ChessPiece(0), xPosOrig, yPosOrig);
                            if(selectPiece->getHasTakenMove() == false){
                                selectPiece->setHasTakenMove();
                            }
                            // If white piece is pawn and reaches opposite side, promote to queen
                            if (selectPiece->getSide() == WHITE && selectPiece->getName() == 'p' && yPosNew == 0) {
                                gameboard.setPieceatPos(new Queen(1), xPosNew, yPosNew);
                            }
                                // if black piece is a pawn and reaches the opposite side, promote to queen
                            else if (selectPiece->getSide() == BLACK && selectPiece->getName() == 'p' && yPosNew == 7) {
                                gameboard.setPieceatPos(new Queen(-1), xPosNew, yPosNew);
                            }
                            //Resets Variables out of scope and switches turns
                            hasTurn = !hasTurn;
                            //Resets Pieces Under Attack
                            for(int y_ind = 0; y_ind < 8; y_ind++){
                                for(int x_ind = 0; x_ind <8; x_ind++){
                                    gameboard.getPieceatPos(x_ind,y_ind)->setIsUnderAttack(0);
                                }
                            }
                            xPosOrig = 0;   // There is no point to do this btw. It will be overwritten on the next use anyways
                            yPosOrig = 0;
                        }
                    }
                    isSelected = false; // Deselect the piece
                }
            }
            //If the user selects a square before selecting the piece
            else if (event.type == sf::Event::MouseButtonPressed && isSelected == false) {
                //std::cout << "log1";
                // Get the X and Y position of where the button was pressed
                xPosOrig = floor(sf::Mouse::getPosition(window).x / 100);
                yPosOrig = floor(sf::Mouse::getPosition(window).y / 100);

                //create temporary variable
                selectPiece = gameboard.getPieceatPos(xPosOrig, yPosOrig);

                //if it is white side turns
                if (hasTurn) {

                    //if the King is in check, and the user attempts to select a piece that's not the king
                    if(whiteSideKing->getisUnderAttack() && selectPiece->getName() != 'k'){
                        isSelected = false;
                    }
                    //if the selected piece is not an empty square, and it is a white piece
                    else if (selectPiece->getName() != 'e' && selectPiece->getSide() == WHITE) {
                        isSelected = true;
                    }
                }
                //If it is black sides turn
                else {
                    if(blackSideKing->getisUnderAttack() && selectPiece->getName() != 'k') {
                        isSelected = false;
                    }
                    //if the selected piece is not an empty square, and it is a black piece
                    else if (selectPiece->getName() != 'e' && selectPiece->getSide() == BLACK) {
                        isSelected = true;
                    }
                }
            };


                window.clear();
                //draw background
                window.draw(chessBoard);

                //SWITCH CASE TO DISPLAY EVERY PIECE ON BOARD
                for (int y_ind = 0; y_ind < 8; y_ind++) {
                    for (int x_ind = 0; x_ind < 8; x_ind++) {
                        ChessPiece *tempPiece = gameboard.getPieceatPos(x_ind, y_ind);
                        if (tempPiece->getSide() == WHITE) {
                            switch (tempPiece->getName()) {
                                case 'p':
                                    whitePawn.setPosition(x_ind * 100, y_ind * 100);
                                    whitePawn.setScale(.125, .125);
                                    window.draw(whitePawn);
                                    break;
                                case 'r':
                                    whiteRook.setPosition(x_ind * 100, y_ind * 100);
                                    whiteRook.setScale(.125, .125);
                                    window.draw(whiteRook);
                                    break;
                                case 'b':
                                    whiteBishop.setPosition(x_ind * 100, y_ind * 100);
                                    whiteBishop.setScale(.125, .125);
                                    window.draw(whiteBishop);
                                    break;
                                case 'n':
                                    whiteKnight.setPosition(x_ind * 100, y_ind * 100);
                                    whiteKnight.setScale(.125, .125);
                                    window.draw(whiteKnight);
                                    break;
                                case 'q':
                                    whiteQueen.setPosition(x_ind * 100, y_ind * 100);
                                    whiteQueen.setScale(.125, .125);
                                    window.draw(whiteQueen);
                                    break;
                                case 'k':
                                    whiteKing.setPosition(x_ind * 100, y_ind * 100);
                                    whiteKing.setScale(.125, .125);
                                    window.draw(whiteKing);
                                    break;
                            };

                        } else if (tempPiece->getSide() == BLACK) {
                            switch (tempPiece->getName()) {
                                case 'p':
                                    blackPawn.setPosition(x_ind * 100, y_ind * 100);
                                    blackPawn.setScale(.125, .125);
                                    window.draw(blackPawn);
                                    break;
                                case 'r':
                                    blackRook.setPosition(x_ind * 100, y_ind * 100);
                                    blackRook.setScale(.125, .125);
                                    window.draw(blackRook);
                                    break;
                                case 'b':
                                    blackBishop.setPosition(x_ind * 100, y_ind * 100);
                                    blackBishop.setScale(.125, .125);
                                    window.draw(blackBishop);
                                    break;
                                case 'n':
                                    blackKnight.setPosition(x_ind * 100, y_ind * 100);
                                    blackKnight.setScale(.125, .125);
                                    window.draw(blackKnight);
                                    break;
                                case 'q':
                                    blackQueen.setPosition(x_ind * 100, y_ind * 100);
                                    blackQueen.setScale(.125, .125);
                                    window.draw(blackQueen);
                                    break;
                                case 'k':
                                    blackKing.setPosition(x_ind * 100, y_ind * 100);
                                    blackKing.setScale(.125, .125);
                                    window.draw(blackKing);
                                    break;
                            };
                        }
                    }
                }
                window.display();
            }


        }

    return 0;
    };
