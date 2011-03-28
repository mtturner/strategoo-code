//Piece.cpp
#include "Sprite.h"
#include "Piece.h"

Piece::Piece(int xPos_=0, int yPos_=0, int rank_=0, int owner_=0, int boardSpace_=0, Sprite* pieceImage_=0)
{
	setXPos(xPos_);
	setYPos(yPos_);
	setRank(rank_);
	setOwner(owner_);
	setBoardSpace(boardSpace_);
	setPieceImage(pieceImage_);

}
//*********************************
Piece::~Piece()
{
}
//*********************************
bool Piece::move()
{
	return true;
}
//*********************************
void Piece::namePiece()
{
}
//*********************************       
void Piece::render()
{
}
//*********************************
int Piece::getRank() const
{
	return rank;
}
//*********************************
int Piece::getXPos() const
{
	return xPos;
}
//*********************************
int Piece::getYPos() const
{
	return yPos;
}
//*********************************
int Piece::getBoardSpace() const
{
	return boardSpace;
}
//*********************************
int Piece::getOwner() const
{
	return owner;
}
//*********************************
Sprite* Piece::getPieceImage() const
{
	return pieceImage;
}
//*********************************
void Piece::setRank(int rank_)
{
     rank = rank_;
}
//*********************************
void Piece::setXPos(int xPos_)
{
	xPos = xPos_;
}
//*********************************
void Piece::setYPos(int yPos_)
{
	yPos = yPos_;
}
//*********************************
void Piece::setBoardSpace(int boardSpace_)
{
	boardSpace = boardSpace_;
}
//*********************************
void Piece::setOwner(int owner_)
{
	owner = owner_;
}
//*********************************
void Piece::setPieceImage(Sprite* pieceImage_)
{
	pieceImage = pieceImage_;
}
