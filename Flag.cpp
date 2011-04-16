/******************************************************
	Flag.cpp

	This is the implementation file for the Flag
	class.
******************************************************/

#include "Flag.h"

Flag::Flag(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "flag.png")
{
	setBoardSpace(boardSpace);
	setRank(12);
}

//****************************************
Flag::Flag(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(12);
}

//****************************************
bool Flag::move()
{
	return true;
}
