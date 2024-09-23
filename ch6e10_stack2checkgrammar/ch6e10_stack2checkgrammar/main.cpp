//
//  main.cpp
//  ch6e10_stack2checkgrammar
//
//  Created by Lucie Chevreuil on 9/22/24.
//

// Write a function that uses a stack to determine whether a string is in the language L, where
// L = {s s : s is a string of characters, s= reverse (s) }
// Note: The following strings are not in the language: The empty string, a string with fewer than two characters, and a string with an odd number of characters.

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isInLanguageL(const string& inputString) {
    // Get the length of the input string
    size_t stringLength = inputString.length();
    
    // The string must have an even number of characters and be at least two characters long
    if (stringLength < 2 || stringLength % 2 != 0) {
        return false;
    }

    stack<char> characterStack;
    size_t halfLength = stringLength / 2;

    // Push the first half of the string onto the stack
    for (size_t i = 0; i < halfLength; ++i) {
        characterStack.push(inputString[i]);
    }

    // Compare the second half of the string with the characters popped from the stack
    for (size_t i = halfLength; i < stringLength; ++i) {
        if (characterStack.top() != inputString[i]) {
            return false; // If any mismatch occurs, the string is not in the language
        }
        characterStack.pop();
    }

    return true;
}

int main() {
    // Test cases: strings that are in the language and those that are not
    vector<string> testStrings = {
        "abba",   // In the language L
        "abcba",  // Not in the language (odd number of characters)
        "abcdba", // Not in the language (does not match reverse)
        "abccba", // In the language L
        "",       // Not in the language (empty string)
        "a",      // Not in the language (fewer than two characters)
        "xyzzyx", // In the language L
        "abcdef"  // Not in the language (no reverse match)
    };

    // Test each string and display the result
    for (const string& testString : testStrings) {
        cout << "Testing string \"" << testString << "\": ";
        if (isInLanguageL(testString)) {
            cout << "In the language L.";
            cout << endl;
        } else {
            cout << "NOT in the language L.";
            cout << endl;
        }
    }

    return 0;
}
