#include"SDL.h"
#include<string>
#include<vector>
#include"Sprite.h"
#include"Piece.h"
#include"Game.h"

Game::Game() : screen(0)
{
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
}

void Game::login()
{
}

void Game::startGame()
{
}

std::string Game::promptName()
{
	return "placeholder";
}

void Game::resetGame()
{
}

bool Game::findPiece() const
{
	return false;
}

bool Game::setPiece()
{
	return false;
}

bool Game::movePiece()
{
	return false;
}

void Game::swapLocation()
{
}

void Game::namePiece()
{
}

void Game::addPiece()
{
}

std::string Game::getPieceName() const
{
	return "placeholder";
}

void Game::loadMenu()
{
}

SDL_Rect* Game::getMouseCoords()
{
	SDL_Rect* rect = NULL;

	return rect;
}

/*Piece* Game::getNewLocationPiece() const
{
}*/

void Game::displayStatistics() const
{
}

void Game::displayResults() const
{
}

void Game::clearPieces()
{
}

//******************************************
bool Game::initialize()
{
	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//set up screen
	setScreen(SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE));

	SDL_WM_SetCaption("strategOO", "strategOO");

	//load images
	if(!introBG->load("intro.bmp"))
	{
		return false;
	}

	if(!loginBG->load("login.bmp"))
	{
		return false;
	}

	if(!startMenuBG->load("startMenu.bmp"))
	{
		return false;
	}

	if(!setPieceBG->load("setPiece.bmp"))
	{
		return false;
	}

	if(!playGameBG->load("playGame.bmp"))
	{
		return false;
	}

	if(!endGameBG->load("endGame.bmp"))
	{
		return false;
	}

	if(!menuBG->load("menu.bmp"))
	{
		return false;
	}

	if(!statisticsBG->load("statistics.bmp"))
	{
		return false;
	}

	if(getScreen() == NULL)
	{
		return false;
	}

	return true;
}

//******************************************
void Game::cleanUp()
{
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

	if(s != NULL)
	{
		screen = s;
	}
}

//******************************************
void Game::handleStartSelectorInput()
{
}

//******************************************
void Game::handleMenuSelectorInput()
{
}
