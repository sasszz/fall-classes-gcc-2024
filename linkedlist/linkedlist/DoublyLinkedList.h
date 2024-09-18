//
//  DoublyLinkedList.hpp
//  linkedlist
//
//  Created by Lucie Chevreuil on 9/17/24.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template <typename DataType>
class DoublyLinkedList {
private:
    Node<DataType>* head;
    Node<DataType>* tail;
    int size;
    void copyList(const DoublyLinkedList<DataType>& other);

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<DataType>& other);
    ~DoublyLinkedList();

    DoublyLinkedList<DataType>& operator=(const DoublyLinkedList<DataType>& other);
    
    // Friend function to overload the insertion operator <<
    friend ostream& operator<<(ostream& os, const DoublyLinkedList<DataType>& list) {
        Node<DataType>* current = list.head;
        while (current) {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }

    void insertFront(DataType value);
    void insertBack(DataType value);
    void insertBefore(Node<DataType>* node, DataType value);
    void insertAfter(Node<DataType>* node, DataType value);

    Node<DataType>* find(DataType value);
    void remove(DataType value);
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void print() const;
    void printAscii() const;
    DoublyLinkedList<DataType>& operator+=(DataType value);
};

#endif // DOUBLYLINKEDLIST_H
