//
//  main.cpp
//  ch16_pp2
//
//  Implement the class BinarySearchTree, as given in Listing 16-4.
//
//  Created by Lucie Chevreuil on 10/7/24.
//

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

// Function for testing traversal
void print(int& data) {
    cout << data << " ";
}

int main() {
    // Create a Binary Search Tree of integers
    // error: Variable type 'BinarySearchTree<int>' is an abstract class
    BinarySearchTree<int> bst;

    // Test if the tree is empty
    cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;

    // Add some values to the tree
    cout << "Adding values 50, 30, 70, 20, 40, 60, 80 to the tree." << endl;
    bst.add(50);
    bst.add(30);
    bst.add(70);
    bst.add(20);
    bst.add(40);
    bst.add(60);
    bst.add(80);

    // Test if the tree is still empty
    cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;

    // Print the tree height
    cout << "Tree height: " << bst.getHeight() << endl;

    // Print the number of nodes
    cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;

    // Test traversal methods
    cout << "Preorder traversal: ";
    bst.preorderTraverse(print);
    cout << endl;

    cout << "Inorder traversal: ";
    bst.inorderTraverse(print);
    cout << endl;

    cout << "Postorder traversal: ";
    bst.postorderTraverse(print);
    cout << endl;

    // Test if the tree contains certain values
    int searchValue = 40;
    cout << "Does the tree contain " << searchValue << "? "
         << (bst.contains(searchValue) ? "Yes" : "No") << endl;

    searchValue = 90;
    cout << "Does the tree contain " << searchValue << "? "
         << (bst.contains(searchValue) ? "Yes" : "No") << endl;

    // Test removal of a node
    cout << "Removing value 30." << endl;
    bst.remove(30);

    // Inorder traversal after removal
    cout << "Inorder traversal after removing 30: ";
    bst.inorderTraverse(print);
    cout << endl;

    // Test clearing the tree
    cout << "Clearing the tree." << endl;
    bst.clear();
    cout << "Is the tree empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
