#include "snake.h"


void start(Snake& snake, Cord tail[], Cord fruits[], string fileName){
    ifstream loadFile;
    string temp;

    // Choosing file to load, will make in plotter eventually

    loadFile.open(fileName);

    loadFile >> snake.gameType >> snake.SPEED >> snake.SIZE;
    getline(loadFile, temp);

    loadFile >> snake.length;
    for(int i = 0; i < snake.length; i++){
        loadFile >> tail[i].x;
        loadFile >> tail[i].y;
    }
    getline(loadFile, temp);

    loadFile >> snake.NUM_FRUITS;
    for(int i = 0; i < snake.NUM_FRUITS; i++){
        loadFile >> fruits[i].x;
        loadFile >> fruits[i].y;
    }
    getline(loadFile, temp);

    loadFile >> temp;
    if(temp == "RIGHT"){
        snake.dir = RIGHT;
    }
    if(temp == "LEFT"){
        snake.dir = LEFT;
    }
    if(temp == "UP"){
        snake.dir = UP;
    }
    if(temp == "DOWN"){
        snake.dir = DOWN;
    }

    loadFile >> snake.x;
    loadFile >> snake.y;

    snake.MAX_LENGTH = (NUM_COL * NUM_ROW)/snake.SIZE;
    loadFile.close();
}

// Stop file
void stop(Snake snake, Cord tail[], Cord fruits[], string fileName){
    ofstream toSave;
    string temp;

    toSave.open(fileName);
    toSave.clear();

// writing data to file
    toSave << snake.gameType << " " << snake.SPEED << " " << snake.SIZE << endl;

    toSave << snake.length << " ";
    for(int i = 0; i < snake.length; i++){
        toSave << tail[i].x;
        toSave << " ";
        toSave << tail[i].y;
        toSave << " ";
    }
    toSave << endl;

    toSave << snake.NUM_FRUITS << " ";
    for(int i = 0; i < snake.NUM_FRUITS; i++){
        toSave << fruits[i].x;
        toSave << " ";
        toSave << fruits[i].y;
        toSave << " ";
    }
    toSave << endl;

    if(snake.dir == RIGHT){
        toSave << "RIGHT";
    }
    else if(snake.dir == LEFT){
        toSave << "LEFT";
    }
    else if(snake.dir == UP){
        toSave << "UP";
    }
    else if(snake.dir == DOWN){
        toSave << "DOWN";
    }
    toSave << " ";
    toSave << snake.x;
    toSave << " ";
    toSave << snake.y;
    toSave.close();
}


// Cord Class

//initialized at -1, -1
Cord::Cord(){
    x = -1;
    y = -1;
}

Cord::Cord(int a, int b){
    x = a;
    y = b;
}


// Snake Class
Snake::Snake(){
    x = NUM_COL/2;
    y = (NUM_ROW/2) + 30;
    length = 1;
    dir = RIGHT;
}

// to be run at the end of each "turn", moves the snake by 1 in
// the current direction, also shifts the tail.
void Snake::update(Cord tail[], bool eaten){
    shift(tail, eaten);

    if(dir == RIGHT){
        x += SIZE;
    }
    if(dir == LEFT){
        x -= SIZE;
    }
    if(dir == UP){
        y -= SIZE;
    }
    if(dir == DOWN){
        y += SIZE;
    }

    if(eaten){
        //cout << "EATEN" << endl;
        length++;
    }
}

// loops over fruit array and checks individual locations
// returns fruit num in array that is being eaten
// returned -1 if no fruit is being eaten

int Snake::isEating(Cord fruits[]){
    int result = -1;
    for(int i = 0; i < NUM_FRUITS; i++){
        if(x == fruits[i].x && y == fruits[i].y){
            result = i;
        }
    }
    return result;
}

bool Snake::checkCollision(Cord tail[]){
    // collision with walls
    bool result = false;
    if(x >= NUM_COL || x < 0){
        result = true;
    }
    else if(y >= 650 || y < 30){
        result = true;
    }
    //self collision
    for(int i = 1; i < length; i++){
        if(tail[i].x != -1 && tail[i].y != -1){
            if(tail[i].x == x && tail[i].y == y){
                result = true;
            }
        }
    }
    return result;
}

// checks to make sure direction is doable, then assigns
void Snake::turn(Direction d){
    if(dir == UP && d != DOWN){
        dir = d;
    }
    else if(dir == DOWN && d != UP){
        dir = d;
    }
    else if(dir == RIGHT && d != LEFT){
        dir = d;
    }
    else if(dir == LEFT && d != RIGHT){
        dir = d;
    }
}

// moves fruit to new location
void Snake::moveFruit(Cord fruits[], int to_move, Cord tail[]){
// still need to stop placing fruit inside of snake tail
    bool check = true;
    do{
        bool check = true;
        int fX1 = (rand() % NUM_ROW);
        int fX2 = fX1 % SIZE;
        fX1 = fX1 - fX2;
        fruits[to_move].x = fX1;
        int fY1 = (rand() % NUM_COL);
        int fY2 = fY1 % SIZE;
        fY1 = fY1 - fY2;
        fruits[to_move].y = fY1+30;
        for(int i = 0; i < length; i++){
            if(fruits[to_move].x == tail[i].x && fruits[to_move].y == tail[i].y){
                check = false;
            }
        }
        if(fruits[to_move].x == x && fruits[to_move].y == y){
            check = false;
        }
    }while(!check);
}

// shifts tail[] by one and pops last value unless fruit is eaten
void Snake::shift(Cord tail[], bool eaten){
    Cord temp[(NUM_ROW*NUM_COL)/SIZE];
    tail[0] = Cord(x, y);

    for(int i = 1; i < length; i++){
        temp[i] = tail[i-1];
    }
    for(int i = 0; i < length; i++){
        tail[i] = temp[i];
    }
    if(!eaten){
        tail[length-1] = Cord(-2, -2);
    }
    else{
        tail[length] = Cord(-2, -2);
    }
}

void Snake::drawSnake(SDL_Plotter& g, Cord tail[], Cord fruits[], Cord prev, int R, int G, int B){
    for(int j = 0; j < SIZE; j++){
        for(int k = 0; k < SIZE; k++){
            g.plotPixel(x + j, y + k, R, G, B);

        }
    }

    // Draw Tail and erase back
    for(int i = 0; i < length; i++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                if(tail[i].x == -2 && tail[i].y == -2){
                    g.plotPixel(prev.x + x, prev.y + y, 255, 255, 255);
                }
                else if (tail[i].x != -1 && tail[i].y != -1){
                    g.plotPixel(tail[i].x + x, tail[i].y + y, R, G, B);
                }
            }
        }
    }
}
string toString(int length){
    stringstream ss;
    ss.clear();
    ss << length;
    string str = ss.str();
    return str;
}

int highScore(string fileName){
    ifstream file;
    file.open(fileName);
    int score;
    string name;

    file >> name >> score;
    file.close();
    return score;
}
void setHighScore(string fileName, string name, int score){
    ofstream file(fileName);

    file << name << " " << score;

    file.close();
}

void cycleHighScore(SDL_Plotter& g, int count, int R, int G, int B){
    ifstream file;
    string name, score, fileName;
    string speed, size, fruits;
    string toPrint;

    if(count == 0){
        fileName = ("(1,1,1).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "SMALL MAP";
        fruits = "l FRUIT";

    }
    else if(count == 1){
        fileName = ("(1,1,2).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "SMALL MAP";
        fruits = "3 FRUITS";


    }
    else if(count == 2){
        fileName = ("(1,1,3).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "SMALL MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 3){
        fileName = ("(1,2,1).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "MEDIUM MAP";
        fruits = "l FRUIT";


    }
    else if(count == 4){
        fileName = ("(1,2,2).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "MEDIUM MAP";
        fruits = "3 FRUITS";


    }
    else if(count == 5){
        fileName = ("(1,2,3).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "MEDIUM MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 6){
        fileName = ("(1,3,1).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "LARGE MAP";
        fruits = "l FRUIT";

    }
    else if(count == 7){
        fileName = ("(1,3,2).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "LARGE MAP";
        fruits = "3 FRUITS";
    }
    else if(count == 8){
        fileName = ("(1,3,3).txt");
        file.open(fileName);
        speed = "SLOW SPEED";
        size = "LARGE MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 9){
        fileName = ("(2,1,1).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "SMALL MAP";
        fruits = "l FRUIT";

    }
    else if(count == 10){
        fileName = ("(2,1,2).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "SMALL MAP";
        fruits = "3 FRUITS";

    }
    else if(count == 11){
        fileName = ("(2,1,3).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "SMALL MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 12){
        fileName = ("(2,2,1).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "MEDIUM MAP";
        fruits = "l FRUIT";

    }
    else if(count == 13){
        fileName = ("(2,2,2).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "MEDIUM MAP";
        fruits = "3 FRUITS";


    }
    else if(count == 14){
        fileName = ("(2,2,3).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "MEDIUM MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 15){
        fileName = ("(2,3,1).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "LARGE MAP";
        fruits = "l FRUIT";

    }
    else if(count == 16){
        fileName = ("(2,3,2).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "LARGE MAP";
        fruits = "3 FRUITS";

    }
    else if(count == 17){
        fileName = ("(2,3,3).txt");
        file.open(fileName);
        speed = "MEDIUM SPEED";
        size = "LARGE MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 18){
        fileName = ("(3,1,1).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "SMALL MAP";
        fruits = "l FRUIT";

    }
    else if(count == 19){
        fileName = ("(3,1,2).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "SMALL MAP";
        fruits = "3 FRUITS";

    }
    else if(count == 20){
        fileName = ("(3,1,3).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "SMALL MAP";
        fruits = "5 FRUITS";

    }
    else if(count == 21){
        fileName = ("(3,2,1).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "MEDIUM MAP";
        fruits = "l FRUIT";

    }
    else if(count == 22){
        fileName = ("(3,2,2).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "MEDIUM MAP";
        fruits = "3 FRUITS";

    }
    else if(count == 23){
        fileName = ("(3,2,3).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "MEDIUM MAP";
        fruits = "5 FRUITS";


    }
    else if(count == 24){
        fileName = ("(3,3,1).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "LARGE MAP";
        fruits = "l FRUIT";

    }
    else if(count == 25){
        fileName = ("(3,3,2).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "LARGE MAP";
        fruits = "3 FRUITS";

    }
    else if(count == 26){
        fileName = ("(3,3,3).txt");
        file.open(fileName);
        speed = "FAST SPEED";
        size = "LARGE MAP";
        fruits = "5 FRUITS";
    }

    file >> name >> score;
    file.close();

    toPrint = speed + "\n\n" + size + "\n\n" + fruits;
    words(g, 220, 530, 2, toPrint, R, G, B);
    words(g, 420, 530, 2, "HIGH SCORE", 0, 0, 0);
    words(g, 420, 560, 3, name + "\n" + score, R, G, B);

}
