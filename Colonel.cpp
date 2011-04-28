/******************************************************
	Colonel.cpp

	This is the implementation file for the Colonel 
	class.
******************************************************/

#include "Colonel.h"

Colonel::Colonel(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "colonel.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(8);
}

//****************************************
Colonel::Colonel(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(8);
}

//****************************************
Piece* Colonel::move(Piece* const destination)
{
	//if the piece is an emptyspace
	if(destination->getRank() == 0)
	{
		swapLocation(destination);

		return destination;
	}
	//else if the piece is the flag
	else if(destination->getRank() == 12)
	{
		swapLocation(destination);

		return this;
	}
	//else need to battle pieces to the death
	else
	{
		if(*this > *destination)
		{
			swapLocation(destination);

			return this;
		}
		else if(*this < *destination)
		{
			return destination;
		}
		else
		{
			//draw
			return 0;
		}
	}
}