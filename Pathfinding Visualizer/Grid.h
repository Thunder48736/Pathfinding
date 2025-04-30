#pragma once
#include <vector>
#include "Node.h"

class Grid {
private:
    int width, height;
    std::vector<std::vector<Node>> nodes;
    Node* startNode;
    Node* endNode;

public:
    Grid(int w, int h);
    void display() const;
    Node* getNode(int x, int y);
    int getWidth() const;
    int getHeight() const;
    void setStart(int x, int y);
    void setEnd(int x, int y);
    void setWall(int x, int y);
    Node* getStart();
    Node* getEnd();
};
