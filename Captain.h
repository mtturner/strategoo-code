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
	//constructors
    Captain(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Captain(std::string filename);

	//move
	virtual Piece* move(Piece* const destination);
};

#endif
