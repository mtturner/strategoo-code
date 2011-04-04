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
bool Statistics::save(std::string currentPlayer)
{
	//declaring local variables
	fstream statsFile;
	std::string playerName;

	statsFile.open("statistics.txt", ios::ate);

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
}

//*******************************************************************
bool Statistics::load(std::string currentPlayer)
{
	//declaring local variables
	ifstream statsFile;
	std::string playerName;

	//opening stats file
	statsFile.open("statistics.txt", ios::ate);

	//finding the correct stats to load
	while( statsFile >> playerName )
	{
		//loading the corresponding stats when a match is found
		if( playerName == currentPlayer)
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
			statsFile >> endl;
			statsFile >> endl;
			statsFile >> endl;
			statsFile >> endl;
			statsFile >> endl;
			statsFile >> endl;
			statsFile >> endl;
		}
	}
	
	if( playerName != currentPlayer )
	{
		return false;
	}

	statsFile.close();
}

//*******************************************************************
void Statistics::display() const
{
	//display stats
}
