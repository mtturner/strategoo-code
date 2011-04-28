/******************************************************
	PieceButton.h

	This is the header file for the PieceButton 
	class.
******************************************************/

#ifndef PIECEBUTTON_H
#define PIECEBUTTON_H

#include "SDL.h"
#include <string>
#include "Sprite.h"
#include "Piece.h"

class PieceButton
{
public:
	//constructors and destructor
	PieceButton();
	PieceButton(const int x, const int y, const int rank,
		        const std::string& button);
	~PieceButton();

	//getters and setters
	inline bool getIsSelected() const;
	inline void setIsSelected(const bool selected);
	inline bool getIsAvailable() const;
	inline void setIsAvailable(const bool available);
	inline int getRank() const;
	void setRank(const int rank);
	inline int getXPos() const;
	void setXPos(const int xPos);
	inline int getYPos() const;
	void setYPos(const int yPos);

	//input and rendering
	void handleInput(SDL_Event& gEvent);
	void show(SDL_Surface* screen) const;

private:
	//sprites
	Sprite* buttonImage;
	Sprite* buttonUnavailable;

	//rank of pieces button represents
	int rank_;

	//isSelected and isAvailable booleans
	bool isSelected,
		 isAvailable;
};

//*****************************************************
inline bool PieceButton::getIsSelected() const
{
	return isSelected;
}

//*****************************************************
inline void PieceButton::setIsSelected(const bool selected)
{
	isSelected = selected;
}

//*****************************************************
inline bool PieceButton::getIsAvailable() const
{
	return isAvailable;
}

//*****************************************************
inline void PieceButton::setIsAvailable(const bool available)
{
	isAvailable = available;
}

//*****************************************************
inline int PieceButton::getRank() const
{
	return rank_;
}

//*****************************************************
inline int PieceButton::getXPos() const
{
	return buttonImage->getXPos();
}

//*****************************************************
inline int PieceButton::getYPos() const
{
	return buttonImage->getYPos();
}

#endif