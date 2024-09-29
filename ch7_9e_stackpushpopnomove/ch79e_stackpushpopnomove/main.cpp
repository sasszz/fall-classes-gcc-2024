//
//  main.cpp
//  ch79e_stackpushpopnomove
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> stack(5);  // Create a stack of size 5
    
    // Test pushing values into the stack
    cout << "Pushing 10, 20, 30 into the stack:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    // Test popping a value from the stack
    cout << "Popping top value:\n";
    stack.pop();
    
    // Test pushing another value into the stack
    cout << "Pushing 40 into the stack:\n";
    stack.push(40);
    
    // Test emptying the stack
    cout << "Popping all values:\n";
    stack.pop();
    stack.pop();
    stack.pop();
    
    return 0;
}
