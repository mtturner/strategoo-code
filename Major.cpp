/******************************************************
	Major.cpp

	This is the implementation file for the Major 
	class.
******************************************************/

#include "Major.h"

Major::Major(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "major.png")
{
	setBoardSpace(boardSpace);
	setRank(7);
}

//****************************************
Major::Major(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(7);
}

//****************************************
bool Major::move()
{
	return true;
}
