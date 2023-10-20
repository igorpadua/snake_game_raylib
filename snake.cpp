#include "snake.hpp"
#include "colors.hpp"
#include "grid.hpp"

Snake::Snake()
    : body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4 , 9}})
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
