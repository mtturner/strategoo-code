//Bomb.h
#ifndef BOMB_H
#define BOMB_H

class Bomb: public Piece
{
      public:
             Bomb();
             Bomb(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Bomb();
             bool move();    
};

#endif
