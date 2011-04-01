//Flag.h
#ifndef FLAG_H
#define FLAG_H

class Flag: public Piece
{
      public:
             Flag();
             Flag(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Flag();
             bool move();     
};

#endif
