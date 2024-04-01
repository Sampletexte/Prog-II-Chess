#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "/Board/Board.h"




int main() {
    sf::Texture board,wp,wr,wb,wn,wq,wk,bp,br,bb,bn,bq,bk;
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

    sf::Sprite chessBoard;
    chessBoard.setTexture(board);
    chessBoard.setScale(.68493150684,.68610634648 );
    sf::Sprite whitePawn;
    whitePawn.setTexture(wp);
    sf::Sprite whiteBishop;
    whiteBishop.setTexture(wb);


    Board gameboard;


    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess 2: The Sequel");
    sf::Event event;
    while (window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            window.clear();
            window.draw(chessBoard);
            for(int y_ind = 0; y_ind < 8; y_ind++ ){
                for(int x_ind = 0; x_ind < 8; x_ind++ ){
                    ChessPiece *tempPiece = gameboard.getPieceatPos(x_ind,y_ind);
                    if(tempPiece->getSide() == WHITE){
                        switch(tempPiece->getName()){

                        }
                    }
                }
            }
            whitePawn.setPosition(100,700);
            whitePawn.setScale(.125,.125);
            window.display();




        }
    }


    return 0;
}
