/******************************************************
	Miner.cpp

	This is the implementation file for the Miner
	class.
******************************************************/

#include "Sprite.h"
#include "Piece.h"
#include "Miner.h"

Miner::Miner() : Piece()
{
}

//****************************************
Miner::Miner(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage) : Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}

//****************************************
Miner::~Miner()
{
}
