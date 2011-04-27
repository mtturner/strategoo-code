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
	Sprite(int x, int y, std::string filename, int alpha);
	~Sprite();

	bool load(std::string filename);
	bool load(std::string filename, int r, int g, int b);
	void show(SDL_Surface* destination) const;
	inline int getXPos() const;
	inline int getYPos() const;
	void setXPos(int xPos);
	void setYPos(int yPos);
	inline SDL_Surface* getSurface() const;
	void setSurface(SDL_Surface* surface);
	void setSurfaceNoFree(SDL_Surface* surface);

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

//******************************************
inline SDL_Surface* Sprite::getSurface() const
{
	return image;
}

#endif
