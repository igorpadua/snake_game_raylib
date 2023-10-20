#include "food.hpp"
#include "colors.hpp"

Food::Food()
    : position({5, 6})
{
    Image image = LoadImage("resources/graphics/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::draw(int cellSize)
{
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}
