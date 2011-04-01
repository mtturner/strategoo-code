#include "Sprite.h"
#include "Piece.h"
#include "Bomb.h"

Bomb::Bomb(): Piece()
{
}
//****************************************
Bomb::Bomb(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage): Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}
//****************************************
Bomb::~Bomb()
{
}
//****************************************
bool Bomb::move()
{
            return true;
}
