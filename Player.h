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
	void clearPiece(const int boardSpace);
	void clearPieces();
	Piece* findUnplacedPiece(const int buttonRank);
	Piece* findPieceAtPosition(const int position);
	inline int getNumPieces() const;

	//statistics functions
	bool loadStatistics();
	bool saveStatistics();
	void displayStatistics(SDL_Surface* background) const;
	void setStatisticsSprites();
	inline void setGamesPlayed(int input);
	inline void setGamesWon(const int input);
	inline void setGamesLost(const int input);
	inline void setFlagsCaptured(const int input);
	inline void setCapturedFlags(const int input);
	inline void setTimesExtinct(const int input);
	inline void setGenocide(const int input);

private:
	std::string name;
	std::vector<Piece*> pieces;
	Statistics* stats;
};

//******************************************************************************
inline int Player::getNumPieces() const
{
	return pieces.size();
}

//******************************************************************************
inline void Player::setGamesPlayed(const int input)
{
	stats->setGamesPlayed(input);
}

//******************************************************************************
inline void Player::setGamesWon(const int input)
{
	stats->setGamesWon(input);
}

//******************************************************************************
inline void Player::setGamesLost(const int input)
{
	stats->setGamesLost(input);
}

//******************************************************************************

inline void Player::setFlagsCaptured(const int input)
{
	stats->setFlagsCaptured(input);
}

//******************************************************************************

inline void Player::setCapturedFlags(const int input)
{
	stats->setCapturedFlags(input);
}

//******************************************************************************

inline void Player::setTimesExtinct(const int input)
{
	stats->setTimesExtinct(input);
}

//******************************************************************************

inline void Player::setGenocide(const int input)
{
	stats->setGenocide(input);
}

#endif
