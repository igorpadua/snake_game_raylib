#include "game.hpp"
#include "raymath.h"

const int CELL_SIZE = 30;
const int CELL_COUNT = 25;
double lastUpdateTime = 0;


Game::Game()
    : snake(Snake())
    , food(Food(snake.getBody()))
    , running(true)
{
}

auto Game::draw() -> void
{
    food.draw();
    snake.draw();
}

auto Game::update() -> void
{
    if (!running) {
        return;
    }
    snake.update();
    checkCollisionWithFood();
    checkCollisionWithEdges();
    checkCollisionWithTail();

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

auto Game::checkCollisionWithEdges() -> void
{
    if (snake.getBody()[0].x == CELL_COUNT or snake.getBody()[0].x == -1) {
        gameOver();
    }

    if (snake.getBody()[0].y == CELL_COUNT or snake.getBody()[0].y == -1) {
        gameOver();
    }
}

auto Game::gameOver() -> void
{
    snake.reset();
    food.setPosition(food.generateRandomPos(snake.getBody()));
    running = false;
}

void Game::snake_move()
{
    auto key = GetKeyPressed();

    switch (key) {
    case KEY_UP:
        if (snake.direction.y != 1) {
            snake.direction = Vector2{0, -1};
            running = true;
        }
        break;
    case KEY_DOWN:
        if (snake.direction.y != -1) {
            snake.direction = Vector2{0, 1};
            running = true;
        }
        break;
    case KEY_LEFT:
        if (snake.direction.x != 1) {
            snake.direction = Vector2{-1, 0};
            running = true;
        }
        break;
    case KEY_RIGHT:
        if (snake.direction.x != -1) {
            snake.direction = Vector2{1, 0};
            running = true;
        }
        break;
    }
}

auto Game::checkCollisionWithTail() -> void
{
    auto headLessBody = snake.getBody();
    headLessBody.pop_front();

    if (elementInDeque(snake.getBody()[0], headLessBody)) {
        gameOver();
    }
}
