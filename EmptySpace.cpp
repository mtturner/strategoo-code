/******************************************************
	EmptySpace.cpp

	This is the implementation file for the EmptySpace 
	class.
******************************************************/

#include "EmptySpace.h"

EmptySpace::EmptySpace(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, -1)
{
	setBoardSpace(boardSpace);
	setRank(0);
}

//****************************************
Piece* EmptySpace::move(Piece* const destination)
{
	//can't move!!!!111oneone
	return 0;
}

//****************************************
void EmptySpace::show(SDL_Surface* const destination) const
{
	//do nothing
}