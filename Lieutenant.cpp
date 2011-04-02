/******************************************************
	Lieutenant.cpp

	This is the implementation file for the
	Lieutenant class.
******************************************************/

#include "Lieutenant.h"

Lieutenant::Lieutenant() : Piece()
{
}

//****************************************
Lieutenant::Lieutenant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Lieutenant::~Lieutenant()
{
}

//****************************************
bool Lieutenant::move()
{
	return true;
}
