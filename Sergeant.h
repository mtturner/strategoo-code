//Sergeant.h
#ifndef SERGEANT_H
#define SERGEANT_H

class Sergeant: public Piece
{
      public:
             Sergeant();
             Sergeant(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Sergeant();     
};

#endif
