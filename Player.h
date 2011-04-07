/******************************************************
	Player.h

	This is the header file for the Player class.
******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Statistics.h"
#include "Piece.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	void clearPiece();
	void clearPieces();
	bool loadStatistics();
	bool saveStatistics();
	void displayStatistics() const;

private:
	std::string name;
	std::vector<Piece*> pieces;
	//Statistics* stats;
};

#endif
