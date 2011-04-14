/******************************************************
	Game.cpp

	This is the implementation file for the Game 
	class.
******************************************************/

#include "Game.h"

Game::Game() : screen(0)
{
	//create player and set other pointers to null
	gPlayer = new Player();
	gComputer = 0;
	gBoard = 0;

	//set initial game state
	setState(0);

	//dynamically allocate sprite objects
	introBG = new Sprite();
	loginBG = new Sprite();
	startMenuBG = new Sprite();
	setPieceBG = new Sprite();
	playGameBG = new Sprite();
	endGameBG = new Sprite();
	menuBG = new Sprite();
	statisticsBG = new Sprite();
}

//******************************************
Game::~Game()
{
	//delete dynamically allocated sprites
	delete introBG;
	delete loginBG;
	delete startMenuBG;
	delete setPieceBG;
	delete playGameBG;
	delete endGameBG;
	delete menuBG;
	delete statisticsBG;

	//delete selector and string input
	delete gSelector;
	delete name;

	//delete piece buttons
	delete bombButton;
	delete captainButton;
	delete colonelButton;
	delete flagButton;
	delete generalButton;
	delete lieutenantButton;
	delete majorButton;
	delete marshalButton;
	delete minerButton;
	delete scoutButton;
	delete sergeantButton;
	delete spyButton;
}

//******************************************
void Game::startGame()
{
	//create player, computer, and board
	gComputer = new Computer();
	gBoard = new Board();

	//temporary piece for creation
	Piece* temp = 0;

	//create emptyspace's and add to appropriate collections
	for(int i = 0; i < 92; i++)
	{
		//if 40 pieces haven't been created
		if(i < 40)
		{
			//add to board's collection along with game's collection
			gBoard->addPiece(temp);
			addPiece(temp);
		}
		//if the first 40 pieces have already been created,
		//only add piece to game's collection
		else
		{
			addPiece(temp);
		}
	}

	//create marshals and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		temp = new Marshal();

		if(i == 0)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create generals and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		temp = new General();

		if(i == 0)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create colonels and add to appropriate collections
	for(int i = 0; i < 4; i++)
	{
		temp = new Colonel();

		if(i < 2)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create majors and add to appropriate collections
	for(int i = 0; i < 6; i++)
	{
		temp = new Major();

		if(i < 3)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create captains and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		temp = new Captain();

		if(i < 4)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create lieutenants and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		temp = new Lieutenant();

		if(i < 4)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create sergeants and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		temp = new Sergeant();

		if(i < 4)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create miners and add to appropriate collections
	for(int i = 0; i < 10; i++)
	{
		temp = new Miner();

		if(i < 5)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create scouts and add to appropriate collections
	for(int i = 0; i < 16; i++)
	{
		temp = new Scout();

		if(i < 8)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create spys and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		temp = new Spy();

		if(i == 0)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create bombs and add to appropriate collections
	for(int i = 0; i < 12; i++)
	{
		temp = new Bomb();

		if(i < 6)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}

	//create flags and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		temp = new Flag();

		if(i == 0)
		{
			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			addPiece(temp);
			gComputer->addPiece(temp);
		}
	}
}

//******************************************
std::string Game::promptName()
{
	return "placeholder";
}

//******************************************
void Game::resetGame()
{
}

//******************************************
bool Game::findPiece() const
{
	return false;
}

//******************************************
bool Game::setPiece()
{
	return false;
}

//******************************************
bool Game::movePiece()
{
	return false;
}

//******************************************
void Game::swapLocation()
{
}

//******************************************
void Game::namePiece()
{
}

//******************************************
void Game::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//******************************************
std::string Game::getPieceName() const
{
	return "placeholder";
}

//******************************************
void Game::loadMenu()
{
}

//******************************************
SDL_Rect* Game::getMouseCoords()
{
	SDL_Rect* rect = 0;

	return rect;
}

//******************************************
/*Piece* Game::getNewLocationPiece() const
{
}*/

//******************************************
void Game::displayStatistics() const
{
}

//******************************************
void Game::displayResults() const
{
}

//******************************************
void Game::clearPieces()
{
}

//******************************************
bool Game::initialize()
{
	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//initialize SDL_ttf
	if(TTF_Init() == -1)
	{
		return false;
	}

	//set up screen
	setScreen(SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE));

	SDL_WM_SetCaption("strategOO", "strategOO");

	//load images
	if(!introBG->load("intro.png"))
	{
		return false;
	}

	if(!loginBG->load("login.png"))
	{
		return false;
	}

	if(!startMenuBG->load("startmenu.png"))
	{
		return false;
	}

	if(!setPieceBG->load("board.png"))
	{
		return false;
	}

	if(!playGameBG->load("board.png"))
	{
		return false;
	}

	if(!endGameBG->load("endGame.png"))
	{
		return false;
	}

	if(!menuBG->load("ingamemenu.png"))
	{
		return false;
	}

	if(!statisticsBG->load("statistics.png"))
	{
		return false;
	}

	//create selector
	gSelector = new Selector();

	//create string input
	name = new StringInput();

	//create piece buttons
	bombButton = new PieceButton(0, 500, "bombbutton.png", "overlay.png");
	captainButton = new PieceButton(0, 200, "captainbutton.png", "overlay.png");
	colonelButton = new PieceButton(0, 100, "colonelbutton.png", "overlay.png");
	flagButton = new PieceButton(0, 550, "flagbutton.png", "overlay.png");
	generalButton = new PieceButton(0, 50, "generalbutton.png", "overlay.png");
	lieutenantButton = new PieceButton(0, 250, "lieutenantbutton.png", "overlay.png");
	majorButton = new PieceButton(0, 150, "majorbutton.png", "overlay.png");
	marshalButton = new PieceButton(0, 0, "marshalbutton.png", "overlay.png");
	minerButton = new PieceButton(0, 350, "minerbutton.png", "overlay.png");
	scoutButton = new PieceButton(0, 400, "scoutbutton.png", "overlay.png");
	sergeantButton = new PieceButton(0, 300, "sergeantbutton.png", "overlay.png");
	spyButton = new PieceButton(0, 450, "spybutton.png", "overlay.png");

	if(getScreen() == 0)
	{
		return false;
	}

	return true;
}

//******************************************
void Game::cleanUp()
{
	//quit SDL_ttf
	TTF_Quit();

	//quit SDL
	SDL_Quit();
}
//******************************************
void Game::setState(int gameState)
{
	//state must be a number from 0 to 8
	if(gameState > -1 && gameState < 9)
	{
		gameState_ = gameState;
	}
}

//******************************************
void Game::showIntro() const
{
	introBG->show(getScreen());
}

//******************************************
void Game::showLogin() const
{
	loginBG->show(getScreen());
}

//******************************************
void Game::showStartMenu() const
{
	startMenuBG->show(getScreen());
}

//******************************************
void Game::showSetPiece() const
{
	setPieceBG->show(getScreen());
}

//******************************************
void Game::showPlayGame() const
{
	playGameBG->show(getScreen());
}

//******************************************
void Game::showEndGame() const
{
	endGameBG->show(getScreen());
}

//******************************************
void Game::showInGameMenu() const
{
	menuBG->show(getScreen());
}

//******************************************
void Game::showStatistics() const
{
	statisticsBG->show(getScreen());
}

//******************************************
bool Game::render() const
{
	if(SDL_Flip(getScreen()) == -1)
	{
		return false;
	}
	
	return true;
}

//******************************************
void Game::setScreen(SDL_Surface* s)
{
	//delete old screen
	SDL_FreeSurface(screen);

	if(s != 0)
	{
		screen = s;
	}
}

//******************************************
bool Game::doIntro()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				setState(STATE_LOGIN);
			}
		}
	}

	//apply the intro image to the screen
	showIntro();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::login()
{
	bool isLoggingIn = true;

	while(isLoggingIn)
	{
		while(SDL_PollEvent(&gEvent))
		{
			//if the user has exited the window
			if(gEvent.type == SDL_QUIT)
			{
				//set next state to exit
				setState(STATE_EXIT);

				isLoggingIn = false;
			}
			//else if the user has hit the enter key
			else if(gEvent.type == SDL_KEYDOWN)
			{
				if(gEvent.key.keysym.sym == SDLK_RETURN)
				{
					setState(STATE_STARTMENU);

					isLoggingIn = false;
				}
			}

			handleNameInput(gEvent);
		}

		//apply the login image to the screen
		showLogin();

		//apply input text to screen
		showNameInput();

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}
	
	//create new player with name that was input
	gPlayer = new Player(name->getInput());

	return true;
}

//******************************************
bool Game::doStartMenu()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
				
		//handle start menu selector input
		handleSelectorInput(gEvent);

		//if the user has hit the enter key
		if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				if(getSelectorChoice() == 0)
				{
					setState(STATE_SETPIECE);

					resetSelector();
				}
				else if(getSelectorChoice() == 1)
				{
					setState(STATE_STATISTICS);

					resetSelector();
				}
			}
		}
	}

	//move the selector
	moveSelector();

	//apply the start menu image and selector image to the screen
	showStartMenu();
	showSelector();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doSetPiece()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				setState(STATE_PLAYGAME);
			}
		}
	}

	//apply the start menu image to the screen
	showSetPiece();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doPlayGame()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				setState(STATE_ENDGAME);
			}
		}
	}

	//apply the start menu image to the screen
	showPlayGame();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doEndGame()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				//reset the game
				setState(STATE_MENU);
			}
		}
	}

	//apply the end game image to the screen
	showEndGame();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doInGameMenu()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
				
		//handle start menu selector input
		handleSelectorInput(gEvent);

		//if the user has hit the enter key
		if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				if(getSelectorChoice() == 0)
				{
					setState(STATE_STATISTICS);

					resetSelector();
				}
				else if(getSelectorChoice() == 1)
				{
					setState(STATE_STARTMENU);

					resetSelector();
				}
			}
		}
	}

	//move the selector
	moveSelector();

	//apply the start menu image and selector image to the screen
	showInGameMenu();
	showSelector();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doStatistics()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the enter key was pressed
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				//set state to start menu
				setState(STATE_INTRO);
			}
		}
	}

	//apply the statistics image and messages to the screen
	showStatistics();

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
void Game::handleSelectorInput(SDL_Event& gEvent)
{
	gSelector->handleInput(gEvent);
}

//******************************************
void Game::moveSelector() const
{
	gSelector->move();
}

//******************************************
void Game::showSelector() const
{
	gSelector->show(screen);
}

//******************************************
void Game::resetSelector()
{
	gSelector->reset();
}
//******************************************
void Game::handleNameInput(SDL_Event& gEvent)
{
     name->handleInput(gEvent);
}
//******************************************
void Game::showNameInput() const
{
     name->show(getScreen());
}
