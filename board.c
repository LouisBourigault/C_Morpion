#include "board.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */

// Déclaration d'un tableau vide de trois pointeurs de PieceType
static PieceType (*boardSquares)[3];

static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    assert(lastChangeX >= 0 && lastChangeX < 3);
    assert(lastChangeY >= 0 && lastChangeY < 3);
    assert(gameResult != NULL);
    PieceType piece = boardSquares[lastChangeX][lastChangeY];
    // Check rows
    if (boardSquares[0][lastChangeY] == piece && boardSquares[1][lastChangeY] == piece && boardSquares[2][lastChangeY] == piece) {
        *gameResult = (piece == CROSS) ? CROSS_WINS : CIRCLE_WINS;
        return true;
    }
    // Check columns
    if (boardSquares[lastChangeX][0] == piece && boardSquares[lastChangeX][1] == piece && boardSquares[lastChangeX][2] == piece) {
        *gameResult = (piece == CROSS) ? CROSS_WINS : CIRCLE_WINS;
        return true;
    }
    // Check diagonal up left to down right
    if (lastChangeX == lastChangeY &&
        boardSquares[0][0] == piece && boardSquares[1][1] == piece && boardSquares[2][2] == piece) {
        *gameResult = (piece == CROSS) ? CROSS_WINS : CIRCLE_WINS;
        return true;
    }
    // Check diagonal down left to up right
    if (lastChangeX + lastChangeY == 2 &&
        boardSquares[0][2] == piece && boardSquares[1][1] == piece && boardSquares[2][0] == piece) {
        *gameResult = (piece == CROSS) ? CROSS_WINS : CIRCLE_WINS;
        return true;
    }
    // Check for draw (board full)
    bool isDraw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (boardSquares[i][j] == NONE) {
                isDraw = false;
                break;
            }
        }
    }
    if (isDraw) {
        *gameResult = DRAW;
        return true;
    }
    return false;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
    for (int i=0; i<3; i++){
        for (int j; j<3; j++){
            boardSquares[i][j]=NONE; //Init board with none case
            onSquareChange(i,j,NONE);
        }
    }
    onEndOfGame(false);
}

void Board_free ()
{
    free(boardSquares);
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    assert(x>=0 && x<3);
    assert(y>=0 && y<3);
    assert(kindOfPiece==CROSS || kindOfPiece==CIRCLE);
    return boardSquares[x][y]=kindOfPiece;
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
    return boardSquares[x][y];
}
