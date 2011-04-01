//Marshal.h
#ifndef MARSHAL_H
#define MARSHAL_H

class Marshal: public Piece
{
      public:
             Marshal();
             Marshal(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Marshal();     
};

#endif
