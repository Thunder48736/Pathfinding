#pragma once

struct Node {
    int x, y;
    bool isWall = false;
    bool isVisited = false;
    bool isPath = false;

    Node(int xCoord, int yCoord)
        : x(xCoord), y(yCoord) {}
};
