/******************************************************
	Miner.cpp

	This is the implementation file for the Miner
	class.
******************************************************/

#include "Miner.h"

Miner::Miner(int xPos, int yPos, int boardSpace) : Piece(xPos, yPos, "miner.png")
{
	setBoardSpace(boardSpace);
	setRank(3);
}

//****************************************
Miner::Miner(std::string filename) : Piece(0, 0, filename.c_str())
{
	setBoardSpace(-1);
	setRank(3);
}

//****************************************
bool Miner::move()
{
	return true;
}
