//
//  BraceBalance.h
//  ch6_2pp_bracebalance
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#ifndef _BRACE_BALANCE
#define _BRACE_BALANCE

#include <string>
#include <iostream>
#include "OurStack.h"

using namespace std;

bool BraceBalance(const string& inputStr) {
    OurStack<char> braceStack;
    bool status = true;

    cout << "Processing string: " << inputStr << endl;

    for (char ch : inputStr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            cout << "Pushing: " << ch << endl;
            braceStack.push(ch);
            braceStack.printStack();
        } else if (ch == ')' || ch == '}' || ch == ']') {
            cout << "Processing closing brace: " << ch << endl;
            if (!braceStack.isEmpty()) {
                char top = braceStack.peek();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    cout << "Matching with: " << top << endl;
                    braceStack.pop();
                    braceStack.printStack();
                } else {
                    cout << "Mismatch detected. Expected matching brace for: " << top << endl;
                    status = false;
                    break;
                }
            } else {
                cout << "No opening brace to match with " << ch << endl;
                status = false;
                break;
            }
        }
    }

    if (!braceStack.isEmpty()) {
        cout << "Unmatched opening braces remain in the stack." << endl;
    }

    return status && braceStack.isEmpty();
}

#endif
