//This is the class that defines the stored statistics

#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{

public:

	Statistics();
	~Statistics();
	//void loadPlayerStatistics() const;
	void display() const;

private:

	int gamesPlayed,
		gamesWon,
		gamesLost,
		flagsCaptured,
		capturedFlags,
		timesExtinct,
		genocide;

};

#endif STATISTICS_H