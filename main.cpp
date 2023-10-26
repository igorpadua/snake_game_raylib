#include <raylib.h>

#include "colors.hpp"
#include "game.hpp"

auto eventTriggered(double interval) -> bool;

int main()
{
    InitWindow(2 * OFFSET + CELL_SIZE * CELL_COUNT, 2 * OFFSET + CELL_SIZE * CELL_COUNT, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (eventTriggered(0.2)) {
            game.update();
        }

        game.snake_move();

        ClearBackground(MY_GREEN);
        DrawRectangleLinesEx(Rectangle{static_cast<float>(OFFSET - 5), static_cast<float>(OFFSET - 5), static_cast<float>(CELL_SIZE * CELL_COUNT + 10), static_cast<float>(CELL_SIZE * CELL_COUNT + 10)}, 5, MY_DARK_GREEN);
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
