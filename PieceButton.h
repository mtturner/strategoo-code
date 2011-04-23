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
	PieceButton();
	PieceButton(const int x, const int y, const int rank,
		        const std::string& button);
	~PieceButton();

	//getters and setters
	inline bool getIsSelected() const;
	void setIsSelected(const bool selected);
	inline bool getIsAvailable() const;
	void setIsAvailable(const bool available);
	inline int getRank() const;
	void setRank(int rank);
	inline int getXPos() const;
	void setXPos(int xPos);
	inline int getYPos() const;
	void setYPos(int yPos);

	//input and rendering
	void handleInput(SDL_Event& gEvent);
	void show(SDL_Surface* screen) const;

private:
	//sprites
	Sprite* buttonImage;
	Sprite* buttonUnavailable;

	int rank_;

	bool isSelected,
		 isAvailable;
};

inline bool PieceButton::getIsSelected() const
{
	return isSelected;
}

//******************************************
inline bool PieceButton::getIsAvailable() const
{
	return isAvailable;
}

//******************************************
inline int PieceButton::getRank() const
{
	return rank_;
}

//******************************************
inline int PieceButton::getXPos() const
{
	return buttonImage->getXPos();
}

//******************************************
inline int PieceButton::getYPos() const
{
	return buttonImage->getYPos();
}

#endif