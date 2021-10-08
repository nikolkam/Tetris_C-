#include "Game.h"
#include <unistd.h>
#include <iostream>
/*
==================
Main
==================
*/



int main(){
    
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;

    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    //get the clock
    unsigned long mTime1 = SDL_GetTicks();

    while(!mIO.IsKeyDown(SDLK_ESCAPE)){
        //Draw
        mIO.ClearScreen();
        mGame.DrawScene();
        mIO.UpdateScreen();

        //Input

        int mKey = mIO.Pollkey();




        switch(mKey){
            case(SDLK_RIGHT):{
                if(mBoard.IsPossibleMovement(mGame.mPosX+1, mGame.mPosY, mGame.tetrimino, mGame.rotation)){
                    mGame.mPosX++;
                }
                break;
            }
            case(SDLK_LEFT):{
                if(mBoard.IsPossibleMovement(mGame.mPosX-1, mGame.mPosY, mGame.tetrimino, mGame.rotation)){
                    mGame.mPosX--;
                }
                break;
            }
            case(SDLK_DOWN):{
                if (mBoard.IsPossibleMovement (mGame.mPosX, mGame.mPosY + 1, mGame.tetrimino, mGame.rotation))
					mGame.mPosY++;	
				break;
            }
            case(SDLK_x):{
                while(mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.tetrimino ,mGame.rotation)){ mGame.mPosY++;}
                
                mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.tetrimino, mGame.rotation);
                mBoard.DeletePossibleLines();

                if(mBoard.isGameOver()){
                    mIO.Getkey();
                    exit(0);
                }

                mGame.NextPiece();
                break;
            }

            case (SDLK_z):{
                int next_rotation = (mGame.rotation+1)%4;
                if(mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.tetrimino, next_rotation)){
                    mGame.rotation = (Rotation) next_rotation;
                }
                break;
            }
        }

        unsigned long mTime2 = SDL_GetTicks();
        unsigned long time_elapsed = mTime2 - mTime1;
        if(time_elapsed > WAIT_TIME){
            if(mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY+1, mGame.tetrimino, mGame.rotation)){
                mGame.mPosY++;
            }else{
                mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.tetrimino, mGame.rotation);
                mBoard.DeletePossibleLines();

                if(mBoard.isGameOver()){
                    mIO.Getkey();
                    exit(0);
                }

                mGame.NextPiece();
            }

            mTime1 = SDL_GetTicks();
        }


    }
    

	return 0;
}
