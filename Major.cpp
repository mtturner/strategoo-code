/******************************************************
	Major.cpp

	This is the implementation file for the Major 
	class.
******************************************************/

#include "Major.h"

Major::Major(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "major.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(7);
}

//*****************************************************
Major::Major(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(7);
}

//*****************************************************
Piece* Major::move(Piece* const destination)
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
