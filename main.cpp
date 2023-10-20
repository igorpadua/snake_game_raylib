#include <memory>
#include <raylib.h>

#include "colors.hpp"
#include "food.hpp"
#include "grid.hpp"
#include "snake.hpp"

int main()
{
    InitWindow(CELL_SIZE * CELL_COUNT, CELL_SIZE * CELL_COUNT, "Retro Snake");
    SetTargetFPS(60);

    auto food = std::unique_ptr<Food>(new Food());
    auto snake = std::unique_ptr<Snake>(new Snake());

    while (WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(MY_GREEN);

        food->draw();
        snake->draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
