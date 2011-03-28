//Piece.h
#ifndef PIECE_H
#define PIECE_H

class Piece
{
      public:
             Piece(int, int, int, int, int, Sprite*);
             ~Piece();
             bool move();
             void namePiece();
             void render();
             int getRank() const;
             int getXPos() const;
             int getYPos() const;
             int getBoardSpace() const;
             int getOwner() const;
             Sprite* getPieceImage() const;
      private:
              int xPos,
                  yPos,
                  boardSpace,
                  rank,
                  owner;
              Sprite* pieceImage;
              void setRank(int);
              void setXPos(int);
              void setYPos(int);
              void setBoardSpace(int);
              void setOwner(int);
              void setPieceImage(Sprite*);
};

#endif
