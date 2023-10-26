#pragma once

#include "raylib.h"

#include <deque>

class Food
{
public:
    Food(std::deque<Vector2> snakeBody);
    ~Food();

    auto draw() -> void;
    auto generateRandomPos(std::deque<Vector2> snakebody) -> Vector2;
    Vector2 getPosition() const;
    auto generateRadomCell() -> Vector2;

    void setPosition(const Vector2 &newPosition);

private:
    Vector2 position;
    Texture2D texture;
};

