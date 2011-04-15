/******************************************************
	Piece.h

	This is the header file for the Piece class.
******************************************************/

#ifndef PIECE_H
#define PIECE_H

#include "Sprite.h"

class Piece
{
public:
	Piece(int x = 0, int y = 0);
	Piece(int x, int y, std::string filename);
    virtual ~Piece();

	virtual bool move() = 0;
	void namePiece();
	void handleInput(SDL_Event& gEvent);
	void show() const;
	inline int getRank() const;
	inline int getBoardSpace() const;
	void setRank(int rank);
	inline int getXPos() const;
	void setXPos(int xPos);
	inline int getYPos() const;
	void setYPos(int yPos);
	void setBoardSpace(int boardSpace);
	inline bool getIsSelected() const;
	void setIsSelected(const bool selected);

	//operator overloads
	inline bool operator==(const Piece& piece) const;
	inline bool operator!=(const Piece& piece) const;
	inline bool operator<(const Piece& piece) const;
	inline bool operator>(const Piece& piece) const;

private:
	Sprite* pieceImage;

	int boardSpace_,
		rank_;
	bool isSelected;
};

//*********************************
inline int Piece::getRank() const
{
	return rank_;
}

//*********************************
inline int Piece::getBoardSpace() const
{
	return boardSpace_;
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
inline bool Piece::getIsSelected() const
{
	return isSelected;
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
