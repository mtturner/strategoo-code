//This is the class defining the in-game menu of the game

#ifndef MENU_H
#define MENU_H

#include"Sprite.h"

class Menu
{
public:
	Menu();
	~Menu();

	void load();

private:
	Sprite* menuImage;
};

#endif
