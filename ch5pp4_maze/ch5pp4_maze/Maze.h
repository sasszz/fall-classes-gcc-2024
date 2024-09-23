//
//  Maze.h
//  ch5pp4_maze
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char WALL = 'x';
const char CLEAR = ' ';
const char PATH = 'o';
const char VISITED = '.';

class Maze {
public:
    vector<vector<char>> grid;
    int width, height;
    pair<int, int> entrance;
    pair<int, int> exit;

    Maze(int w, int h, pair<int, int> ent, pair<int, int> ex, vector<string> layout);
    void printMaze();
    bool isClear(int x, int y);
    void markPath(int x, int y);
    void markVisited(int x, int y);
    bool isExit(int x, int y);
};

#endif
