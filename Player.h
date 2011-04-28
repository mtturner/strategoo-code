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
	//constructors and destructor
	Player();
	Player(std::string& currentPlayer);
	~Player();

	//setters
	inline void setName(const std::string& newPlayer);
	inline void setGamesPlayed(int input) const;
	inline void setGamesWon(const int input) const;
	inline void setGamesLost(const int input) const;
	inline void setFlagsCaptured(const int input) const;
	inline void setCapturedFlags(const int input) const;
	inline void setTimesExtinct(const int input) const;
	inline void setGenocide(const int input) const;

	//collection functions
	void addPiece(Piece* const piece);
	void clearPiece(const int boardSpace);
	inline void clearPieces();
	Piece* findUnplacedPiece(const int buttonRank);
	Piece* findPieceAtPosition(const int position);
	inline int getNumPieces() const;

	//statistics functions
	void setStatisticsSprites() const;
	bool loadStatistics() const;
	bool saveStatistics() const;
	void displayStatistics(SDL_Surface* background) const;

private:
	//player name
	std::string name;

	//collection of pieces
	std::vector<Piece*> pieces;

	//statistics
	Statistics* stats;
};

//*****************************************************
inline void Player::setName(const std::string& newPlayer)
{
	name = newPlayer;
}

//*****************************************************
inline void Player::setGamesPlayed(const int input) const
{
	stats->setGamesPlayed(input);
}

//*****************************************************
inline void Player::setGamesWon(const int input) const
{
	stats->setGamesWon(input);
}

//*****************************************************
inline void Player::setGamesLost(const int input) const
{
	stats->setGamesLost(input);
}

//*****************************************************
inline void Player::setFlagsCaptured(const int input) const
{
	stats->setFlagsCaptured(input);
}

//*****************************************************
inline void Player::setCapturedFlags(const int input) const
{
	stats->setCapturedFlags(input);
}

//*****************************************************
inline void Player::setTimesExtinct(const int input) const
{
	stats->setTimesExtinct(input);
}

//*****************************************************
inline void Player::setGenocide(const int input) const
{
	stats->setGenocide(input);
}

//*****************************************************
inline void Player::clearPieces()
{
	pieces.clear();
}

//*****************************************************
inline int Player::getNumPieces() const
{
	return pieces.size();
}

#endif
