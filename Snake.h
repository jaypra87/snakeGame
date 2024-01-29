#ifndef SNAKE_H
#define SNAKE_H

#include "Food.h"
#include <windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
    private:
        COORD position;
        int length;
        int velocity;
        char direction;
        vector<COORD> body;
    public:
        Snake(COORD position, int velocity); //This is a constructor that will initialize the variables
        void changeDirection(char dir); //This method will change the direction of the snake
        void moveSnake(); //This method will move the snake in a particular direction
        COORD getPosition(); //This method will get the current position of the snake
        bool haseaten(COORD foodPosition);
        void grow();
        bool collided();

        vector<COORD> getBody();
};

#endif