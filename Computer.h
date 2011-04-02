//This is the class defining the AI player of the game

#ifndef COMPUTER_H
#define COMPUTER_H

#include<vector>
#include"Piece.h"

class Computer
{
public:
    Computer();
    ~Computer();
    
    void clearPiece();
    void clearPieces();
    
private:
    std::vector<Piece*> computerPieces;
};

#endif
