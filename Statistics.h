//This is the class that defines the stored statistics of the game

#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
public:
    Statistics();
    ~Statistics();

    void load();
    void display() const;

private:
    int gamesPlayed_,
	gamesWon_,
	gamesLost_,
	flagsCaptured_,
	capturedFlags_,
	timesExtinct_,
	genocide_;
};

#endif
