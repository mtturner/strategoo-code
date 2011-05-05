/*****************************************************
 	Sound.cpp

 	This is the implementation file for the Sound 
 	class.
*****************************************************/

#include "Sound.h"

Sound::Sound()
{
	menuTheme = 0;
	gameTheme = 0;
	winTheme = 0;
	loseTheme = 0;
	battleSound = 0;
	bombExplosion = 0;
	buttonPress = 0;
	moveSelector = 0;
	selectPiece = 0;
	placePiece = 0;
}

//*****************************************************
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

//*****************************************************
bool Sound::loadSounds()
{
	//loading the theme tracks
	menuTheme = Mix_LoadMUS("strategOO_Game_Theme.wav");
	gameTheme = Mix_LoadMUS("strategOO_Game_Theme.wav");
	winTheme = Mix_LoadMUS("winMusic.wav");
	loseTheme = Mix_LoadMUS("loseMusic.wav");

	if((menuTheme == 0) || (gameTheme == 0) || (winTheme == 0) ||
	   (loseTheme == 0))
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

	if((battleSound == 0) || (buttonPress == 0) || (moveSelector == 0) 
	   || (selectPiece == 0) || (placePiece == 0))
	{
		return false;
	}

	//if all sound files loaded OK
	return true;
}

//*****************************************************
bool Sound::playMenuTheme() const
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

//*****************************************************
bool Sound::playGameTheme() const
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

//*****************************************************
bool Sound::playWinTheme() const
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

//*****************************************************
bool Sound::playLoseTheme() const
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

//*****************************************************
bool Sound::playBattleSound() const
{
	//play the battle sound
	if(Mix_PlayChannel(-1, battleSound, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//*****************************************************
bool Sound::playBombExplosion() const
{
	//play the explosion sound
	if(Mix_PlayChannel(-1, bombExplosion, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//*****************************************************
bool Sound::playButtonPress() const
{
	//play the button press sound
	if(Mix_PlayChannel(-1, buttonPress, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//*****************************************************
bool Sound::playMoveSelector() const
{
	//play the selector move sound
	if(Mix_PlayChannel(-1, moveSelector, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;	
}

//*****************************************************
bool Sound::playSelectPiece() const
{
	//play the select piece sound
	if(Mix_PlayChannel(-1, selectPiece, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//*****************************************************
bool Sound::playPlacePiece() const
{
	//play the place piece sound
	if(Mix_PlayChannel(-1, placePiece, 0) == -1)
	{
		return 1;
	}

	//if everything executed OK
	return 0;
}

//*****************************************************
void Sound::pauseMusic() const
{
	//pause the currently playing music
	if(Mix_PausedMusic() == 0)
	{
		Mix_PauseMusic();
	}
}

//*****************************************************
void Sound::resumeMusic() const
{
	//resume current music
	if(Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
}
	