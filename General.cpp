/******************************************************
	General.cpp

	This is the implementation file for the General 
	class.
******************************************************/

#include "General.h"

General::General(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "general.png")
{
	setBoardSpace(boardSpace);
	setRank(9);
}

//****************************************
General::General(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(9);
}

//****************************************
bool General::move()
{
	return true;
}
