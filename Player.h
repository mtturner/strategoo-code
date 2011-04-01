//This is the class that defines the human player of the game

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();
	~Player();

	void clearPiece();
	void clearPieces();
	void loadStatistics();
	void displayStatistics() const;

private:
	std::string name;
	Statistics* stats;
	std::vector<Piece*> pieces;
};

#endif
