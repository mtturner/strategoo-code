/******************************************************
	StringInput.cpp

	This is the implementation file for the 
	StringInput class.
******************************************************/

#include "StringInput.h"

StringInput::StringInput() : text(0), font(0), textColor(0)
{
	//initialize the string
    setInput("");

	//set font
	TTF_Font* temp = TTF_OpenFont("nuschoolmunitions.ttf", 28);

    setFont(temp);

	//temporary SDL_Color struct
	SDL_Color* color = new SDL_Color();

	//set rgb values
    color->r = 153;
	color->g = 217;
	color->b = 234;

	//set font color
	setFontColor(color);

    //enable Unicode
    SDL_EnableUNICODE(SDL_ENABLE);
}

//****************************************
StringInput::~StringInput()
{
    //free text surface
    SDL_FreeSurface(text);

	delete textColor;

    //disable Unicode
    SDL_EnableUNICODE(SDL_DISABLE);
}

//****************************************
void StringInput::setInput(std::string newInput)
{
	input = newInput;
}

//****************************************
void StringInput::setMessageSurface(SDL_Surface* surface)
{
	SDL_FreeSurface(text);

	text = surface;
}

//****************************************
void StringInput::setFont(TTF_Font* newFont)
{
	TTF_CloseFont(font);

	font = newFont;
}

//****************************************
void StringInput::setFontColor(SDL_Color* color)
{
	delete textColor;

	textColor = color;
}

//****************************************
void StringInput::handleInput(SDL_Event& gEvent)
{
    //if a key was pressed
    if(gEvent.type == SDL_KEYDOWN)
    {
        //temporary version of input to be modified
        std::string temp = getInput();

        //if the string less than maximum size
        if(temp.length() <= 16)
        {
            //if the key is a number
            if((gEvent.key.keysym.unicode >= static_cast<Uint16>('0')) && 
					(gEvent.key.keysym.unicode <= static_cast<Uint16>('9')))
            {
                //append the character
                temp += static_cast<char>(gEvent.key.keysym.unicode);
            }
            //if the key is an uppercase letter
            else if((gEvent.key.keysym.unicode >= static_cast<Uint16>('A')) && 
				    (gEvent.key.keysym.unicode <= static_cast<Uint16>('Z')))
            {
                //append the character
                temp += static_cast<char>(gEvent.key.keysym.unicode);
            }
            //if the key is a lowercase letter
            else if((gEvent.key.keysym.unicode >= static_cast<Uint16>('a')) && 
				    (gEvent.key.keysym.unicode <= static_cast<Uint16>('z')))
            {
                //append the character
                temp += static_cast<char>(gEvent.key.keysym.unicode);
            }
        }

        //if backspace was pressed and the string isn't blank
        if((gEvent.key.keysym.sym == SDLK_BACKSPACE) && (temp.length() != 0))
        {
            //remove a character from the end
            temp.erase(temp.length() - 1);
        }

        //if the string was changed
        if(getInput() != temp)
        {
			//set new input
			setInput(temp);

			//temporary surface for new input surface
            SDL_Surface* newInput;

            //render a new text surface
            newInput = TTF_RenderText_Solid(getFont(), getInput().c_str(), *(getFontColor()));

			//set new text
			setMessageSurface(newInput);
        }
    }
}

//****************************************
void StringInput::show(SDL_Surface* screen)
{
    //if the surface isn't blank
    if(getMessageSurface() != 0)
    {
        //holds offsets
        SDL_Rect offset;

        //get offsets
        offset.x = (800 - getMessageSurface()->w) / 2;
        offset.y = (600 - getMessageSurface()->h) / 2;

        //blit
        SDL_BlitSurface(getMessageSurface(), 0, screen, &offset);
    }
}