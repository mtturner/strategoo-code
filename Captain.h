/******************************************************
	Captain.h

	This is the header file for the Captain class.
******************************************************/

#ifndef CAPTAIN_H
#define CAPTAIN_H

#include"Piece.h"

class Captain : public Piece
{
public:
	Captain();
    Captain(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~Captain();     
};

#endif
