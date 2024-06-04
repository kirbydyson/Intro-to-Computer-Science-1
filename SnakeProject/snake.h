#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDL_Plotter.h"
#include "print.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// hopefully will eventually be defined in the start function
enum Direction {UP, DOWN, LEFT, RIGHT};
const int NUM_ROW = 600;
const int NUM_COL = 600;



// Coordinate definition
struct Cord{
    int x, y;
    Cord();
    Cord(int, int);
};

// Snake definition
struct Snake{
    public:
        int x, y, length;
        int SIZE;
        int MAX_LENGTH;
        int SPEED = 120;
        int NUM_FRUITS;
        string gameType = "(0,0,0).txt";
        Direction dir;
        Snake();
        void update(Cord tail[], bool);
        int isEating(Cord fruits[]);
        bool checkCollision(Cord tail[]);
        void turn(Direction);
        void moveFruit(Cord fruits[], int, Cord tail[]);
        void shift(Cord tail[], bool);
        void drawSnake(SDL_Plotter&, Cord tail[], Cord fruits[], Cord, int, int, int);
};

// Start game function
void start(Snake&, Cord tail[], Cord fruits[], string);

// Stop game function
void stop(Snake, Cord tail[], Cord fruits[], string);

int highScore(string);

void setHighScore(string, string, int);

// Prints High score to screen
void cycleHighScore(SDL_Plotter&, int, int, int, int);

//makes scoreboard easier. converts an int to a string
string toString(int);

#endif // SNAKE_H_INCLUDED
