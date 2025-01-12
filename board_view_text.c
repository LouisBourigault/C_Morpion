#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
  //this is the constructor of this module
}

void BoardView_free (void)
{
  //nothing to complete ?
}

void BoardView_displayAll (void)
{
  // FIX => voir si modification ? coordinate => int usinf coordinate ?
  /**
 * Displays sthe entire board (including background) at current status.
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
    #ifndef CONFIG_PLAYER_MANAGER_MOCK//If we don't use the mock
	    clear();                      // clear the console
    #endif
	    BoardView_displayAll();//display the board
	    bool is_draw = false;
	    if (result == CIRCLE_WINS) {// Circle wins
		    printf("Circle Wins\n");
        printf("██     ██ ██ ███    ██ \n██     ██ ██ ████   ██ \n██  █  ██ ██ ██ ██  ██ \n██ ███ ██ ██ ██  ██ ██ \n ███ ███  ██ ██   ████ \n");

	    } else if (result == CROSS_WINS) {// If cross wins
		    printf("Cross Wins\n");
        printf("██     ██ ██ ███    ██ \n██     ██ ██ ████   ██ \n██  █  ██ ██ ██ ██  ██ \n██ ███ ██ ██ ██  ██ ██ \n ███ ███  ██ ██   ████ \n");

	     else {
		    is_draw = true;//save that is a draw
		    printf("________ __________    _____  __      __ \n"
		       "\\______ \\\\______   \\  /  _  \\/  \\    /  \\\n"
		       " |    |  \\|       _/ /  /_\\  \\   \\/\\/   /\n"
		       " |    `   \\    |   \\/    |    \\        / \n"
		       "/_______  /____|_  /\\____|__  /\\__/\\  /  \n"
		       "        \\/       \\/         \\/      \\/ \n");
		    //display a message
	    }      

      //print the winner of the game
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  //diplaye the player who will played

  switch (thisPlayer)
  {
    case CROSS:
      printf("It's cross turn \n");
    break;
    case CIRCLE :
      printf("It's circle turn \n");
    break;
  } 
}

void BoardView_sayCannotPutPiece (void)
{
  printf("This place is already occupied");
  //said if the square is already occupied
}

#endif // defined CONFIG_TEXTUI
