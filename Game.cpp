#include "Game.h"
#include <stdlib.h>
#include <ctime>
#ifndef LINUX
#include <windows.h>
#endif




/*
    Game Constructor. Initializes board object, piece object, mIO object.
    @Board pBoard : board
    @Pieces pPieces : piece
    @IO pIO : IO
    @int pScreenHeight : screen height in pixels
*/
Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight){
    screenHeight = pScreenHeight;

    board = pBoard;
    pieces = pPieces;
    mIO = pIO;

    InitGame();

}

/*
    Sets up a next tetrimino as well as its initial position.
*/
void Game::NextPiece(){
    //current piece
    tetrimino = nextTetrimino;
    rotation = nextRotation;
    mPosX = (BOARD_WIDTH/2) + pieces->GetXInitialPosition(tetrimino, rotation);
    mPosY = pieces->GetYInitialPosition(tetrimino, rotation);
    
    //generate next piece
    nextTetrimino = (Tetrimino) GetRand(0,6);
    nextRotation = Rotation::UP;
}

/*
    Generates a random number between min and max (inclusive)
    @int min : minimum range for the random number
    @int max : maximum range for the random number
    return @ int : random number between [min - max]
*/
int Game::GetRand(int min, int max){
    srand(time(0));
    int r = rand();
    return r % (max - min + 1) + min;
}


/*
    Initializes game. Sets up first and next tetrimino and rotation. 
*/
void Game::InitGame(){
    //current piece
    tetrimino = (Tetrimino) GetRand(0,6);
    rotation = Rotation::UP;
    mPosX = (BOARD_WIDTH/2) + pieces->GetXInitialPosition(tetrimino,rotation);
    mPosY = pieces->GetYInitialPosition(tetrimino,rotation);

    //next piece
    nextTetrimino = (Tetrimino) GetRand(0,6);
    nextRotation = Rotation::UP;
    mNextPosX = BOARD_WIDTH + 5;
    mNextPosY = 5;
}

/*
    Given the coordinate and piece information, draws the tetrimino piece on the board.
    @int x : Horizontal position of the piece in board matrix
    @int y : Vertical position of the piece in board matrix
    @Tetrimino tetrimino : Tetrimino to draw
    @Rotation rotation : Rotation of the particular tetrimino
*/
void Game::DrawPiece (int x, int y, Tetrimino tetrimino, Rotation rotation){
	Color mColor;				// Color of the block 

	// Obtain the position in pixel in the screen of the block we want to draw
	int pixelX = board->GetXPositionInPixels (x);
	int pixelY = board->GetYPositionInPixels (y);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < TETRIMINO_LENGTH; i++){
		for (int j = 0; j < TETRIMINO_LENGTH; j++){
			// Get the type of the block and draw it with the correct color
			switch (tetrimino){
				case Tetrimino::I: mColor = CYAN;        break;	// For each block of the piece except the pivot
				case Tetrimino::SQUARE: mColor = YELLOW; break;	// For the pivot
                case Tetrimino::T: mColor = MAGENTA;     break;
                case Tetrimino::L: mColor = ORANGE;      break;
                case Tetrimino::L_MIRROR: mColor = BLUE; break;
                case Tetrimino::N: mColor = RED;       break;
                case Tetrimino::N_MIRROR: mColor = GREEN;         break;

                //enum Color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};
                //enum Tetrimino {SQUARE = 0, I = 1, L = 2, L_MIRROR = 3, N = 4, N_MIRROR = 5, T = 6}; //Enum encapsulating the tetrimino

            }
			
			if (pieces->GetBlockType (tetrimino, rotation, i, j) != 0)
				mIO->DrawRectangle	(pixelX + i * BLOCK_LENGHT, 
									pixelY + j * BLOCK_LENGHT, 
									(pixelX + i * BLOCK_LENGHT) + BLOCK_LENGHT - 1, 
									(pixelY + j * BLOCK_LENGHT) + BLOCK_LENGHT - 1, 
									mColor);
		}
	}
}


void Game::DrawBoard(){
    int x_left = BOARD_CENTER - (BLOCK_LENGHT * (BOARD_WIDTH/2)) - 1;
    int x_right = BOARD_CENTER + (BLOCK_LENGHT * (BOARD_WIDTH/2));
    int y_bottom = screenHeight - (BLOCK_LENGHT * BOARD_HEIGHT);

    //left line & right line of the board
    mIO->DrawRectangle(x_left - BOARD_LINE_WIDTH, y_bottom, x_left, screenHeight - 1, BLUE);
    mIO->DrawRectangle(x_right, y_bottom, x_right+ BOARD_LINE_WIDTH, screenHeight, BLUE);

    //draw all filled blocks
    for(int x = 0; x < BOARD_WIDTH; x++){
        for(int y = 0; y < BOARD_HEIGHT; y++){
            if(!board->isFreeBlock(x,y)){
                SqreCoordinates coordinates = board->getCellCoordinates(x,y);
                mIO->DrawRectangle(coordinates.upperLeftX, coordinates.upperLeftY, coordinates.lowerRightX, coordinates.lowerRightY, RED);
            }

        }
    }

}

/*
    Draws the whole scene including current piece, next piece and the board.
*/
void Game::DrawScene(){
    DrawBoard();
    DrawPiece(mPosX,mPosY,tetrimino,rotation);
    DrawPiece(mNextPosX, mNextPosY, nextTetrimino, nextRotation);
}