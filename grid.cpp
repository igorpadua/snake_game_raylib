#include "grid.hpp"
#include "raymath.h"

const int CELL_SIZE = 30;
const int CELL_COUNT = 25;
double lastUpdateTime = 0;

bool elementInDeque(Vector2 element, std::deque<Vector2> deque)
{
    for (auto i = 0u; i < deque.size(); ++i) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}
