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
	Miner();
    Miner(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Miner();     

	virtual bool move();
};

#endif
