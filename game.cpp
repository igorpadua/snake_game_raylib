#include "game.hpp"
#include "raymath.h"

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
    }
}
