#include <raylib.h>

#include "colors.hpp"

const auto CELLSIZE = 30;
const auto CELLCOUNT = 25;

int main()
{
    InitWindow(CELLSIZE * CELLCOUNT, CELLSIZE * CELLCOUNT, "Retro Snake");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(MY_GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
