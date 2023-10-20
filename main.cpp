#include <raylib.h>

#include "colors.hpp"
#include "food.hpp"
#include "grid.hpp"

int main()
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Retro Snake");
    SetTargetFPS(60);

    auto food = Food();

    while (WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(MY_GREEN);

        food.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
