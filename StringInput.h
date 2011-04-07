/******************************************************
	StringInput.h

	This is the header file for the StringInput
	class.
******************************************************/

#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

//The key press interpreter
class StringInput
{
public:
	StringInput();
	~StringInput();

	//getters and setters
	inline std::string getInput() const;
	void setInput(std::string newInput);
	inline SDL_Surface* getMessageSurface() const;
	void setMessageSurface(SDL_Surface* surface);
	inline TTF_Font* getFont() const;
	void setFont(TTF_Font* newFont);
	inline SDL_Color* getFontColor() const;
	void setFontColor(SDL_Color* color);
	
	void handleInput(SDL_Event& gEvent);

    //Shows the message on screen
    void show(SDL_Surface* screen);
    

private:
	//The storage string
    std::string str;

    //The text surface
    SDL_Surface* text;
    TTF_Font* font;
    SDL_Color* textColor;
};

//****************************************
inline std::string StringInput::getInput() const
{
	return str;
}

//****************************************
inline SDL_Surface* StringInput::getMessageSurface() const
{
	return text;
}

//****************************************
inline TTF_Font* StringInput::getFont() const
{
	return font;
}

//****************************************
inline SDL_Color* StringInput::getFontColor() const
{
	return textColor;
}

#endif