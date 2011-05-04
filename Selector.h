/******************************************************
	Selector.h

	This is the header file for the Selector class.
******************************************************/

#ifndef SELECTOR_H
#define SELECTOR_H

#include "SDL/SDL.h"
#include <string>
#include "Sprite.h"

class Selector
{
public:
	//constructor and destructor
	Selector();
	~Selector();

	//getters and setters
	inline int getChoice() const;
	void setChoice(const int choice);
	inline void setMoved(const bool moved);

	//reset
	void reset();

	//input, logic, and rendering
	void handleInput(SDL_Event& gEvent);
	bool move();
	void show(SDL_Surface* const destination) const;

private:
	//image surface
	Sprite* selectorImage;
	
	//choice
	int choice_; //0 is top option, 1 is bottom option

	//isMoved boolean
	bool isMoved;
};

//*****************************************************
inline int Selector::getChoice() const
{
	return choice_;
}

//*****************************************************
inline void Selector::setMoved(const bool moved)
{
	isMoved = moved;
}

//*****************************************************
inline void Selector::show(SDL_Surface* const destination) const
{
	selectorImage->show(destination);
}

#endif
