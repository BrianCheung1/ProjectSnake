#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <curses.h>


using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;



void Setup(){
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = 12;
    fruitY = 12;
    score = 0;
}
void Draw(){
    system("clear");
    for(int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0)
                cout << "#";
            if(i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for(int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
    cout << "X:" << x << " " << "Y:" << y << endl;
    cout << "Height:" << height << " " << "Width:" << width << endl;
    cout << "FruitX:" << fruitX << " " << "FruitY:" << fruitY << endl;

}
void Input(){
    switch(getchar(){
        case 'a':
            x++;
            dir = LEFT;
            break;
        case 'd':
            x--;
            dir = RIGHT;
            break;
        case 'w':
            y++;
            dir = UP;
            break;
        case 's':
            y--;
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
    }
}
void Logic(){
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x > width || x < 0 || y > height || y < 0){
        gameOver = true;
    }
    if(x == fruitX && y == fruitY){
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}
int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    return 0;
}