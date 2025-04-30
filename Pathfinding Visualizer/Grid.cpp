#include "Grid.h"
#include <iostream>

Grid::Grid(int w, int h) : width(w), height(h) {
    for (int i = 0; i < height; ++i) {
        std::vector<Node> row;
        for (int j = 0; j < width; ++j) {
            row.emplace_back(j, i);
        }
        nodes.push_back(row);
    }
    startNode = &nodes[0][0];
    endNode = &nodes[height - 1][width - 1];
}

void Grid::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            const Node& node = nodes[i][j];
            if (&node == startNode)
                std::cout << "S ";
            else if (&node == endNode)
                std::cout << "E ";
            else if (node.isPath)
                std::cout << ". ";
            else if (node.isWall)
                std::cout << "# ";
            else
                std::cout << "- ";
        }
        std::cout << "\n";
    }
}

Node* Grid::getNode(int x, int y) {
    return &nodes[y][x];
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

void Grid::setStart(int x, int y) {
    startNode = &nodes[y][x];
}

void Grid::setEnd(int x, int y) {
    endNode = &nodes[y][x];
}

void Grid::setWall(int x, int y) {
    nodes[y][x].isWall = true;
}

Node* Grid::getStart() {
    return startNode;
}

Node* Grid::getEnd() {
    return endNode;
}
