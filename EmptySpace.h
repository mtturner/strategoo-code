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
	//constructor
    EmptySpace(int xPos = 0, int yPos = 0, int boardSpace = -1);

	//move and show
    virtual Piece* move(Piece* const destination);
	inline virtual void show(SDL_Surface* const destination) const;
};

//*****************************************************
inline void EmptySpace::show(SDL_Surface* const destination) const
{
	//do nothing
}

#endif
