//
//  main.cpp
//  ch16_pp4
//
//  Created by Lucie Chevreuil on 10/7/24.
//
// Write an array-based implementation of the ADT binary tree that uses dynamic memory allocation.
// Use a data structure like the one in Figure 16-1.
// Repeat the previous problem, but define a binary search tree instead.

#include <iostream>
#include <vector>

using namespace std;

class BinarySearchTree {
private:
    vector<int> tree;  // Using a vector to dynamically allocate memory
    int capacity;  // Max number of nodes
    
    int getLeftChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 1;
    }

    int getRightChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 2;
    }

public:
    BinarySearchTree(int size) : capacity(size) {
        tree.resize(size, -1); // Initialize with -1 to represent empty slots
    }

    void insert(int value) {
        if (tree[0] == -1) {
            tree[0] = value; // Root insertion
        } else {
            int currentIndex = 0;
            while (currentIndex < capacity) {
                if (value < tree[currentIndex]) {
                    int leftIndex = getLeftChildIndex(currentIndex);
                    if (leftIndex >= capacity) {
                        cout << "Tree is full." << endl;
                        return;
                    }
                    if (tree[leftIndex] == -1) {
                        tree[leftIndex] = value;
                        return;
                    } else {
                        currentIndex = leftIndex;
                    }
                } else {
                    int rightIndex = getRightChildIndex(currentIndex);
                    if (rightIndex >= capacity) {
                        cout << "Tree is full." << endl;
                        return;
                    }
                    if (tree[rightIndex] == -1) {
                        tree[rightIndex] = value;
                        return;
                    } else {
                        currentIndex = rightIndex;
                    }
                }
            }
        }
    }

    bool search(int value) {
        int currentIndex = 0;
        while (currentIndex < capacity && tree[currentIndex] != -1) {
            if (tree[currentIndex] == value) {
                return true;
            }
            if (value < tree[currentIndex]) {
                currentIndex = getLeftChildIndex(currentIndex);
            } else {
                currentIndex = getRightChildIndex(currentIndex);
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (tree[i] != -1) {
                cout << tree[i] << " ";
            } else {
                cout << "_ ";  // Underscore for empty slots
            }
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst(15); // Tree with capacity for 15 nodes
    
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(7);
    bst.insert(12);
    bst.insert(20);

    bst.display();  // Display the tree

    cout << "Search for 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search for 21: " << (bst.search(21) ? "Found" : "Not Found") << endl;

    return 0;
}
