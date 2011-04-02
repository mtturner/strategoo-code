/******************************************************
	Colonel.h

	This is the header file for the Colonel class.
******************************************************/

#ifndef COLONEL_H
#define COLONEL_H

#include"Piece.h"

class Colonel : public Piece
{
public:
	Colonel();
    Colonel(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Colonel();   

	virtual bool move();
};

#endif
