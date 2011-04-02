/******************************************************
	Statistics.cpp

	This is the implementation file for the 
	Statistics class.
******************************************************/

#include "Statistics.h"

using namespace std;

Statistics::Statistics()
{
	gamesPlayed_ = 0;
	gamesWon_ = 0;
	gamesLost_ = 0;
	flagsCaptured_ = 0;
	capturedFlags_ = 0;
	timesExtinct_ = 0;
	genocide_ = 0;

	gamesPlayedLine_ = new Sprite;
	gamesWonLine_ = new Sprite;
	gamesLostLine_ = new Sprite;
	flagsCapturedLine_ = new Sprite;
	capturedFlagsLine_ = new Sprite;
	timesExtinctLine_ = new Sprite;
	genocideLine_ = new Sprite;
}

//*******************************************************************
Statistics::~Statistics()
{
	delete gamesPlayedLine_;
	delete gamesWonLine_;
	delete gamesLostLine_;
	delete flagsCapturedLine_;
	delete capturedFlagsLine_;
	delete timesExtinctLine_;
	delete genocideLine_;
}

//*******************************************************************
bool Statistics::save()
{
	//declaring local variables
	fstream statsFile;
	std::string playerName;

	statsFile.open("statistics.txt", ios::ate);

	while(statsFile >> playerName)
	{

		if( playerName == Player.getName)
		{
		}
	}
}

//*******************************************************************
bool Statistics::save()
{
	//declaring local variables
	fstream statsFile;
	std::string playerName;

	statsFile.open("statistics.txt", ios::ate);
}

//*******************************************************************
void Statistics::load()
{
	//load statistics
}

//*******************************************************************
void Statistics::display() const
{
	//display stats
}
