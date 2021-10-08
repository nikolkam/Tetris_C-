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
        Board(Pieces *pPieces, int pScreenHeight);
        
        //Board getters
        int GetXPositionInPixels(int x);
        int GetYPositionInPixels(int y);
        bool IsPossibleMovement(int x, int y, int tetrimino, int rotation);
        bool IsPossibleMovementVr2(int X, int Y, int piece, int rotation);
        bool isGameOver();
        bool isFreeBlock(int x, int y);
        SqreCoordinates getCellCoordinates(int x, int y);

        //Board setters
        void StorePiece (int pX, int pY, Tetrimino pPiece, Rotation pRotation);
        void DeletePossibleLines();
        
        enum BLOCK{FREE = 0, FILLED = 1};
        BLOCK board_matrix [BOARD_WIDTH][BOARD_HEIGHT]; 

    private:
        void initBoard();
        void DeleteLine(int y);


            //enum parm to indicate whether block is free
         //matrix representing board block by block
        Pieces* pieces;
        int screenHeight;
};




#endif // _BOARD_