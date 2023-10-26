#include "snake.hpp"
#include "colors.hpp"
#include "game.hpp"

#include <raymath.h>

Snake::Snake()
    : body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4 , 9}})
    , direction{1, 0}
    , addSegment{false}
{

}

auto Snake::draw() -> void
{
    for (auto i = 0u; i < body.size(); ++i) {
        auto x = body[i].x;
        auto y = body[i].y;
        auto segment = Rectangle{OFFSET + x * CELL_SIZE, OFFSET + y * CELL_SIZE, static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)};
        DrawRectangleRounded(segment, 0.5, 6, MY_DARK_GREEN);
    }
}

auto Snake::update() -> void
{
    body.push_front(Vector2Add(body[0], direction));
    if (addSegment) {
        addSegment = false;
        return;
    }

    body.pop_back();
}

std::deque<Vector2> Snake::getBody() const
{
    return body;
}

void Snake::reset()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4 , 9}};
    direction = {1, 0};
}
