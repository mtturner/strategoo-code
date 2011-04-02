/******************************************************
	Major.h

	This is the header file for the Major class.
******************************************************/

#ifndef MAJOR_H
#define MAJOR_H

#include"Piece.h"

class Major : public Piece
{
public:
	Major();
    Major(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~Major();     
};

#endif
