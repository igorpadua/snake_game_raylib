#include "food.hpp"
#include "snake.hpp"

#pragma once


class Game
{
public:
    Game();

    auto draw() -> void;
    auto update() ->void;
    Snake snake;

private:
    Food food;
};

