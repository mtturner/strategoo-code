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

	//collection functions
	void addPiece(Piece* piece);
	void clearPiece(const int boardSpace);
	void clearPieces();
	Piece* findSelectedPiece();

	//input and render
	void handlePieceInput(SDL_Event& gEvent);
	void show(SDL_Surface* destination) const;

private:
	Sprite* boardImage;
	std::vector<Piece*> pieces;
};

#endif
