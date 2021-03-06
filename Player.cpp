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

//*****************************************************
Player::Player(std::string& currentPlayer)
{
	setName(currentPlayer);

	stats = new Statistics();

	stats->load(currentPlayer);
}

//*****************************************************
Player::~Player()
{
	delete stats;
}

//*****************************************************
void Player::addPiece(Piece* const piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//*****************************************************
void Player::clearPiece(const int boardSpace)
{
	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	//found boolean
	bool found = false;

	while(!found && iter != pieces.end())
	{
		if((*iter)->getBoardSpace() == boardSpace)
		{
			found = true;

			pieces.erase(iter);
		}

		if(!found)
		{
			iter++;
		}
	}
}

//*****************************************************
Piece* Player::findPieceAtPosition(const int position)
{
	return pieces[position];
}

//*****************************************************
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

//*****************************************************
void Player::setStatisticsSprites() const
{
	stats->setSprites();
}

//*****************************************************
bool Player::loadStatistics() const
{
	return (stats->load(name));
}

//*****************************************************
bool Player::saveStatistics() const
{
	return (stats->save(name));
}

//*****************************************************
void Player::displayStatistics(SDL_Surface* background) const
{
	stats->display(background);
}