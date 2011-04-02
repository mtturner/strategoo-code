/******************************************************
	Colonel.cpp

	This is the implementation file for the Colonel 
	class.
******************************************************/

#include "Colonel.h"

Colonel::Colonel() : Piece()
{
}

//****************************************
Colonel::Colonel(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Colonel::~Colonel()
{
}

//****************************************
bool Colonel::move()
{
	return true;
}

