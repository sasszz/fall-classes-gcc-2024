//
//  DoublyLinkedList.cpp
//  linkedlist
//
//  Created by Lucie Chevreuil on 9/17/24.
//

#include "DoublyLinkedList.h"
using namespace std;

// Constructor: Initializes an empty list
// Initializes head and tail to nullptr, and size to 0
template <typename DataType>
DoublyLinkedList<DataType>::DoublyLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor: Copies another list
// Calls copyList function to copy all elements from the other list
template <typename DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(const DoublyLinkedList<DataType>& other) {
    copyList(other);
}

// Destructor: Clears the list and deletes memory
// Calls clear function to remove all nodes and free memory
template <typename DataType>
DoublyLinkedList<DataType>::~DoublyLinkedList() {
    clear();
}

// Assignment operator: Assigns another list to this one
// Checks for self-assignment, clears the current list, and copies from the other list
template <typename DataType>
DoublyLinkedList<DataType>& DoublyLinkedList<DataType>::operator=(const DoublyLinkedList<DataType>& other) {
    if (this != &other) {
        clear();
        copyList(other);
    }
    return *this;
}

// Insert front: Adds a value at the front
// Creates a new node with the given value
// If the list is empty, set both head and tail to the new node
// Otherwise, update pointers and set newNode as the new head
template <typename DataType>
void DoublyLinkedList<DataType>::insertFront(DataType value) {
    Node<DataType>* newNode = new Node<DataType>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    ++size;
}

// Insert back: Adds a value at the end
// Creates a new node with the given value
// If the list is empty, set both head and tail to the new node
// Otherwise, update pointers and set newNode as the new tail
template <typename DataType>
void DoublyLinkedList<DataType>::insertBack(DataType value) {
    Node<DataType>* newNode = new Node<DataType>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size;
}

// Insert before: Inserts a value before a specific node
// If the node is null, the function does nothing
// Creates a new node with the given value and updates the pointers of surrounding nodes
template <typename DataType>
void DoublyLinkedList<DataType>::insertBefore(Node<DataType>* node, DataType value) {
    if (!node) return;
    Node<DataType>* newNode = new Node<DataType>(value);
    newNode->next = node;
    newNode->prev = node->prev;
    if (node->prev) {
        node->prev->next = newNode;
    } else {
        head = newNode;
    }
    node->prev = newNode;
    ++size;
}

// Insert after: Inserts a value after a specific node
// If the node is null, the function does nothing
// Creates a new node with the given value and updates the pointers of surrounding nodes
template <typename DataType>
void DoublyLinkedList<DataType>::insertAfter(Node<DataType>* node, DataType value) {
    if (!node) return;
    Node<DataType>* newNode = new Node<DataType>(value);
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next) {
        node->next->prev = newNode;
    } else {
        tail = newNode;
    }
    node->next = newNode;
    ++size;
}

// Find: Returns the node containing the given value
// Starts from the head and traverses the list to find the node
// Returns nullptr if the value is not found
template <typename DataType>
Node<DataType>* DoublyLinkedList<DataType>::find(DataType value) {
    Node<DataType>* current = head;
    while (current) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Remove: Deletes the node containing the given value
// Finds the node with the specified value
// Updates the pointers of surrounding nodes and deletes the node
template <typename DataType>
void DoublyLinkedList<DataType>::remove(DataType value) {
    Node<DataType>* nodeToDelete = find(value);
    if (!nodeToDelete) return;

    if (nodeToDelete->prev) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        head = nodeToDelete->next;
    }

    if (nodeToDelete->next) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    } else {
        tail = nodeToDelete->prev;
    }

    delete nodeToDelete;
    --size;
}

// isEmpty: Checks if the list is empty
// Returns true if size is 0, otherwise false
template <typename DataType>
bool DoublyLinkedList<DataType>::isEmpty() const {
    return size == 0;
}

// getSize: Returns the size of the list
// Returns the current number of elements in the list
template <typename DataType>
int DoublyLinkedList<DataType>::getSize() const {
    return size;
}

// clear: Removes all nodes from the list
// Traverses the list, deletes each node, and resets head, tail, and size
template <typename DataType>
void DoublyLinkedList<DataType>::clear() {
    Node<DataType>* current = head;
    while (current) {
        Node<DataType>* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// print: Prints all node values in the list
// Traverses the list from head to tail and prints each value
template <typename DataType>
void DoublyLinkedList<DataType>::print() const {
    Node<DataType>* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename DataType>
void DoublyLinkedList<DataType>::printAscii() const {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node<DataType>* current = head;
    
    // Traverse the list and print each node with ASCII representation
    while (current) {
        // Print the previous pointer
        if (current->prev) {
            cout << "< ";
        } else {
            cout << "HEAD ";  // For the first node
        }

        // Print the current node value
        cout << "[" << current->value << "]";

        // Print the next pointer
        if (current->next) {
            cout << " >";
        }

        current = current->next;
    }
    cout << endl;
}


// copyList: Copies all nodes from another list
// Traverses the other list and inserts each value into this list
template <typename DataType>
void DoublyLinkedList<DataType>::copyList(const DoublyLinkedList<DataType>& other) {
    head = tail = nullptr;
    size = 0;
    Node<DataType>* current = other.head;
    while (current) {
        insertBack(current->value);
        current = current->next;
    }
}

// operator+=: Adds a value to the end of the list
// Inserts the value at the back and returns the current list
template <typename DataType>
DoublyLinkedList<DataType>& DoublyLinkedList<DataType>::operator+=(DataType value) {
    insertBack(value);
    return *this;
}

// Explicit template instantiation for int
template class DoublyLinkedList<int>;
