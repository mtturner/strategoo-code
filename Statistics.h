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

    bool save();
	bool load();
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
	Sprite* statisticsScreen_
	gamesPlayedLine_,
	gamesWonLine_,
	gamesLostLine_,
	flagsCapturedLine_,
	capturedFlagsLine_,
	timesExtinctLine_,
	genocideLine_;
};

#endif
