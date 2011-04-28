/******************************************************
	Statistics.h

	This is the header file for the Statistics class.
******************************************************/

#ifndef STATISTICS_H
#define STATISTICS_H

#include "Sprite.h"

class Statistics
{
public:
	//constructor and destructor
    Statistics();
    ~Statistics();

	//setters
	inline void setGamesPlayed(const int input);
	inline void setGamesWon(const int input);
	inline void setGamesLost(const int input);
	inline void setFlagsCaptured(const int input);
	inline void setCapturedFlags(const int input);
	inline void setTimesExtinct(const int input);
	inline void setGenocide(const int input);
	bool setSprites() const;

	//save, load, and display
    bool save(const std::string& currentPlayer) const;
    bool load(const std::string& currentPlayer);
    void display(SDL_Surface* const background) const;

private:
	//statistics
    int gamesPlayed_,
	gamesWon_,
	gamesLost_,
	flagsCaptured_,
	capturedFlags_,
	timesExtinct_,
	genocide_;

	//sprites to display each stat
	Sprite* gamesPlayedLine;
	Sprite* gamesWonLine;
	Sprite* gamesLostLine;
	Sprite* flagsCapturedLine;
	Sprite* capturedFlagsLine;
	Sprite* timesExtinctLine;
	Sprite* genocideLine;
};

//*****************************************************
inline void Statistics::setGamesPlayed(const int input)
{
	gamesPlayed_ += input;
}

//*****************************************************
inline void Statistics::setGamesWon(const int input)
{
	gamesWon_ += input;
}

//*****************************************************
inline void Statistics::setGamesLost(const int input)
{
	gamesLost_ += input;
}

//*****************************************************
inline void Statistics::setFlagsCaptured(const int input)
{
	flagsCaptured_ += input;
}

//*****************************************************
inline void Statistics::setCapturedFlags(const int input)
{
	capturedFlags_ += input;
}

//*****************************************************
inline void Statistics::setTimesExtinct(const int input)
{
	timesExtinct_ += input;
}

//*****************************************************
inline void Statistics::setGenocide(const int input)
{
	genocide_ += input;
}

#endif