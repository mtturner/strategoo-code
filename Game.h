/******************************************************
	Game.h

	This is the header file for the Game class.
******************************************************/

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Computer.h"
#include "Board.h"
#include "Sprite.h"
#include "Piece.h"
#include "Marshal.h"
#include "General.h"
#include "Colonel.h"
#include "Major.h"
#include "Captain.h"
#include "Lieutenant.h"
#include "Sergeant.h"
#include "Miner.h"
#include "Scout.h"
#include "Spy.h"
#include "Bomb.h"
#include "Flag.h"
#include "EmptySpace.h"
#include "Selector.h"
#include "StringInput.h"
#include "PieceButton.h"

class Game
{
public:
	Game();
	~Game();

	void startGame();
	std::string promptName();
	void resetGame();
	bool findPiece() const;
	bool setPiece();
	bool movePiece();
	void swapLocation();
	void namePiece();
	void addPiece(Piece* piece);
	std::string getPieceName() const;
	void loadMenu();
	SDL_Rect* getMouseCoords();
	//Piece* getNewLocationPiece() const;
	void displayStatistics() const;
	void displayResults() const;
	void clearPieces();
	bool initialize();
	void cleanUp();
	void setState(int gameState);
	inline int getState() const;
	void showIntro() const;
	void showLogin() const;
	void showStartMenu() const;
	void showSetPiece() const;
	void showPlayGame() const;
	void showEndGame() const;
	void showInGameMenu() const;
	void showStatistics() const;
	bool render() const;
	inline SDL_Surface* getScreen() const;
	void setScreen(SDL_Surface* s);

	//main loop functions
	bool doIntro();
	bool login();
	bool doStartMenu();
	bool doSetPiece();
	bool doPlayGame();
	bool doEndGame();
	bool doInGameMenu();
	bool doStatistics();

	//selector functions
	void handleSelectorInput(SDL_Event& gEvent);
	void moveSelector() const;
	void showSelector() const;
	inline int getSelectorChoice() const;
	void resetSelector();

	//string input functions
	void handleNameInput(SDL_Event& gEvent);
	void showNameInput() const;

private:
	//SDL_Event structure
	SDL_Event gEvent;

	//player, computer, and board
	Player* gPlayer;
	Computer* gComputer;
	Board* gBoard;

	//game's collection of pieces
	std::vector<Piece*> pieces;

	//game state backgrounds
	Sprite* introBG;
	Sprite* loginBG;
	Sprite* startMenuBG;
	Sprite* setPieceBG;
	Sprite* playGameBG;
	Sprite* endGameBG;
	Sprite* menuBG;
	Sprite* statisticsBG;

	//selector
	Selector* gSelector;

	//screen surface
	SDL_Surface* screen;

	//string input class for login
	StringInput* name;
	
	//current game state
	int gameState_;

	//piece buttons for set piece
	PieceButton* buttons[12];

	//enumeration of all game states
	enum GameStates {STATE_INTRO, STATE_LOGIN, STATE_STARTMENU,
		             STATE_SETPIECE, STATE_PLAYGAME, STATE_ENDGAME,
					 STATE_MENU, STATE_STATISTICS, STATE_EXIT};
};

//******************************************
int Game::getState() const
{
	return gameState_;
}

//******************************************
SDL_Surface* Game::getScreen() const
{
	return screen;
}

//******************************************
inline int Game::getSelectorChoice() const
{
	return gSelector->getChoice();
}

#endif
