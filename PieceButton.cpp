/******************************************************
	PieceButton.cpp

	This is the implementation file for the 
	PieceButton class.
******************************************************/

#include "PieceButton.h"

PieceButton::PieceButton()
{
	//create sprites
	buttonImage = new Sprite();
	buttonUnavailable = new Sprite();

	//set isSelected and isAvailable to false
	setIsAvailable(false);
	setIsSelected(false);
}

//*****************************************************
PieceButton::PieceButton(const int x, const int y, const int rank,
						 const std::string& button)
{
	//create sprites
	buttonImage = new Sprite(x, y, button.c_str());
	buttonUnavailable = new Sprite(x, y, "piecebuttonunavailable.png");

	//set button rank
	setRank(rank);

	//set isSelected to false and isAvailable to true
	setIsSelected(false);
	setIsAvailable(true);
}

//*****************************************************
PieceButton::~PieceButton()
{
	//delete sprites
	delete buttonImage;
	delete buttonUnavailable;
}

//*****************************************************
void PieceButton::setRank(const int rank)
{
	if(rank > 0 && rank < 13)
	{
		rank_ = rank;
	}
}

//*****************************************************
void PieceButton::setXPos(const int xPos)
{
	if(xPos > -1 && xPos < 800)
	{
		buttonImage->setXPos(xPos);
		buttonUnavailable->setXPos(xPos);
	}
}

//*****************************************************
void PieceButton::setYPos(const int yPos)
{
	if(yPos > -1 && yPos < 600)
	{
		buttonImage->setYPos(yPos);
		buttonUnavailable->setYPos(yPos);
	}
}

//*****************************************************
void PieceButton::handleInput(SDL_Event& gEvent)
{
	//mouse offsets
	int x = 0,
		y = 0;

	//if the button is available
	if(getIsAvailable())
	{
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
				if((x > buttonImage->getXPos()) && (x < buttonImage->getXPos() + 200) &&
				   (y > buttonImage->getYPos()) && (y < buttonImage->getYPos() + 50))
				{
					//button is selected
					setIsSelected(true);
				}
			}
		}
	}
}

//*****************************************************
void PieceButton::show(SDL_Surface* screen) const
{
	//if the button is available
	if(getIsAvailable())
	{
		//show the button
		buttonImage->show(screen);
	}
	else
	{
		buttonUnavailable->show(screen);
	}
}