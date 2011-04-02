/******************************************************
	General.h

	This is the header file for the General class.
******************************************************/

#ifndef GENERAL_H
#define GENERAL_H

#include"Piece.h"

class General : public Piece
{
public:
	General();
	General(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~General();     
};

#endif
