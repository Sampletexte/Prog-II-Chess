#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Board/Board.h"




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

    //Create list of textures for white pieces
    std::string whiteTextureList[6] = {"Sprites/Chess_plt45.svg.png", "Sprites/Chess_rlt45.svg.png",
                                       "Sprites/Chess_blt45.svg.png",
                                       "Sprites/Chess_nlt45.svg.png", "Sprites/Chess_qlt45.svg.png",
                                       "Sprites/Chess_klt45.svg.png"};

    //Create list of texture for black pieces
    std::string blackTextureList[6] = {"Sprites/Chess_pdt45.svg.png", "Sprites/Chess_rdt45.svg.png",
                                       "Sprites/Chess_bdt45.svg.png",
                                       "Sprites/Chess_ndt45.svg.png", "Sprites/Chess_qdt45.svg.png",
                                       "Sprites/Chess_kdt45.svg.png"};

    //Create list of
    char charList[6] = {'p', 'b', 'q', 'k', 'r', 'n'};

    //Empty maps for white and black pieces
    std::unordered_map<char, sf::Sprite> whiteTextureMap{};
    std::unordered_map<char, sf::Sprite> blackTextureMap{};


    for (int i = 0; i < 6; i++) {
        sf::Texture tempTexture;
        tempTexture.loadFromFile(whiteTextureList[i]);
        whiteTextureMap[charList[i]] = sf::Sprite(tempTexture);
    }

    for (int i = 0; i < 6; i++) {
        sf::Texture tempTexture;
        tempTexture.loadFromFile(blackTextureList[i]);
        blackTextureMap[charList[i]] = sf::Sprite(tempTexture);
    }

    sf::Sprite whitePawn;
    whitePawn.setTexture(wp);
    sf::Sprite whiteBishop;
    whiteBishop.setTexture(wb);



    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess 2: The Sequel");
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear();
            window.draw(chessBoard);
            // Try using set texture Rect
            // combingin all the pngs into one larger file, sort by X and Y and by width and height (800 by 800)
            for (int y_ind = 0; y_ind < 8; y_ind++) {
                for (int x_ind = 0; x_ind < 8; x_ind++) {
                    ChessPiece *tempPiece = gameboard.getPieceatPos(x_ind, y_ind);
                    if (tempPiece->getSide() == WHITE) {
                        sf::Sprite piece = whiteTextureMap[tempPiece->getName()];
                        piece.setPosition(x_ind * 100, y_ind * 100);
                        piece.setScale(.125,.125);
                    }
                }
            }
        }


        window.display();

    }
    return 0;
}
