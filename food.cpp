#include "food.hpp"
#include "colors.hpp"

Food::Food()
{

}

void Food::draw(int cellSize)
{
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, MY_DARK_GREEN);
}
