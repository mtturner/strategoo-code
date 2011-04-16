/******************************************************
	Sprite.cpp

	This is the implementation file for the Sprite 
	class.
******************************************************/

#include "SDL_image.h"
#include "Sprite.h"

Sprite::Sprite() : image(0)
{
	setXPos(0);
	setYPos(0);
}

//******************************************
Sprite::Sprite(int x, int y) : image(0)
{
	setXPos(x);
	setYPos(y);
}

//******************************************
Sprite::Sprite(int x, int y, std::string filename) : image(0)
{
	setXPos(x);
	setYPos(y);

	load(filename.c_str());
}

//******************************************
Sprite::Sprite(int x, int y, std::string filename, int alpha) : image(0)
{
	setXPos(x);
	setYPos(y);
	
	load(filename.c_str());

	SDL_SetAlpha(getSurface(), SDL_SRCALPHA, alpha);
}

//******************************************
Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}

//******************************************
bool Sprite::load(std::string filename)
{
	//temporary SDL surfaces
	SDL_Surface* loaded = 0;
	//load bool
	bool success = false;

	//delete old image
	delete image;

	loaded = IMG_Load(filename.c_str());

	if(loaded)
	{
		image = SDL_DisplayFormat(loaded);

		SDL_FreeSurface(loaded);

		if(image != 0)
		{
			Uint32 colorkey = SDL_MapRGB(image->format, 255, 0, 255);

			SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

			return true;
		}
	}

	return false;
}

//******************************************
void Sprite::show(SDL_Surface* destination) const
{
	SDL_Rect position;

	position.x = getXPos();
	position.y = getYPos();

	SDL_BlitSurface(image, 0, destination, &position);
}

//******************************************
void Sprite::setXPos(int xPos)
{
	//x must be greater than -1 and less than 800
	if(xPos > -1 && xPos < 800)
	{
		xPos_ = xPos;
	}
}

//******************************************
void Sprite::setYPos(int yPos)
{
	//y must be greater than -1 and less than 600
	if(yPos > -1 && yPos < 600)
	{
		yPos_ = yPos;
	}
}

//******************************************
void Sprite::setSurface(SDL_Surface* surface)
{
	if(surface != 0)
	{
		SDL_FreeSurface(image);

		image = surface;
	}
}