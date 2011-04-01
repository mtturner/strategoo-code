//Lieutenant.h
#ifndef LIEUTENANT_H
#define LIEUTENANT_H

class Lieutenant: public Piece
{
      public:
             Lieutenant();
             Lieutenant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Lieutenant();     
};

#endif
