
#include "SDL_Plotter.h"
#include "snake.h"
#include "Print.h"

Cord fruits[5];
Cord tail[(NUM_ROW*NUM_COL)/80];

int main(int argc, char **argv){
    // Data Abstraction
    Cord prev, lastPrev;
    char key;
    SDL_Plotter g(650, NUM_COL);
    int R = 255, G = 0, B = 127;
    Snake snake;
    Snake homescreen;
    Cord homeTail[50];
    Cord temp[3];
    int fruitEaten;
    int eaten = false;
    int count = 0;
    int turn = 0;
    int scoreNum = 0;
    int lastScore = 0;
    int shift = 0;
    int initial = 0;
    int space = 0;
    bool justUnpaused = false;
    bool paused = false;
    bool started = false;
    bool chosen = false;
    bool saveFile = true;
    bool saving = false;
    bool phaseOne = false;
    bool phaseTwo = false;
    bool phaseThree = false;
    bool gameOver = false;
    bool win = false;
    string name = "AAA";
    string prevName = "AAA";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string tempStr;
    g.initSound("AppleEat.wav");
    g.initSound("DeathSound.wav");

    start(homescreen, homeTail, temp, "homeSnake.txt");

    while(!g.getQuit()){
        //User Input
        if(g.kbhit()){
            key = g.getKey();
            switch(key){
                case UP_ARROW:
                    snake.turn(UP);
                break;
                case DOWN_ARROW:
                    snake.turn(DOWN);
                break;
                case LEFT_ARROW:
                    if(gameOver){
                        prevName = name;
                        if(shift == 0){
                            shift = 25;
                        }
                        else{
                            shift--;
                        }
                        name[initial] = alphabet[shift];
                    }
                    else if(!started){
                        lastScore = scoreNum;
                        if(scoreNum == 0){
                            scoreNum = 26;
                        }
                        else{
                            scoreNum--;
                        }
                    }
                    snake.turn(LEFT);

                break;
                case RIGHT_ARROW:
                    if(gameOver){
                        prevName = name;
                        if(shift == 25){
                            shift = 0;
                        }
                        else{
                            shift++;
                        }
                        name[initial] = alphabet[shift];
                    }
                    else if(!started){
                        lastScore = scoreNum;
                        if(scoreNum == 26){
                            scoreNum = 0;
                        }
                        else{
                            scoreNum++;
                        }
                    }
                    snake.turn(RIGHT);
                break;
                case PAUSE:
                    paused = true;
                    break;
                case UNPAUSE:
                    paused = false;
                    justUnpaused = true;
                    break;
                case Q:
                    if(paused){
                        saving = true;
                    }
                    if(gameOver){
                        initial++;
                    }
                    else if(!started && phaseThree){
                        started = true;
                        g.Sleep(1000);
                        clear(g, 255, 255, 255);
                        for(int y = 0; y < 30; y++){
                            for(int x = 0; x < NUM_COL; x++){
                                g.plotPixel(x, y, 0, 0, 0);
                            }
                        }
                        for(int i = 0; i < snake.NUM_FRUITS; i++){
                            snake.moveFruit(fruits, i, tail);
                        }
                    }
                    break;
                case ONE:
                    if(!chosen){
                        chosen = true;
                        saveFile = false;
                    }
                    else if(!saveFile){
                        start(snake, tail, fruits, "save1.txt");
                        saveFile = true;
                        phaseOne = true;
                        phaseTwo = true;
                        phaseThree = true;
                    }
                    else if(!phaseOne){
                        snake.SPEED = 140;
                        phaseOne = true;
                        snake.gameType[1] = '1';
                    }
                    else if(!phaseTwo){
                        snake.SIZE = 60;
                        phaseTwo = true;
                        snake.gameType[3] = '1';

                    }
                    else if(!phaseThree){
                        snake.NUM_FRUITS = 1;
                        phaseThree = true;
                        snake.gameType[5] = '1';

                    }
                    else if(saving){
                        stop(snake, tail, fruits, "save1.txt");
                        g.setQuit(true);
                    }
                    break;
                case TWO:
                    if(!chosen){
                        chosen = true;
                    }
                    else if(!saveFile){
                        start(snake, tail, fruits, "save2.txt");
                        saveFile = true;
                        phaseOne = true;
                        phaseTwo = true;
                        phaseThree = true;
                    }
                    else if(!phaseOne){
                        snake.SPEED = 120;
                        phaseOne = true;
                        snake.gameType[1] = '2';

                    }
                    else if(!phaseTwo){
                        snake.SIZE = 50;
                        phaseTwo = true;
                        snake.gameType[3] = '2';

                    }
                    else if(!phaseThree){
                        snake.NUM_FRUITS = 3;
                        phaseThree = true;
                        snake.gameType[5] = '2';

                    }
                    else if(saving){
                        stop(snake, tail, fruits, "save2.txt");
                        g.setQuit(true);
                    }
                    break;
                case THREE:
                    if(!chosen){

                    }
                    else if(!saveFile){
                        start(snake, tail, fruits, "save3.txt");
                        saveFile = true;
                        phaseOne = true;
                        phaseTwo = true;
                        phaseThree = true;
                    }
                    else if(!phaseOne){
                        snake.SPEED = 100;
                        phaseOne = true;
                        snake.gameType[1] = '3';

                    }
                    else if(!phaseTwo){
                        snake.SIZE = 30;
                        phaseTwo = true;
                        snake.gameType[3] = '3';

                    }
                    else if(!phaseThree){
                        snake.NUM_FRUITS = 5;
                        phaseThree = true;
                        snake.gameType[5] = '3';

                    }
                    else if(saving){
                        stop(snake, tail, fruits, "save3.txt");
                        g.setQuit(true);
                    }
                    break;

            }
        }
        eaten = false;

        //Process
        if(started){
            tempStr = toString(snake.length);
            space = 0;
            for(int i = 1; i < tempStr.size(); i++){
                space += 40;
            }
            words(g, 560 - space, 25, 4, toString(snake.length-1), 0, 0, 0);
            words(g, 560 - (space-40), 25, 4, toString(snake.length-1), 0, 0, 0);
            words(g, 560 - space, 25, 4, toString(snake.length), 255, 255, 255);
            if(!paused){
                if(justUnpaused){
                    words(g, 5, 300, 3, "PRESS U TO RESUME GAME\nPRESS Q TO SAVE PROGRESS", 255, 255, 255);
                    justUnpaused = false;
                }
                // Check if Fruit is Eaten
                fruitEaten = snake.isEating(fruits);
                if(fruitEaten != -1){
                    eaten = false;
                    if(fruitEaten != -1){
                        eaten = true;
                        snake.moveFruit(fruits, fruitEaten, tail);
                        g.playSound("AppleEat.wav");

                    }
                }

                //Fruit Draw
                for(int i = 0; i < snake.NUM_FRUITS; i++){
                    for(int y = 0; y < snake.SIZE; y++){
                        for(int x = 0; x < snake.SIZE; x++){
                            g.plotPixel(fruits[i].x + x, fruits[i].y + y, 120, 190, 33);

                        }
                    }
                }

                // Update Snake tail and head
                if(snake.length == 1){
                    prev = Cord(snake.x, snake.y);
                    lastPrev = prev;
                }
                else if(snake.length == 2){
                    prev = lastPrev;
                    lastPrev = Cord(snake.x, snake.y);
                }
                else{
                    prev = lastPrev;
                    lastPrev = tail[snake.length-2];
                }

                snake.update(tail, eaten);
                snake.drawSnake(g, tail, temp, prev, R, G, B);

                if(snake.checkCollision(tail)){
                    g.update();
                    g.quitSound("AppleEat.wav");
                    g.playSound("DeathSound.wav");
                    g.Sleep(500);
                    started = false;
                    gameOver = true;
                }
                if(snake.length >= snake.MAX_LENGTH){
                    win = true;
                    gameOver = true;
                    started = false;
                }


                //Draw grid
                for(int j = 0; j < NUM_ROW; j++) {
                    for(int k = 0; k < NUM_COL; k++){
                        k = k + snake.SIZE-1;
                        g.plotPixel(j, k+30, 0, 20, 50);
                    }
                }
                for(int j = 0; j < NUM_ROW; j++) {
                    j = j + snake.SIZE-1;
                    for(int k = 0; k < 600; k++){
                        g.plotPixel(j, k+30, 0, 20, 50);
                    }
                }

            }
            else{
                if(!saving){
                    words(g, 5, 350, 3, "PRESS U TO RESUME GAME\nPRESS Q TO SAVE PROGRESS", 0, 0, 0);
                }
                else{
                    words(g, 5, 350, 3, "PRESS U TO RESUME GAME\nPRESS Q TO SAVE PROGRESS", 255, 255, 255);
                    words(g, 5, 350, 3, "PRESS l FOR SAVE FILE l\nPRESS 2 FOR SAVE FILE 2\nPRESS 3 FOR SAVE FILE 3", 0, 0, 0);

                }
            }
        }
        else if(!gameOver){ // TITLE SCREEN / SETUP
            words(g, 20, 200, 15, "SNAKE", 0, 0, 0);

            if(!chosen){
                words(g, 20, 350, 3, "PRESS l TO LOAD A SAVE\nPRESS 2 FOR A NEW GAME", 0, 0, 0);
            }

            else if(!saveFile){
                words(g, 20, 350, 3, "PRESS l TO LOAD A SAVE\nPRESS 2 FOR A NEW GAME", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS l FOR SAVE FILE l\nPRESS 2 FOR SAVE FILE 2\nPRESS 3 FOR SAVE FILE 3", 0, 0, 0);
            }
            else if(!phaseOne){
                words(g, 20, 350, 3, "PRESS l TO LOAD A SAVE\nPRESS 2 FOR A NEW GAME", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS l FOR SAVE FILE l\nPRESS 2 FOR SAVE FILE 2\nPRESS 3 FOR SAVE FILE 3", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS l FOR SLOW SPEED\nPRESS 2 FOR MEDIUM SPEED\nPRESS 3 FOR FAST SPEED", 0, 0, 0);
            }
            else if(!phaseTwo){
                words(g, 20, 350, 3, "PRESS l FOR SLOW SPEED\nPRESS 2 FOR MEDIUM SPEED\nPRESS 3 FOR FAST SPEED", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS l FOR SMALL MAP\nPRESS 2 FOR MEDIUM MAP\nPRESS 3 FOR LARGE MAP", 0, 0, 0);

            }
            else if(!phaseThree){
                words(g, 20, 350, 3, "PRESS l FOR SMALL MAP\nPRESS 2 FOR MEDIUM MAP\nPRESS 3 FOR LARGE MAP", 255, 255, 255);
                snake.MAX_LENGTH = (NUM_ROW * NUM_COL)/snake.SIZE;
                words(g, 20, 350, 3, "PRESS l FOR l FRUIT\nPRESS 2 FOR 3 FRUITS\nPRESS 3 FOR 5 FRUITS", 0, 0, 0);
            }
            else{
                words(g, 20, 350, 3, "PRESS l FOR SAVE FILE l\nPRESS 2 FOR SAVE FILE 2\nPRESS 3 FOR SAVE FILE 3", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS l FOR l FRUIT\nPRESS 2 FOR 3 FRUITS\nPRESS 3 FOR 5 FRUITS", 255, 255, 255);
                words(g, 20, 350, 3, "PRESS Q TO START GAME", 0, 0, 0);

            }


            if(count == 20 && (turn == 0 || turn == 2)){
                count = 0;
                if(turn == 0){
                    turn++;
                    homescreen.turn(UP);
                }

                else{
                    turn++;
                    homescreen.turn(DOWN);
                }
            }
            else if((count == 6 || count == 14) && (turn == 1 || turn == 3)){
                count = 0;
                if(turn == 1){
                    turn++;
                    homescreen.turn(LEFT);
                }
                else{
                    turn = 0;
                    homescreen.turn(RIGHT);
                }

            }

            prev = lastPrev;
            lastPrev = homeTail[homescreen.length-2];

            homescreen.update(homeTail, false);

            homescreen.drawSnake(g, homeTail, temp, prev, R, G, B);
            count++;

            cycleHighScore(g, lastScore, 255, 255, 255);
            cycleHighScore(g, scoreNum, 0, 0, 0);
            g.Sleep(homescreen.SPEED);
        }
        else{
            if(!win){
                R = 200;
                G = 90;
                B = 90;
                clear(g, R, G, B);
                words(g, 30, 200, 9, "YOU DIED", 0, 0, 0);
                if(snake.length >= highScore(snake.gameType)){
                    words(g, 45, 300, 5, "NEW HIGH SCORE", 0, 0, 0);
                }
            }
            else{
                R = 90;
                G = 200;
                B = 90;
                clear(g, R, G, B);
                words(g, 30, 200, 10, "YOU WON", 0, 0, 0);
                words(g, 40, 300, 8, "CONGRATULATIONS", 0, 0, 0);
            }


            if(snake.length >= highScore(snake.gameType)){
                words(g, 30, 380, 3, "USE ARROW KEYS TO CHANGE\nPRESS Q TO CONFIRM LETTER", 0, 0, 0);
                words(g, 200, 500, 10, prevName, R, G, B);
                words(g, 200, 500, 10, name, 0, 0, 0);
                if(initial == 3){
                    setHighScore(snake.gameType, name, snake.length);
                    words(g, 30, 80, 3, "THANKS FOR PLAYING SNAKE\n HIGH SCORE SAVED", 0, 0, 0);
                    g.update();
                    g.Sleep(5000);
                    g.setQuit(true);
                }
            }
            else{
                words(g, 40, 80, 3, "THANKS FOR PLAYING SNAKE", 0, 0, 0);
                g.update();
                g.Sleep(5000);
                g.setQuit(true);
            }
        }
        g.update();
        g.Sleep(snake.SPEED);

    }

    return 0;
}
