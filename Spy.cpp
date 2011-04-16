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
Spy::Spy(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(1);
}

//****************************************
bool Spy::move()
{
	return true;
}
