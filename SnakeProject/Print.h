#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <fstream>
#include "SDL_Plotter.h"
#include "snake.h"

using namespace std;

const int ROW = 5, COL = 5, MAX = 25;


struct Letters{
    char letter;
    char lets[ROW][COL];

    void findLetter(char);

    void drawLetter(SDL_Plotter& g, int, int, int, int, int, int);

    void startScreen(SDL_Plotter& g);

};

void words(SDL_Plotter& g, int, int, int, string, int, int, int);

void clear(SDL_Plotter& g, int R, int G, int B);


#endif // PRINT_H_INCLUDED
