//Colonel.h
#ifndef COLONEL_H
#define COLONEL_H

class Colonel: public Piece
{
      public:
             Colonel();
             Colonel(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Colonel();     
};

#endif
