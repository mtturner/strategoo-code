//Miner.h
#ifndef MINER_H
#define MINER_H

class Miner: public Piece
{
      public:
             Miner();
             Miner(int xPos, int yPos, int rank, int owner, int boardSpace, Sprite* pieceImage);
             ~Miner();     
};

#endif
