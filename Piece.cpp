/******************************************************
	Piece.cpp

	This is the implementation file for the Piece 
	class.
******************************************************/

#include "Piece.h"

Piece::Piece()
{
	rank_ = -1;
	owner_ = -1;
	boardSpace_ = -1;

	pieceImage = new Sprite();
}

//*********************************
Piece::Piece(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage)
{
	setPieceImage(pieceImage);

	pieceImage->setXPos(xPos);
	pieceImage->setYPos(yPos);

	setRank(rank);
	setOwner(owner);
	setBoardSpace(boardSpace);
}

//*********************************
Piece::~Piece()
{
	delete pieceImage;
}

//*********************************
void Piece::namePiece()
{
}

//*********************************       
void Piece::render() const
{
}

//*********************************
void Piece::setRank(int rank)
{
     rank_ = rank;
}

//*********************************
void Piece::setXPos(int xPos)
{
	pieceImage->setXPos(xPos);
}

//*********************************
void Piece::setYPos(int yPos)
{
	pieceImage->setYPos(yPos);
}

//*********************************
void Piece::setBoardSpace(int boardSpace)
{
	boardSpace_ = boardSpace;
}

//*********************************
void Piece::setOwner(int owner)
{
	owner_ = owner;
}

//*********************************
void Piece::setPieceImage(Sprite* image)
{
	if(image != 0)
	{
		delete pieceImage;

		pieceImage = image;
	}
}
