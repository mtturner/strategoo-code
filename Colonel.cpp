#include "Sprite.h"
#include "Piece.h"
#include "Colonel.h"

Colonel::Colonel(): Piece()
{
}
//****************************************
Colonel::Colonel(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage): Piece(xPos, yPos,  rank,  owner, boardSpace, pieceImage)
{
}
Colonel::~Colonel()
{
}

