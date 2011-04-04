#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include <string>
#include "SDL_ttf.h"

//The key press interpreter
class StringInput
{
    private:
            //The storage string
            std::string str;

             //The text surface
             SDL_Surface* text;
             TTF_Font* font;
             SDL_Color textColor;

    public:
           StringInput();
           ~StringInput();

           void handle_input(SDL_Event& gEvent);

           //Shows the message on screen
           void show_centered(SDL_Surface* screen);
};

#endif