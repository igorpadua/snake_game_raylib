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

private:
    std::deque<Vector2> body;
    Vector2 direction;
};

