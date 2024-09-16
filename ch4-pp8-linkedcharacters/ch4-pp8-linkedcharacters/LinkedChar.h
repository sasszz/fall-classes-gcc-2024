//
//  LinkedChar.h
//  ch4-pp8-linkedcharacters
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#ifndef LINKEDCHAR_H
#define LINKEDCHAR_H

#include "List.h"

using namespace std;

class LinkedChar {
private:
    int length;
    List *list;

public:
    LinkedChar() : length(0), list(new List()) {}

    LinkedChar(char array[], int n) : length(0), list(new List()) {
        for (int i = 0; i < n; ++i) {
            list->insertRear(array[i]);
        }
        length = list->getLength();
    }

    int getLength() const {
        return length;
    }

    void append(const LinkedChar &rhs) {
        for (int i = 0; i < rhs.getLength(); ++i) {
            list->insertRear(rhs[i]);
        }
        length = list->getLength();
    }

    void display() const {
        Node *iter = list->getIterator();
        while (iter) {
            cout << iter->item;
            iter = iter->next;
        }
    }

    int indexOfLeftMostChar(char ch) const {
        Node *iter = list->getIterator();
        int idx = 0;
        while (iter) {
            if (iter->item == ch) {
                return idx;
            }
            ++idx;
            iter = iter->next;
        }
        return -1;
    }

    bool isSubstring(const LinkedChar &pattern) const {
        if (pattern.getLength() > getLength()) {
            return false;
        }

        Node *iterText = list->getIterator();
        while (iterText) {
            Node *start = iterText;
            Node *iterPattern = pattern.list->getIterator();
            bool matched = true;

            while (start && iterPattern) {
                if (start->item != iterPattern->item) {
                    matched = false;
                    break;
                }
                start = start->next;
                iterPattern = iterPattern->next;
            }

            if (iterPattern == nullptr && matched) {
                return true;
            }

            iterText = iterText->next;
        }

        return false;
    }

    char operator[](int index) const {
        return list->operator[](index);
    }
};

#endif
