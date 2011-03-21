#include"SDL.h"
#include"SDL_image.h"
#include<string>
#include"Sprite.h"

Sprite::Sprite() : image(0)
{
	setXPos(0);
	setYPos(0);
}

//******************************************
Sprite::Sprite(int x, int y, std::string filename)
{
	setXPos(x);
	setYPos(y);

	load(filename.c_str());
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
	SDL_Surface* loaded = NULL;
	//load bool
	bool success = false;

	//delete old image
	delete image;


	loaded = IMG_Load(filename.c_str());

	if(loaded)
	{
		image = SDL_DisplayFormat(loaded);

		SDL_FreeSurface(loaded);

		if(image != NULL)
		{
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

	SDL_BlitSurface(image, NULL, destination, &position);
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