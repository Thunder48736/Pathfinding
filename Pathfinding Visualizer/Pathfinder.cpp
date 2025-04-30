#include "Pathfinder.h"

Pathfinder::Pathfinder(Grid& g) : grid(g) {}

bool Pathfinder::isValid(int x, int y) {
    return (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight());
}

bool Pathfinder::BFS() {
    Node* start = grid.getStart();
    Node* end = grid.getEnd();

    std::queue<Node*> q;
    q.push(start);
    start->isVisited = true;

    std::vector<std::vector<Node*>> parent(grid.getHeight(), std::vector<Node*>(grid.getWidth(), nullptr));

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == end) {
            Node* pathNode = end;
            while (pathNode != start) {
                pathNode->isPath = true;
                pathNode = parent[pathNode->y][pathNode->x];
            }
            return true;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int newX = current->x + dx[dir];
            int newY = current->y + dy[dir];

            if (isValid(newX, newY)) {
                Node* neighbor = grid.getNode(newX, newY);
                if (!neighbor->isVisited && !neighbor->isWall) {
                    neighbor->isVisited = true;
                    parent[newY][newX] = current;
                    q.push(neighbor);
                }
            }
        }
    }

    return false;
}
