/******************************************************
	Sergeant.cpp

	This is the implementation file for the Sergeant 
	class.
******************************************************/

#include "Sergeant.h"

Sergeant::Sergeant(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "sergeant.png")
{
	setBoardSpace(boardSpace);
	setRank(4);
}

//****************************************
bool Sergeant::move()
{
	return true;
}
