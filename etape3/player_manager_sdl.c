/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <SDL.h>
#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_SDL

void PlayerManager_init (void)
{
	assert (SDL_WasInit (SDL_INIT_VIDEO) != 0);
}

void PlayerManager_free (void)
{
}

static bool tryMove (int x, int y)
{

  if (x < 3 && x >= 0 && y < 3 && y >= 0) {// Check if coordinate are valid
		//if the square is empty
		if (Board_putPiece(x, y, thisPlayer) == PIECE_IN_PLACE) {
			return true;
		} else {
			BoardView_sayCannotPutPiece();//else display msg
			return false;
		}
	}
}

void PlayerManager_oneTurn (void)
{
	int error;
	SDL_Event event;
	bool validMove;

	do
	{
		validMove = false;
		error = SDL_WaitEvent (&event);
		assert (error == 1);
		switch (event.type)
		{
			case SDL_WINDOWEVENT:
				//if user ask to close the windows
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					validMove = true;      //go out the loop
					TemoinFinPartie = true;//end the game loop which will lead
					                       // to the end of the program
				}
				break;
			case SDL_MOUSEBUTTONDOWN: //in case of mouse click
				SDL_GetMouseState(&xMouse, &yMouse);//get mouse position
				xMouse = xMouse / 158;//get valid coordinate
				yMouse = yMouse / 158;//get valid coordinate
				validMove = tryMove(xMouse, yMouse);//check if the move is valid
				BoardView_displayAll();//display the board
				break;
		}
	}
	while (!validMove);
	//switch player
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
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
