/******************************************************
	Game.h

	This is the header file for the Game class.
******************************************************/

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
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
	std::string getPieceName() const;
	void loadMenu();
	SDL_Rect* getMouseCoords();
	//Piece* getNewLocationPiece() const;
	void displayStatistics() const;
	void displayResults() const;
	bool initialize();
	void cleanUp();
	void setState(int gameState);
	bool render() const;
	void setScreen(SDL_Surface* s);
	bool checkPlayerWins();
	bool checkComputerWins();

	//play-by-play
	void updatePlayByPlay(int firstRank, int secondRank, int mover, int winner);
	void updatePlayByPlay(int firstRank, int mover);
	void updateComputerPlayByPlay();
	void shiftPlayByPlayDown();

	//piece functions
	void namePiece();
	bool findPiece() const;
	Piece* findEmptySpacePiece();
	bool setPiece();
	void swapLocation(Piece* first, Piece* second);
	bool movePiece();
	bool isMoveablePiece(Piece* selected, int mover);
	bool isValidMove(Piece* selected, Piece* destination);
	void moveComputerPiece();

	//collection functions
	void addPiece(Piece* piece);
	void clearPieces();

	//getters and setters
	inline int getState() const;
	inline SDL_Surface* getScreen() const;
	inline bool getIsPieceSelected() const;
	void setIsPieceSelected(const bool selected);
	inline bool getIsButtonSelected() const;
	void setIsButtonSelected(const bool selected);

	//main loop functions
	bool doIntro();
	bool login();
	bool doStartMenu();
	bool doSetPiece();
	bool doPlayGame();
	bool doEndGame();
	bool doInGameMenu();
	bool doStatistics();

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

	//piece and piece button overlays
	Sprite* pieceOverlay;
	Sprite* buttonOverlay;

	//sprite for set piece finish
	Sprite* finishedSetPiece;

	//sprites for winner of game
	Sprite* playerWinsImage;
	Sprite* computerWinsImage;

	//play-by-play sprites
	Sprite* playByPlayHeader;
	Sprite* playByPlayArea;
	Sprite* playByPlayOne;
	Sprite* playByPlayTwo;
	Sprite* playByPlayThree;
	Sprite* playByPlayFour;
	Sprite* playByPlayFive;
	Sprite* playByPlaySix;
	Sprite* playByPlaySeven;
	Sprite* playByPlayEight;
	Sprite* playByPlayNine;

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

	//selected bools
	bool isPieceSelected,
		 isButtonSelected;

	//enumeration of all game states
	enum GameStates {STATE_INTRO, STATE_LOGIN, STATE_STARTMENU,
		             STATE_SETPIECE, STATE_PLAYGAME, STATE_ENDGAME,
					 STATE_MENU, STATE_STATISTICS, STATE_EXIT};
};

//******************************************
inline int Game::getState() const
{
	return gameState_;
}

//******************************************
inline SDL_Surface* Game::getScreen() const
{
	return screen;
}

//******************************************
inline bool Game::getIsPieceSelected() const
{
	return isPieceSelected;
}

//******************************************
inline bool Game::getIsButtonSelected() const
{
	return isButtonSelected;
}

#endif
