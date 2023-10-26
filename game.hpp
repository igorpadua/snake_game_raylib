#include "food.hpp"
#include "snake.hpp"

#pragma once

extern const int CELL_SIZE;
extern const int CELL_COUNT;
extern double lastUpdateTime;

class Game
{
public:
    Game();

    auto draw() -> void;
    auto update() ->void;
    auto checkCollisionWithFood() -> void;
    static auto elementInDeque(Vector2 element, std::deque<Vector2> deque) -> bool;
    auto checkCollisionWithEdges() ->void;
    auto gameOver() -> void;
    auto snake_move() -> void;

    Snake snake;

private:
    Food food;
    bool running;
};

