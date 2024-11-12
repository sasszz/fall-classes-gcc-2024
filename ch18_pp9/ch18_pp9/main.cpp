//
//  main.cpp
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//


// Repeat Programming Problem 7, but use the class HashedDictionary, as described in Section 18.4.6, which uses separate chaining to resolve collisions. Use the hash function h(x) = x mod tableSize and the algorithm that involves Horner’s rule, as described in Section 18.4.1 about hash functions, to convert a variable into an integer x.
// Because you add an item to the dictionary only if its search key is not already present, does the time required for an insertion increase?

// Programming Problem 7: Implement the symbol table described in Exercise 5 by reusing the class TreeDictionary, as described in Section 18.2.2 of this chapter.

// Exercise 5: A C++ compiler uses a symbol table to keep track of the identifiers that a program uses. When the compiler encounters an identifier, it searches the symbol table to see whether that identifier has already been encoun- tered. If the identifier is new, it is inserted into the table. Thus, the symbol table needs only insertion and retrieval operations. Which implementation of the ADT dictionary would be most efficient as a symbol table?

#include <iostream>
#include "SymbolTable.h"

using namespace std;

int main() {
    SymbolTable symTable;

    // Inserting identifiers
    symTable.insert("x", 10);
    symTable.insert("y", 20);
    symTable.insert("z", 30);

    // Checking existence
    if (symTable.contains("x")) {
        cout << "x is in the symbol table with value: " << symTable.retrieve("x") << endl;
    }

    // Retrieving an identifier
    try {
        cout << "Value for y: " << symTable.retrieve("y") << endl;
    } catch (const NotFoundException& e) {
        cerr << e.what() << endl;
    }

    // Handling an identifier not found
    try {
        cout << "Value for a: " << symTable.retrieve("a") << endl;
    } catch (const NotFoundException& e) {
        cerr << e.what() << endl;
    }
    
    // Define a list of identifiers to retrieve
    vector<std::string> identifiers = {"x", "y", "a", "z"};

    // Print the identifiers and their values
    cout << "\nSymbol Table:\n";
    symTable.printIdentifiers(identifiers);
    cout << endl;

    return 0;
}
