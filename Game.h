#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Piece.h"
#include "IO.h"
#include <time.h>


#define WAIT_TIME 700 //Milliseconds for block to drop

class Game{
public:
    Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight);

    void DrawScene();
    void NextPiece();


    int mPosX, mPosY; // Position of the current tetrimino
    Tetrimino tetrimino;
    Rotation rotation;

private:
    int screenHeight;
    int mNextPosX, mNextPosY;
    Tetrimino nextTetrimino;
    Rotation nextRotation;

    Board* board;
    Pieces* pieces;
    IO *mIO;

    int GetRand(int min, int max);
    void InitGame();
    void DrawPiece(int x, int y, int Tetrimino, int Rotation);
    void DrawBoard();
};






#endif