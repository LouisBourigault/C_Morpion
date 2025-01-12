/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_MOCK

  PieceType thisPlayer; // to know who need to play
  int i; //variable to browse into test tab

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  #ifdef CONFIG_PLAYER_MANAGER_MOCK
    clear();
  #endif
   //Faire un coup predef => passer au coup suivant 
  #if defined DEF_CIRCLE_WINS
	  //Circle Win test set
	  int test_x[6] = {0, 1, 0, 1, 2, 1};//row
	  int test_y[6] = {0, 0, 1, 1, 2, 2};
  #endif
  #if defined DEF_CROSS_WINS
	  //CROSS Win test set
	  int test_x[5] = {0, 1, 0, 1, 0}; //row
	  int test_y[5] = {0, 0, 1, 1, 2};
  #endif
  #if defined DEF_DRAW
	  //Draw Test set
	  int test_x[9] = {0,0,1,2,1,0,2,1,2};//row
	  int test_y[9] = {1,0,0,1,1,2,0,2,2};
  #endif

  Board_putPiece(test_x[i], test_y[i], thisPlayer); //Put the piece
	// No need to check if the square is empty because we already decide
	// all coordinate

	//next player
	switch (thisPlayer) {
		case CROSS:
			thisPlayer = CIRCLE;
			break;
		case CIRCLE:
			thisPlayer = CROSS;
			break;
		default:
			printf("Error during change of player.");
	}
	i++; // go to the next coordinate
 

}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
