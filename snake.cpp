#include "snake.hpp"
#include "colors.hpp"
#include "grid.hpp"

#include <raymath.h>

Snake::Snake()
    : body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4 , 9}})
    , direction{1, 0}
{

}

auto Snake::draw() -> void
{
    for (auto i = 0u; i < body.size(); ++i) {
        auto x = body[i].x;
        auto y = body[i].y;
        auto segment = Rectangle{x * CELL_SIZE,  y * CELL_SIZE, static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)};
        DrawRectangleRounded(segment, 0.5, 6, MY_DARK_GREEN);
    }
}

auto Snake::update() -> void
{
    body.pop_back();
    body.push_front(Vector2Add(body[0], direction));
}

auto Snake::move() -> void
{
    auto key = GetKeyPressed();

    switch (key) {
    case KEY_UP:
        if (direction.y != 1) {
            direction = Vector2{0, -1};
        }
        break;
    case KEY_DOWN:
        if (direction.y != -1) {
            direction = Vector2{0, 1};
        }
    case KEY_LEFT:
        if (direction.x != 1) {
            direction = Vector2{-1, 0};
        }
        break;
    case KEY_RIGHT:
        if (direction.x != -1) {
            direction = Vector2{1, 0};
        }
        break;
    }
}
