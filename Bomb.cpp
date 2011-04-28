/******************************************************
	Bomb.cpp

	This is the implementation file for the Bomb
	class.
******************************************************/

#include "Bomb.h"

Bomb::Bomb(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "bomb.png", 0)
{
	setBoardSpace(boardSpace);
	setRank(11);
}

//****************************************
Bomb::Bomb(std::string filename) : Piece(0, 0, filename.c_str(), 1)
{
	setBoardSpace(-1);
	setRank(11);
}

//****************************************
Piece* Bomb::move(Piece* const destination)
{
	//bombs can't move!!!!!111111oneoneone
	return 0;
}
