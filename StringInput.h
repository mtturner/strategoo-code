#ifndef STRINGINPUT_H
#define STRINGINPUT_H

#include <string>

//The key press interpreter
class StringInput
{
    private:
    //The storage string
    std::string str;

    //The text surface
    SDL_Surface *text;

    public:
    //Initializes variables
    StringInput();

    //Does clean up
    ~StringInput();

    //Handles input
    void handle_input();

    //Shows the message on screen
    void show_centered(SDL_Surface* screen);
};

#endif
