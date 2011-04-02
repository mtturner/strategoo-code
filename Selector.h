/******************************************************
	Selector.h

	This is the header file for the Selector class.
******************************************************/

#ifndef SELECTOR_H
#define SELECTOR_H

#include "SDL.h"
#include <string>
#include "Sprite.h"

class Selector
{
public:
	Selector();
	~Selector();

	inline int getChoice() const;
	void setChoice(int choice);
	void setMoved(bool moved);

	void handleInput(SDL_Event& gEvent);
	void move();
	void show(SDL_Surface* destination) const;

private:
	Sprite* selectorImage;
	int choice_; //0 is top option, 1 is bottom option
	bool isMoved;
};

inline int Selector::getChoice() const
{
	return choice_;
}

#endif