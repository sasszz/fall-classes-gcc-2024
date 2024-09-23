//
//  Creature.cpp
//  ch5pp4_maze
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#include "Creature.h"

#include <iostream>

using namespace std;

Creature::Creature(pair<int, int> start) {
    position = start;
}

bool Creature::goNorth(Maze &maze) {
    int x = position.first - 1, y = position.second;
    if (maze.isClear(x, y)) {
        cout << "Going North to (" << x << ", " << y << ")" << endl;
        position = {x, y};
        maze.markPath(x, y);
        printPosition();
        maze.printMaze();
        cout << endl;
        if (maze.isExit(x, y)) return true;
        if (goNorth(maze) || goWest(maze) || goEast(maze)) return true;
        maze.markVisited(x, y);
        cout << "Backtracking South to (" << x + 1 << ", " << y << ")" << endl;
        position = {x + 1, y};
    }
    return false;
}

bool Creature::goSouth(Maze &maze) {
    int x = position.first + 1, y = position.second;
    if (maze.isClear(x, y)) {
        cout << "Going South to (" << x << ", " << y << ")" << endl;
        position = {x, y};
        maze.markPath(x, y);
        printPosition();
        maze.printMaze();
        cout << endl;
        if (maze.isExit(x, y)) return true;
        if (goSouth(maze) || goWest(maze) || goEast(maze)) return true;
        maze.markVisited(x, y);
        cout << "Backtracking North to (" << x - 1 << ", " << y << ")" << endl;
        position = {x - 1, y};
    }
    return false;
}

bool Creature::goEast(Maze &maze) {
    int x = position.first, y = position.second + 1;
    if (maze.isClear(x, y)) {
        cout << "Going East to (" << x << ", " << y << ")" << endl;
        position = {x, y};
        maze.markPath(x, y);
        printPosition();
        maze.printMaze();
        cout << endl;
        if (maze.isExit(x, y)) return true;
        if (goNorth(maze) || goEast(maze) || goSouth(maze)) return true;
        maze.markVisited(x, y);
        cout << "Backtracking West to (" << x << ", " << y - 1 << ")" << endl;
        position = {x, y - 1};
    }
    return false;
}

bool Creature::goWest(Maze &maze) {
    int x = position.first, y = position.second - 1;
    if (maze.isClear(x, y)) {
        cout << "Going West to (" << x << ", " << y << ")" << endl;
        position = {x, y};
        maze.markPath(x, y);
        printPosition();
        maze.printMaze();
        cout << endl;
        if (maze.isExit(x, y)) return true;
        if (goNorth(maze) || goWest(maze) || goSouth(maze)) return true;
        maze.markVisited(x, y);
        cout << "Backtracking East to (" << x << ", " << y + 1 << ")" << endl;
        position = {x, y + 1};
    }
    return false;
}

void Creature::printPosition() {
    cout << "Creature at: (" << position.first << ", " << position.second << ")" << endl;
}
