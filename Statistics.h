/******************************************************
	Statistics.h

	This is the header file for the Statistics class.
******************************************************/


#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include "Sprite.h"

class Statistics
{
public:
    Statistics();
    ~Statistics();

    bool save(const std::string& currentPlayer);
    bool load(const std::string& currentPlayer);
    void display() const;

private:
    int gamesPlayed_,
	gamesWon_,
	gamesLost_,
	flagsCaptured_,
	capturedFlags_,
	timesExtinct_,
	genocide_;

	//Sprites to display each stat
	Sprite* gamesPlayedLine;
	Sprite* gamesWonLine;
	Sprite* gamesLostLine;
	Sprite* flagsCapturedLine;
	Sprite* capturedFlagsLine;
	Sprite* timesExtinctLine;
	Sprite* genocideLine;
};

#endif