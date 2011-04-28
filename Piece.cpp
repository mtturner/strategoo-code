/******************************************************
	Piece.cpp

	This is the implementation file for the Piece
	class.
******************************************************/

#include "Piece.h"

Piece::Piece(const int x, const int y, const int owner)
{
	pieceImage = new Sprite(x, y);

	setOwner(owner);
	setIsSelected(false);
	name_ = "john doe";
}

//*****************************************************
Piece::Piece(const int x, const int y, const std::string& filename, 
	         const int owner)
{
	pieceImage = new Sprite(x, y, filename.c_str());

	setOwner(owner);
	setIsSelected(false);
}

//*****************************************************
Piece::~Piece()
{
	delete pieceImage;
}

//*****************************************************
void Piece::setRank(const int rank)
{
	if(rank > -1 && rank < 13)
	{
		rank_ = rank;
	}
}

//*****************************************************
void Piece::setBoardSpace(const int boardSpace)
{
	if(boardSpace > -2 && boardSpace < 100 &&
	   boardSpace != 42 && boardSpace != 43 &&
	   boardSpace != 46 && boardSpace != 47 &&
	   boardSpace != 52 && boardSpace != 53 &&
	   boardSpace != 56 && boardSpace != 57)
	{
		boardSpace_ = boardSpace;
	}
}

//*****************************************************
void Piece::setOwner(const int owner)
{
	if(owner == 0 || owner == 1)
	{
		owner_ = owner;
	}
}

//*****************************************************
void Piece::swapLocation(Piece* const other)
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

//*****************************************************
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
