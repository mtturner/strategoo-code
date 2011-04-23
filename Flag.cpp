/******************************************************
	Flag.cpp

	This is the implementation file for the Flag
	class.
******************************************************/

#include "Flag.h"

Flag::Flag(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "flag.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(-1);
}

//****************************************
Flag::Flag(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(-1);
}

//****************************************
Piece* Flag::move(Piece* destination)
{
	//can't move!!!!!!!!
	return 0;
}
