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
	Piece* findPieceAtBoardSpace(const int boardSpace);

	//piece functions
	bool isMoveablePiece(Piece* selected);
	bool isValidScoutMove(Piece* scout, Piece* destination);

	//input and render
	void handlePieceInput(SDL_Event& gEvent);
	void show(SDL_Surface* destination) const;

private:
	std::vector<Piece*> pieces;
};

#endif
