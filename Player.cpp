//These are the function definitions for the Player class

#include "Player.h"

Player::Player()
{

	name = " ";
	pieces.load( NULL );
	stats.load();

}

//*******************************************************************

Player::~Player()
{

	//deallocate memory

}

//*******************************************************************

void Player::clearPieces()
{

	//clear players pieces

}

//*******************************************************************

void Player::loadPlayerStatistics()
{

	//load stats

}

//*******************************************************************

void Player::displayStatistics() const
{

	stats.display();

}

//*******************************************************************