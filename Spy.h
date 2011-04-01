//Spy.h
#ifndef SPY_H
#define SPY_H

class Spy: public Piece
{
      public:
             Spy();
             Spy(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Spy();     
};

#endif
