/******************************************************
	Scout.h

	This is the header file for the Scout class.
******************************************************/

#ifndef SCOUT_H
#define SCOUT_H

#include"Piece.h"

class Scout: public Piece
{
public:
	Scout();
	Scout(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~Scout();

    bool move();   
};

#endif
