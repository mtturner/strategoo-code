//Major.h
#ifndef MAJOR_H
#define MAJOR_H

class Major: public Piece
{
      public:
             Major();
             Major(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Major();     
};

#endif
