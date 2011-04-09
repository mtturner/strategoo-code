/******************************************************
	Player.cpp

	This is the implementation file for the Player 
	class.
******************************************************/

#include "Player.h"

Player::Player()
{
	setName(" ");
}

//*******************************************************************
Player::Player(std::string& currentPlayer)
{
	setName(currentPlayer);
}

//*******************************************************************
Player::~Player()
{
	//deallocate memory
}

//*******************************************************************
void Player::setName(std::string newPlayer)
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
	stats->load(name);

	return true;
}

//*******************************************************************
bool Player::saveStatistics()
{
	stats->save(name);

	return true;
}

//*******************************************************************
void Player::displayStatistics() const
{
	//stats->display();
}