//These are the function definitions for the Player class
#include<string>
#include"Statistics.h"
#include "Player.h"

Player::Player()
{

	name = " ";
	//pieces.load( NULL );

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

void Player::loadStatistics()
{

	//load stats

}

//*******************************************************************

void Player::displayStatistics() const
{

	stats->display();

}