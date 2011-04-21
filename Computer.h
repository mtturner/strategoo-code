/******************************************************
	Computer.h

	This is the header file for the Computer class.
******************************************************/

#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include <algorithm>
#include "Piece.h"

class Computer
{
public:
    Computer();
    ~Computer();
    
	void addPiece(Piece* piece);
    void clearPiece(const int boardSpace);
    void clearPieces();
	Piece* findPieceAtPosition(const int position);
	void setPieces();
	inline int getNumPieces() const;
    
private:
    std::vector<Piece*> pieces;
};

inline int Computer::getNumPieces() const
{
	return pieces.size();
}

#endif
