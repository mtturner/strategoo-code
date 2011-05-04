/******************************************************
	Game.h

	This is the header file for the Game class.
******************************************************/

#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
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
#include "Sound.h"

class Game
{
public:
	//constructor and destructor
	Game();
	~Game();

	//getters and setters
	inline int getState() const;
	void setState(const int gameState);
	inline int getPreviousState() const;
	void setPreviousState(const int gameState);
	inline int getTurn() const;
	void setTurn(const int turn);
	inline SDL_Surface* getScreen() const;
	void setScreen(SDL_Surface* s);
	inline bool getIsPieceSelected() const;
	void setIsPieceSelected(const bool selected);
	inline bool getIsButtonSelected() const;
	void setIsButtonSelected(const bool selected);

	//start up, closing, and render
	bool initialize();
	void cleanUp() const;
	bool render() const;

	//main loop functions
	bool doIntro();
	bool login();
	bool doStartMenu();
	bool doSetPiece();
	bool doPlayGame();
	bool doInGameMenu();
	bool doStatistics();

	//game functions
	void startGame();
	void resetGame();
	bool checkPlayerWins();
	bool checkComputerWins();

	//collection functions
	void addPiece(Piece* const piece);
	inline void clearPieces();

	//piece functions
	Piece* findEmptySpacePiece();
	void swapLocation(Piece* const first, Piece* const second) const;
	bool isMoveablePiece(Piece* const selected, const int mover) const;
	bool isValidMove(Piece* const selected, Piece* const destination) const;
	void moveComputerPiece();

	//play-by-play
	void updatePlayByPlay(Piece* const first, Piece* const sencond, 
						  const int mover, const int winner) const;
	void updatePlayByPlay(Piece* const moved, Piece* const destination, 
		                  const int mover) const;
	void updateComputerPlayByPlay(Piece* const moved, 
		                          Piece* const destination) const;
	void shiftPlayByPlayDown() const;
	void resetPlayByPlay() const;

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
	//sprite for naming pieces
	Sprite* namePieceBG;

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

	//sound player
	Sound* gameSound;

	//current and previous game states
	int gameState_,
		previousState_;

	//turn
	int turn_;

	//piece buttons for set piece
	PieceButton* buttons[12];

	//selected bools
	bool isPieceSelected,
		 isButtonSelected;

	//enumeration of all game states
	enum GameStates {STATE_INTRO, STATE_LOGIN, STATE_STARTMENU,
		             STATE_SETPIECE, STATE_PLAYGAME, STATE_MENU,
					 STATE_STATISTICS, STATE_EXIT};
};

//*****************************************************
inline int Game::getState() const
{
	return gameState_;
}

//*****************************************************
inline int Game::getPreviousState() const
{
	return previousState_;
}

//*****************************************************
inline int Game::getTurn() const
{
	return turn_;
}

//*****************************************************
inline SDL_Surface* Game::getScreen() const
{
	return screen;
}

//*****************************************************
inline bool Game::getIsPieceSelected() const
{
	return isPieceSelected;
}

//*****************************************************
inline bool Game::getIsButtonSelected() const
{
	return isButtonSelected;
}

//*****************************************************
inline void Game::clearPieces()
{
	pieces.clear();
}

#endif
