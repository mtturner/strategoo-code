/******************************************************
	Player.cpp

	This is the implementation file for the Player 
	class.
******************************************************/

#include "Player.h"

Player::Player()
{
	name = " ";
	//pieces.load(0);
}

//*******************************************************************
Player::~Player()
{
	//deallocate memory
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
}

//*******************************************************************
bool Player::saveStatistics()
{
	stats->save(name);
}

//*******************************************************************
void Player::displayStatistics() const
{
	stats->display();
}
