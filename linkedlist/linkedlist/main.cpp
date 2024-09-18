//
//  main.cpp
//  linkedlist
//
//  Created by Lucie Chevreuil on 9/17/24.
//

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    DoublyLinkedList<int> list;

    // Demonstrating isEmpty and insertFront
    cout << "Initial list (empty): ";
    list.print();
    list.printAscii();
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    cout << endl << "Inserting 10 at the front..." << endl;
    list.insertFront(10);
    cout << "List after insertFront(10): ";
    list.print();
    list.printAscii();

    // Demonstrating insertBack
    cout << endl << "Inserting 20 at the back..." << endl;
    list.insertBack(20);
    cout << "List after insertBack(20): ";
    list.print();
    list.printAscii();

    // Demonstrating insertFront again
    cout << endl << "Inserting 5 at the front..." << endl;
    list.insertFront(5);
    cout << "List after insertFront(5): ";
    list.print();
    list.printAscii();

    // Demonstrating insertBefore
    Node<int>* node = list.find(10);
    if (node) {
        cout << endl << "Inserting 7 before 10..." << endl;
        list.insertBefore(node, 7);
        cout << "List after insertBefore(7, 10): ";
        list.print();
        list.printAscii();
    }

    // Demonstrating insertAfter
    node = list.find(20);
    if (node) {
        cout << endl << "Inserting 25 after 20..." << endl;
        list.insertAfter(node, 25);
        cout << "List after insertAfter(25, 20): ";
        list.print();
        list.printAscii();
    }

    // Demonstrating find and remove
    cout << endl << "Removing 10 from the list..." << endl;
    list.remove(10);
    cout << "List after remove(10): ";
    list.print();
    list.printAscii();

    // Demonstrating getSize
    cout << endl << "Current size of the list: " << list.getSize() << endl;
    
    // Using the overloaded << operator to print the list
    cout << endl << "Overload the insertion operator (<<) to print all the items in the list... " << endl;
    cout << "List contents: " << list << endl;

    // Demonstrating operator+=
    cout << endl << "Using operator+= to add 30..." << endl;
    list += 30;
    cout << "List after operator+=(30): ";
    list.print();
    list.printAscii();
    
    // Demonstrating operator+= with chaining
    cout << "Chaining operator+= to add values 5, 10, and 15..." << endl;
    // Chaining the operator+=
    list += 5;
    list += 10;
    list += 15;
    cout << "List after chaining operator+=: ";
    list.print();
    list.printAscii();

    // Demonstrating copyList (copy constructor)
    cout << endl << "Copying the current list into a new list..." << endl;
    DoublyLinkedList<int> copiedList(list); // Using copy constructor
    cout << "Copied list: ";
    copiedList.print();
    copiedList.printAscii();

    // Modifying the original list to show that copied list remains unchanged
    cout << endl << "Inserting 50 at the back of the original list..." << endl;
    list.insertBack(50);
    cout << "Original list after insertBack(50): ";
    list.print();
    list.printAscii();

    cout << "Copied list remains unchanged: ";
    copiedList.print();
    copiedList.printAscii();

    // Demonstrating clear
    cout << endl << "Clearing the original list..." << endl;
    list.clear();
    cout << "Original list after clear(): ";
    list.print();
    list.printAscii();
    cout << "Is the original list empty now? " << (list.isEmpty() ? "Yes" : "No") << endl;
    
    // Verifying that the copied list is still intact after clearing the original
    cout << "Copied list after clearing the original: ";
    copiedList.print();
    copiedList.printAscii();
    
    cout << endl;

    return 0;
}
