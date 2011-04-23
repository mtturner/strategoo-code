/******************************************************
	Captain.cpp

	This is the implementation file for the Captain
	class.
******************************************************/

#include "Captain.h"

Captain::Captain(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "captain.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(6);
}

//****************************************
Captain::Captain(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(6);
}

//****************************************
Piece* Captain::move(Piece* destination)
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
