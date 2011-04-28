/******************************************************
	Flag.h

	This is the header file for the Flag class.
******************************************************/

#ifndef FLAG_H
#define FLAG_H

#include"Piece.h"

class Flag : public Piece
{
public:
	Flag(int xPos = 0, int yPos = 0, int boardSpace = -1);
	Flag(std::string filename);

	virtual Piece* move(Piece* const destination); 
};

#endif
