/******************************************************
	Major.cpp

	This is the implementation file for the Major 
	class.
******************************************************/

#include "Major.h"

Major::Major() : Piece()
{
}

//****************************************
Major::Major(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Major::~Major()
{
}

//****************************************
bool Major::move()
{
	return true;
}
