/******************************************************
	Lieutenant.cpp

	This is the implementation file for the
	Lieutenant class.
******************************************************/

#include "Lieutenant.h"

Lieutenant::Lieutenant(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "lieutenant.png")
{
	setBoardSpace(boardSpace);
	setRank(5);
}

//****************************************
Lieutenant::Lieutenant(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(5);
}

//****************************************
bool Lieutenant::move()
{
	return true;
}
