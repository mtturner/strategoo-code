/******************************************************
	Menu.h

	This is the header file for the Menu class.
******************************************************/

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
