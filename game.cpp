#include "game.hpp"
#include "raymath.h"

const int CELL_SIZE = 30;
const int CELL_COUNT = 25;
double lastUpdateTime = 0;


Game::Game()
    : snake(Snake())
    , food(Food(snake.getBody()))
{

}

auto Game::draw() -> void
{
    food.draw();
    snake.draw();
}

auto Game::update() -> void
{
    snake.update();
    checkCollisionWithFood();

}

auto Game::checkCollisionWithFood() -> void
{
    if (Vector2Equals(snake.getBody()[0], food.getPosition())) {
        food.setPosition(food.generateRandomPos(snake.getBody()));
        snake.addSegment = true;
    }
}


bool Game::elementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for (auto i = 0u; i < deque.size(); ++i) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}
