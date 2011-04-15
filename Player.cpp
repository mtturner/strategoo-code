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
Piece* Player::findUnplacedPiece(const int rank)
{
	//temp piece
	Piece* temp = 0;

	//found boolean
	bool found = false;

	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	while(iter != pieces.end() && !found)
	{
		//if the piece is of the correct rank
		if((*iter)->getRank() == rank)
		{
			//if the piece has not been already set
			if((*iter)->getBoardSpace() == -1)
			{
				temp = *iter;

				found = true;
			}
		}

		iter++;
	}

	return temp;
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