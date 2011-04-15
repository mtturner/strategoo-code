/******************************************************
	Piece.cpp

	This is the implementation file for the Piece 
	class.
******************************************************/

#include "Piece.h"

Piece::Piece(int x, int y)
{
	pieceImage = new Sprite(x, y);

	setIsSelected(false);
}

//*********************************
Piece::Piece(int x, int y, std::string filename)
{
	pieceImage = new Sprite(x, y, filename.c_str());

	setIsSelected(false);
}

//*********************************
Piece::~Piece()
{
	delete pieceImage;
}

//*********************************
void Piece::setXPos(int xPos)
{
	pieceImage->setXPos(xPos);
}

//*********************************
void Piece::setYPos(int yPos)
{
	pieceImage->setYPos(yPos);
}

//*********************************
void Piece::handleInput(SDL_Event& gEvent)
{
	//mouse offsets
	int x = 0,
		y = 0;

	//if the mouse was clicked
	if(gEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		//if the left mouse button was clicked
		if(gEvent.button.button == SDL_BUTTON_LEFT)
		{
			//get mouse offsets
			x = gEvent.button.x;
			y = gEvent.button.y;

			//if the mouse was over the button when it was clicked
			if((x > pieceImage->getXPos()) && (x < pieceImage->getXPos() + 60) &&
			   (y > pieceImage->getYPos()) && (y < pieceImage->getYPos() + 60))
			{
				//button is selected
				setIsSelected(true);
			}
		}
	}
}

//*********************************       
void Piece::show(SDL_Surface* destination) const
{
	pieceImage->show(destination);
}

//*********************************
void Piece::namePiece()
{
}

//*********************************
void Piece::setRank(int rank)
{
     rank_ = rank;
}

//*********************************
void Piece::setBoardSpace(int boardSpace)
{
	boardSpace_ = boardSpace;
}

//*********************************
void Piece::setIsSelected(const bool selected)
{
	isSelected = selected;
}