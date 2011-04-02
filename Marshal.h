/******************************************************
	Marshal.h

	This is the header file for the Marshal class.
******************************************************/

#ifndef MARSHAL_H
#define MARSHAL_H

#include"Piece.h"

class Marshal : public Piece
{
public:
	Marshal();
    Marshal(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~Marshal();     
};

#endif
