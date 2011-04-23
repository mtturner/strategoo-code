/******************************************************
	Marshal.cpp

	This is the implementation file for the Marshal 
	class.
******************************************************/

#include "Marshal.h"

Marshal::Marshal(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "marshal.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(10);
}

//****************************************
Marshal::Marshal(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(10);
}

//****************************************
Piece* Marshal::move(Piece* destination)
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
