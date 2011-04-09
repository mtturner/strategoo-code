/******************************************************
	Computer.h

	This is the header file for the Computer class.
******************************************************/

#ifndef COMPUTER_H
#define COMPUTER_H

#include<vector>
#include"Piece.h"

class Computer
{
public:
    Computer();
    ~Computer();
    
	void addPiece(Piece* piece);
    void clearPiece();
    void clearPieces();
    
private:
    std::vector<Piece*> pieces;
};

#endif
