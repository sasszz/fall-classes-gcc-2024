//
//  main.cpp
//  ch17_pp1
//
//  Created by Lucie Chevreuil on 10/7/24.
//
// Complete the implementation file for the class ArrayMaxHeap that is described in Section 17.2.2.

#include <iostream>
#include "ArrayMaxHeap.h"

using namespace std;

int main() {
    // Create an instance of ArrayMaxHeap with a capacity of 10
    ArrayMaxHeap<int> maxHeap;

    // Add elements to the heap
    cout << "Adding elements to the heap..." << endl;
    maxHeap.add(45);
    maxHeap.add(20);
    maxHeap.add(35);
    maxHeap.add(10);
    maxHeap.add(50);

    // Peek the top element
    try {
        cout << "Top element of the heap: " << maxHeap.peekTop() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Remove the top element
    cout << "Removing the top element..." << endl;
    maxHeap.remove();
    
    // Peek the top element after removal
    try {
        cout << "Top element after removal: " << maxHeap.peekTop() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Add more elements
    maxHeap.add(60);
    maxHeap.add(55);

    // Peek the top element again
    try {
        cout << "Top element after adding more elements: " << maxHeap.peekTop() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Test if heap is empty
    cout << "Is heap empty? " << (maxHeap.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
