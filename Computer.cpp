/******************************************************
	Computer.cpp

	This is the implementation file for the Computer
	class.
******************************************************/

#include "Computer.h"

Computer::Computer()
{
}

//*********************************
Computer::~Computer()
{
}

//*********************************
void Computer::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//*********************************
void Computer::clearPiece()
{
}

//*********************************
void Computer::clearPieces()
{
}

//*********************************
void Computer::setPieces()
{
	//vector to hold board spaces
	std::vector<int> vect;

	//iterator
	std::vector<Piece*>::iterator iter;

	//counter
	int i = 0;

	for(int x = 0; x < 40; x++)
	{
		vect.push_back(x);
	}

	//shuffle vector
	std::random_shuffle(vect.begin(), vect.end());

	//assign pieces board space and rendering position
	for(iter = pieces.begin(); iter != pieces.end(); iter++)
	{
		//assign board space
		(*iter)->setBoardSpace(vect.at(i));

		//increment
		i++;

		//assign rendering position
		switch((*iter)->getBoardSpace())
		{
		case 0:
			(*iter)->setXPos(200);
			(*iter)->setYPos(0);
			break;
		case 1:
			(*iter)->setXPos(260);
			(*iter)->setYPos(0);
			break;
		case 2:
			(*iter)->setXPos(320);
			(*iter)->setYPos(0);
			break;
		case 3:
			(*iter)->setXPos(380);
			(*iter)->setYPos(0);
			break;
		case 4:
			(*iter)->setXPos(440);
			(*iter)->setYPos(0);
			break;
		case 5:
			(*iter)->setXPos(500);
			(*iter)->setYPos(0);
			break;
		case 6:
			(*iter)->setXPos(560);
			(*iter)->setYPos(0);
			break;
		case 7:
			(*iter)->setXPos(620);
			(*iter)->setYPos(0);
			break;
		case 8:
			(*iter)->setXPos(680);
			(*iter)->setYPos(0);
			break;
		case 9:
			(*iter)->setXPos(740);
			(*iter)->setYPos(0);
			break;
		case 10:
			(*iter)->setXPos(200);
			(*iter)->setYPos(60);
			break;
		case 11:
			(*iter)->setXPos(260);
			(*iter)->setYPos(60);
			break;
		case 12:
			(*iter)->setXPos(320);
			(*iter)->setYPos(60);
			break;
		case 13:
			(*iter)->setXPos(380);
			(*iter)->setYPos(60);
			break;
		case 14:
			(*iter)->setXPos(440);
			(*iter)->setYPos(60);
			break;
		case 15:
			(*iter)->setXPos(500);
			(*iter)->setYPos(60);
			break;
		case 16:
			(*iter)->setXPos(560);
			(*iter)->setYPos(60);
			break;
		case 17:
			(*iter)->setXPos(620);
			(*iter)->setYPos(60);
			break;
		case 18:
			(*iter)->setXPos(680);
			(*iter)->setYPos(60);
			break;
		case 19:
			(*iter)->setXPos(740);
			(*iter)->setYPos(60);
			break;
		case 20:
			(*iter)->setXPos(200);
			(*iter)->setYPos(120);
			break;
		case 21:
			(*iter)->setXPos(260);
			(*iter)->setYPos(120);
			break;
		case 22:
			(*iter)->setXPos(320);
			(*iter)->setYPos(120);
			break;
		case 23:
			(*iter)->setXPos(380);
			(*iter)->setYPos(120);
			break;
		case 24:
			(*iter)->setXPos(440);
			(*iter)->setYPos(120);
			break;
		case 25:
			(*iter)->setXPos(500);
			(*iter)->setYPos(120);
			break;
		case 26:
			(*iter)->setXPos(560);
			(*iter)->setYPos(120);
			break;
		case 27:
			(*iter)->setXPos(620);
			(*iter)->setYPos(120);
			break;
		case 28:
			(*iter)->setXPos(680);
			(*iter)->setYPos(120);
			break;
		case 29:
			(*iter)->setXPos(740);
			(*iter)->setYPos(120);
			break;
		case 30:
			(*iter)->setXPos(200);
			(*iter)->setYPos(180);
			break;
		case 31:
			(*iter)->setXPos(260);
			(*iter)->setYPos(180);
			break;
		case 32:
			(*iter)->setXPos(320);
			(*iter)->setYPos(180);
			break;
		case 33:
			(*iter)->setXPos(380);
			(*iter)->setYPos(180);
			break;
		case 34:
			(*iter)->setXPos(440);
			(*iter)->setYPos(180);
			break;
		case 35:
			(*iter)->setXPos(500);
			(*iter)->setYPos(180);
			break;
		case 36:
			(*iter)->setXPos(560);
			(*iter)->setYPos(180);
			break;
		case 37:
			(*iter)->setXPos(620);
			(*iter)->setYPos(180);
			break;
		case 38:
			(*iter)->setXPos(680);
			(*iter)->setYPos(180);
			break;
		case 39:
			(*iter)->setXPos(740);
			(*iter)->setYPos(180);
			break;
		}
	}
}
