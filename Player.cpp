/******************************************************
	Player.cpp

	This is the implementation file for the Player 
	class.
******************************************************/

#include "Player.h"

Player::Player()
{
	setName(" ");
	stats = new Statistics();
}

//*******************************************************************
Player::Player(std::string& currentPlayer)
{
	setName(currentPlayer);
	stats = new Statistics();
}

//*******************************************************************
Player::~Player()
{
	delete stats;
}

//*******************************************************************
void Player::setName(const std::string& newPlayer)
{
	name = newPlayer;
}

//*******************************************************************
void Player::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//*******************************************************************
void Player::clearPiece()
{
	//clear a single piece
}

//*******************************************************************
void Player::clearPieces()
{
	//clear players pieces
}

//*******************************************************************
bool Player::loadStatistics()
{
	return(stats->load(name));
}

//*******************************************************************
bool Player::saveStatistics()
{
	return(stats->save(name));
}

//*******************************************************************
void Player::displayStatistics() const
{
	stats->display();
}