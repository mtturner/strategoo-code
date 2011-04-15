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
	PieceButton(const int x, const int y, const std::string& button);
	~PieceButton();

	//getters and setters
	inline bool getIsSelected() const;
	void setIsSelected(const bool selected);
	inline bool getIsAvailable() const;
	void setIsAvailable(const bool available);

	//input and rendering
	void handleInput(SDL_Event& gEvent);
	void show(SDL_Surface* screen) const;

private:
	//sprites
	Sprite* buttonImage;

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

#endif