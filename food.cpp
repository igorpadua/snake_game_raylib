#include "food.hpp"
#include "grid.hpp"

Food::Food(std::deque<Vector2> snakeBody)
    : position(generateRandomPos(snakeBody))
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

auto Food::generateRandomPos(std::deque<Vector2> snakebody) -> Vector2
{
    auto position = generateRadomCell();

    while (elementInDeque(position, snakebody)) {
        position = generateRadomCell();
    }

    return position;
}

auto Food::getPosition() const -> Vector2
{
    return position;
}

auto Food::generateRadomCell() -> Vector2
{
    auto x = static_cast<float>(GetRandomValue(0, CELL_COUNT - 1));
    auto y =  static_cast<float>(GetRandomValue(0, CELL_COUNT - 1));
    return Vector2{x, y};
}

auto Food::setPosition(const Vector2 &newPosition) -> void
{
    position = newPosition;
}
