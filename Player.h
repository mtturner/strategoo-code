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
	Player(std::string& currentPlayer);
	~Player();

	//collection functions
	void addPiece(Piece* piece);
	void clearPiece();
	void clearPieces();
	Piece* findUnplacedPiece(const int rank);

	void setName(const std::string& newPlayer);

	//statistics functions
	bool loadStatistics();
	bool saveStatistics();
	void displayStatistics() const;

private:
	std::string name;
	std::vector<Piece*> pieces;
	Statistics* stats;
};

#endif
