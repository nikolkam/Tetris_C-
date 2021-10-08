/*
    Tetris C++ Implementation
    Author: Nikola Maeda
    
    Board class header.

    This class includes general information about the board's sizes as well as Board class declaration.
    Board class is used to keep track of the each cell on the board whether they are free/blocked.
    It also contains functions to be used by other component of the program such getting the Pixel position, collision detection etc...

*/


#ifndef _BOARD_
#define _BOARD_


#include "Piece.h"


#define BOARD_WIDTH 10         //board's block width
#define BOARD_HEIGHT 20        //board's block height  
#define BLOCK_LENGHT 16        //block's length in pixels 
#define BOARD_CENTER 320       //center position of the board from the left of the screen
#define TETRIMINO_LENGTH 5     //block length of each square containing tetrimino
#define VARTICAL_MARGIN 20     //vertical margin for the board
#define HORIZONTAL_MARGIN 20   //horizontal margin for the board
#define BOARD_LINE_WIDTH 6     //line width of the board


struct SqreCoordinates{
    int upperLeftX, upperLeftY, lowerRightX, lowerRightY;
};

class Board{
    public:
        Board(Pieces* pieces, int screen_height);
        
        //Board getters
        int GetXPositionInPixels(int x);
        int GetYPositionInPixels(int y);
        bool IsPossibleMovement(int x, int y, int tetrimino, int rotation);
        bool isGameOver();
        bool isFreeBlock(int x, int y);
        SqreCoordinates getCellCoordinates(int x, int y);

        //Board setters
        void StorePiece (int x, int y, Tetrimino piece, Rotation rotation);
        void DeletePossibleLines();
        
        
        enum BLOCK{FREE = 0, FILLED = 1};                //enum to indicate whether particular block is free/ocupied
        BLOCK board_matrix [BOARD_WIDTH][BOARD_HEIGHT];  //board matrix that manages each block in the board

    private:
        void initBoard();
        void DeleteLine(int y);


        Pieces* pieces;    
        int screenHeight; //screen height in pixels 
};




#endif // _BOARD_