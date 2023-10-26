#pragma once

#include <deque>
#include <raylib.h>

class Snake
{
public:
    Snake();

    auto draw() -> void;
    auto update() -> void;
    std::deque<Vector2> getBody() const;
    auto reset() -> void;

    Vector2 direction;
    bool addSegment;

private:
    std::deque<Vector2> body;
};

