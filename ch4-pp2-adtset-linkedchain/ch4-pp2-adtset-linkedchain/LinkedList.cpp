//
//  LinkedList.cpp
//  ch4-pp2-adtset-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include "LinkedList.h"

using namespace std;

// Constructor: Initializes the linked list with no elements
// Both front and back are null (empty list)
LinkedList::LinkedList() {
    front = back = NULL;
}

// Destructor: Deallocate memory by removing all nodes from the list
// Continue removing front nodes until the list is empty
LinkedList::~LinkedList() {
    while (Length() > 0) {
        RemoveFront();
    }
}

// Inserts a new node at the front of the list
// Create a new node
// Set the data value for the new node
// If the list is empty, set both front and back to this new node
// New node points to null (no next node)
// Otherwise, insert the new node at the front
// New node points to current front
// New node becomes the front
void LinkedList::InsertFront(int newValue) {
    Node* newNode = new Node;
    newNode->data = newValue;
    if (front == NULL) {
        front = back = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->next = front;
        front = newNode;
    }
}

// Removes the front node from the list and returns its data
// Variable to store the data of the removed node
// Temporary pointer to hold the node to be deleted
// If the list is not empty, remove the front node
// Get the data of the front node
// Store the current front node in temp
// Move front to the next node
// Deallocate the memory of the old front node
// If the list is empty, return 0
// Return the data of the removed node
int LinkedList::RemoveFront() {
    int returnValue;
    Node* temp;
    if (front != NULL) {
        returnValue = front->data;
        temp = front;
        front = front->next;
        delete temp;
    }
    else {
        returnValue = 0;
    }
    return returnValue;
}

// Returns the number of nodes in the list
// Temporary pointer for traversing the list
// Counter to keep track of the number of nodes
// Traverse the list and count the nodes
// Return the total count of nodes
int LinkedList::Length() {
    Node* temp;
    int count = 0;
    for (temp = front; temp != NULL; temp = temp->next) {
        count++;
    }
    return count;
}

// Outputs the contents of the list to the console
// Temporary pointer for traversing the list
// Traverse the list and print the data of each node
// Print data with space
void LinkedList::Output() {
    Node* temp;
    for (temp = front; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
    }
}

// Searches the list for a specific value and returns its index
// Temporary pointer for traversing the list
// Counter to track the index of the current node
// Traverse the list
// If the current node's data matches the target value, return the index
// Move to the next node
// If the value is not found, return -1
int LinkedList::Search(int targetValue) {
    Node* temp;
    int count = 0;
    for (temp = front; temp != NULL; temp = temp->next) {
        if (temp->data == targetValue) {
            return count;
        }
        count++;
    }
    return -1;
}
