/******************************************************
	Flag.h

	This is the header file for the Flag class.
******************************************************/

#ifndef FLAG_H
#define FLAG_H

#include"Piece.h"

class Flag : public Piece
{
public:
	Flag();
	Flag(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    virtual ~Flag();

    virtual bool move();   
};

#endif
