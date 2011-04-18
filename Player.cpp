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
Piece* Player::findUnplacedPiece(const int buttonRank)
{
	//temp piece
	Piece* temp = 0;

	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	//found boolean
	bool found = false;

	while(!found && iter != pieces.end())
	{
		if((*iter)->getRank() == buttonRank && (*iter)->getBoardSpace() == -1)
		{
			temp = *iter;

			found = true;
		}

		if(!found)
		{
			iter++;
		}
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
void Player::displayStatistics(SDL_Surface* background) const
{
	stats->display(background);
}

void Player::setStatisticsSprites()
{
	stats->setSprites();
}