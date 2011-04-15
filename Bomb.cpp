/******************************************************
	Bomb.cpp

	This is the implementation file for the Bomb
	class.
******************************************************/

#include "Bomb.h"

Bomb::Bomb(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "bomb.png")
{
	setBoardSpace(boardSpace);
	setRank(11);
}

//****************************************
bool Bomb::move()
{
	return true;
}
