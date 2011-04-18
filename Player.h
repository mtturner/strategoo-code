/******************************************************
	Player.h

	This is the header file for the Player class.
******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
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
	void clearPiece();
	void clearPieces();
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
