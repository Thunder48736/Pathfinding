#pragma once
#include "Grid.h"
#include <queue>

class Pathfinder {
public:
    Pathfinder(Grid& g);
    bool BFS();

private:
    Grid& grid;
    bool isValid(int x, int y);
};

