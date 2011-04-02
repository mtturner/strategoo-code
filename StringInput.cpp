#include "SDL_ttf.h"
#include "SDL.h"
#include "StringInput.h"

SDL_Event gEvent;
SDL_Color textColor = { 153, 217, 234 };
TTF_Font *font = TTF_OpenFont( "lazy.ttf", 24 );
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;


StringInput::StringInput()
{
    //Initialize the string
    str = "";

    //Initialize the surface
    text = NULL;

    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );
}
//****************************************
StringInput::~StringInput()
{
    //Free text surface
    SDL_FreeSurface( text );

    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );
}
//****************************************
void StringInput::handle_input()
{
    //If a key was pressed
    if( gEvent.type == SDL_KEYDOWN )
    {
        //Keep a copy of the current version of the string
        std::string temp = str;

        //If the string less than maximum size
        if( str.length() <= 16 )
        {
            //If the key is a space
            if( gEvent.key.keysym.unicode == (Uint16)' ' )
            {
                //Append the character
                str += (char)gEvent.key.keysym.unicode;
            }
            //If the key is a number
            else if( ( gEvent.key.keysym.unicode >= (Uint16)'0' ) && ( gEvent.key.keysym.unicode <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)gEvent.key.keysym.unicode;
            }
            //If the key is a uppercase letter
            else if( ( gEvent.key.keysym.unicode >= (Uint16)'A' ) && ( gEvent.key.keysym.unicode <= (Uint16)'Z' ) )
            {
                //Append the character
                str += (char)gEvent.key.keysym.unicode;
            }
            //If the key is a lowercase letter
            else if( ( gEvent.key.keysym.unicode >= (Uint16)'a' ) && ( gEvent.key.keysym.unicode <= (Uint16)'z' ) )
            {
                //Append the character
                str += (char)gEvent.key.keysym.unicode;
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( gEvent.key.keysym.sym == SDLK_BACKSPACE ) && ( str.length() != 0 ) )
        {
            //Remove a character from the end
            str.erase( str.length() - 1 );
        }

        //If the string was changed
        if( str != temp )
        {
            //Free the old surface
            SDL_FreeSurface( text );

            //Render a new text surface
            text = TTF_RenderText_Solid(font, str.c_str(), textColor);
        }
    }
}
//****************************************
void StringInput::show_centered(SDL_Surface* screen)
{
    //If the surface isn't blank
    if( text != NULL )
    {
        //Holds offsets
        SDL_Rect offset;

        //Get offsets
        offset.x = ( SCREEN_WIDTH - text->w ) / 2;
        offset.y = ( SCREEN_HEIGHT - text->h ) / 2;

        //Blit
        SDL_BlitSurface( text, NULL, screen, &offset );
    }
}
