//This is the class defining the board of the game

#ifndef BOARD_H
#define BOARD_H

class Board
{

public:

	Board();
	~Board();
	bool addPiece();
	void clearPiece();
	void clearPieces();
	void render() const;

private:

	Piece pieces;
	Sprite image;

};

#endif BOARD_H