/******************************************************
	EmptySpace.cpp

	This is the implementation file for the EmptySpace 
	class.
******************************************************/

#include "EmptySpace.h"

EmptySpace::EmptySpace(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos)
{
	setBoardSpace(boardSpace);
	setRank(0);
}

//****************************************
bool EmptySpace::move()
{
	return true;
}
