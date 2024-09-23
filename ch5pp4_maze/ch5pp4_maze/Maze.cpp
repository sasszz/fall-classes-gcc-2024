//
//  Maze.cpp
//  ch5pp4_maze
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#include "Maze.h"

Maze::Maze(int w, int h, pair<int, int> ent, pair<int, int> ex, vector<string> layout) {
    width = w;
    height = h;
    entrance = ent;
    exit = ex;
    for (const string &row : layout) {
        grid.push_back(vector<char>(row.begin(), row.end()));
    }
}

void Maze::printMaze() {
    cout << "   "; // Print initial padding for column headers

    // Print column headers
    for (int col = 0; col < width; ++col) {
        cout << col % 10 << " "; // Print column number (mod 10 to keep it single digit)
    }
    cout << endl;

    // Print the maze with row headers
    for (int row = 0; row < height; ++row) {
        cout << row % 10 << "  "; // Print row number (mod 10 to keep it single digit)
        for (int col = 0; col < width; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool Maze::isClear(int x, int y) {
    cout << x << "," << y << endl;
    return (x >= 0 && x < height && y >= 0 && y < width && grid[x][y] == CLEAR);
}

void Maze::markPath(int x, int y) {
    grid[x][y] = PATH;
}

void Maze::markVisited(int x, int y) {
    grid[x][y] = VISITED;
}

bool Maze::isExit(int x, int y) {
    return x == exit.first && y == exit.second;
}
