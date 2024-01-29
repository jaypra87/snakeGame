#include <iostream>
#include <conio.h> 
#include <ctime>

#include "Snake.h"
#include "Food.h"

//Defining the macros. Macros are just one-line codes that make it easier for the user to perform a certain function.
//For example, if I want to calculate the square of a number, I can make it so that when the key 'S' is clicked - it calculates the square of a number,

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int score;

void board()
{
    COORD snakePosition = snake.getPosition();
    COORD foodPosition = food.getFoodPosition();

    vector<COORD> snakeBody = snake.getBody();

    cout << "SCORE: " << score << "\n\n";

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << "#";

            else if (i == snakePosition.Y && j + 1 == snakePosition.X) cout << "0";
            else if (i == foodPosition.Y && j + 1 == foodPosition.X) cout << "$";

            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snakeBody.size() - 1; k++)
                {
                    if (i == snakeBody[k].Y && j+1 == snakeBody[k].X)
                    {
                        cout << "o";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart)
                {
                    cout << " ";
                }
            }
        }
        cout << "#\n";
    }
}

int main()
{
    score = 0;

    srand(time(NULL));

    bool gameOver = false;
    while (!gameOver)
    {
        board();

        if (kbhit())
        {
            switch(getch())
            {
                case 'w': snake.changeDirection('u');break;
                case 'a': snake.changeDirection('l');break;
                case 's': snake.changeDirection('d');break;
                case 'd': snake.changeDirection('r');break;
            }
        }

        if (snake.collided()) gameOver = true;

        if (snake.haseaten(food.getFoodPosition()))
        {
            food.generateFood();
            snake.grow();
            score += 10;
        }

        snake.moveSnake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0 ,0});
    }
}
