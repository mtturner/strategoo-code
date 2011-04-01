#include "Sprite.h"
#include "Piece.h"
#include "Marshal.h"

Marshal::Marshal(): Piece()
{
}
//****************************************
Marshal::Marshal(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage): Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}
Marshal::~Marshal()
{
}
