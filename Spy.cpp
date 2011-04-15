/******************************************************
	Spy.cpp

	This is the implementation file for the Spy 
	class.
******************************************************/

#include "Spy.h"

Spy::Spy(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "spy.png")
{
	setBoardSpace(boardSpace);
	setRank(1);
}

//****************************************
bool Spy::move()
{
	return true;
}
