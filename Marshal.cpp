/******************************************************
	Marshal.cpp

	This is the implementation file for the Marshal 
	class.
******************************************************/

#include "Marshal.h"

Marshal::Marshal(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "marshal.png")
{
	setBoardSpace(boardSpace);
	setRank(10);
}

//****************************************
bool Marshal::move()
{
	return true;
}
