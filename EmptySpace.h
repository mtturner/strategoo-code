/******************************************************
	EmptySpace.h

	This is the header file for the EmptySpace class.
******************************************************/

#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include "Piece.h"

class EmptySpace : public Piece
{
public:
    EmptySpace(int xPos = 0, int yPos = 0, int boardSpace = -1);

    virtual bool move();
	virtual void show(SDL_Surface* destination) const;
};

#endif
