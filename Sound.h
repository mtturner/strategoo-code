/******************************************************
	Sound.h

 	This is the header file for the Sound class.
******************************************************/

#ifndef SOUND_H
#define SOUND_H

#include "SDL_mixer.h"

class Sound
{
public:
	//constructor and destructor
	Sound();
	~Sound();

	//load function
	bool loadSounds();

	//sound call-functions
	bool playMenuTheme() const;
	bool playGameTheme() const;
	bool playWinTheme() const;
	bool playLoseTheme() const;
	bool playBattleSound() const;
	bool playBombExplosion() const;
	bool playButtonPress() const;
	bool playMoveSelector() const;
	bool playSelectPiece() const;
	bool playPlacePiece() const;

	//music manipulation functions
	inline void stopMusic() const;
	void pauseMusic() const;
	void resumeMusic() const;

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
inline void Sound::stopMusic() const
{
	//stop the currently playing music
	Mix_HaltMusic();
}

#endif	
