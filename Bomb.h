/******************************************************
	Bomb.h

	This is the header file for the Bomb class.
******************************************************/

#ifndef BOMB_H
#define BOMB_H

#include"Piece.h"

class Bomb : public Piece
{
public:
	Bomb();
    Bomb(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
    ~Bomb();

    bool move();    
};

#endif
