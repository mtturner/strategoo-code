/******************************************************
	Statistics.cpp

	This is the implementation file for the 
	Statistics class.
******************************************************/


#include "SDL.h"
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

	statsFile.open("statistics.txt", ios::app);

	while( statsFile >> playerName )
	{
		if( playerName == currentPlayer )
		{
			statsFile << gamesPlayed_ << endl;
			statsFile << gamesWon_ << endl;
			statsFile << gamesLost_ << endl;
			statsFile << flagsCaptured_ << endl;
			statsFile << capturedFlags_ << endl;
			statsFile << timesExtinct_ << endl;
			statsFile << genocide_ << endl;
		}
	}

	statsFile.close();

	if(statsFile.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}

//*******************************************************************
bool Statistics::load(const string& currentPlayer)
{
	//declaring local variables
	ifstream statsFile;
	string playerName;

	//opening stats file
	statsFile.open("statistics.txt", ios::app);

	//finding the correct stats to load
	while(statsFile >> playerName)
	{
		//loading the corresponding stats when a match is found
		if(playerName == currentPlayer)
		{
			statsFile >> gamesPlayed_;
			statsFile >> gamesWon_;
			statsFile >> gamesLost_;
			statsFile >> flagsCaptured_;
			statsFile >> capturedFlags_;
			statsFile >> timesExtinct_;
			statsFile >> genocide_;
		}
		//advancing to the next stored name in the file if a match is not found
		else
		{
			statsFile.seekg(28L, ios::cur);
		}
	}
	
	if( playerName != currentPlayer )
	{
		return false;
	}
	else
	{
		return true;
	}

	statsFile.close();

	return 0;
}

//*******************************************************************
void Statistics::display() const
{
	//display stats
}
