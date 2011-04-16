/******************************************************
	Miner.h

	This is the header file for the Miner class.
******************************************************/

#ifndef MINER_H
#define MINER_H

#include"Piece.h"

class Miner : public Piece
{
public:
    Miner(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Miner(std::string filename);

	virtual bool move();
};

#endif
