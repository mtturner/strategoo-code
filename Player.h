/******************************************************
	Player.h

	This is the header file for the Player class.
******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include <string>
#include <vector>
#include "Statistics.h"
#include "Piece.h"

using namespace std;

class Player
{
public:
	Player();
	Player(std::string& currentPlayer);
	~Player();

	void setName(const std::string& newPlayer);
	void addPiece(Piece* piece);
	void clearPiece(const int boardSpace);
	void clearPieces();
	Piece* findUnplacedPiece(const int buttonRank);
	bool loadStatistics();
	bool saveStatistics();
	void displayStatistics(SDL_Surface* background) const;
	void setStatisticsSprites();

private:
	std::string name;
	std::vector<Piece*> pieces;
	Statistics* stats;
};

#endif
