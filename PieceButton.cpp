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
	selectedOverlay = new Sprite();

	//set isEmpty to true
	setIsAvailable(true);
}

//******************************************
PieceButton::PieceButton(const int x, const int y, const std::string& setter, 
						 const std::string& overlay)
{
	//create sprites
	buttonImage = new Sprite(x, y, setter.c_str());
	selectedOverlay = new Sprite(x, y, overlay.c_str());

	//set isEmpty to false
	setIsAvailable(false);
}

//******************************************
PieceButton::~PieceButton()
{
	//delete sprites
	delete buttonImage;
	delete selectedOverlay;
}

//******************************************
void PieceButton::setIsSelected(const bool selected)
{
	isSelected = selected;
}

//******************************************
void PieceButton::setIsAvailable(const bool available)
{
	isAvailable = available;
}

//******************************************
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
				else
				{
					//button isn't selected
					setIsSelected(false);
				}
			}
		}
	}
}

//******************************************
void PieceButton::show(SDL_Surface* screen)
{
	//if the button is available
	if(getIsAvailable())
	{
		//show the button
		buttonImage->show(screen);

		//if the button is currently selected
		if(getIsSelected())
		{
			//show the selected overlay
			selectedOverlay->show(screen);
		}
	}
}