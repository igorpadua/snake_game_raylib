#pragma once

#include <deque>
#include <raylib.h>

class Snake
{
public:
    Snake();

    auto draw() -> void;
    auto update() -> void;
    auto move() -> void;
    Vector2 direction;

private:
    std::deque<Vector2> body;
};

