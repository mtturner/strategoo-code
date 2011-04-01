#include "Sprite.h"
#include "Piece.h"
#include "Major.h"

Major::Major(): Piece()
{
}
//****************************************
Major::Major(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage): Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}
Major::~Major()
{
}
