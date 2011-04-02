/******************************************************
	Piece.h

	This is the header file for the Piece class.
******************************************************/

#ifndef PIECE_H
#define PIECE_H

#include"Sprite.h"

class Piece
{
public:
	Piece();
    Piece(int xPos, int yPos, int boardSpace, int rank, int owner, Sprite* image);
    ~Piece();

	virtual bool move();
	void namePiece();
	void render() const;
	inline int getRank() const;
	inline int getXPos() const;
	inline int getYPos() const;
	inline int getBoardSpace() const;
	inline int getOwner() const;
	inline Sprite* getPieceImage() const;
	void setRank(int rank);
	void setXPos(int xPos);
	void setYPos(int yPos);
	void setBoardSpace(int boardSpace);
	void setOwner(int owner);
	void setPieceImage(Sprite* image);

	//operator overloads
	inline bool operator==(const Piece& piece) const;
	inline bool operator!=(const Piece& piece) const;
	inline bool operator<(const Piece& piece) const;
	inline bool operator>(const Piece& piece) const;

private:
	int boardSpace_,
        rank_,
        owner_;
    Sprite* pieceImage;
};

//*********************************
inline int Piece::getRank() const
{
	return rank_;
}

//*********************************
inline int Piece::getXPos() const
{
	return pieceImage->getXPos();
}

//*********************************
inline int Piece::getYPos() const
{
	return pieceImage->getYPos();
}

//*********************************
inline int Piece::getBoardSpace() const
{
	return boardSpace_;
}

//*********************************
inline int Piece::getOwner() const
{
	return owner_;
}

//*********************************
inline Sprite* Piece::getPieceImage() const
{
	return pieceImage;
}

//*********************************
inline bool Piece::operator==(const Piece& piece) const
{
	return getRank() == piece.getRank();
}

//*********************************
inline bool Piece::operator!=(const Piece& piece) const
{
	return !(*this == piece);
}

//*********************************
inline bool Piece::operator<(const Piece& piece) const
{
	return getRank() < piece.getRank();
}

//*********************************
inline bool Piece::operator>(const Piece& piece) const
{
	return getRank() > piece.getRank();
}

#endif
