#include "Snake.h"

Snake::Snake(COORD position, int velocity)
{
    this-> position = position;
    this-> velocity = velocity;
    direction = 'n';
    length = 1;

    body.push_back(position);
}

void Snake::changeDirection(char dir) {direction = dir;}
void Snake::grow() {length++;}
COORD Snake::getPosition() { return position; }

vector<COORD> Snake::getBody() { return body; }

void Snake::moveSnake()
{
    switch (direction)
    {
        case 'u': position.Y -= velocity;break;
        case 'd': position.Y += velocity;break;
        case 'l': position.X -= velocity;break;
        case 'r': position.X += velocity;break;
    }

    body.push_back(position);
    if (body.size() > length)
    {
        body.erase(body.begin());
    }
}

bool Snake::haseaten(COORD foodPosition)
{
    if (foodPosition.X == position.X && foodPosition.Y == position.Y) return true;
    else return false;
}

bool Snake::collided()
{
    if (position.X < 1 || position.X > WIDTH - 2 || position.Y < 1 || position.Y > HEIGHT - 2) return true;

    for (int i = 0; i < length - 1; i++)
    {
        if (position.X == body[i].X && position.Y == body[i].Y)
        {
            return true;
        }
    }
    return false;
}