/******************************************************
	Board.cpp

	This is the implementation file for the Board 
	class.
******************************************************/

#include "Board.h"

Board::Board()
{
	boardImage = new Sprite(0, 0, "board.png");
}

//*******************************************************************
Board::~Board()
{
	delete boardImage;
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
void Board::handlePieceInput(SDL_Event& gEvent)
{
	//iterator
	std::vector<Piece*>::iterator iter;

	for(iter = pieces.begin(); iter != pieces.end(); iter++)
	{
		(*iter)->handleInput(gEvent);
	}
}

//*******************************************************************
Piece* Board::findSelectedPiece()
{
	//temp piece
	Piece* temp = 0;

	//found boolean
	bool found = false;

	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	while(iter != pieces.end() && !found)
	{
		//if the piece has been selected
		if((*iter)->getIsSelected())
		{
			temp = *iter;

			//reset piece
			temp->setIsSelected(false);

			found = true;
		}
	}

	return temp;
}

//*******************************************************************
void Board::show() const
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
