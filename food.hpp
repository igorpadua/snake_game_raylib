#pragma once

#include "raylib.h"

class Food
{
public:
    Food();
    Vector2 position = {5, 6};

    void draw(int cellSize);
};

