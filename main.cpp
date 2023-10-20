#include <memory>
#include <raylib.h>

#include "colors.hpp"
#include "food.hpp"
#include "grid.hpp"
#include "snake.hpp"

auto eventTriggered(double interval) -> bool;

int main()
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Retro Snake");
    SetTargetFPS(60);

    auto food = std::unique_ptr<Food>(new Food());
    auto snake = std::unique_ptr<Snake>(new Snake());

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (eventTriggered(0.2)) {
            snake->update();
        }

        snake->move();

        ClearBackground(MY_GREEN);

        food->draw();
        snake->draw();

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
