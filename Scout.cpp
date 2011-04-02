/******************************************************
	Scout.cpp

	This is the implementation file for the Scout 
	class.
******************************************************/

#include "Sprite.h"
#include "Piece.h"
#include "Scout.h"

Scout::Scout() : Piece()
{
}

//****************************************
Scout::Scout(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Scout::~Scout()
{
}

//****************************************
bool Scout::move()
{
	return true;
}
