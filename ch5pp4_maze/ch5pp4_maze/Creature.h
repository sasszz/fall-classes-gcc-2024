//
//  Creature.h
//  ch5pp4_maze
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#ifndef CREATURE_H
#define CREATURE_H

#include "Maze.h"

class Creature {
public:
    pair<int, int> position;

    Creature(pair<int, int> start);
    bool goNorth(Maze &maze);
    bool goSouth(Maze &maze);
    bool goEast(Maze &maze);
    bool goWest(Maze &maze);
    void printPosition();
};

#endif
