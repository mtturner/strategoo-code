/******************************************************
	Main.cpp

	This is Main for the application.
******************************************************/

#include "SDL/SDL.h"
#include "Game.h"

int main(int argc, char* args[]) 
{ 
	//controller object and event structure
	Game controller;

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
			if(!controller.doIntro())
			{
				return 1;
			}

			break;

		case STATE_LOGIN:
			if(!controller.login())
			{
				return 1;
			}

			break;

		case STATE_STARTMENU:
			if(!controller.doStartMenu())
			{
				return 1;
			}

			break;

		case STATE_SETPIECE:
			if(!controller.doSetPiece())
			{
				return 1;
			}

			break;

		case STATE_PLAYGAME:
			if(!controller.doPlayGame())
			{
				return 1;
			}

			break;

		case STATE_ENDGAME:
			if(!controller.doEndGame())
			{
				return 1;
			}

			break;

		case STATE_MENU:
			if(!controller.doInGameMenu())
			{
				return 1;
			}

			break;

		case STATE_STATISTICS:
			if(!controller.doStatistics())
			{
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
