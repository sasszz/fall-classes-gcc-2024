//
//  Stack.h
//  ch7_pp10_stackpalindrone
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip> // for std::setw()

using namespace std;

template <class T>
class Stack {
private:
    int maxSize;
    int topIndex;
    T* stackArray;

public:
    Stack(int size);
    ~Stack();
    
    bool push(const T& value);
    bool pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
};

template <class T>
Stack<T>::Stack(int size) {
    maxSize = size;
    stackArray = new T[maxSize];
    topIndex = maxSize; // Start from the end
}

template <class T>
Stack<T>::~Stack() {
    delete[] stackArray;
}

template <class T>
bool Stack<T>::push(const T& value) {
    if (isFull()) {
        cout << "Stack is full. Cannot push.\n";
        return false;
    }
    topIndex--;
    stackArray[topIndex] = value;
    return true;
}

template <class T>
bool Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop.\n";
        return false;
    }
    topIndex++;
    return true;
}

template <class T>
T Stack<T>::top() const {
    if (!isEmpty()) {
        return stackArray[topIndex];
    }
    throw out_of_range("Stack is empty.");
}

template <class T>
bool Stack<T>::isEmpty() const {
    return topIndex == maxSize;
}

template <class T>
bool Stack<T>::isFull() const {
    return topIndex == 0;
}

#endif
