#include <raylib.h>

int main()
{
    InitWindow(750, 750, "Retro Snake");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
