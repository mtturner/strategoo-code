/******************************************************
	Piece.cpp

	This is the implementation file for the Piece
	class.
******************************************************/

#include "Piece.h"

Piece::Piece(int x, int y, int owner)
{
	pieceImage = new Sprite(x, y);

	setOwner(owner);
	setIsSelected(false);
	name_ = 'l';
}

//*********************************
Piece::Piece(int x, int y, std::string filename, int owner)
{
	pieceImage = new Sprite(x, y, filename.c_str());

	setOwner(owner);
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

//*********************************
void Piece::setOwner(const int owner)
{
	if(owner == 0 || owner == 1)
	{
		owner_ = owner;
	}
}

void Piece::setName(const std::string& name)
{
    name_ = name;
}

//*********************************
void Piece::swapLocation(Piece* other)
{
	//x, y, and boardspace
	int x = 0,
		y = 0,
		boardSpace = 0;

	//hold first's position
	x = getXPos();
	y = getYPos();
	boardSpace = getBoardSpace();

	//set first's position to second's position
	setXPos(other->getXPos());
	setYPos(other->getYPos());
	setBoardSpace(other->getBoardSpace());

	//set second's position with first's position
	other->setXPos(x);
	other->setYPos(y);
	other->setBoardSpace(boardSpace);
}
