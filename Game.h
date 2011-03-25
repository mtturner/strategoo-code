#ifndef GAME_H
#define GAME_H

// This is the main controller class header file

//class Piece;
//class Player;

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
	//Piece getNewLocationPiece() const;
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
	void handleMenuSelectorInput();
	void handleStartSelectorInput();

private:

	Sprite* introBG;
	Sprite* loginBG;
	Sprite* startMenuBG;
	Sprite* setPieceBG;
	Sprite* playGameBG;
	Sprite* endGameBG;
	Sprite* menuBG;
	Sprite* statisticsBG;

	SDL_Surface* screen;
	
	int gameState_;

	//game's collection of pieces
	std::vector<Piece*> pieces;

	//Player* gPlayer;
	//Computer* gComputer;

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

#endif GAME_H