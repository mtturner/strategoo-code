/******************************************************
	Board.cpp

	This is the implementation file for the Board 
	class.
******************************************************/

#include "Board.h"

Board::Board()
{
	boardImage->load("board.png");
}

//*******************************************************************
Board::~Board()
{
	//deallocate memory
}

//*******************************************************************
bool Board::addPiece()
{
	//add pieces

	return true;
}

//*******************************************************************
void Board::clearPiece()
{
	//clear piece
}

//*******************************************************************
void Board::clearPieces()
{
	//clear pieces
}

//*******************************************************************
void Board::render() const
{
	//render the board
}

//*********************************
void Board::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}
