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
	//constructors and destructor
	Sprite();
	Sprite(const int x, const int y);
	Sprite(const int x, const int y, const std::string filename);
	Sprite(const int x, const int y, const std::string filename, const int alpha);
	~Sprite();

	//getters and setters
	inline int getXPos() const;
	inline int getYPos() const;
	void setXPos(int xPos);
	void setYPos(int yPos);
	inline SDL_Surface* getSurface() const;
	void setSurface(SDL_Surface* const surface);
	inline void setSurfaceNoFree(SDL_Surface* const surface);

	//load and show
	bool load(const std::string& filename);
	bool load(const std::string& filename, const int r, const int g, const int b);
	void show(SDL_Surface* const destination) const;

private:
	//image surface
	SDL_Surface* image;

	//rendering coordinates
	int xPos_,
		yPos_;
};

//*****************************************************
inline int Sprite::getXPos() const
{
	return xPos_;
}

//*****************************************************
inline int Sprite::getYPos() const
{
	return yPos_;
}

//*****************************************************
inline SDL_Surface* Sprite::getSurface() const
{
	return image;
}

//*****************************************************
inline void Sprite::setSurfaceNoFree(SDL_Surface* const surface)
{
	image = surface;
}

#endif
