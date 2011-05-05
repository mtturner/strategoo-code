/*****************************************************
 	Sound.cpp

 	This is the implementation file for the sound 
 	class.
*****************************************************/

#include "Sound.h"

Sound::Sound()
{
	menuTheme = NULL;
	gameTheme = NULL;
	winTheme = NULL;
	loseTheme = NULL;
	battleSound = NULL;
	bombExplosion = NULL;
	buttonPress = NULL;
	moveSelector = NULL;
	selectPiece = NULL;
	placePiece = NULL;

	//load all sounds
	loadSounds();
}

//******************************************************************************
Sound::~Sound()
{
	//Free the theme tracks
	Mix_FreeMusic(menuTheme);
	Mix_FreeMusic(gameTheme);
	Mix_FreeMusic(winTheme);
	Mix_FreeMusic(loseTheme);

	//Free the sound effects
	Mix_FreeChunk(battleSound);
	Mix_FreeChunk(bombExplosion);
	Mix_FreeChunk(buttonPress);
	Mix_FreeChunk(moveSelector);
	Mix_FreeChunk(selectPiece);
	Mix_FreeChunk(placePiece);
}

//******************************************************************************
bool Sound::loadSounds()
{
	//loading the theme tracks
	menuTheme = Mix_LoadMUS("strategOO_Menu_Theme.wav");
	gameTheme = Mix_LoadMUS("strategOO_Game_Theme.wav");
	winTheme = Mix_LoadMUS("winMusic.wav");
	loseTheme = Mix_LoadMUS("loseMusic.wav");

	if((menuTheme == NULL) || (gameTheme == NULL) || (winTheme == NULL) || 
	   (loseTheme == NULL))
	{
		return false;
	}

	//loading the sound effects
	battleSound = Mix_LoadWAV("battleSound.wav");
	bombExplosion = Mix_LoadWAV("explosion.wav");
	buttonPress = Mix_LoadWAV("buttonPress.wav");
	moveSelector = Mix_LoadWAV("selectorMove.wav");
	selectPiece = Mix_LoadWAV("pieceSelect.wav");
	placePiece = Mix_LoadWAV("piecePlace.wav");

	if((battleSound == NULL) || (buttonPress == NULL) || (moveSelector == NULL) 
	   || (selectPiece == NULL) || (placePiece == NULL))
	{
		return false;
	}

	//if all sound files loaded OK
	return true;
}

//******************************************************************************
bool Sound::playMenuTheme()
{
	//if there is no music playing
	if(Mix_PlayingMusic() == 0)
	{
		//play the menu theme
		if(Mix_PlayMusic(menuTheme, -1) == -1)
		{
			return 1;
		}
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playGameTheme()
{
	//if there is no music playing
	if(Mix_PlayingMusic() == 0)
	{
		//play the in-game theme
		if(Mix_PlayMusic(gameTheme, -1) == -1)
		{
			return 1;
		}
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playWinTheme()
{
	//if there is no music playing
	if(Mix_PlayingMusic() == 0)
	{
		//play the win theme
		if(Mix_PlayMusic(winTheme, -1) == -1)
		{
			return 1;
		}
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playLoseTheme()
{
	//if there is no music playing
	if(Mix_PlayingMusic() == 0)
	{
		if(Mix_PlayMusic(loseTheme, -1) == -1)
		{
			return 1;
		}
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playBattleSound()
{
	//play the battle sound
	if(Mix_PlayChannel(-1, battleSound, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playBombExplosion()
{
	//play the explosion sound
	if(Mix_PlayChannel(-1, bombExplosion, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playButtonPress()
{
	//play the button press sound
	if(Mix_PlayChannel(-1, buttonPress, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playMoveSelector()
{
	//play the selector move sound
	if(Mix_PlayChannel(-1, moveSelector, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playSelectPiece()
{
	//play the select piece sound
	if(Mix_PlayChannel(-1, selectPiece, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
bool Sound::playPlacePiece()
{
	//play the place piece sound
	if(Mix_PlayChannel(-1, placePiece, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//******************************************************************************
void Sound::stopMusic()
{
	//stop the currently playing music
	Mix_HaltMusic();
}

//******************************************************************************
void Sound::pauseMusic()
{
	//pause the currently playing music
	if(Mix_PausedMusic() == 0)
	{
		Mix_PauseMusic();
	}
}

//******************************************************************************
void Sound::resumeMusic()
{
	//resume current music
	if(Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
}
	