#include "Game.h"
#include <stdlib.h>

#ifndef LINUX
#include <windows.h>
#endif

#include<iostream>


Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight){
    screenHeight = pScreenHeight;

    board = pBoard;
    pieces = pPieces;
    mIO = pIO;

    InitGame();

}

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


int Game::GetRand(int min, int max){
    int r = rand();
    return r % (max - min + 1) + min;
}

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

void Game::DrawPiece (int pX, int pY, int pPiece, int pRotation)
{
	Color mColor;				// Color of the block 

	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = board->GetXPositionInPixels (pX);
	int mPixelsY = board->GetYPositionInPixels (pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < TETRIMINO_LENGTH; i++)
	{
		for (int j = 0; j < TETRIMINO_LENGTH; j++)
		{
			// Get the type of the block and draw it with the correct color
			switch (pieces->GetBlockType ((Tetrimino) pPiece, (Rotation) pRotation, j, i))
			{
				case 1: mColor = GREEN; break;	// For each block of the piece except the pivot
				case 2: mColor = BLUE; break;	// For the pivot
			}
			
			if (pieces->GetBlockType ((Tetrimino)pPiece, (Rotation)pRotation, j, i) != 0)
				mIO->DrawRectangle	(mPixelsX + i * BLOCK_LENGHT, 
									mPixelsY + j * BLOCK_LENGHT, 
									(mPixelsX + i * BLOCK_LENGHT) + BLOCK_LENGHT - 1, 
									(mPixelsY + j * BLOCK_LENGHT) + BLOCK_LENGHT - 1, 
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

void Game::DrawScene(){
    DrawBoard();
    DrawPiece(mPosX,mPosY,tetrimino,rotation);
    DrawPiece(mNextPosX, mNextPosY, nextTetrimino, nextRotation);
}