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
	//constructor and destructor
    Computer();
    
	//collection functions
	void addPiece(Piece* const piece);
    void clearPiece(const int boardSpace);
    inline void clearPieces();
	Piece* findPieceAtPosition(const int position);
	inline int getNumPieces() const;
	
	//piece functions
	void setPieces();
    
private:
	//collection of pieces
    std::vector<Piece*> pieces;
};

//*****************************************************
inline void Computer::clearPieces()
{
	pieces.clear();
}

//*****************************************************
inline int Computer::getNumPieces() const
{
	return pieces.size();
}

#endif
