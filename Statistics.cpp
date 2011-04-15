/******************************************************
	Statistics.cpp

	This is the implementation file for the 
	Statistics class.
******************************************************/

#include "SDL.h"
#include <iostream>
#include <fstream>
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

	gamesPlayedLine = new Sprite(300, 0);
	gamesWonLine = new Sprite(300, 75);
	gamesLostLine = new Sprite(300, 150);
	flagsCapturedLine = new Sprite(300, 225);
	capturedFlagsLine = new Sprite(300, 300);
	timesExtinctLine = new Sprite(300, 375);
	genocideLine = new Sprite(300, 450);
}

//*******************************************************************
Statistics::~Statistics()
{
	delete gamesPlayedLine;
	delete gamesWonLine;
	delete gamesLostLine;
	delete flagsCapturedLine;
	delete capturedFlagsLine;
	delete timesExtinctLine;
	delete genocideLine;
}

//*******************************************************************
bool Statistics::save(const string& currentPlayer)
{
	//declaring local variables
	fstream statsFile;
	string playerName;

	statsFile.open("statistics.txt", ios::in | ios::out);

	while( statsFile >> playerName )
	{
		if( playerName == currentPlayer )
		{
			statsFile << gamesPlayed_;
			statsFile << gamesWon_;
			statsFile << gamesLost_;
			statsFile << flagsCaptured_;
			statsFile << capturedFlags_;
			statsFile << timesExtinct_;
			statsFile << genocide_;
		}
	}

	statsFile.close();

	/*if(statsFile.fail())
	{
		return false;
	}
	else
	{
		return true;
	}*/

	return 0;
}

//*******************************************************************
bool Statistics::load(const string& currentPlayer)
{
	//declaring local variables
	fstream statsFile;
	string playerName;
	string currentStat;

	//opening stats file
	statsFile.open("statistics.txt", ios::in);

	if(statsFile.fail())
	{
		cout << "There was a problem opening the file.";
	}

	while(getline(statsFile, playerName))
	{
		if(playerName == currentPlayer)
		{
			statsFile >> currentStat;
		}
	}

	cout << statsFile.good();
	//cout << gamesWon_ << gamesPlayed_;

	statsFile.close();

	return 0;
}

//*******************************************************************
void Statistics::display() const
{
	//display stats
}
