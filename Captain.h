//Captain.h
#ifndef CAPTAIN_H
#define CAPTAIN_H

class Captain: public Piece
{
      public:
             Captain();
             Captain(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Captain();     
};

#endif
