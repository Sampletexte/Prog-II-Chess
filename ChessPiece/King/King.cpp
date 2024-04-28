//
// Created by sochin1519 on 3/25/2024.
//

#include "King.h"

King::King():ChessPiece() {
    name = 'k';
}


/**
 * Remove duplicates. This isn't the most effiecient code.
 * Removes duplicates by using the fact that map's can only have 1 key.
 * @param pointLst - A reference to the pointlist that will be operated on
 */
void King::removeDuplicates(std::vector<Point> &pointLst) {
    auto comp = [](const Point& p1, const Point& p2){
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    };
    std::map<Point, int, decltype(comp)> uniquePoints(comp);

    // The duplicate points will overwrite each other
    for( auto pnt : pointLst ) {
        uniquePoints.insert( {pnt, 0} );
    }

    // Add all of the keys to the output vector
    pointLst.clear();
    for(auto iter = uniquePoints.begin(); iter != uniquePoints.end(); ++iter)
        pointLst.push_back(iter->first);
}

/**
 * Removes all of the points in pointLst that are in pointsToRem
 * @param pointLst - The list to remove points from
 * @param pointsToRem - The list of points to remove
 */
void King::removePoints(std::vector<Point> &pointLst, std::vector<Point> &pointsToRem) {
    auto comp = [](const Point& p1, const Point& p2){
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    };
    std::map<Point, int, decltype(comp)> uniquePoints(comp);

    // Create a map for quick loopup
    for( auto pnt : pointLst ) {
        uniquePoints.insert( {pnt, 0} );
    }

    // Remove all of the unwanted keys( Points )
    for( auto pnt : pointsToRem)
        uniquePoints.erase( pnt );

    // Add all of the keys to the output vector
    pointLst.clear();
    for(auto iter = uniquePoints.begin(); iter != uniquePoints.end(); ++iter)
        pointLst.push_back(iter->first);
}

/**
 * Check if the king is in check on the gameboard
 * @param gameboard - The current chessboard
 * @param posX - Teh position of the king
 * @param posY - The position of the king
 * @return - A bool representing if the king is in check on the gameboard
 */
bool King::isInCheck(std::vector<std::vector<ChessPiece *>> *gameboard) {
    std::vector<Point> allPosEnmyMovs = getAllMoves(gameboard); // Get all moves the enemy can make

    auto it = std::find_if(allPosEnmyMovs.begin(), allPosEnmyMovs.end(), [this](Point s) { return(pos.x == s.x && pos.y == s.y); } );

    // Check if the King's position is in the array of possible moves
    if( it != allPosEnmyMovs.end()) {
        /* allPosEnmyMovs has the king's position */
        return true;
    } else {
        /* allPosEnmyMovs does not have the king's position */
        return false;
    }
}


/**
 * Gets all of the moves possible of all pieces. This is used to calculate check
 * @param gameboard - The current chessboard
 * @param posX - Teh position of the king
 * @param posY - The position of the king
 * @return List of all possible attacks the enemy can do.
 */
std::vector<Point> King::getAllMoves(std::vector<std::vector<ChessPiece *>> *gameboard) {
    std::vector<Point> allPosEnmyMovs;

    // Iterate though the entire gameboard and if there is an enemy piece, add it to the allPosEnmyMovs array
    for( int y=0; y < 8; y++ ) {
        for( int x=0; x < 8; x++ ) {
            if( (*gameboard)[y][x]->getSide() == -side && (x != pos.x && y != pos.y ) ) {  // If it is an enemy piece add it's possible moves to the list. Skip over the king in question
                if( (*gameboard)[y][x]->getName() == 'k' ) {    // If the point location is the enemy king
                    // Add all of the cells surrounding the enemy king. It doesn't matter if it is out of bounds as it can never be moved to
                    std::vector<Point> movs = {
                            {x-1,y-1},{x,y-1},{x+1,y-1},
                            {x-1,y},{x+1,y},
                            {x-1,y+1},{x,y+1},{x+1,y+1}
                    };
                    allPosEnmyMovs.insert(std::end(allPosEnmyMovs), std::begin(movs),std::end(movs));  // Extend the movs to the end of the array
                } else {
                    ChessPiece *piece = (*gameboard)[y][x];
                    std::vector<Point> movs = (*gameboard)[y][x]->getPossibleMoves(gameboard, x, y);
                    allPosEnmyMovs.insert(std::end(allPosEnmyMovs), std::begin(movs),std::end(movs));  // Extend the movs to the end of the array
                }
            }
        }
    }

    // Remove duplicates
    removeDuplicates(allPosEnmyMovs);

    return allPosEnmyMovs;
}

/**
 *
 * @param gameboard - The current chess board
 * @param posX - The position of the king
 * @param posY - The position of the king
 * @return - A list of cells that the piece can move to.
 */
std::vector<Point> King::getPossibleMoves(std::vector<std::vector<ChessPiece *>> *gameboard, int posX, int posY) {
    std::vector<Point> posMovs;
    std::vector<Point> posAtt;  // Possible attacks that a king can do. For

    // Iterate around the king
    for(int yOffset = -1; yOffset <= 1; ++yOffset) {
        for(int xOffset = -1; xOffset <= 1; ++xOffset) {
            if( !(posY+yOffset < 0 || posY+yOffset > 7) && !(posX+xOffset < 0 || posX+xOffset > 7) ) {  // If in bounds
                ChessPiece *piece = (*gameboard)[posY+yOffset][posX+xOffset];

                // Add the cell as a possible move or attack, depending on the piece's side.
                if (piece->getSide() == NO_PIECE) { // If there is no piece then it is an possible move
                    Point pnt{posX+xOffset, posY+yOffset};
                    posMovs.push_back(pnt);
                } else if(piece->getSide() == -side) { // If there is a piece then it is a possible attack
                    Point pnt{posX+xOffset, posY+yOffset};
                    posAtt.push_back(pnt);
                }
            }
        }
    }

    std::vector<Point> allEnemyMoves = getAllMoves(gameboard);

    // Remove all moves that the king could make that overlap with enemy attack rays
    removePoints( posMovs, allEnemyMoves);

    posMovs.insert(std::end(posMovs), std::begin(posAtt), std::end(posAtt));  // Extend the posMovs to the end of the array


    return posMovs;
}


