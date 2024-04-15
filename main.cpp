#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Board/Board.h"
#include <cmath>




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

//    //Create list of textures for white pieces
//    std::string whiteTextureList[6] = {"Sprites/Chess_plt45.svg.png", "Sprites/Chess_rlt45.svg.png",
//                                       "Sprites/Chess_blt45.svg.png",
//                                       "Sprites/Chess_nlt45.svg.png", "Sprites/Chess_qlt45.svg.png",
//                                       "Sprites/Chess_klt45.svg.png"};
//
//    //Create list of texture for black pieces
//    std::string blackTextureList[6] = {"Sprites/Chess_pdt45.svg.png", "Sprites/Chess_rdt45.svg.png",
//                                       "Sprites/Chess_bdt45.svg.png",
//                                       "Sprites/Chess_ndt45.svg.png", "Sprites/Chess_qdt45.svg.png",
//                                       "Sprites/Chess_kdt45.svg.png"};
//
//    //Create list of
//    char charList[6] = {'p', 'b', 'q', 'k', 'r', 'n'};
//
//    //Empty maps for white and black pieces
//    std::unordered_map<char, sf::Sprite> whiteTextureMap{};
//    std::unordered_map<char, sf::Sprite> blackTextureMap{};
//
//
//    for (int i = 0; i < 6; i++) {
//        sf::Texture tempTexture;
//        tempTexture.loadFromFile(whiteTextureList[i]);
//        whiteTextureMap[charList[i]] = sf::Sprite(tempTexture);
//    }
//
//    for (int i = 0; i < 6; i++) {
//        sf::Texture tempTexture;
//        tempTexture.loadFromFile(blackTextureList[i]);
//        blackTextureMap[charList[i]] = sf::Sprite(tempTexture);
//    }


//APLOGIES HERE IS A TEXTURE DUMP
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


    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess 2: The Sequel", sf::Style::Default);
    sf::Event event;


    bool isSelected = false;
    ChessPiece *selectPiece = nullptr;

    int xPosOrig;
    int yPosOrig;


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && isSelected == true){
                std::cout <<"log2";
                int xPosNew = floor(sf::Mouse::getPosition(window).x / 100);
                int yPosNew = floor(sf::Mouse::getPosition(window).y / 100);

                // get the point of the user click
                Point moveSelect {xPosNew, yPosNew};

                ChessPiece * confirmSelect = gameboard.getPieceatPos(xPosNew, yPosNew);

                std::vector<Point> validSelect = selectPiece->getPossibleMoves(gameboard.getGameboard(), xPosOrig, yPosOrig);

                for(int i = 0; i < validSelect.size(); i++){
                    if(moveSelect.x == validSelect[i].x && moveSelect.y == validSelect[i].y){
                        gameboard.setPieceatPos(selectPiece,xPosNew,yPosNew);
                        gameboard.setPieceatPos(new ChessPiece(0),xPosOrig,yPosOrig);
                        isSelected = false;
                        xPosOrig = 0;
                        yPosOrig = 0;
                    }
                }
            }

            //FRAMEWORK FOR SELECTING A PIECE TO MOVE, NEED TO CREATE MOVEPIECE FUNCTION
            else if (event.type == sf::Event::MouseButtonPressed && isSelected == false) {
                std::cout << "log1";
                // Get the X and Y position of where the button was pressed
                xPosOrig = floor(sf::Mouse::getPosition(window).x / 100);
                yPosOrig = floor(sf::Mouse::getPosition(window).y / 100);

                //create temporary variable
                selectPiece = gameboard.getPieceatPos(xPosOrig,yPosOrig);

                //if the selected piece is not an empty square
                if (selectPiece->getName() != 'e') {
                    //this bool marks that the user has a selected piece
                    isSelected = true;
                }
            };




                window.clear();
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


}