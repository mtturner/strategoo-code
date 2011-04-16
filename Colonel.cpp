/******************************************************
	Colonel.cpp

	This is the implementation file for the Colonel 
	class.
******************************************************/

#include "Colonel.h"

Colonel::Colonel(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "colonel.png")
{
	setBoardSpace(boardSpace);
	setRank(8);
}

//****************************************
Colonel::Colonel(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(8);
}

//****************************************
bool Colonel::move()
{
	return true;
}

