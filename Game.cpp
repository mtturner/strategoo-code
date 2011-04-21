/******************************************************
	Game.cpp

	This is the implementation file for the Game 
	class.
******************************************************/

#include "Game.h"

Game::Game() : screen(0)
{
	//set player, computer and board pointers to null
	gPlayer = 0;
	gComputer = 0;
	gBoard = 0;

	//set initial game state
	setState(0);

	//set booleans to false
	setIsPieceSelected(false);
	setIsButtonSelected(false);

	//dynamically allocate sprite objects
	introBG = new Sprite();
	loginBG = new Sprite();
	startMenuBG = new Sprite();
	setPieceBG = new Sprite();
	playGameBG = new Sprite();
	endGameBG = new Sprite();
	menuBG = new Sprite();
	statisticsBG = new Sprite();
}

//******************************************
Game::~Game()
{
	//delete dynamically allocated sprites
	delete introBG;
	delete loginBG;
	delete startMenuBG;
	delete setPieceBG;
	delete playGameBG;
	delete endGameBG;
	delete menuBG;
	delete statisticsBG;

	//delete player, computer, and board
	delete gPlayer;
	delete gComputer;
	delete gBoard;

	//delete selector and string input
	delete gSelector;
	delete name;

	//delete piece buttons
	for(int i = 0; i < 12; i++)
	{
		delete buttons[i];
	}
	
	//delete overlays
	delete pieceOverlay;
	delete buttonOverlay;

	//delete set piece finish
	delete finishedSetPiece;
}

//******************************************
void Game::startGame()
{
	//create player, computer, and board
	gComputer = new Computer();
	gBoard = new Board();

	//temporary piece for creation
	Piece* temp = 0;

	//piece coordinates
	int x = 200,
		y = 240;

	//create emptyspace's and add to appropriate collections
	for(int i = 0; i < 100; i++)
	{
		//skip over no man's land
		if(i == 42)
		{
			i = 44;
		}
		else if(i == 46)
		{
			i = 48;
		}
		else if(i == 52)
		{
			i = 54;
		}
		else if(i == 56)
		{
			i = 58;
		}

		//if 40 pieces have been created
		if(i > 39)
		{
			temp = new EmptySpace(x, y, i);

			//add to board's collection along with game's collection
			gBoard->addPiece(temp);
			addPiece(temp);

			//update coordinates
			x += 60;

			if(x == 800)
			{
				x = 200;
				y += 60;
			}

			//skip over no man's land
			if((x == 320) && (y == 240))
			{
				x = 440;
			}
			else if((x == 560) && (y == 240))
			{
				x = 680;
			}
			else if((x == 320) && (y == 300))
			{
				x = 440;
			}
			else if((x == 560) && (y == 300))
			{
				x = 680;
			}
		}
		//if the first 40 pieces have already been created,
		//only add piece to game's collection
		else
		{
			temp = new EmptySpace();

			addPiece(temp);
		}
	}

	//create marshals and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			temp = new Marshal();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Marshal("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create generals and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			temp = new General();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new General("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create colonels and add to appropriate collections
	for(int i = 0; i < 4; i++)
	{
		if(i < 2)
		{
			temp = new Colonel();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Colonel("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create majors and add to appropriate collections
	for(int i = 0; i < 6; i++)
	{
		if(i < 3)
		{
			temp = new Major();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Major("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create captains and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		if(i < 4)
		{
			temp = new Captain();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Captain("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create lieutenants and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		if(i < 4)
		{
			temp = new Lieutenant();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Lieutenant("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create sergeants and add to appropriate collections
	for(int i = 0; i < 8; i++)
	{
		if(i < 4)
		{
			temp = new Sergeant();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Sergeant("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create miners and add to appropriate collections
	for(int i = 0; i < 10; i++)
	{
		if(i < 5)
		{
			temp = new Miner();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Miner("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create scouts and add to appropriate collections
	for(int i = 0; i < 16; i++)
	{
		if(i < 8)
		{
			temp = new Scout();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Scout("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create spys and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			temp = new Spy();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Spy("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create bombs and add to appropriate collections
	for(int i = 0; i < 12; i++)
	{
		if(i < 6)
		{
			temp = new Bomb();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Bomb("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}

	//create flags and add to appropriate collections
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			temp = new Flag();

			addPiece(temp);
			gPlayer->addPiece(temp);
		}
		else
		{
			temp = new Flag("cpiece.png");

			addPiece(temp);
			gComputer->addPiece(temp);
			gBoard->addPiece(temp);
		}
	}
}

//******************************************
std::string Game::promptName()
{
	return "placeholder";
}

//******************************************
void Game::resetGame()
{
}

//******************************************
bool Game::findPiece() const
{
	return false;
}

//******************************************
Piece* Game::findEmptySpacePiece()
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
		if((*iter)->getRank() == 0 && (*iter)->getBoardSpace() == -1)
		{
			temp = *iter;

			found = true;
		}

		if(!found)
		{
			iter++;
		}
	}

	return temp;
}

//******************************************
bool Game::setPiece()
{
	return false;
}

//******************************************
bool Game::movePiece()
{
	return false;
}

//******************************************
bool Game::isMoveablePiece(Piece* selected, int mover)
{
	return gBoard->isMoveablePiece(selected, mover);
}

//******************************************
bool Game::isValidMove(Piece* selected, Piece* destination)
{
	//if the selected piece is not a scout
	if(selected->getRank() != 2)
	{
		//make sure destination is one space away above,
		//below, to the left of, or to the right of the
		//selected piece
		if(selected->getBoardSpace() != (destination->getBoardSpace() - 10) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() + 10) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() - 1) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() + 1))
		{
			return false;
		}
		else
		{
			//check to see if destination is emptyspace, and if not
			//check to see if pieces have different owners
			if(destination->getRank() != 0)
			{
				if(selected->getOwner() == destination->getOwner())
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
	}
	//else if piece is a scout
	else
	{
		//check to see if destination piece is directly
		//above, below, to the left of, or to the right
		//of the selected piece
		if((destination->getBoardSpace() % 10) == (selected->getBoardSpace() % 10) ||
		   (destination->getBoardSpace() / 10) == (selected->getBoardSpace() / 10))
		{
			//check to see if it is a valid scout move
			if(gBoard->isValidScoutMove(selected, destination))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

//******************************************
void Game::moveComputerPiece()
{
	//pieces
	Piece* selected = 0;
	Piece* destination = 0;
	Piece* winner = 0;
	Piece* temp = 0;

	//find piece and fine move booleans
	bool isFindingPiece = true,
		 isFindingMove = true;

	//found boolean
	bool found = false;

	//counter
	int i = 99;

	//find moveable piece
	while(isFindingPiece)
	{
		selected = gComputer->findRandomPiece();

		if(isMoveablePiece(selected, 1))
		{
			isFindingPiece = false;
		}
	}

	//find valid move
	while(isFindingMove)
	{
		//search board from bottom to top to help keep
		//the computer advancing
		while(!found)
		{
			//skip over no man's land
			if(i != 42 && i != 43 && i != 46 && i != 47 &&
			   i != 52 && i != 53 && i != 56 && i != 57)
			{
				destination = gBoard->findPieceAtBoardSpace(i);

				if(isValidMove(selected, destination))
				{
					found = true;

					isFindingMove = false;
				}
			}

			i--;
		}
	}

	//move piece
	winner = selected->move(destination);

	//depending on the move outcome, remove defeated
	//pieces from board's collection and owner's collection
	//if needed and add emptyspace's where necessary
	if(winner == 0)
	{
		temp = findEmptySpacePiece();

		gBoard->addPiece(temp);

		gBoard->clearPiece(destination->getBoardSpace());
		gBoard->clearPiece(selected->getBoardSpace());

		//remove pieces from player and computer collections
		if(selected->getOwner() == 0)
		{
			gPlayer->clearPiece(selected->getBoardSpace());
		}
		else
		{
			gComputer->clearPiece(selected->getBoardSpace());
		}

		if(destination->getOwner() == 0)
		{
			gPlayer->clearPiece(destination->getBoardSpace());
		}
		else
		{
			gComputer->clearPiece(destination->getBoardSpace());
		}

		swapLocation(temp, selected);

		temp = findEmptySpacePiece();

		gBoard->addPiece(temp);

		swapLocation(temp, destination);

		temp = 0;
	}
	else if(winner->getRank() == 0)
	{
		//dont need to clear any pieces
	}
	else if(winner->getBoardSpace() == destination->getBoardSpace())
	{
		temp = findEmptySpacePiece();

		gBoard->addPiece(temp);

		gBoard->clearPiece(selected->getBoardSpace());

		//remove pieces from player and computer collections
		if(selected->getOwner() == 0)
		{
			gPlayer->clearPiece(selected->getBoardSpace());
		}
		else
		{
			gComputer->clearPiece(selected->getBoardSpace());
		}

		swapLocation(temp, selected);

		temp = 0;
	}
	else
	{
		temp = findEmptySpacePiece();

		gBoard->addPiece(temp);

		gBoard->clearPiece(destination->getBoardSpace());

		//remove pieces from player and computer collections
		if(selected->getOwner() == 0)
		{
			gPlayer->clearPiece(destination->getBoardSpace());
		}
		else
		{
			gComputer->clearPiece(destination->getBoardSpace());
		}

		swapLocation(temp, destination);

		temp = 0;
	}
}

//******************************************
void Game::swapLocation(Piece* first, Piece* second)
{
	//x, y, and boardspace
	int x = 0,
		y = 0,
		boardSpace = 0;

	//hold first's position
	x = first->getXPos();
	y = first->getYPos();
	boardSpace = first->getBoardSpace();

	//set first's position to second's position
	first->setXPos(second->getXPos());
	first->setYPos(second->getYPos());
	first->setBoardSpace(second->getBoardSpace());

	//set second's position with first's position
	second->setXPos(x);
	second->setYPos(y);
	second->setBoardSpace(boardSpace);
}

//******************************************
void Game::namePiece()
{
}

//******************************************
void Game::addPiece(Piece* piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//******************************************
std::string Game::getPieceName() const
{
	return "placeholder";
}

//******************************************
void Game::loadMenu()
{
}

//******************************************
SDL_Rect* Game::getMouseCoords()
{
	SDL_Rect* rect = 0;

	return rect;
}

//******************************************
/*Piece* Game::getNewLocationPiece() const
{
}*/

//******************************************
void Game::displayStatistics() const
{
}

//******************************************
void Game::displayResults() const
{
}

//******************************************
void Game::clearPieces()
{
}

//******************************************
bool Game::initialize()
{
	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//initialize SDL_ttf
	if(TTF_Init() == -1)
	{
		return false;
	}

	//set up screen
	setScreen(SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE));

	SDL_WM_SetCaption("strategOO", "strategOO");

	//load images
	if(!introBG->load("intro.png"))
	{
		return false;
	}

	if(!loginBG->load("login.png"))
	{
		return false;
	}

	if(!startMenuBG->load("startmenu.png"))
	{
		return false;
	}

	if(!setPieceBG->load("board.png"))
	{
		return false;
	}

	if(!playGameBG->load("board.png"))
	{
		return false;
	}

	if(!endGameBG->load("endGame.png"))
	{
		return false;
	}

	if(!menuBG->load("ingamemenu.png"))
	{
		return false;
	}

	if(!statisticsBG->load("statistics.png"))
	{
		return false;
	}

	//create selector
	gSelector = new Selector();

	//create string input
	name = new StringInput();

	//create piece buttons
	buttons[0] = new PieceButton(0, 500, 11, "bombbutton.png");
	buttons[1] = new PieceButton(0, 200, 6, "captainbutton.png");
	buttons[2] = new PieceButton(0, 100, 8, "colonelbutton.png");
	buttons[3] = new PieceButton(0, 550, 12, "flagbutton.png");
	buttons[4] = new PieceButton(0, 50, 9, "generalbutton.png");
	buttons[5] = new PieceButton(0, 250, 5, "lieutenantbutton.png");
	buttons[6] = new PieceButton(0, 150, 7, "majorbutton.png");
	buttons[7] = new PieceButton(0, 0, 10, "marshalbutton.png");
	buttons[8] = new PieceButton(0, 350, 3, "minerbutton.png");
	buttons[9] = new PieceButton(0, 400, 2, "scoutbutton.png");
	buttons[10] = new PieceButton(0, 300, 4, "sergeantbutton.png");
	buttons[11] = new PieceButton(0, 450, 1, "spybutton.png");

	//create overlays
	pieceOverlay = new Sprite(0, 0, "pieceoverlay.png", 100);
	buttonOverlay = new Sprite(0, 0, "buttonoverlay.png", 100);

	//create set piece finish image
	finishedSetPiece = new Sprite(260, 50, "gamestart.png");

	if(getScreen() == 0)
	{
		return false;
	}

	return true;
}

//******************************************
void Game::cleanUp()
{
	//quit SDL_ttf
	TTF_Quit();

	//quit SDL
	SDL_Quit();
}
//******************************************
void Game::setState(int gameState)
{
	//state must be a number from 0 to 8
	if(gameState > -1 && gameState < 9)
	{
		gameState_ = gameState;
	}
}

//******************************************
bool Game::render() const
{
	if(SDL_Flip(getScreen()) == -1)
	{
		return false;
	}
	
	return true;
}

//******************************************
void Game::setScreen(SDL_Surface* s)
{
	//delete old screen
	SDL_FreeSurface(screen);

	if(s != 0)
	{
		screen = s;
	}
}

//******************************************
void Game::setIsPieceSelected(const bool selected)
{
	isPieceSelected = selected;
}

//******************************************
void Game::setIsButtonSelected(const bool selected)
{
	isButtonSelected = selected;
}

//******************************************
bool Game::doIntro()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				setState(STATE_LOGIN);
			}
		}
	}

	//apply the intro image to the screen
	introBG->show(getScreen());

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::login()
{
	bool isLoggingIn = true;
	std::string inputtedName;

	while(isLoggingIn)
	{
		while(SDL_PollEvent(&gEvent))
		{
			//if the user has exited the window
			if(gEvent.type == SDL_QUIT)
			{
				//set next state to exit
				setState(STATE_EXIT);

				isLoggingIn = false;
			}
			//else if the user has hit the enter key
			else if(gEvent.type == SDL_KEYDOWN)
			{
				if(gEvent.key.keysym.sym == SDLK_RETURN)
				{
					setState(STATE_STARTMENU);

					isLoggingIn = false;
				}
			}

			name->handleInput(gEvent);
		}

		//apply the login image to the screen
		loginBG->show(getScreen());

		//apply input text to screen
		name->show(getScreen());

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}
	
	//getting current user's name
	inputtedName = name->getInput();
	
	//create new player with name that was input
	gPlayer = new Player(inputtedName);

	gPlayer->loadStatistics();

	return true;
}

//******************************************
bool Game::doStartMenu()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
				
		//handle start menu selector input
		gSelector->handleInput(gEvent);

		//if the user has hit the enter key
		if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				if(gSelector->getChoice() == 0)
				{
					setState(STATE_SETPIECE);

					gSelector->reset();
				}
				else if(gSelector->getChoice() == 1)
				{
					setState(STATE_STATISTICS);

					gSelector->reset();
				}
			}
		}
	}

	//move the selector
	gSelector->move();

	//apply the start menu image and selector image to the screen
	startMenuBG->show(getScreen());
	gSelector->show(getScreen());

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doSetPiece()
{
	//start the game
	startGame();

	//set computer pieces
	gComputer->setPieces();

	//current piece button selection and
	//current piece selection
	PieceButton* currentButton = 0;
	Piece* currentPiece = 0;

	//clicked piece and unplaced piece
	Piece* clickedPiece = 0;
	Piece* unplacedPiece = 0;

	//button rank
	int buttonRank = -1;

	//setPiece loop boolean and finished boolean
	bool isSettingPiece = true,
		 finished = false;

	while(isSettingPiece)
	{
		while(SDL_PollEvent(&gEvent))
		{
			//if the user has exited the window
			if(gEvent.type == SDL_QUIT)
			{
				//set next state to exit
				setState(STATE_EXIT);

				isSettingPiece = false;
			}
			//else if the user has hit the enter key
			else if(gEvent.type == SDL_KEYDOWN)
			{
				if(gEvent.key.keysym.sym == SDLK_RETURN)
				{
					setState(STATE_PLAYGAME);

					isSettingPiece = false;
				}
			}
	
			//handle piece button input
			for(int i = 0; i < 12; i++)
			{
				buttons[i]->handleInput(gEvent);
			}

			//handle board piece input
			gBoard->handlePieceInput(gEvent);
		}

		//check to see if a button was selected
		for(int i = 0; i < 12; i++)
		{
			if(buttons[i]->getIsSelected())
			{
				currentButton = buttons[i];

				//reset button
				buttons[i]->setIsSelected(false);

				//set overlay to cover current button
				buttonOverlay->setXPos(currentButton->getXPos());
				buttonOverlay->setYPos(currentButton->getYPos());

				//get button rank
				buttonRank = buttons[i]->getRank();

				//set isButtonSelected to true
				setIsButtonSelected(true);
			}
		}

		//check to see if a piece was selected
		clickedPiece = gBoard->findSelectedPiece();

		//if a selected piece was found and is in one
		//of player's boardspaces that isn't already occupied
		//and a piece button that is available is already selected
		if(clickedPiece != 0 && (clickedPiece->getBoardSpace() > 59) &&
		   (clickedPiece->getRank() == 0) && (currentButton != 0) &&
		   currentButton->getIsAvailable())
		{	
			//set currently selected piece
			currentPiece = clickedPiece;

			//set isPieceSelected to true
			setIsPieceSelected(true);

			//reset clickedPiece
			clickedPiece = 0;
		}

		//check to see if a piece was set
		if(isPieceSelected && isButtonSelected)
		{
			//find an unplaced piece of the correct type
			unplacedPiece = gPlayer->findUnplacedPiece(buttonRank);

			//if there's a piece to set
			if(unplacedPiece != 0)
			{
				//swap boardspace and rendering coordinates with emptyspace
				swapLocation(currentPiece, unplacedPiece);

				//remove emptyspace from board's collection
				gBoard->clearPiece(currentPiece->getBoardSpace());

				//add set piece to board's collection
				gBoard->addPiece(unplacedPiece);

				//reset isPieceSelected
				setIsPieceSelected(false);
			}

			//find an unplaced piece of the correct type
			unplacedPiece = gPlayer->findUnplacedPiece(buttonRank);

			//if there's no unplaced pieces of this rank
			if(unplacedPiece == 0)
			{
				//disable the piece button
				currentButton->setIsAvailable(false);

				//set isButtonSelected to false
				setIsButtonSelected(false);
			}
		}

		//set finished to true
		finished = true;

		//check to see if all pieces are set
		for(int i = 0; i < 12; i++)
		{
			if(buttons[i]->getIsAvailable())
			{
				finished = false;
			}
		}

		//apply the start menu image to the screen
		setPieceBG->show(getScreen());

		//apply button images to screen
		for(int i = 0; i < 12; i++)
		{
			buttons[i]->show(getScreen());
		}

		//render button overlay if needed
		if(getIsButtonSelected())
		{
			buttonOverlay->show(getScreen());
		}

		//render board to screen
		gBoard->show(getScreen());

		//render finished set piece image if need
		if(finished)
		{
			finishedSetPiece->show(getScreen());
		}

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}

	return true;
}

//******************************************
bool Game::doPlayGame()
{
	//pieces
	Piece* selected = 0;
	Piece* destination = 0;
	Piece* winner = 0;
	Piece* temp = 0;

	//loop and overlay booleans
	bool playingGame = true,
		 showOverlay = false;

	while(playingGame)
	{
		while(SDL_PollEvent(&gEvent))
		{
			//if the user has exited the window
			if(gEvent.type == SDL_QUIT)
			{
				//set next state to exit
				setState(STATE_EXIT);

				playingGame = false;
			}
			//else if the user has hit the enter key
			else if(gEvent.type == SDL_KEYDOWN)
			{
				if(gEvent.key.keysym.sym == SDLK_RETURN)
				{
					setState(STATE_ENDGAME);

					playingGame = false;
				}
			}

			//handle board piece input
			gBoard->handlePieceInput(gEvent);
		}

		//if no piece has been selected
		if(selected == 0 && destination == 0)
		{
			selected = gBoard->findSelectedPiece();

			//if a piece was found
			if(selected != 0)
			{
				//if the piece is moveable
				if(isMoveablePiece(selected, 0))
				{
					//reset selected variable
					selected->setIsSelected(false);

					//set overlay to show
					showOverlay = true;

					//move overlay to this piece
					pieceOverlay->setXPos(selected->getXPos());
					pieceOverlay->setYPos(selected->getYPos());
				}
				else
				{
					//reset selected
					selected = 0;
				}
			}
		}
		//else if one piece has been selected
		else if(destination == 0)
		{
			destination = gBoard->findSelectedPiece();

			//if a piece was found and it isn't the same piece
			//as the first selected piece and the owners are not identical
			if(destination != 0 && destination->getBoardSpace() !=
			   selected->getBoardSpace() && destination->getOwner() !=
			   selected->getOwner())
			{
				//if the move is valid
				if(isValidMove(selected, destination))
				{
					//move the piece
					winner = selected->move(destination);

					//depending on the move outcome, remove defeated
					//pieces from board's collection if needed and
					//add emptyspace's where necessary
					if(winner == 0)
					{
						temp = findEmptySpacePiece();

						gBoard->addPiece(temp);

						gBoard->clearPiece(destination->getBoardSpace());
						gBoard->clearPiece(selected->getBoardSpace());

						//remove pieces from player and computer collections
						if(selected->getOwner() == 0)
						{
							gPlayer->clearPiece(selected->getBoardSpace());
						}
						else
						{
							gComputer->clearPiece(selected->getBoardSpace());
						}

						if(destination->getOwner() == 0)
						{
							gPlayer->clearPiece(destination->getBoardSpace());
						}
						else
						{
							gComputer->clearPiece(destination->getBoardSpace());
						}

						swapLocation(temp, selected);

						temp = findEmptySpacePiece();

						gBoard->addPiece(temp);

						swapLocation(temp, destination);

						temp = 0;
					}
					else if(winner->getRank() == 0)
					{
						//dont need to clear any pieces
					}
					else if(winner->getBoardSpace() == destination->getBoardSpace())
					{
						temp = findEmptySpacePiece();

						gBoard->addPiece(temp);

						gBoard->clearPiece(selected->getBoardSpace());

						//remove pieces from player and computer collections
						if(selected->getOwner() == 0)
						{
							gPlayer->clearPiece(selected->getBoardSpace());
						}
						else
						{
							gComputer->clearPiece(selected->getBoardSpace());
						}

						swapLocation(temp, selected);

						temp = 0;
					}
					else
					{
						temp = findEmptySpacePiece();

						gBoard->addPiece(temp);

						gBoard->clearPiece(destination->getBoardSpace());

						//remove pieces from player and computer collections
						if(destination->getOwner() == 0)
						{
							gPlayer->clearPiece(destination->getBoardSpace());
						}
						else
						{
							gComputer->clearPiece(destination->getBoardSpace());
						}

						swapLocation(temp, destination);

						temp = 0;
					}

					//check to see if the game has been won

					//do computer's turn
					moveComputerPiece();

					//check to see if the game has been won

					//reset pieces
					selected = 0;
					destination = 0;
					winner = 0;

					//reset overlay
					showOverlay = false;
				}
				else
				{
					//reset destination
					destination = 0;
				}
			}
			else if(destination != 0)
			{
				if(destination->getOwner() == selected->getOwner() && isMoveablePiece(destination, 0))
				{
					//set selected to destination, reset destination,
					//and update piece overlay
					selected = destination;
					destination = 0;

					pieceOverlay->setXPos(selected->getXPos());
					pieceOverlay->setYPos(selected->getYPos());
				}
				else
				{
					//reset destination
					destination = 0;
				}
			}
		}

		//apply the start menu image to the screen
		playGameBG->show(getScreen());

		//show board
		gBoard->show(getScreen());

		//show piece overlay if needed
		if(showOverlay)
		{
			pieceOverlay->show(getScreen());
		}

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}

	return true;
}

//******************************************
bool Game::doEndGame()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
		//else if the user has hit the enter key
		else if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				//reset the game
				setState(STATE_MENU);
			}
		}
	}

	//apply the end game image to the screen
	endGameBG->show(getScreen());

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doInGameMenu()
{
	while(SDL_PollEvent(&gEvent))
	{
		//if the user has exited the window
		if(gEvent.type == SDL_QUIT)
		{
			//set next state to exit
			setState(STATE_EXIT);
		}
				
		//handle start menu selector input
		gSelector->handleInput(gEvent);

		//if the user has hit the enter key
		if(gEvent.type == SDL_KEYDOWN)
		{
			if(gEvent.key.keysym.sym == SDLK_RETURN)
			{
				if(gSelector->getChoice() == 0)
				{
					setState(STATE_STATISTICS);

					gSelector->reset();
				}
				else if(gSelector->getChoice() == 1)
				{
					setState(STATE_STARTMENU);

					gSelector->reset();
				}
			}
		}
	}

	//move the selector
	gSelector->move();

	//apply the start menu image and selector image to the screen
	menuBG->show(getScreen());
	gSelector->show(getScreen());

	//render to the screen
	//if rendering was unsuccessful
	if(!render())
	{
		//return 1, closing the program
		return false;
	}

	return true;
}

//******************************************
bool Game::doStatistics()
{
	bool showingStatistics = true;

	gPlayer->setStatisticsSprites();

	while(showingStatistics)
	{
		while(SDL_PollEvent(&gEvent))
		{
			//if the user has exited the window
			if(gEvent.type == SDL_QUIT)
			{
				//set next state to exit
				setState(STATE_EXIT);

				showingStatistics = false;
			}
			//else if the enter key was pressed
			else if(gEvent.type == SDL_KEYDOWN)
			{
				if(gEvent.key.keysym.sym == SDLK_RETURN)
				{
					//set state to start menu
					setState(STATE_INTRO);
				}

				showingStatistics = false;
			}
		}

		//apply the statistics image and messages to the screen
		statisticsBG->show(getScreen());

		//apply statistics messages to screen
		gPlayer->displayStatistics(getScreen());

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}

	return true;
}
