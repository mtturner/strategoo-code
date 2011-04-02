/******************************************************
	Spy.cpp

	This is the implementation file for the Spy 
	class.
******************************************************/

#include "Spy.h"

Spy::Spy() : Piece()
{
}

//****************************************
Spy::Spy(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Spy::~Spy()
{
}

//****************************************
bool Spy::move()
{
	return true;
}
