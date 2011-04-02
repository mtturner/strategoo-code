/******************************************************
	EmptySpace.cpp

	This is the implementation file for the EmptySpace 
	class.
******************************************************/

#include "EmptySpace.h"

EmptySpace::EmptySpace() : Piece()
{
}

//****************************************
EmptySpace::EmptySpace(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
EmptySpace::~EmptySpace()
{
}

//****************************************
bool EmptySpace::move()
{
	return true;
}
