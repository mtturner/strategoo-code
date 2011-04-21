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
bool Board::isMoveablePiece(Piece* selected, int mover)
{

    //booleans to determine the movibility of the selected piece
	bool movablePiece = true,
        frontBlocked = false,
        backBlocked = false,
        rightBlocked = false,
        leftBlocked = false;


    //iterator
	std::vector<Piece*>::iterator iter;

	//check that mover is the owner of the piece
	if(selected->getOwner() == mover)
	{
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
					if( ((*iter)->getBoardSpace() == (selected->getBoardSpace() + 1)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece is block on the right side
						rightBlocked = true;
					}
					//if the board's piece is behind the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece blocked on the back side
						backBlocked = true;
					}
					//if the board's piece is in front of the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
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
					if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 1)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece is blocked on the left side
						leftBlocked = true;
					}
					//if the board's piece is behind the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece blocked on the back side
						backBlocked = true;
					}
					//if the board's piece is in front of the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
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
					if( ((*iter)->getBoardSpace() == (selected->getBoardSpace() + 1)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece is block on the right side
						rightBlocked = true;
					}
					//if the board's piece is to the left of the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 1)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece is blocked on the left side
						leftBlocked = true;
					}
					//if the board's piece is behind the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() + 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece blocked on the back side
						backBlocked = true;
					}
					//if the board's piece is in front of the selected piece, and shares an owner with the selected piece
					else if(((*iter)->getBoardSpace() == (selected->getBoardSpace() - 10)) && ((*iter)->getOwner() == selected->getOwner()) && ((*iter)->getRank() != 0))
					{
						//the selected piece is block on the front side
						frontBlocked = true;
					}
				}
			}

			//things that were missed
			//if the selected piece is block by no mans land
			if((selected->getBoardSpace() == 62) || (selected->getBoardSpace() == 63) || (selected->getBoardSpace() == 67) || (selected->getBoardSpace() == 66))
			{
				frontBlocked = true;
			}
			if((selected->getBoardSpace() == 32) || (selected->getBoardSpace() == 33) || (selected->getBoardSpace() == 37) || (selected->getBoardSpace() == 36))
			{
				backBlocked = true;
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
	}
	else
	{
		movablePiece = false;
	}

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
			direction = 1;
		}
		else
		{
			direction = 3;
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
			else
			{
				found = true;

				valid = false;
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
			else
			{
				found = true;

				valid = false;
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
			else
			{
				found = true;

				valid = false;
			}

			i += 10;
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
			else
			{
				found = true;

				valid = false;
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
