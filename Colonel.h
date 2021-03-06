/******************************************************
	Colonel.h

	This is the header file for the Colonel class.
******************************************************/

#ifndef COLONEL_H
#define COLONEL_H

#include"Piece.h"

class Colonel : public Piece
{
public:
	//constructors
    Colonel(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Colonel(std::string filename);

	//move
	virtual Piece* move(Piece* const destination);
};

#endif
