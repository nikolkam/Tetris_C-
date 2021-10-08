#include "Board.h"
#include <iostream>


Board::Board(Pieces *pPieces, int pScreenHeight){
    screenHeight = pScreenHeight;
    pieces = pPieces;
    initBoard();
}



int Board::GetXPositionInPixels(int x){
    // left most cell's position
    int left_most = BOARD_CENTER - (BLOCK_LENGHT*BOARD_WIDTH/2); 
    return left_most + x*BLOCK_LENGHT;
}
int Board::GetYPositionInPixels(int y){
    // bottom cell's position
    int down_most = screenHeight - (BLOCK_LENGHT*BOARD_HEIGHT);
    return down_most + BLOCK_LENGHT*y;
}

bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
	// Checks collision with pieces already stored in the board or the board limits
	// This is just to check the 5x5 blocks of a piece with the appropiate area in the board
	for (int i1 = pX, i2 = 0; i1 < pX + TETRIMINO_LENGTH; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + TETRIMINO_LENGTH; j1++, j2++)
		{	
			// Check if the piece is outside the limits of the board
			if (	i1 < 0 			|| 
				i1 > BOARD_WIDTH  - 1	||
				j1 > BOARD_HEIGHT - 1)
			{
				if (pieces->GetBlockType ((Tetrimino) pPiece, (Rotation) pRotation, j2, i2) != Block::E)
					return false;		
			}

			// Check if the piece have collisioned with a block already stored in the map
			if (j1 >= 0)	
			{
				if ((pieces->GetBlockType ((Tetrimino) pPiece, (Rotation) pRotation, j2, i2) != Block::E) &&
					(!isFreeBlock (i1, j1))	)
					return false;
			}
		}
	}

	// No collision
	return true;
}

bool Board::IsPossibleMovementVr2(int x, int y, int tetrimino, int rotation){
    //tX, tY : Tetrimino's box index [0 to 4]
    //pX, pY : Particular block's index on the board [0 to BOARD_WIDTH-1, 0 to BOARD_HEIGHT-1]
    for(int tX = 0, pX = x; tX < TETRIMINO_LENGTH; tX++, pX++){
        for(int tY = 0, pY = y; tY < TETRIMINO_LENGTH; tY++, pY++){
            //if the particular block's index is not filled by a tetrimino, skip
            if(pieces->GetBlockType((Tetrimino) tetrimino, (Rotation) rotation, tX, tY) == Block::E){
                continue;
            }
            
            //check for collision with walls
            if(pX < 0 || pX > BOARD_WIDTH - 1 || pY > BOARD_HEIGHT - 1){
                return false;
            }

            //check for collision with other tetriminos
            //first check that the block is in a valid board field in terms of height
            if(pY > 0){
                if(!isFreeBlock(pX, pY)){
                    return false;
                }
            }
        }
    }
}



bool Board::isGameOver(){
    for(int x = 0; x < BOARD_WIDTH; x++){
        if(board_matrix[x][0] == BLOCK::FILLED){
            return true;
        }
    }
    return false;
}

bool Board::isFreeBlock(int x, int y){
    return board_matrix[x][y] == BLOCK::FREE;
}


SqreCoordinates Board::getCellCoordinates(int x, int y){
    //get bottom left coordinates
    int pX = GetXPositionInPixels(x);
    int pY = GetYPositionInPixels(y);
    
    SqreCoordinates coordinates;
    coordinates.upperLeftX = pX;
    coordinates.upperLeftY = pY;
    coordinates.lowerRightX = pX + BLOCK_LENGHT - 1;
    coordinates.lowerRightY = pY + BLOCK_LENGHT - 1; 

    return coordinates;
}


void Board::initBoard(){
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            board_matrix[i][j] = BLOCK::FREE;
        }
    }
}

void Board::StorePiece (int pX, int pY, Tetrimino pPiece, Rotation pRotation)
{
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + TETRIMINO_LENGTH; i1++, i2++){
		for (int j1 = pY, j2 = 0; j1 < pY + TETRIMINO_LENGTH; j1++, j2++){	
			// Store only the blocks of the piece that are not holes
			if (pieces->GetBlockType (pPiece, pRotation, j2, i2) != Block::E)		
				board_matrix[i1][j1] = BLOCK::FILLED;	
		}
	}
}


void Board::DeletePossibleLines(){
    for(int y = 0; y < BOARD_HEIGHT; y++){
        for(int x = 0; x < BOARD_WIDTH; x++){
            if(board_matrix[x][y] == BLOCK::FREE){
                break;
            }

            if(x == BOARD_WIDTH-1){
                DeleteLine(y);
                break;
            }
        }
    }
}


void Board::DeleteLine(int y){

    for(int j = y; j > 0; j--){ 
        for(int i = 0; i < BOARD_WIDTH; i++){
            board_matrix[i][j] = board_matrix[i][j-1];
        }
    }
}