#include <raylib.h>

#include "colors.hpp"
#include "food.hpp"

const auto CELLSIZE = 30;
const auto CELLCOUNT = 25;

int main()
{
    InitWindow(CELLSIZE * CELLCOUNT, CELLSIZE * CELLCOUNT, "Retro Snake");
    SetTargetFPS(60);

    auto food = Food();

    while (WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(MY_GREEN);

        food.draw(CELLSIZE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
