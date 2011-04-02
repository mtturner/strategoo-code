/******************************************************
	Board.h

	This is the header file for the Board class.
******************************************************/

#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include"Sprite.h"
#include"Piece.h"

class Board
{
public:
	Board();
	~Board();

	bool addPiece();
	void clearPiece();
	void clearPieces();
	void render() const;

private:
	Sprite* boardImage;
	std::vector<Piece*> pieces;
};

#endif
