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
	//constructor
	Board();

	//collection functions
	void addPiece(Piece* const piece);
	void clearPiece(const int boardSpace);
	inline void clearPieces();
	Piece* findSelectedPiece();
	Piece* findPieceAtBoardSpace(const int boardSpace);

	//piece functions
	bool isMoveablePiece(Piece* const selected,  const int owner); //mover 0 - player, 1 computer
	bool isValidScoutMove(Piece* const scout, Piece* const destination);

	//input and render
	void handlePieceInput(SDL_Event& gEvent);
	void show(SDL_Surface* const destination) const;

private:
	//collection of pieces
	std::vector<Piece*> pieces;
};

//*****************************************************
inline void Board::clearPieces()
{
	pieces.clear();
}

#endif
