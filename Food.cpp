#include "Food.h"

Food::Food()
{
    generateFood();
}

void Food::generateFood()
{
    foodPosition.X = (rand() % WIDTH - 3) + 1;
    foodPosition.Y = (rand() % HEIGHT - 3) + 1;
}

COORD Food::getFoodPosition() 
{
    return foodPosition;
}