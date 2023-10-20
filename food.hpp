#pragma once

#include "raylib.h"

class Food
{
public:
    Food();
    ~Food();

    void draw(int cellSize);
private:
    Vector2 position;
    Texture2D texture;
};

