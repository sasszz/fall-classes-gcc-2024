//
//  LinkedList.hpp
//  ch4-pp2-adtset-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Node structure to represent each element in the linked list
struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node in the list
};

// LinkedList class that provides the basic linked list operations
class LinkedList {
public:
    Node* front;   // Pointer to the first node in the list
    Node* back;    // Pointer to the last node in the list
    LinkedList();   // Constructor
    ~LinkedList();  // Destructor
    void InsertFront(int newValue);  // Insert a new node at the front of the list
    int RemoveFront();                 // Remove the front node
    int Length();                      // Return the number of nodes in the list
    void Output();                     // Display the contents of the list
    int Search(int targetValue);         // Search for a value in the list
};

#endif
