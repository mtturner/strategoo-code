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
	//constructors
	Scout(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Scout(std::string filename);

	//move
    virtual Piece* move(Piece* const destination);
};

#endif
