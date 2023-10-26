#include "food.hpp"
#include "snake.hpp"

#pragma once

extern const int CELL_SIZE;
extern const int CELL_COUNT;
extern double lastUpdateTime;
extern const int OFFSET;

class Game
{
public:
    Game();
    ~Game();

    auto draw() -> void;
    auto update() ->void;
    auto checkCollisionWithFood() -> void;
    static auto elementInDeque(Vector2 element, std::deque<Vector2> deque) -> bool;
    auto checkCollisionWithEdges() ->void;
    auto gameOver() -> void;
    auto snake_move() -> void;
    auto checkCollisionWithTail() -> void;

    int score;
    Snake snake;

private:
    Sound eatSound;
    Sound wallSound;
    Food food;
    bool running;
};

