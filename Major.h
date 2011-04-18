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
    Major(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Major(std::string filename);

	virtual Piece* move(Piece* destination);
};

#endif
