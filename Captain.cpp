/******************************************************
	Captain.cpp

	This is the implementation file for the Captain
	class.
******************************************************/

#include "Sprite.h"
#include "Piece.h"
#include "Captain.h"

Captain::Captain() : Piece()
{
}

//****************************************
Captain::Captain(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Captain::~Captain()
{
}

//****************************************
bool Captain::move()
{
	return true;
}
