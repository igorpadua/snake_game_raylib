#include <deque>
#include <raylib.h>

#pragma once

extern const int CELL_SIZE;
extern const int CELL_COUNT;
extern double lastUpdateTime;

bool elementInDeque(Vector2 element, std::deque<Vector2> deque);
