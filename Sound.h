/******************************************************
	Sound.h

 	This is the header file for the sound class.
******************************************************/

#ifndef SOUND_H
#define SOUND_H

#include "SDL/SDL_mixer.h"

class Sound
{
public:
	//constructor and destructor
	Sound();
	~Sound();

	//load function
	bool loadSounds();

	//sound call-functions
	bool playMenuTheme();
	bool playGameTheme();
	bool playWinTheme();
	bool playLoseTheme();
	bool playBattleSound();
	bool playBombExplosion();
	bool playButtonPress();
	bool playMoveSelector();
	bool playSelectPiece();
	bool playPlacePiece();

	//music manipulation functions
	void stopMusic();
	void pauseMusic();
	void resumeMusic();

private:
	//SDL music datatypes
	Mix_Music* menuTheme;
	Mix_Music* gameTheme;
	Mix_Music* winTheme;
	Mix_Music* loseTheme;

	//SDL sound effect datatypes
	Mix_Chunk* battleSound;
	Mix_Chunk* bombExplosion;
	Mix_Chunk* buttonPress;
	Mix_Chunk* moveSelector;
	Mix_Chunk* selectPiece;
	Mix_Chunk* placePiece;

};

//*****************************************************

#endif	