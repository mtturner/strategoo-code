//EmptySpace.h
#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

class EmptySpace: public Piece
{
      public:
             EmptySpace();
             EmptySpace(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~EmptySpace();
             bool move();     
};

#endif
