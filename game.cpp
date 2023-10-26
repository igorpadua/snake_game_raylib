#include "game.hpp"

Game::Game()
    : snake(Snake())
    , food(Food())
{

}

auto Game::draw() -> void
{
    food.draw();
    snake.draw();
}

void Game::update()
{
    snake.update();

}
