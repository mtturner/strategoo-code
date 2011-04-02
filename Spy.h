/******************************************************
	Spy.h

	This is the header file for the Spy class.
******************************************************/

#ifndef SPY_H
#define SPY_H

#include"Piece.h"

class Spy : public Piece
{
public:
	Spy();
    Spy(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Spy();  

	virtual bool move();
};

#endif
