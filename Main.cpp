/******************************************************
	Main.cpp

	This is Main for the application.
******************************************************/

#include "SDL.h"
#include "Game.h"

int main(int argc, char* args[]) 
{ 
	//controller object and event structure
	Game controller;
	SDL_Event gEvent;

	//enumeration of all game states
	enum GameStates {STATE_INTRO, STATE_LOGIN, STATE_STARTMENU,
		             STATE_SETPIECE, STATE_PLAYGAME, STATE_ENDGAME,
					 STATE_MENU, STATE_STATISTICS, STATE_EXIT};

	//initialize SDL and load images
	if(!controller.initialize())
	{
		return 1;
	}

	//set initial game state to intro
	controller.setState(STATE_INTRO);

	//main game loop
	while(controller.getState() != STATE_EXIT)
	{
		//state machine
		switch(controller.getState())
		{
		case STATE_INTRO:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the user has hit the enter key
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						controller.setState(STATE_LOGIN);
					}
				}
			}

			//apply the intro image to the screen
			controller.showIntro();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_LOGIN:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the user has hit the enter key
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						controller.setState(STATE_STARTMENU);
					}
				}

				controller.handleNameInput(gEvent);
			}

			//apply the login image to the screen
			controller.showLogin();

			//apply input text to screen
			controller.showNameInput();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_STARTMENU:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				
				//handle start menu selector input
				controller.handleSelectorInput(gEvent);

				//if the user has hit the enter key
				if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						if(controller.getSelectorChoice() == 0)
						{
							controller.setState(STATE_SETPIECE);

							controller.resetSelector();
						}
						else if(controller.getSelectorChoice() == 1)
						{
							controller.setState(STATE_STATISTICS);

							controller.resetSelector();
						}
					}
				}
			}

			//move the selector
			controller.moveSelector();

			//apply the start menu image and selector image to the screen
			controller.showStartMenu();
			controller.showSelector();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_SETPIECE:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the user has hit the enter key
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						controller.setState(STATE_PLAYGAME);
					}
				}
			}

			//apply the start menu image to the screen
			controller.showSetPiece();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_PLAYGAME:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the user has hit the enter key
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						controller.setState(STATE_ENDGAME);
					}
				}
			}

			//apply the start menu image to the screen
			controller.showPlayGame();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_ENDGAME:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the user has hit the enter key
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						//reset the game
						controller.setState(STATE_MENU);
					}
				}
			}

			//apply the end game image to the screen
			controller.showEndGame();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_MENU:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				
				//handle start menu selector input
				controller.handleSelectorInput(gEvent);

				//if the user has hit the enter key
				if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						if(controller.getSelectorChoice() == 0)
						{
							controller.setState(STATE_STATISTICS);

							controller.resetSelector();
						}
						else if(controller.getSelectorChoice() == 1)
						{
							controller.setState(STATE_STARTMENU);

							controller.resetSelector();
						}
					}
				}
			}

			//move the selector
			controller.moveSelector();

			//apply the start menu image and selector image to the screen
			controller.showInGameMenu();
			controller.showSelector();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_STATISTICS:
			while(SDL_PollEvent(&gEvent))
			{
				//if the user has exited the window
				if(gEvent.type == SDL_QUIT)
				{
					//set next state to exit
					controller.setState(STATE_EXIT);
				}
				//else if the enter key was pressed
				else if(gEvent.type == SDL_KEYDOWN)
				{
					if(gEvent.key.keysym.sym == SDLK_RETURN)
					{
						//set state to start menu
						controller.setState(STATE_INTRO);
					}
				}
			}

			//apply the statistics image and messages to the screen
			controller.showStatistics();

			//render to the screen
			//if rendering was unsuccessfull
			if(!controller.render())
			{
				//return 1, closing the program
				return 1;
			}

			break;

		case STATE_EXIT:
			break;
		}
	}

	//clean up SDL and dynamically allocated memory
	controller.cleanUp();
	
	return 0; 
} 
