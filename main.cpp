#include <memory>
#include <raylib.h>

#include "colors.hpp"
#include "food.hpp"
#include "game.hpp"
#include "grid.hpp"
#include "snake.hpp"

auto eventTriggered(double interval) -> bool;

int main()
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (eventTriggered(0.2)) {
            game.update();
        }

        game.snake.move();

        ClearBackground(MY_GREEN);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

auto eventTriggered(double interval) -> bool {
    auto currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
