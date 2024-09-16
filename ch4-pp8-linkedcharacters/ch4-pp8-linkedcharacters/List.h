//
//  List.h
//  ch4-pp8-linkedcharacters
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#ifndef LIST_H
#define LIST_H

#include "Node.h"

using namespace std;

class List {
private:
    Node *first;
    Node *last;
    int length;

public:
    List() : first(nullptr), last(nullptr), length(0) {}

    Node *getIterator() {
        return first;
    }

    void insertFront(char ch) {
        Node *newNode = new Node(ch, first);
        first = newNode;
        if (last == nullptr) {
            last = first;
        }
        ++length;
    }

    void insertRear(char ch) {
        Node *newNode = new Node(ch);
        if (first == nullptr) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        ++length;
    }

    int getLength() const {
        return length;
    }

    char operator[](int index) const {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        Node *iter = first;
        for (int i = 0; i < index; ++i) {
            iter = iter->next;
        }
        return iter->item;
    }
};

#endif
