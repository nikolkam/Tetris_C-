#include "Board.h"



/*
    Stores pieces, screen height info and initializes the board
    @Pieces *pPieces: Piece class instance
    @int screen_height: screen height of the board in pixels
*/
Board::Board(Pieces* pieces, int screen_height){
    screenHeight = screen_height;
    pieces = pieces;
    initBoard();
}


/*
    Returns the horizontal pixel position of the block given the x board index
    @int x: Horizontal position of the block in the board
    return: pixel x coordinate of the board
*/
int Board::GetXPositionInPixels(int x){
    // left most cell's position
    int left_most = BOARD_CENTER - (BLOCK_LENGHT*BOARD_WIDTH/2); 
    return left_most + x*BLOCK_LENGHT;
}
/*
    Returns the vertical pixel position of the block given the y board index
    @int y: vertical position of the block in the board
    return: pixel y coordinate of the board
*/
int Board::GetYPositionInPixels(int y){
    // bottom cell's position
    int down_most = screenHeight - (BLOCK_LENGHT*BOARD_HEIGHT);
    return down_most + BLOCK_LENGHT*y;
}

/*
    Check if the piece's given coordinate and rotation does not cause any collision.
    @int x: x board coordinate of the current piece
    @int y: y board coordinate of the current piece
    @int tetrimino: Type of tetrimino specified by integer [0-6]
    @int rotation: Rotation of the tetrimino piece specified by integer [0-3]
    return: True if given position of the tetrimino does not collide with wall & pieces otherwise false 
*/
bool Board::IsPossibleMovement (int x, int y, int pPiece, int pRotation)
{
	//tX, tY : Tetrimino's box index [0 to TETRIMINO_LENGTH-1]
    //bX, bY : Particular block's index on the board [0 to BOARD_WIDTH-1, 0 to BOARD_HEIGHT-1]
	for (int bX = x, tX = 0; tX < TETRIMINO_LENGTH; bX++, tX++)
	{
		for (int bY = y, tY = 0; tY < TETRIMINO_LENGTH; bY++, tY++){	
			//Skip if the particular tetrimino is empty
			if (pieces->GetBlockType ((Tetrimino) pPiece, (Rotation) pRotation, tX, tY) == Block::E){
                continue;
            }
            
            //Check for wall collision
            if (bX < 0 || bX > BOARD_WIDTH  - 1	|| bY > BOARD_HEIGHT - 1){
				return false;		
			}

			// Check if the piece have collisioned with a block already stored in the board
			if (bY >= 0){
				if (!isFreeBlock (bX, bY))
					return false;
			}
		}
	}

	// No collision
	return true;
}


/*
    Checks current board condition and returns true if game is over
*/
bool Board::isGameOver(){
    for(int x = 0; x < BOARD_WIDTH; x++){
        if(board_matrix[x][0] == BLOCK::FILLED){
            return true;
        }
    }
    return false;
}

/*
    Given the specific board index x&y returns whether the block is occupied
    @int x : x board coordinate [0-BOARD_WIDTH-1]
    @int y : y board coordinate [0-BOARD_HEIGHT-1]
    return: True if the block is free, otherwise false 
*/
bool Board::isFreeBlock(int x, int y){
    return board_matrix[x][y] == BLOCK::FREE;
}

/*
    Given the specific board index x&y returns the pixel coordinate to be painted
    @int x : x board coordinate [0-BOARD_WIDTH-1]
    @int y : y board coordinate [0-BOARD_HEIGHT+2]
    return : SqreCoordinates class with pixel square coordinate information
*/
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

/*
    Initializes board by feeling the board_matrix with free cells
*/
void Board::initBoard(){
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            board_matrix[i][j] = BLOCK::FREE;
        }
    }
}

/*
    Given the piece information, (board index, tetrimino, rotation) stores pieces to the board
    @int x : horizontal board coordinate of the piece
    @int y : vertical board coordinate of the piece
    @Tetrimino piece : type of tetrimino piece
    @Rotation rotation : current rotation of the piece
*/
void Board::StorePiece (int x, int y, Tetrimino piece, Rotation rotation)
{
	// Store each block of the piece into the board
	for (int i1 = x, i2 = 0; i1 < x + TETRIMINO_LENGTH; i1++, i2++){
		for (int j1 = y, j2 = 0; j1 < y + TETRIMINO_LENGTH; j1++, j2++){	
			// Store only the blocks of the piece that are not holes
			if (pieces->GetBlockType (piece, rotation, i2, j2) != Block::E)		
				board_matrix[i1][j1] = BLOCK::FILLED;	
		}
	}
}

/*
    Looks for horizontal lines that are fully occupied and deletes them
*/
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

/*
    Empties the specified line
    @int y : vertical board index of the line
*/
void Board::DeleteLine(int y){

    for(int j = y; j > 0; j--){ 
        for(int i = 0; i < BOARD_WIDTH; i++){
            board_matrix[i][j] = board_matrix[i][j-1];
        }
    }
}