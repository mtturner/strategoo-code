/******************************************************
	Player.h

	This is the header file for the Player class.
******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include"Statistics.h"
#include"Piece.h"

class Player
{
public:
	Player();
	~Player();

	void clearPiece();
	void clearPieces();
	void loadStatistics();
	void displayStatistics() const;

private:
	std::string name;
	std::vector<Piece*> pieces;
	Statistics* stats;
};

#endif
