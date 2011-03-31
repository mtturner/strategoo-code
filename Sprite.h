//This is the class defining the visual components of the game

#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
public:
	Sprite();
	Sprite(int x, int y, std::string filename);
	~Sprite();

	bool load(std::string filename);
	void show(SDL_Surface* destination) const;
	inline int getXPos() const;
	inline int getYPos() const;
	void setXPos(int xPos);
	void setYPos(int yPos);

private:
	SDL_Surface* image;
	int xPos_,
		yPos_;
};

//******************************************
int Sprite::getXPos() const
{
	return xPos_;
}

//******************************************
int Sprite::getYPos() const
{
	return yPos_;
}

#endif
