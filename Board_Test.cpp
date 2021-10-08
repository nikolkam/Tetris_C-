#include "Board.h"
#include "Piece.h"
#include "IO.h"
#include<iostream>

bool isEmptyBoardTest(){
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;

    Board mBoard(&mPieces, mScreenHeight);

    for(int tetrimino = 0; tetrimino < 7; tetrimino++){
        for(int rotation = 0; rotation < 4; rotation++){
            for(int x = 0; x < BOARD_WIDTH; x++){
                for(int y = 0; y < BOARD_HEIGHT; y++){
                    if(mBoard.IsPossibleMovement(x,y,tetrimino,rotation) !=  mBoard.IsPossibleMovementVr2(x,y,tetrimino,rotation)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, char **argv){
    std::cout<<isEmptyBoardTest()<<std::endl;
}