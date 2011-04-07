/******************************************************
	Sprite.h

	This is the header file for the Sprite class.
******************************************************/

#ifndef SPRITE_H
#define SPRITE_H

#include"SDL.h"
#include<string>

class Sprite
{
public:
	Sprite();
	Sprite(int x, int y);
	Sprite(int x, int y, std::string filename);
	~Sprite();

	bool load(std::string filename);
	void show(SDL_Surface* destination) const;
	inline int getXPos() const;
	inline int getYPos() const;
	void setXPos(int xPos);
	void setYPos(int yPos);
	void setSurface(SDL_Surface* surface);

private:
	SDL_Surface* image;
	int xPos_,
		yPos_;
};

//******************************************
inline int Sprite::getXPos() const
{
	return xPos_;
}

//******************************************
inline int Sprite::getYPos() const
{
	return yPos_;
}

#endif
