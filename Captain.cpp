/******************************************************
	Captain.cpp

	This is the implementation file for the Captain
	class.
******************************************************/

#include "Captain.h"

Captain::Captain(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "captain.png")
{
	setBoardSpace(boardSpace);
	setRank(6);
}

//****************************************
Captain::Captain(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(6);
}

//****************************************
bool Captain::move()
{
	return true;
}
