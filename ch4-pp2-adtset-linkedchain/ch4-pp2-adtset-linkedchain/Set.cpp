//
//  Set.cpp
//  ch4-pp2-adtset-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include "Set.h"

// Insert a value into the set if it doesn't already exist
// Only insert the value if it is not already in the set
// Call the linked list method to insert at front
void Set::Insert(int newValue) {
    if (Search(newValue) == -1) {
        InsertFront(newValue);
    }
}

// Perform the union of two sets and store the result in the current set
// Start with the first node in set 'a'
// Traverse set 'a' and insert all elements into the current set
// Now, traverse set 'b' and insert all elements into the current set
void Set::Union(Set& a, Set& b) {
    Node* tempNode = a.front;
    while (tempNode != NULL) {
        Insert(tempNode->data);
        tempNode = tempNode->next;
    }
    tempNode = b.front;
    while (tempNode != NULL) {
        Insert(tempNode->data);
        tempNode = tempNode->next;
    }
}

// Perform the intersection of two sets and store the result in the current set
// Pointer to traverse set 'a'
// Traverse set 'a'
// Pointer to traverse set 'b'
// For each element in set 'a', check if it's in set 'b'
// If an element is found in both sets, insert it into the current set
void Set::Intersection(Set& a, Set& b) {
    Node* tempA = a.front;
    while (tempA != NULL) {
        Node* tempB = b.front;
        while (tempB != NULL) {
            if (tempA->data == tempB->data) {
                Insert(tempA->data);
            }
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
}
