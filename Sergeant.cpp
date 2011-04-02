/******************************************************
	Sergeant.cpp

	This is the implementation file for the Sergeant 
	class.
******************************************************/

#include "Sergeant.h"

Sergeant::Sergeant() : Piece()
{
}

//****************************************
Sergeant::Sergeant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Sergeant::~Sergeant()
{
}

//****************************************
bool Sergeant::move()
{
	return true;
}
