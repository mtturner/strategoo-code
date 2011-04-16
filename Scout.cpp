/******************************************************
	Scout.cpp

	This is the implementation file for the Scout 
	class.
******************************************************/

#include "Scout.h"

Scout::Scout(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "scout.png")
{
	setBoardSpace(boardSpace);
	setRank(2);
}

//****************************************
Scout::Scout(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(2);
}

//****************************************
bool Scout::move()
{
	return true;
}
