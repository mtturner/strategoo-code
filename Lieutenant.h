/******************************************************
	Lieutenant.h

	This is the header file for the Lieutenant class.
******************************************************/

#ifndef LIEUTENANT_H
#define LIEUTENANT_H

#include"Piece.h"

class Lieutenant : public Piece
{
public:
	Lieutenant();
    Lieutenant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Lieutenant(); 

	virtual bool move();
};

#endif
