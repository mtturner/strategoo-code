//Scout.h
#ifndef SCOUT_H
#define SCOUT_H

class Scout: public Piece
{
      public:
             Scout();
             Scout(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Scout();
             bool move();   
};

#endif
