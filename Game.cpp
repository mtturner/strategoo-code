/******************************************************
	Game.cpp

	This is the implementation file for the Game
	class.
******************************************************/

#include <fstream>
#include "Game.h"

Game::Game() : screen(0)
{
	//set player, computer and board pointers to null
	gPlayer = 0;
	gComputer = 0;
	gBoard = 0;

	//set initial game state
	setState(STATE_INTRO);
	setPreviousState(STATE_INTRO);

	//set turn
	setTurn(0);

	//set booleans to false
	setIsPieceSelected(false);
	setIsButtonSelected(false);

	//dynamically allocate sprite objects
	introBG = new Sprite();
	loginBG = new Sprite();
	startMenuBG = new Sprite();
	setPieceBG = new Sprite();
	playGameBG = new Sprite();
	menuBG = new Sprite();
	statisticsBG = new Sprite();

	gameSound = new Sound();
}

//*****************************************************
Game::~Game()
{
	//delete dynamically allocated sprites
	delete introBG;
	delete loginBG;
	delete startMenuBG;
	delete setPieceBG;
	delete playGameBG;
	delete menuBG;
	delete statisticsBG;

	//delete all pieces
	for(int i = 0; i < static_cast<int>(pieces.size()); i++)
	{
		delete pieces[i];
	}

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

	delete namePieceBG;

	//delete game result images
	delete playerWinsImage;
	delete computerWinsImage;

	//delete play-by-plays
	delete playByPlayHeader;
	delete playByPlayArea;
	delete playByPlayOne;
	delete playByPlayTwo;
	delete playByPlayThree;
	delete playByPlayFour;
	delete playByPlayFive;
	delete playByPlaySix;
	delete playByPlaySeven;
	delete playByPlayEight;
	delete playByPlayNine;

	//delete sound class
	delete gameSound;
}

//*****************************************************
void Game::setState(const int gameState)
{
	//state must be a number from 0 to 7
	if(gameState > -1 && gameState < 8)
	{
		gameState_ = gameState;
	}
}

//*****************************************************
void Game::setPreviousState(const int gameState)
{
	//state must be a number from 0 to 7
	if(gameState > -1 && gameState < 8)
	{
		previousState_ = gameState;
	}
}

//*****************************************************
void Game::setTurn(const int turn)
{
	if(turn == 0 || turn == 1)
	{
		turn_ = turn;
	}
}

//*****************************************************
void Game::setScreen(SDL_Surface* s)
{
	//delete old screen
	SDL_FreeSurface(screen);

	if(s != 0)
	{
		screen = s;
	}
}

//*****************************************************
void Game::setIsPieceSelected(const bool selected)
{
	isPieceSelected = selected;
}

//*****************************************************
void Game::setIsButtonSelected(const bool selected)
{
	isButtonSelected = selected;
}

//*****************************************************
bool Game::initialize()
{
	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//initialize SDL_ttf
	if(TTF_Init() == -1)
	{
		return false;
	}

	//initialize SDL_mixer
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

	//load all sound files into sound class
	gameSound->loadSounds();

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
	finishedSetPiece = new Sprite(260, 50);
	finishedSetPiece->load("gamestart.png", 255, 255, 255);

	//create name piece image
	namePieceBG = new Sprite(260, 50, "namingpiece.png");

	//create game result images
	playerWinsImage = new Sprite(260, 50, "playerwins.png");
	computerWinsImage = new Sprite(260, 50, "computerwins.png");

	//create play by plays
	playByPlayHeader = new Sprite(0, 0, "playbyplay.png");
	playByPlayArea = new Sprite(0, 50, "playbyplayarea.png");
	playByPlayOne = new Sprite(5, 55);
	playByPlayTwo = new Sprite(5, 80);
	playByPlayThree = new Sprite(5, 105);
	playByPlayFour = new Sprite(5, 155);
	playByPlayFive = new Sprite(5, 180);
	playByPlaySix = new Sprite(5, 205);
	playByPlaySeven = new Sprite(5, 255);
	playByPlayEight = new Sprite(5, 280);
	playByPlayNine = new Sprite(5, 305);

	if(getScreen() == 0)
	{
		return false;
	}

	return true;
}

//*****************************************************
void Game::cleanUp() const
{
	//quit SDL_ttf
	TTF_Quit();

	//quit SDL_mixer
	Mix_CloseAudio();

	//quit SDL
	SDL_Quit();
}

//*****************************************************
bool Game::render() const
{
	if(SDL_Flip(getScreen()) == -1)
	{
		return false;
	}

	return true;
}

//*****************************************************
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

	//start menu background music and stop any previously playing music
	//gameSound->stopMusic();
	gameSound->playMenuTheme();

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

//*****************************************************
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

	return true;
}

//*****************************************************
bool Game::doStartMenu()
{
	//play menu music if not already playing
	//gameSound->stopMusic();
	gameSound->playMenuTheme();
	
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
					setPreviousState(STATE_STARTMENU);

					gSelector->reset();
				}
			}
		}
	}

	//move the selector
	if(gSelector->move())
	{
		if(getState() == STATE_STARTMENU)
		{
			//play sound effect if selector was moved
			gameSound->playMoveSelector();
		}
	}

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

//*****************************************************
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
		 finished = false,
		 namingPiece = false;

    std::ifstream infile;
    std::string temp;

    infile.open("names.txt");

    getline(infile, temp);

    name->setFont("Therfont.ttf", 58);
    name->setMessageSurface(temp);

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
				    if(finished)
				    {
                        setState(STATE_PLAYGAME);

                        isSettingPiece = false;
				    }
				}
				else if(gEvent.key.keysym.sym == SDLK_RCTRL || gEvent.key.keysym.sym == SDLK_LCTRL)
				{
					namingPiece = false;
				}
			}

			//if the player is not naming a piece
			if(!namingPiece)
			{
				//handle piece button input
				for(int i = 0; i < 12; i++)
				{
					buttons[i]->handleInput(gEvent);
				}

				//handle board piece input
				gBoard->handlePieceInput(gEvent);
			}
			//if the player is naming a piece
			else
			{
                //handle string input for naming of pieces
                name->handleInput(gEvent, 6);
			}
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

				//play button press sound effect
				gameSound->playButtonPress();
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

			//set namingPiece to true
			namingPiece = true;

			//reset clickedPiece
			clickedPiece = 0;
		}

		//check to see if a piece was set
		if(isPieceSelected && isButtonSelected && !namingPiece)
		{
			//find an unplaced piece of the correct type
			unplacedPiece = gPlayer->findUnplacedPiece(buttonRank);

			//if there's a piece to set
			if(unplacedPiece != 0)
			{
			    //name the piece
			    unplacedPiece->setName(name->getInput());

                getline(infile, temp);

                //reset the StringInput string
			    name->setMessageSurface(temp);

				//swap boardspace and rendering coordinates with emptyspace
				swapLocation(currentPiece, unplacedPiece);

				//remove emptyspace from board's collection
				gBoard->clearPiece(currentPiece->getBoardSpace());

				//add set piece to board's collection
				gBoard->addPiece(unplacedPiece);

				//reset isPieceSelected
				setIsPieceSelected(false);

				//play place piece sound effect
				gameSound->playPlacePiece();
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

		//render namingPieceBG and piece name if needed
		if(namingPiece)
		{
		    namePieceBG->show(getScreen());
		    name->show(getScreen(), 415, 135);
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

//*****************************************************
bool Game::doPlayGame()
{
	//pieces
	Piece* selected = 0;
	Piece* destination = 0;
	Piece* winner = 0;
	Piece* temp = 0;

	//win or loss sprite
	Sprite* gameResult = 0;

	Sprite* man = new Sprite(5, 400);
	man->load("man.png", 255, 255, 255);

    //object to display the piece name
    StringInput pieceName;

	//loop, overlay, and firstFrame booleans
	bool playingGame = true,
		 showOverlay = false,
		 firstFrame = true;

	//coordinates for displaying piece name
	int x,
	    y;

	//game winner, 0 - player, 1 - computer
	int winningTeam = -1;

	pieceName.setFont("Therfont.ttf", 18);

	//play in-game music after stopping any current playing music
	gameSound->stopMusic();
	//gameSound->playGameTheme();

	while(playingGame)
	{
		//if it's player's turn and the game hasn't been won
		if(getTurn() == 0 && winningTeam == -1)
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
					if(gEvent.key.keysym.sym == SDLK_m)
					{
						setState(STATE_MENU);
						setPreviousState(STATE_MENU);

						playingGame = false;
					}
				}

				//handle board piece input
				gBoard->handlePieceInput(gEvent);
			}

			//check for winning conditions in the first frame
			if(firstFrame)
			{
				//check to see if the game has been won by player
				if(checkPlayerWins())
				{
					//set winner to player
					winningTeam = 0;

					//set game result sprite to player wins
					gameResult = playerWinsImage;

					//play win theme music after stopping current music
					gameSound->stopMusic();
					gameSound->playWinTheme();
				}
				else if(checkComputerWins())
				{
					//set winner to computer
					winningTeam = 1;

					//set game result sprite to computer wins
					gameResult = computerWinsImage;

					//play lose theme music after stopping current music
					gameSound->stopMusic();
					gameSound->playLoseTheme();
				}

				firstFrame = false;
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
						x = selected->getXPos() + 2;
						y = selected->getYPos() + 1;

						pieceName.setMessageSurface(selected->getName());

						//play selected piece sound effect
						gameSound->playSelectPiece();
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
				if((destination != 0 && destination->getBoardSpace() !=
				  selected->getBoardSpace() && destination->getOwner() !=
				  selected->getOwner()) || (destination != 0 && destination->getBoardSpace() !=
				  selected->getBoardSpace() && destination->getRank() == 0))
				{
					//if the move is valid
					if(isValidMove(selected, destination))
					{
						//move the piece
						winner = selected->move(destination);

						//play place-piece sound effect
						gameSound->playPlacePiece();

						//depending on the move outcome, remove defeated
						//pieces from board's collection if needed and
						//add emptyspace's where necessary
						if(winner == 0)
						{
							shiftPlayByPlayDown();
							updatePlayByPlay(selected, destination, 0, -1);

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

							//play battle sound effect
							gameSound->playBattleSound();
						}
						else if(winner->getRank() == 0)
						{
							shiftPlayByPlayDown();
							updatePlayByPlay(selected, destination, 0);
						}
						else if(winner->getBoardSpace() == destination->getBoardSpace())
						{
							shiftPlayByPlayDown();
							updatePlayByPlay(selected, destination, 0, 1);

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

							//play battle sound effect or explosion if winner
							//is a bomb
							if(winner->getRank() == 11)
							{
								gameSound->playBombExplosion();
							}
							else
							{
								gameSound->playBattleSound();
							}
						}
						else
						{
							shiftPlayByPlayDown();
							updatePlayByPlay(selected, destination, 0, 0);

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

							//play battle sound effect or explosion if winner
							//is a bomb
							if(winner->getRank() == 11)
							{
								gameSound->playBombExplosion();
							}
							else
							{
								gameSound->playBattleSound();
							}
						}

						//check to see if the game has been won by player
						if(checkPlayerWins())
						{
							//set winner to player
							winningTeam = 0;

							//set game result sprite to player wins
							gameResult = playerWinsImage;

							//play win theme music after stopping current music
							gameSound->stopMusic();
							gameSound->playWinTheme();
						}
						else if(checkComputerWins())
						{
							//set winner to computer
							winningTeam = 1;

							//set game result sprite to computer wins
							gameResult = computerWinsImage;

							//play lose theme music after stopping current music
							gameSound->stopMusic();
							gameSound->playLoseTheme();
						}

						//if the game has not been won, set turn to computer's
						if(winningTeam == -1)
						{
							setTurn(1);
						}

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
						x = selected->getXPos() + 2;
						y = selected->getYPos() + 1;

						pieceName.setMessageSurface(selected->getName());

						//play selected piece sound effect
						gameSound->playSelectPiece();
					}
					else
					{
						//reset destination
						destination = 0;
					}
				}
			}
		}
		//else if it's computer's turn and the game hasn't been won
		else if(getTurn() == 1 && winningTeam == -1)
		{
			//do computer's turn
			//delay two seconds to simulate computer thinking
			SDL_Delay(2000);

			//move play-by-play down
			shiftPlayByPlayDown();

			//move a piece of computer's
			moveComputerPiece();

			//check to see if the game has been won by player
			if(checkPlayerWins())
			{
				//set winner to player
				winningTeam = 0;

				//set game result sprite to player wins
				gameResult = playerWinsImage;

				//play win theme music after stopping current music
				gameSound->stopMusic();
				gameSound->playWinTheme();
			}
			else if(checkComputerWins())
			{
				//set winner to computer
				winningTeam = 1;

				//set game result sprite to computer wins
				gameResult = computerWinsImage;

				//play lose theme music after stopping current music
				gameSound->stopMusic();
				gameSound->playLoseTheme();
			}

			//set turn to player's
			if(winningTeam == -1)
			{
				setTurn(0);
			}
		}

		//if the game has been won
		if(winningTeam != -1)
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
						setState(STATE_MENU);
						setPreviousState(STATE_PLAYGAME);

						//update player stats
						gPlayer->setGamesPlayed(1);

						//save stats to file
						gPlayer->saveStatistics();

						//stop current music
						gameSound->stopMusic();

						playingGame = false;
					}
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
			pieceName.show(getScreen(), x, y);
		}

		//show game result sprite if needed
		if(winningTeam != -1)
		{
			gameResult->show(getScreen());
		}

		//render play-by-play
		playByPlayHeader->show(getScreen());
		playByPlayArea->show(getScreen());
		playByPlayOne->show(getScreen());
		playByPlayTwo->show(getScreen());
		playByPlayThree->show(getScreen());
		playByPlayFour->show(getScreen());
		playByPlayFive->show(getScreen());
		playByPlaySix->show(getScreen());
		playByPlaySeven->show(getScreen());
		playByPlayEight->show(getScreen());
		playByPlayNine->show(getScreen());

		if(man != 0)
		{
            man->show(getScreen());
		}

		//render to the screen
		//if rendering was unsuccessful
		if(!render())
		{
			//return 1, closing the program
			return false;
		}
	}

	delete man;

	return true;
}

//*****************************************************
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

					//reset game
					resetGame();
				}
			}
			else if(gEvent.key.keysym.sym == SDLK_m)
			{
				if(getPreviousState() == STATE_MENU)
				{
					setState(STATE_PLAYGAME);

					gSelector->reset();
				}
			}
		}
	}

	//move the selector
	if(gSelector->move())
	{
		if(getState() == STATE_MENU)
		{
			//play sound effect if the selector was moved
			gameSound->playMoveSelector();
		}
	}

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

//*****************************************************
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
					if(getPreviousState() == STATE_STARTMENU)
					{
						//set state to start menu
						setState(STATE_STARTMENU);
					}
					else if(getPreviousState() == STATE_MENU ||
						    getPreviousState() == STATE_PLAYGAME)
					{
						setState(STATE_MENU);
					}
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

//*****************************************************
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

//*****************************************************
void Game::resetGame()
{
	//delete all pieces in game's collection
	for(int i = 0; i < 92; i++)
	{
		delete pieces[i];
	}

	//clear game's collection of pieces
	clearPieces();

	//clear board's, player's, and computer's collections of pieces
	gBoard->clearPieces();
	gPlayer->clearPieces();
	gComputer->clearPieces();

	//reset piece buttons
	for(int i = 0; i < 12; i++)
	{
		buttons[i]->setIsAvailable(true);
	}

	//reset turn
	setTurn(0);

	//reset play-by-play
	resetPlayByPlay();

	//stop any possibly playing music
	gameSound->stopMusic();
}

//*****************************************************
bool Game::checkPlayerWins()
{
	//flag exists and moveable piece exists booleans
	bool flagExists = false,
		 moveablePieceExists = false;

	//counter
	int j = 0;

	//temporary piece
	Piece* temp = 0;

	//number of pieces computer has
	int numPieces = gComputer->getNumPieces();

	//check for existence of computer's flag
	for(int i = 0; i < numPieces; i++)
	{
		temp = gComputer->findPieceAtPosition(i);

		if(temp->getRank() == 12)
		{
			flagExists = true;
		}
	}

	//check for existence of moveable piece
	while(!moveablePieceExists && j < numPieces)
	{
		temp = gComputer->findPieceAtPosition(j);

		if(isMoveablePiece(temp, 1))
		{
			moveablePieceExists = true;
		}

		if(!moveablePieceExists)
		{
			j++;
		}
	}

	if(!flagExists || !moveablePieceExists)
	{
		gPlayer->setGamesWon(1);
		
		if(!flagExists)
		{
			gPlayer->setFlagsCaptured(1);
		}
		else
		{
			gPlayer->setGenocide(1);
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

//*****************************************************
bool Game::checkComputerWins()
{
	//flag exists and moveable piece exists booleans
	bool flagExists = false,
		 moveablePieceExists = false;

	//counter
	int j = 0;

	//temporary piece
	Piece* temp = 0;

	//number of pieces player has
	int numPieces = gPlayer->getNumPieces();

	//check for existence of player's flag
	for(int i = 0; i < numPieces; i++)
	{
		temp = gPlayer->findPieceAtPosition(i);

		if(temp->getRank() == 12)
		{
			flagExists = true;
		}
	}

	//check for existence of moveable piece
	while(!moveablePieceExists && j < numPieces)
	{
		temp = gPlayer->findPieceAtPosition(j);

		if(isMoveablePiece(temp, 0))
		{
			moveablePieceExists = true;
		}

		if(!moveablePieceExists)
		{
			j++;
		}
	}

	if(!flagExists || !moveablePieceExists)
	{
		gPlayer->setGamesLost(1);

		if(!flagExists)
		{
			gPlayer->setCapturedFlags(1);
		}
		else
		{
			gPlayer->setTimesExtinct(1);
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

//*****************************************************
void Game::addPiece(Piece* const piece)
{
	if(piece != 0)
	{
		pieces.push_back(piece);
	}
}

//*****************************************************
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

//*****************************************************
void Game::swapLocation(Piece* const first, Piece* const second) const
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

//*****************************************************
bool Game::isMoveablePiece(Piece* const selected, const int mover) const
{
	return gBoard->isMoveablePiece(selected, mover);
}

//*****************************************************
bool Game::isValidMove(Piece* const selected, Piece* const destination) const
{
	//if the selected piece is not a scout
	if(selected->getRank() != 2)
	{
		//make sure destination is one space away above,
		//below, to the left of, or to the right of the
		//selected piece
		if(selected->getBoardSpace() != (destination->getBoardSpace() - 1) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() + 1) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() - 10) &&
		   selected->getBoardSpace() != (destination->getBoardSpace() + 10))
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
			//check to see if owners are different
			if(selected->getOwner() == destination->getOwner())
			{
				return false;
			}

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

//*****************************************************
void Game::moveComputerPiece()
{
	//pieces
	Piece* selected = 0;
	Piece* destination = 0;
	Piece* winner = 0;
	Piece* temp = 0;

	//vector of integers
	std::vector<int> numbers;

	//vector of int's iterator
	std::vector<int>::iterator iter;

	//number of pieces that computer has
	int numPieces = gComputer->getNumPieces();

	//find piece and fine move booleans
	bool isFindingPiece = true,
		 isFindingMove = true;

	//found boolean
	bool found = false;

	//counter
	int i = 99;

	//seed time
	srand(unsigned(time(0)));

	//populate numbers vector with integers from 0
	//to the number of pieces computer has
	for(int j = 0; j < numPieces; j++)
	{
		numbers.push_back(j);
	}

	//shuffle numbers
	random_shuffle(numbers.begin(), numbers.end());

	iter = numbers.begin();

	//find moveable piece
	while(isFindingPiece)
	{
		selected = gComputer->findPieceAtPosition(*iter);

		if(isMoveablePiece(selected, 1))
		{
			isFindingPiece = false;

			//play select-piece sound effect
			gameSound->playSelectPiece();
		}

		if(isFindingPiece)
		{
			iter++;
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

	//play place-piece sound effect
	gameSound->playPlacePiece();

	//depending on the move outcome, remove defeated
	//pieces from board's collection and owner's collection
	//if needed and add emptyspace's where necessary
	if(winner == 0)
	{
		updatePlayByPlay(selected, destination, 1, -1);

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

		//play battle sound effect
		gameSound->playBattleSound();
	}
	else if(winner->getRank() == 0)
	{
		updateComputerPlayByPlay(destination, selected);
	}
	else if(winner->getBoardSpace() == destination->getBoardSpace())
	{
		updatePlayByPlay(selected, destination, 1, 0);

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

		//play battle sound effect or explosion if winner
		//is a bomb
		if(winner->getRank() == 11)
		{
			gameSound->playBombExplosion();
		}
		else
		{
			gameSound->playBattleSound();
		}
	}
	else
	{
		updatePlayByPlay(selected, destination, 1, 1);

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

		//play battle sound effect or explosion if winner
		//is a bomb
		if(winner->getRank() == 11)
		{
			gameSound->playBombExplosion();
		}
		else
		{
			gameSound->playBattleSound();
		}
	}
}

//*****************************************************
void Game::updatePlayByPlay(Piece* const first, Piece* const second, 
							const int mover, const int winner) const
{
	//play-by-play stringstream
	std::stringstream ss;

	//font for play-by-play
	TTF_Font* font = TTF_OpenFont("Therfont.ttf", 18);

	//SDL surface for new playByPlay message
	SDL_Surface* newMessage = 0;

	//text color
	SDL_Color textColor = {0, 0, 0};

	//if player moved
	if(mover == 0)
	{
		ss << "Player's ";

		switch(first->getRank())
		{
		//marshal
		case 10:
			ss << "Marshal(";
			break;
		//general
		case 9:
			ss << "General(";
			break;
		//colonel
		case 8:
			ss << "Colonel(";
			break;
		//major
		case 7:
			ss << "Major(";
			break;
		//captain
		case 6:
			ss << "Captain(";
			break;
		//lieutenant
		case 5:
			ss << "Lieutenant(";
			break;
		//sergeant
		case 4:
			ss << "Sergeant(";
			break;
		//miner
		case 3:
			ss << "Miner(";
			break;
		//scout
		case 2:
			ss << "Scout(";
			break;
		//spy
		case 1:
			ss << "Spy(";
			break;
		}

		if(winner == 0)
		{
			ss << second->getBoardSpace() << ")";
		}
		else
		{
			ss << first->getBoardSpace() << ")";
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayOne->setSurfaceNoFree(newMessage);

		ss.str("");

		//if draw
		if(winner == -1)
		{
			ss << "draws with";
		}
		//if player won
		else if(winner == 0)
		{
			if(second->getRank() == 12)
			{
				ss << "captures";
			}
			else if(second->getRank() == 11)
			{
				ss << "defuses";
			}
			else
			{
				ss << "defeats";
			}
		}
		//if computer won
		else
		{
			if(second->getRank() == 11)
			{
				ss << "is blown up by";
			}
			else
			{
				ss << "is defeated by";
			}
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayTwo->setSurfaceNoFree(newMessage);

		ss.str("");

		ss << "Gary's ";

		switch(second->getRank())
		{
		//flag
		case 12:
			ss << "Flag(";
			break;
		//bomb
		case 11:
			ss << "Bomb(";
			break;
		//marshal
		case 10:
			ss << "Marshal(";
			break;
		//general
		case 9:
			ss << "General(";
			break;
		//colonel
		case 8:
			ss << "Colonel(";
			break;
		//major
		case 7:
			ss << "Major(";
			break;
		//captain
		case 6:
			ss << "Captain(";
			break;
		//lieutenant
		case 5:
			ss << "Lieutenant(";
			break;
		//sergeant
		case 4:
			ss << "Sergeant(";
			break;
		//miner
		case 3:
			ss << "Miner(";
			break;
		//scout
		case 2:
			ss << "Scout(";
			break;
		//spy
		case 1:
			ss << "Spy(";
			break;
		}

		if(winner == 0)
		{
			ss << first->getBoardSpace() << ").";
		}
		else
		{
			ss << second->getBoardSpace() << ").";
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayThree->setSurfaceNoFree(newMessage);
	}
	//if computer moved
	else
	{
		ss << "Gary's ";

		switch(first->getRank())
		{
		//marshal
		case 10:
			ss << "Marshal(";
			break;
		//general
		case 9:
			ss << "General(";
			break;
		//colonel
		case 8:
			ss << "Colonel(";
			break;
		//major
		case 7:
			ss << "Major(";
			break;
		//captain
		case 6:
			ss << "Captain(";
			break;
		//lieutenant
		case 5:
			ss << "Lieutenant(";
			break;
		//sergeant
		case 4:
			ss << "Sergeant(";
			break;
		//miner
		case 3:
			ss << "Miner(";
			break;
		//scout
		case 2:
			ss << "Scout(";
			break;
		//spy
		case 1:
			ss << "Spy(";
			break;
		}

		if(winner == 1)
		{
			ss << second->getBoardSpace() << ")";
		}
		else
		{
			ss << first->getBoardSpace() << ")";
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayOne->setSurfaceNoFree(newMessage);

		ss.str("");

		//if draw
		if(winner == -1)
		{
			ss << "draws with";
		}
		//if computer won
		else if(winner == 1)
		{
			if(second->getRank() == 12)
			{
				ss << "captures";
			}
			else if(second->getRank() == 11)
			{
				ss << "defuses";
			}
			else
			{
				ss << "defeats";
			}
		}
		//if player won
		else
		{
			if(second->getRank() == 11)
			{
				ss << "is blown up by";
			}
			else
			{
				ss << "is defeated by";
			}
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayTwo->setSurfaceNoFree(newMessage);

		ss.str("");

		ss << "Player's ";

		switch(second->getRank())
		{
		//flag
		case 12:
			ss << "Flag(";
			break;
		//bomb
		case 11:
			ss << "Bomb(";
			break;
		//marshal
		case 10:
			ss << "Marshal(";
			break;
		//general
		case 9:
			ss << "General(";
			break;
		//colonel
		case 8:
			ss << "Colonel(";
			break;
		//major
		case 7:
			ss << "Major(";
			break;
		//captain
		case 6:
			ss << "Captain(";
			break;
		//lieutenant
		case 5:
			ss << "Lieutenant(";
			break;
		//sergeant
		case 4:
			ss << "Sergeant(";
			break;
		//miner
		case 3:
			ss << "Miner(";
			break;
		//scout
		case 2:
			ss << "Scout(";
			break;
		//spy
		case 1:
			ss << "Spy(";
			break;
		}

		if(winner == 1)
		{
			ss << first->getBoardSpace() << ").";
		}
		else
		{
			ss << second->getBoardSpace() << ").";
		}

		//update play-by-play and clear stringstream
		//create new playByPlay image
		newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

		//update playByPlay image
		playByPlayThree->setSurfaceNoFree(newMessage);
	}
}

//*****************************************************
void Game::updatePlayByPlay(Piece* const moved, Piece* const destination, const int mover) const
{
	//play-by-play stringstream
	std::stringstream ss;

	//font for play-by-play
	TTF_Font* font = TTF_OpenFont("Therfont.ttf", 18);

	//SDL surface for new playByPlay message
	SDL_Surface* newMessage = 0;

	//text color
	SDL_Color textColor = {0, 0, 0};

	if(mover == 0)
	{
		ss << "Player moves a ";
	}
	else
	{
		ss << "Gary moves a ";
	}

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayOne->setSurfaceNoFree(newMessage);

	ss.str("");

	if(mover == 0 || mover == 1)
	{
		switch(moved->getRank())
		{
		//marshal
		case 10:
			ss << "Marshal(" << destination->getBoardSpace() << ")";
			break;
		//general
		case 9:
			ss << "General(" << destination->getBoardSpace() << ")";
			break;
		//colonel
		case 8:
			ss << "Colonel(" << destination->getBoardSpace() << ")";
			break;
		//major
		case 7:
			ss << "Major(" << destination->getBoardSpace() << ")";
			break;
		//captain
		case 6:
			ss << "Captain(" << destination->getBoardSpace() << ")";
			break;
		//lieutenant
		case 5:
			ss << "Lieutenant(" << destination->getBoardSpace() << ")";
			break;
		//sergeant
		case 4:
			ss << "Sergeant(" << destination->getBoardSpace() << ")";
			break;
		//miner
		case 3:
			ss << "Miner(" << destination->getBoardSpace() << ")";
			break;
		//scout
		case 2:
			ss << "Scout(" << destination->getBoardSpace() << ")";
			break;
		//spy
		case 1:
			ss << "Spy(" << destination->getBoardSpace() << ")";
			break;
		}
	}
	else
	{
		ss << " ";
	}

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayTwo->setSurfaceNoFree(newMessage);

	ss.str("");

	ss << "to board space " << moved->getBoardSpace() << ".";

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayThree->setSurfaceNoFree(newMessage);
}

//*****************************************************
void Game::updateComputerPlayByPlay(Piece* const moved, Piece* const destination) const
{
	//play-by-play stringstream
	std::stringstream ss;

	//font for play-by-play
	TTF_Font* font = TTF_OpenFont("Therfont.ttf", 18);

	//SDL surface for new playByPlay message
	SDL_Surface* newMessage = 0;

	//text color
	SDL_Color textColor = {0, 0, 0};

	ss << "Gary moves a";

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayOne->setSurfaceNoFree(newMessage);

	ss.str("");

	ss << "piece(" << moved->getBoardSpace() << ")";

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayTwo->setSurfaceNoFree(newMessage);

	ss.str("");

	ss << "to board space " << destination->getBoardSpace() << ".";

	//update play-by-play and clear stringstream
	//create new playByPlay image
	newMessage = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);

	//update playByPlay image
	playByPlayThree->setSurfaceNoFree(newMessage);
}

//*****************************************************
void Game::shiftPlayByPlayDown() const
{
	//move block two down to block three
	playByPlaySeven->setSurface(playByPlayFour->getSurface());
	playByPlayEight->setSurface(playByPlayFive->getSurface());
	playByPlayNine->setSurface(playByPlaySix->getSurface());

	//move block one down to block two
	playByPlayFour->setSurfaceNoFree(playByPlayOne->getSurface());
	playByPlayFive->setSurfaceNoFree(playByPlayTwo->getSurface());
	playByPlaySix->setSurfaceNoFree(playByPlayThree->getSurface());
}

//*****************************************************
void Game::resetPlayByPlay() const
{
	//play-by-play stringstream
	std::stringstream ss;

	//font for play-by-play
	TTF_Font* font = TTF_OpenFont("Therfont.ttf", 18);

	//SDL surface for new playByPlay message
	SDL_Surface* newMessage = 0;

	//text color
	SDL_Color textColor = {0, 0, 0};

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayOne->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayTwo->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayThree->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayFour->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayFive->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlaySix->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlaySeven->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayEight->setSurface(newMessage);

	newMessage = TTF_RenderText_Solid(font, " ", textColor);

	playByPlayNine->setSurface(newMessage);
}
