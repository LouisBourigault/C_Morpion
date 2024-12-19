#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
  // TODO:  => voir si modification ? coordinate => int usinf coordinate ?
  /**
 * Displays the entire board (including background) at current status.
 */

  printf("AFFICHAGE DE LA GRILLE \n"); 

   for(int i=0; i<3; i++)
   { 
      for(int j=0; j<3; j++)
      {
        printf("|   ");
      }
      printf("|\n");
      printf("-------------\n");
    }

}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  // TODO: à compléter

  **
 * Displays a message to the user at the end of the game.
 *
 * @param [in] result winning status
 */

  char winner; 

  switch (result)
  {
  case DRAW:
  //case both lose (if all the case are fill => nobody can win )
    strcpy(winner,"nobody")
    break;
   case CIRCLE:
    strcpy(winner,"circle")
    break;
  case CROSS:
    strcpy(winner,"cross")
    break;
  } 

  //print the winner of the game
  
  

}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  // TODO: à compléter
}

void BoardView_sayCannotPutPiece (void)
{
  // TODO: à compléter
}

#endif // defined CONFIG_TEXTUI
