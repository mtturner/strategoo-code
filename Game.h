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
#include "Sprite.h"
#include "Piece.h"
#include "Selector.h"
#include "StringInput.h"

class Game
{
public:
	Game();
	~Game();

	void login();
	void startGame();
	std::string promptName();
	void resetGame();
	bool findPiece() const;
	bool setPiece();
	bool movePiece();
	void swapLocation();
	void namePiece();
	void addPiece();
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

	//selector functions
	void handleSelectorInput(SDL_Event& gEvent);
	void moveSelector() const;
	void showSelector() const;
	inline int getSelectorChoice() const;
	void resetSelector();

	//String input functions
	void handleNameInput(SDL_Event& gEvent);
	void showNameInput() const;

private:
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

	SDL_Surface* screen;

	StringInput* name;
	
	int gameState_;
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
