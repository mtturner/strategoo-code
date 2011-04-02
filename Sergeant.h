/******************************************************
	Sergeant.h

	This is the header file for the Sergeant class.
******************************************************/

#ifndef SERGEANT_H
#define SERGEANT_H

#include"Piece.h"

class Sergeant : public Piece
{
public:
	Sergeant();
    Sergeant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Sergeant();     

	virtual bool move();
};

#endif
