/******************************************************
	General.cpp

	This is the implementation file for the General 
	class.
******************************************************/

#include "Sprite.h"
#include "Piece.h"
#include "General.h"

General::General() : Piece()
{
}

//****************************************
General::General(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
General::~General()
{
}

//****************************************
bool General::move()
{
	return true;
}
