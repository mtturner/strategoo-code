#include "Sprite.h"
#include "Piece.h"
#include "Spy.h"

Spy::Spy(): Piece()
{
}
//****************************************
Spy::Spy(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage): Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}
Spy::~Spy()
{
}
