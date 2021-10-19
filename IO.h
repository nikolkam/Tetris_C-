
#ifndef _IO_
#define _IO_


#include <SDL/SDL.h>									
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")
enum Color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, ORANGE ,COLOR_MAX};

class IO{
public:    
    IO();

    void DrawRectangle (int leftUpX, int leftUpY, int rightDownX, int rightDownY, Color color);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int Pollkey();
    int IsKeyDown(int pKey);
    void UpdateScreen();
    int Getkey();

};




#endif