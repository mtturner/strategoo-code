/******************************************************
	Computer.cpp

	This is the implementation file for the Computer
	class.
******************************************************/

#include "Computer.h"

Computer::Computer()
{
}

//*********************************
Computer::~Computer()
{
}

//*********************************
void Computer::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//*********************************
void Computer::clearPiece()
{
}

//*********************************
void Computer::clearPieces()
{
}
