/******************************************************
	Board.cpp

	This is the implementation file for the Board
	class.
******************************************************/

#include "Board.h"

Board::Board()
{
}

//*******************************************************************
Board::~Board()
{
}

//*******************************************************************
void Board::clearPiece(const int boardSpace)
{
	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	//found boolean
	bool found = false;

	while(!found && iter != pieces.end())
	{
		if((*iter)->getBoardSpace() == boardSpace)
		{
			found = true;

			pieces.erase(iter);
		}

		if(!found)
		{
			iter++;
		}
	}
}

//*******************************************************************
void Board::clearPieces()
{
	//clear pieces
}

//*******************************************************************
void Board::handlePieceInput(SDL_Event& gEvent)
{
	//iterator
	std::vector<Piece*>::iterator iter;

	for(iter = pieces.begin(); iter != pieces.end(); iter++)
	{
		(*iter)->handleInput(gEvent);
	}
}

//*******************************************************************
Piece* Board::findSelectedPiece()
{
	//temp piece
	Piece* temp = 0;

	//found boolean
	bool found = false;

	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	while(iter != pieces.end() && !found)
	{
		//if the piece has been selected
		if((*iter)->getIsSelected())
		{
			temp = *iter;

			//reset piece
			temp->setIsSelected(false);

			found = true;
		}

		iter++;
	}

	return temp;
}

//*******************************************************************
Piece* Board::findPieceAtBoardSpace(const int boardSpace)
{
	//iterator
	std::vector<Piece*>::iterator iter = pieces.begin();

	//found boolean
	bool found = false;

	while(!found && iter != pieces.end())
	{
		if((*iter)->getBoardSpace() == boardSpace)
		{
			found = true;
		}

		if(!found)
		{
			iter++;
		}
	}

	if(found)
	{
		return *iter;
	}
	else
	{
		return 0;
	}
}

//*******************************************************************
bool Board::isMoveablePiece(Piece* selected)
{
    //booleans to determine the movibility of the selected piece
	bool movablePiece = true,
        frontBlocked = false,
        backBlocked = false,
        rightBlocked = false,
        leftBlocked = false;

    //iterator
	std::vector<Piece*>::iterator iter;

    //if the selected piece is a flag, bomb, or empty space
	if((selected->getRank() == 12) ||
    (selected->getRank() == 11) ||
    (selected->getRank() == 0))
    {
        //the piece is not movable
        movablePiece = false;
    }
    //overwise check to see if the selected piece is blocked on all sides
    else
    {
        //if the selected piece is on the left edge of the board
        if(((selected->getBoardSpace()) == 60) || ((selected->getBoardSpace()) == 70) ||
        ((selected->getBoardSpace()) == 80) || ((selected->getBoardSpace()) == 90) ||
        ((selected->getBoardSpace()) == 0) || ((selected->getBoardSpace()) == 10) ||
        ((selected->getBoardSpace()) == 20) || ((selected->getBoardSpace()) == 30) ||
        ((selected->getBoardSpace()) == 40) || ((selected->getBoardSpace()) == 50))
        {
            //the selected piece is blocked on the left side
            leftBlocked = true;

            //check the board's collection for pieces that block the selected piece
            for(iter = pieces.begin(); iter != pieces.end(); iter++)
            {
                //if the board's piece is to the right of the selected piece, and shares an owner with the selected piece
                if( ((*iter)->getBoardSpace() == (selected->getBoardSpace() + 1)) && ((*iter)->getOwner() == selected->getOwner()) )
                {
                    //the selected piece is block on the right side
                    rightBlocked = true;
                }
                //if the board's piece is behind the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece blocked on the back side
                    backBlocked = true;
                }
                //if the board's piece is in front of the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece is block on the front side
                    frontBlocked = true;
                }
            }
        }
        //if the selected piece is on the right edge of the board
        else if(((selected->getBoardSpace()) == 69) || ((selected->getBoardSpace()) == 79) ||
        ((selected->getBoardSpace()) == 89) || ((selected->getBoardSpace()) == 99) ||
        ((selected->getBoardSpace()) == 9) || ((selected->getBoardSpace()) == 19) ||
        ((selected->getBoardSpace()) == 29) || ((selected->getBoardSpace()) == 39) ||
        ((selected->getBoardSpace()) == 49) || ((selected->getBoardSpace()) == 59))
        {
            //the selected piece is blocked on the right side
            rightBlocked = true;

            //check the board's collection for pieces that block the selected piece
            for(iter = pieces.begin(); iter != pieces.end(); iter++)
            {
                //if the board's piece is to the left of the selected piece, and shares an owner with the selected piece
                if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 1)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece is blocked on the left side
                    leftBlocked = true;
                }
                //if the board's piece is behind the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece blocked on the back side
                    backBlocked = true;
                }
                //if the board's piece is in front of the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece is block on the front side
                    frontBlocked = true;
                }
            }
        }
        //otherwise
        else
        {
            //check the board's collection for pieces that block the selected piece
            for(iter = pieces.begin(); iter != pieces.end(); iter++)
            {
                //if the board's piece is to the right of the selected piece, and shares an owner with the selected piece
                if( ((*iter)->getBoardSpace() == (selected->getBoardSpace() + 1)) && ((*iter)->getOwner() == selected->getOwner()) )
                {
                    //the selected piece is block on the right side
                    rightBlocked = true;
                }
                //if the board's piece is to the left of the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 1)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece is blocked on the left side
                    leftBlocked = true;
                }
                //if the board's piece is behind the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece blocked on the back side
                    backBlocked = true;
                }
                //if the board's piece is in front of the selected piece, and shares an owner with the selected piece
                else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()))
                {
                    //the selected piece is block on the front side
                    frontBlocked = true;
                }
            }
        }

        //if the selected piece is in the top row
        if(selected->getBoardSpace() < 10)
        {
            //the selected piece is block on the front side
            frontBlocked = true;
        }
        //if the selected piece is in the bottom row
        if(selected->getBoardSpace() > 89)
        {
            //the selected piece blocked on the back side
            backBlocked = true;
        }
    }

    //if the selected piece is blocked on all sides
    if(rightBlocked && leftBlocked && frontBlocked && backBlocked)
    {
        //the selected piece is not movable
        movablePiece = false;
    }

	/*
	//pieces above, below, to the left of, and to the right of selected
	Piece* up = 0;
	Piece* down = 0;
	Piece* left = 0;
	Piece* right = 0;

	//board spaces
	int upBS = 0,
		downBS = 0,
		leftBS = 0,
		rightBS = 0;

	if((selected->getRank() == 12) || (selected->getRank() == 11) ||
	   (selected->getRank() == 0))
	{
		moveablePiece = false;
	}
	else
	{
		//set board spaces
		if((selected->getBoardSpace() - 10) > -1)
		{
			upBS = selected->getBoardSpace() - 10;

			if(upBS == 42 || upBS == 43 || upBS == 46 || upBS == 47 ||
			   upBS == 52 || upBS == 53 || upBS == 56 || upBS == 57)
			{
				upBS = selected->getBoardSpace();
			}
		}
		else
		{
			upBS = selected->getBoardSpace();
		}

		if((selected->getBoardSpace() + 10) < 100)
		{
			downBS = selected->getBoardSpace() + 10;

			if(downBS == 42 || downBS == 43 || downBS == 46 || downBS == 47 ||
			   downBS == 52 || downBS == 53 || downBS == 56 || downBS == 57)
			{
				downBS = selected->getBoardSpace();
			}
		}
		else
		{
			downBS = selected->getBoardSpace();
		}

		if(((selected->getBoardSpace() + 1) / 10) == (selected->getBoardSpace() / 10) &&
		   selected->getBoardSpace() + 1 < 100)
		{
			rightBS = selected->getBoardSpace() + 1;

			if(rightBS == 42 || rightBS == 43 || rightBS == 46 || rightBS == 47 ||
			   rightBS == 52 || rightBS == 53 || rightBS == 56 || rightBS == 57)
			{
				rightBS = selected->getBoardSpace();
			}
		}
		else
		{
			rightBS = selected->getBoardSpace();
		}

		if(((selected->getBoardSpace() - 1) / 10) == (selected->getBoardSpace() / 10) &&
		   selected->getBoardSpace() - 1 > -1)
		{
			leftBS = selected->getBoardSpace() - 1;

			if(leftBS == 42 || leftBS == 43 || leftBS == 46 || leftBS == 47 ||
			   leftBS == 52 || leftBS == 53 || leftBS == 56 || leftBS == 57)
			{
				leftBS = selected->getBoardSpace();
			}
		}
		else
		{
			leftBS = selected->getBoardSpace();
		}

		//set pieces
		up = findPieceAtBoardSpace(upBS);
		down = findPieceAtBoardSpace(downBS);
		left = findPieceAtBoardSpace(leftBS);
		right = findPieceAtBoardSpace(rightBS);

		if(selected->getOwner() == up->getOwner() && selected->getOwner() == down->getOwner() &&
		   selected->getOwner() == left->getOwner() && selected->getOwner() == right->getOwner())
		{
			moveablePiece = false;
		}
	}
	*/

	return movablePiece;
}

//*******************************************************************
bool Board::isValidScoutMove(Piece* scout, Piece* destination)
{
	//temporary piece
	Piece* temp = 0;

	//valid  and found booleans
	bool valid = true,
		 found = false;

	//counter variable
	int i = 0;

	//direction to destination
	//up - 1, right - 2, down - 3, left - 4
	int direction = 0;

	if((scout->getBoardSpace() % 10) == (destination->getBoardSpace() % 10))
	{
		if(scout->getBoardSpace() > destination->getBoardSpace())
		{
			direction = 3;
		}
		else
		{
			direction = 1 ;
		}
	}
	else
	{
		if(scout->getBoardSpace() > destination->getBoardSpace())
		{
			direction = 4;
		}
		else
		{
			direction = 2;
		}
	}

	switch(direction)
	{
	//above
	case 1:
		i = scout->getBoardSpace() - 10;

		while(!found && i > -1)
		{
			temp = findPieceAtBoardSpace(i);

			if(temp != 0)
			{
				if(temp->getBoardSpace() == destination->getBoardSpace())
				{
					found = true;
				}

				if(temp->getBoardSpace() != destination->getBoardSpace() &&
				   temp->getRank() != 0)
				{
					valid = false;
				}
			}

			i -= 10;
		}

		break;

	//to the right of
	case 2:
		i = scout->getBoardSpace() + 1;

		while(!found && i < (((scout->getBoardSpace() / 10) + 1) * 10))
		{
			temp = findPieceAtBoardSpace(i);

			if(temp != 0)
			{
				if(temp->getBoardSpace() == destination->getBoardSpace())
				{
					found = true;
				}

				if(temp->getBoardSpace() != destination->getBoardSpace() &&
				   temp->getRank() != 0)
				{
					valid = false;
				}
			}

			i++;
		}

		break;

	//below
	case 3:
		i = scout->getBoardSpace() + 10;

		while(!found && i < 100)
		{
			temp = findPieceAtBoardSpace(i);

			if(temp != 0)
			{
				if(temp->getBoardSpace() == destination->getBoardSpace())
				{
					found = true;
				}

				if(temp->getBoardSpace() != destination->getBoardSpace() &&
				   temp->getRank() != 0)
				{
					valid = false;
				}
			}

			i -= 10;
		}
		break;

	//to the left of
	case 4:
		i = scout->getBoardSpace() - 1;

		while(!found && i > (((scout->getBoardSpace() / 10) * 10)) - 1)
		{
			temp = findPieceAtBoardSpace(i);

			if(temp != 0)
			{
				if(temp->getBoardSpace() == destination->getBoardSpace())
				{
					found = true;
				}

				if(temp->getBoardSpace() != destination->getBoardSpace() &&
				   temp->getRank() != 0)
				{
					valid = false;
				}
			}

			i--;
		}
		break;
	}

	return valid;
}

//*******************************************************************
void Board::show(SDL_Surface* destination) const
{
	//iterator
	std::vector<Piece*>::const_iterator iter;

	//render pieces
	for(iter = pieces.begin(); iter != pieces.end(); iter++)
	{
		(*iter)->show(destination);
	}
}

//*********************************
void Board::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}
