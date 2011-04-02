/******************************************************
	Flag.cpp

	This is the implementation file for the Flag
	class.
******************************************************/

#include "Sprite.h"
#include "Piece.h"
#include "Flag.h"

Flag::Flag() : Piece()
{
}

//****************************************
Flag::Flag(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Flag::~Flag()
{
}

//****************************************
bool Flag::move()
{
	return true;
}
