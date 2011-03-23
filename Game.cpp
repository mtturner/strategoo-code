#include "SDL.h"
#include <string>
#include"Sprite.h"
#include "Game.h"

using namespace std;

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

string Game::promptName()
{
	return "placeholder";
}

void Game::resetGame()
{
}

bool Game::findPiece() const
{
	return 0;
}

bool Game::setPiece()
{
	return 0;
}

bool Game::movePiece()
{
	return 0;
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

string Game::getPieceName() const
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

/*Piece Game::getNewLocationPiece() const
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
	if(!introBG->load("intro.png"))
	{
		return false;
	}

	if(!loginBG->load("login.png"))
	{
		return false;
	}

	if(!startMenuBG->load("startMenu.png"))
	{
		return false;
	}

	if(!setPieceBG->load("setPiece.png"))
	{
		return false;
	}

	if(!playGameBG->load("playGame.png"))
	{
		return false;
	}

	if(!endGameBG->load("endGame.png"))
	{
		return false;
	}

	if(!menuBG->load("menu.png"))
	{
		return false;
	}

	if(!statisticsBG->load("statistics.png"))
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
	delete screen;

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