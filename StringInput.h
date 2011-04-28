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

class StringInput
{
public:
	//constructor and destructor
	StringInput();
	~StringInput();

	//getters and setters
	inline std::string getInput() const;
	void setInput(const std::string& newInput);
	inline SDL_Surface* getMessageSurface() const;
	void setMessageSurface(SDL_Surface* const surface);
	void setMessageSurface(const std::string& message);
	inline TTF_Font* getFont() const;
	void setFont(TTF_Font* const newFont);
	void setFont(const std::string& fontName, const int fontSize);
	inline SDL_Color* getFontColor() const;
	void setFontColor(SDL_Color* const color);

    //input and rendering
	void handleInput(SDL_Event& gEvent,  const unsigned int maxLength = 16);
    void show(SDL_Surface* const screen) const;
    void show(SDL_Surface* const screen, const int xPos, const int yPos) const;


private:
	//input
    std::string input;

    //image surface
    SDL_Surface* text;

	//font
    TTF_Font* font;

	//text color
    SDL_Color* textColor;
};

//*****************************************************
inline std::string StringInput::getInput() const
{
	return input;
}

//*****************************************************
inline SDL_Surface* StringInput::getMessageSurface() const
{
	return text;
}

//*****************************************************
inline TTF_Font* StringInput::getFont() const
{
	return font;
}

//*****************************************************
inline SDL_Color* StringInput::getFontColor() const
{
	return textColor;
}

#endif
