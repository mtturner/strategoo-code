/******************************************************
	EmptySpace.h

	This is the header file for the EmptySpace class.
******************************************************/

#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include"Piece.h"

class EmptySpace : public Piece
{
public:
	EmptySpace();
    EmptySpace(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~EmptySpace();

    bool move();     
};

#endif
