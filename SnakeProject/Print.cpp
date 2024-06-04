#include "Print.h"


void Letters::findLetter(char letter){
    ifstream inFile;
    char a;

    inFile.open("Letters.txt");

    do{
        inFile >> a;
    } while(a != letter);

    for(int x = 0; x < COL; x++){
        for(int y = 0; y < ROW; y++){
            inFile >> lets[x][y];
        }
    }

    inFile.close();
}
void Letters::drawLetter(SDL_Plotter& g, int yPos, int xPos, int s, int R=0, int G=0, int B=0){
    // lowercase o is Zero
    // lowercase l is One
    for(int x = 0; x < COL * s; x++){
        for(int y = 0; y < ROW * s; y++){
            if(lets[x/s][y/s] == '1'){
                g.plotPixel(y + yPos, x + xPos, R, G, B);
            }
        }
    }

}

void words(SDL_Plotter& g, int yPos, int xPos, int s, string text, int R=0, int G=0, int B=0){
    Letters lets[text.size()];

    int inityPos = yPos;

    for(int i = 0; i < text.size(); i++){
        if(text[i] == '0'){
            text[i] = 'o';
        }
        if(text[i] == '1'){
            text[i] = 'l';
        }
        if(text[i] == ' '){
            yPos += 5 * s;
        }
        else if(text[i] == '\n'){
            xPos += 8 * s;
            yPos = inityPos;
        }
        else{
            lets[i].findLetter(text[i]);
            lets[i].drawLetter(g, yPos, xPos, s, R, G, B);
            yPos += 8 * s;
        }
    }
}

void clear(SDL_Plotter& g, int R, int G, int B){
    for(int y = 0; y < NUM_ROW+50; y++){
        for(int x = 0; x < NUM_COL; x++){
            g.plotPixel(x, y, R, G, B);
        }
    }
}
