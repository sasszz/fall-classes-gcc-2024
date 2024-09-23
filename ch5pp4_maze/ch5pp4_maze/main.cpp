//
//  main.cpp
//  ch5pp4_maze
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#include "Creature.h"
#include "Maze.h"

int main() {
//    int width = 7, height = 5;
//    pair<int, int> exit = {0, 4};       // Exit at top-right corner
//    pair<int, int> entrance = {5, 1};   // Entrance at bottom-left corner
//    vector<string> layout = {
//        "xxxx xx",
//        "x x   x",
//        "xx    x",
//        "x     x",
//        "x xxxxx"
//    };
    
    int width = 14, height = 10;
    pair<int, int> exit = {0, 12};      // Exit near the top-right corner
    pair<int, int> entrance = {9, 1};   // Entrance near the bottom-left corner
    vector<string> layout = {
        "xxxxxxxxxxxx xxx",  // Row 0 (Exit at (0,13))
        "x              x",  // Row 1
        "x xxxxxx x xxx x",  // Row 2
        "x x    x x   x x",  // Row 3
        "x xxx xx xxxxx x",  // Row 4
        "x   x        x x",  // Row 5
        "xxx xxxxxxxxxx x",  // Row 6
        "x           x  x",  // Row 7
        "x xxxxxxxxx xx x",  // Row 8
        "x            x x"   // Row 9 (Entrance at (9,1))
    };


    Maze maze(width, height, entrance, exit, layout);
    Creature creature(entrance);

    cout << "Initial Maze: " << endl;
    maze.printMaze(); // Print the maze at the beginning
    cout << endl;
    
    cout << "Starting the maze-solving process..." << endl;
    cout << "GOOD LUCK!!!" << endl;
    cout << endl;
        if (creature.goNorth(maze)) {
            cout << "Exit found!" << endl;
        } else {
            cout << "No path to exit." << endl;
        }

    cout << "Final Maze: " << endl;
    maze.printMaze(); // Print the maze at the end after solving

    return 0;
}
