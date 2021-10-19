#include "Piece.h"


//each tetrimino's with each rotatoin
Block mPieces[7][4][5][5]{
    //Square
    {
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,E,R,F,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,E,R,F,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,E,R,F,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,E,R,F,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    },
    //I
    {
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,F,F},
        {E,E,E,E,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,E,E},
        {E,E,F,E,E},
        {E,E,F,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,F,F},
        {E,E,E,E,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,E,E},
        {E,E,F,E,E},
        {E,E,F,E,E}
    },
    },
    //L
    {
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,E,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,F,E},
        {E,F,E,E,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,F,F,E,E},
        {E,E,R,E,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {   
        {E,E,E,E,E},
        {E,E,E,F,E},
        {E,F,R,F,E},
        {E,E,E,E,E},
        {E,E,E,E,E}
    },
    },
    // L mirrored
    {
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,E,E},
        {E,F,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,F,E,E,E},
        {E,F,R,F,E},
        {E,E,E,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,F,F,E},
        {E,E,R,E,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,F,E},
        {E,E,E,F,E},
        {E,E,E,E,E}
    }
    },
    // N
    {
    {
        {E,E,E,E,E},
        {E,E,E,F,E},
        {E,E,R,F,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,E,E},
        {E,E,F,F,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,F,R,E,E},
        {E,F,E,E,E},
        {E,E,E,E,E}
    },

    {
        {E,E,E,E,E},
        {E,F,F,E,E},
        {E,E,R,F,E},
        {E,E,E,E,E},
        {E,E,E,E,E}
    }
    },
    // N mirrored
    {
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,F,E},
        {E,E,E,F,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,E,R,F,E},
        {E,F,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,F,E,E,E},
        {E,F,R,E,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,F,F,E},
        {E,F,R,E,E},
        {E,E,E,E,E},
        {E,E,E,E,E}
    }
    },
    // T
    {
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,E,R,F,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,E,E,E},
        {E,F,R,F,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,F,R,E,E},
        {E,E,F,E,E},
        {E,E,E,E,E}
    },
    {
        {E,E,E,E,E},
        {E,E,F,E,E},
        {E,F,R,F,E},
        {E,E,E,E,E},
        {E,E,E,E,E}
    }
    }
};

//initial position of each tetrimino
int piece_position[7 /*kind */ ][4 /* rotation */ ][2 /* position */] =
{
/* Square */
  {
	{-2, -3}, 
    {-2, -3},
    {-2, -3},
    {-2, -3}
   },
/* I */
  {
	{-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3}
   },
/* L */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* L mirrored */
  {
	{-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3}
   },
/* N */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* N mirrored */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* T */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
};


/*
    Returns the cell of tetrimino's specified rotation
    @Tetrimino tetrimino : tetrimino
    @Rotation rotation : rotation
    @int x : x coordinate
    @int y : y coordinate
    return Block : Indicates if the particular block is filled, rotatoinal, or free
*/
Block Pieces::GetBlockType(Tetrimino tetrimino, Rotation rotation, int x, int y){
    return mPieces[tetrimino][rotation][y][x];
}


/*
    Returns initial starting X coordinate of the tetrimino with particular rotation
    @int pPiece : tetrimino
    @int pRotation : rotation
*/
int Pieces::GetXInitialPosition(int pPiece, int pRotation){
    return piece_position[pPiece][pRotation][0];
}

/*
    Returns initial starting Y coordinate of the tetrimino with particular rotation
    @int pPiece : tetrimino
    @int pRotation : rotation
*/
int Pieces::GetYInitialPosition(int pPiece, int pRotation){
    return piece_position[pPiece][pRotation][1];
}
