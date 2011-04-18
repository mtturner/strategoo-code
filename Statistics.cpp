/******************************************************
	Statistics.cpp

	This is the implementation file for the 
	Statistics class.
******************************************************/

#include "SDL.h"
#include "SDL_ttf.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
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
	ifstream search;
	ofstream output;
	string playerName;
	long readPos;
	bool newPlayer = true;

	//opening input stream to search player data
	search.open("statistics.txt", ios::in);
	
	//reading through data
	while(search >> playerName)
	{
		if(playerName == currentPlayer)
		{
			//catching current position
			readPos = search.tellg();
			//current player is not new
			newPlayer = false;
		}
	}

	//closing input stream
	search.close();

	//opening output stream to record new data
	output.open("statistics.txt", ios::out|ios::in);

	//if current player is not new go to their prior saved data
	if(newPlayer == false)
	{
		output.seekp(readPos, ios::beg);
	}
	//if current player is new go to the end of the file
	else
	{
		output.seekp(0L, ios::end);
		output << "\n" << currentPlayer;
	}

	//writing out current player's stats
	output << "\n" << gamesPlayed_;
	output << "\n" << gamesWon_;
	output << "\n" << gamesLost_;
	output << "\n" << flagsCaptured_;
	output << "\n" << capturedFlags_;
	output << "\n" << timesExtinct_;
	output << "\n" << genocide_;

	//closing output stream
	output.close();

	//relay whether current player is new
	if(newPlayer)
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
	fstream statsFile;
	string playerName;

	//opening stats file
	statsFile.open("statistics.txt", ios::in);

	//reading through data
	while(statsFile >> playerName)
	{
		//loading data if stored data exists
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
	}
	
	//closing input stream
	statsFile.close();

	//relaying if player had stored data
	if(gamesPlayed_ == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

//*******************************************************************
bool Statistics::setSprites() const
{
	//creating surface for statistics text
	SDL_Surface* currentStat;

	//declaring an SDL font to use
	TTF_Font* font = NULL;

	//setting text color to black
	SDL_Color textColor = {0, 0, 0};

	//open font file that will be referenced
	font = TTF_OpenFont("armalite.ttf", 28);

	//error checking
	if(font == NULL)
	{
		return false;
	}

	//declaring char array to hold converted variable
	string currentVar;

	//declaring string stream to write variables to
	stringstream outStr;

	//setting gamesPlayed variable
	outStr << gamesPlayed_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	gamesPlayedLine->setSurface(currentStat);
	outStr.str("");

	//setting gamesWon variable
	outStr << gamesWon_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	gamesWonLine->setSurface(currentStat);
	outStr.str("");

	//setting gamesLost variable
	outStr << gamesLost_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	gamesLostLine->setSurface(currentStat);
	outStr.str("");

	//setting flagsCaptured variable
	outStr << flagsCaptured_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	flagsCapturedLine->setSurface(currentStat);
	outStr.str("");

	//setting capturedFlags variable
	outStr << capturedFlags_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	capturedFlagsLine->setSurface(currentStat);
	outStr.str("");

	//setting timesExtinct variable
	outStr << timesExtinct_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	timesExtinctLine->setSurface(currentStat);
	outStr.str("");

	//setting genocide variable
	outStr << genocide_;
	currentVar = outStr.str();
	currentStat = TTF_RenderText_Solid(font, currentVar.c_str(), textColor);
	genocideLine->setSurface(currentStat);
	
	//closing reference to prior used font
	TTF_CloseFont(font);
	
	//error checking
	if(currentStat == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//******************************************************************************
void Statistics::display(SDL_Surface* background) const
{
	//setting individual stat surfaces to display
	gamesPlayedLine->show(background);
	gamesWonLine->show(background);
	gamesLostLine->show(background);
	flagsCapturedLine->show(background);
	capturedFlagsLine->show(background);
	timesExtinctLine->show(background);
	genocideLine->show(background);
}