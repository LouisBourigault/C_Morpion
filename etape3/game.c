/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"
bool TemoinFinPartie;


void Game_SquareChangeCallBack(Coordinate x, Coordinate y,
                               PieceType kindOfPiece)
{
	BoardView_displaySquare(x, y, kindOfPiece);
}

void Game_EndOfGameCallBack(GameResult result)
{
	TemoinFinPartie = true;
	BoardView_displayEndOfGame(result);
}

void Game_init (void)
{
  TemoinFinPartie = true;
  BoardView_displayEndOfGame(Game_SquareChangeCallBack,Game_EndOfGameCallBack);
  Board_init();
  PlayerManager_init();
}

void Game_free (void)
{
  BoardView_free();
  PlayerManager_free();
  Board_free();
}

void Game_loop (void)
{
  PlayerManager_oneTurn();
  while (!TemoinFinPartie)
  {
    PlayerManager_oneTurn();
  }
}    
