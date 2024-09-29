//
//  main.cpp
//  ch7_pp10_stackpalindrone
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#include <iostream>
#include <cctype>   // For isalnum and tolower
#include "Stack.h"

using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int len = str.length();
    Stack<char> stack(len);

    // Push the first half of the string onto the stack
    for (int i = 0; i < len / 2; ++i) {
        if (isalnum(str[i])) { // Only push alphanumeric characters
            stack.push(tolower(str[i]));
        }
    }

    // Handle odd length strings by skipping the middle character
    int startIndex = (len % 2 == 0) ? len / 2 : len / 2 + 1;

    // Compare second half with the stack
    for (int i = startIndex; i < len; ++i) {
        if (isalnum(str[i])) { // Only compare alphanumeric characters
            if (stack.isEmpty() || stack.top() != tolower(str[i])) {
                return false;
            }
            stack.pop();
        }
    }

    return true;
}

int main() {
    string testStr1 = "radar";
    string testStr2 = "hello";

    cout << "\"" << testStr1 << "\" is ";
    if (!isPalindrome(testStr1)) cout << "not ";
    cout << "a palindrome." << endl;

    cout << "\"" << testStr2 << "\" is ";
    if (!isPalindrome(testStr2)) cout << "not ";
    cout << "a palindrome." << endl;

    return 0;
}
