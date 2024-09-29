//
//  OurStack.h
//  ch6_2pp_bracebalance
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#ifndef _OUR_STACK
#define _OUR_STACK

#include <stack>
#include <iostream>
#include "StackInterface.h"

using namespace std;

template<typename ItemType>
class OurStack : public StackInterface<ItemType> {
private:
    stack<ItemType> ourStack;

public:
    bool isEmpty() const override {
        return ourStack.empty();
    }

    bool push(const ItemType& newEntry) override {
        ourStack.push(newEntry);
        return ourStack.top() == newEntry;
    }

    bool pop() override {
        if (!ourStack.empty()) {
            ourStack.pop();
            return true;
        }
        return false;
    }

    ItemType peek() const override {
        return ourStack.top();
    }

    // Print the current stack for visualization
    void printStack() const override {
        stack<ItemType> tempStack = ourStack;
        cout << "Stack: [ ";
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << "]" << endl;
    }
};

#endif
