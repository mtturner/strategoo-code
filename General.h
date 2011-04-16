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
	General(int xPos = 0, int yPos = 0, int boardSpace = -1);
	General(std::string filename);

	virtual bool move();
};

#endif
