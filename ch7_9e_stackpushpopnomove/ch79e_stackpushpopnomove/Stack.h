//
//  Stack.h
//  ch79e_stackpushpopnomove
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#ifndef STACK_H
#define STACK_H

using namespace std;

#include <iostream>
#include <iomanip> // for std::setw()

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
    void displayStack() const;
    void displayVisual() const;
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
        cout << "Stack is full. Cannot push." << endl;
        return false;
    }
    topIndex--;
    stackArray[topIndex] = value;
    displayVisual(); // Visualize stack after push
    return true;
}

template <class T>
bool Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop." << endl;
        return false;
    }
    topIndex++;
    displayVisual(); // Visualize stack after pop
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

template <class T>
void Stack<T>::displayStack() const {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack from top to bottom: ";
    for (int i = topIndex; i < maxSize; i++) {
        cout << stackArray[i] << " ";
    }
    cout << endl;
}

template <class T>
void Stack<T>::displayVisual() const {
    cout << "Index:  ";
    for (int i = 0; i < maxSize; i++) {
        cout << setw(3) << i;
    }
    cout << "\nArray:  ";
    for (int i = 0; i < maxSize; i++) {
        if (i >= topIndex)
            cout << setw(3) << stackArray[i];
        else
            cout << setw(3) << " ";
    }
    cout << "\ntopIndex: " << topIndex << "\n\n";
}

#endif
