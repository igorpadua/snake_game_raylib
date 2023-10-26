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

    std::deque<Vector2> getBody() const;

private:
    std::deque<Vector2> body;
};

