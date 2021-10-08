#ifndef _PIECES_
#define _PIECES_

enum Tetrimino {SQUARE = 0, I = 1, L = 2, L_MIRROR = 3, N = 4, N_MIRROR = 5, T = 6}; //Enum encapsulating the tetrimino
enum Rotation {UP=0, RIGHT=1, DOWN=2, LEFT=3};  //Enum encapsulating the rotation of a tetrimino
enum Block {E=0, F=1, R=2}; //Enum encapsulating the status of the block E = Empty, F = Filled, R = Rotational Block

class Pieces{
public:
    Block GetBlockType(Tetrimino tetrimino, Rotation rotation, int x, int y);
    int GetXInitialPosition(int pPiece, int pRotation);
    int GetYInitialPosition(int pPiece, int pRotation);
};

#endif //_PIECES_

