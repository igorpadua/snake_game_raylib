#include "food.hpp"
#include "grid.hpp"

Food::Food()
    : position(generateRandomPos())
{
    Image image = LoadImage("resources/graphics/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food()
{
    UnloadTexture(texture);
}

auto Food::draw() -> void
{
    DrawTexture(texture, position.x * CELL_SIZE, position.y * CELL_SIZE, WHITE);
}

auto Food::generateRandomPos() -> Vector2
{
    auto x = static_cast<float>(GetRandomValue(0, CELL_COUNT - 1));
    auto y =  static_cast<float>(GetRandomValue(0, CELL_COUNT - 1));
    return Vector2{x, y};
}
