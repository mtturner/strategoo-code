//These are the function definitions for the Board class

#include"SDL.h"
#include<string>
#include"Sprite.h"
#include "Board.h"

Board::Board()
{

	boardImage->load( "board.png" );

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