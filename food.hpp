#pragma once

#include "raylib.h"

class Food
{
public:
    Food();
    ~Food();

    auto draw() -> void;
    auto generateRandomPos() -> Vector2;
private:
    Vector2 position;
    Texture2D texture;
};

