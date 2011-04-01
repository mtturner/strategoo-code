//General.h
#ifndef GENERAL_H
#define GENERAL_H

class General: public Piece
{
      public:
             General();
             General(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~General();     
};

#endif
