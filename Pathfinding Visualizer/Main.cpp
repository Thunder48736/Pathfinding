#include <iostream>
#include "Grid.h"
#include "Pathfinder.h"

int main() {
    Grid grid(10, 10);

    grid.setStart(0, 0);
    grid.setEnd(9, 9);

    grid.setWall(1, 0);
    grid.setWall(1, 1);
    grid.setWall(1, 2);
    grid.setWall(2, 3);
    grid.setWall(3, 2);
    grid.setWall(4, 2);

    Pathfinder pathfinder(grid);
    bool found = pathfinder.BFS();

    if (found)
        std::cout << "Ścieżka znaleziona!\n";
    else
        std::cout << "Brak możliwej ścieżki!\n";

    grid.display();
    return 0;
}
