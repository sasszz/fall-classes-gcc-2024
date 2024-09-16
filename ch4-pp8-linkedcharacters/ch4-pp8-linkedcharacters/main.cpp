//
//  main.cpp
//  ch4-pp8-linkedcharacters
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include <iostream>
#include "LinkedChar.h"

using namespace std;

void printStats(const string& label, const LinkedChar& str) {
    cout << "---------------------------------" << endl;
    cout << "Stats for " << label << ":" << endl;
    cout << "---------------------------------" << endl;
    cout << label << " is '";
    str.display();
    cout << "'" << endl;
    cout << "Length: " << str.getLength() << endl;
    cout << "First character: '" << str[0] << "'" << endl;

    cout << endl;
}

int main() {
    char A[3] = {'a', 'b', 'c'};
    LinkedChar stringOne(A, 3);

    char b[5] = {'d', 'e', 'f', 'g', 'h'};
    LinkedChar stringTwo(b, 5);

    printStats("String one", stringOne);
    printStats("String two", stringTwo);
    
    if (stringOne.isSubstring(stringTwo)) {
        cout << "String two IS a substring of string one" << endl;
    } else {
        cout << "String two is NOT a substring of string one" << endl;
    }
    cout << endl;

    cout << "Appending string two to string one..." << endl;
    stringOne.append(stringTwo);
    cout << endl;
    cout << "String one after appending is '";
    stringOne.display();
    cout << "'" << endl;
    cout << "Length of string one is now " << stringOne.getLength() << endl;
    cout << endl;

    if (stringOne.isSubstring(stringTwo)) {
        cout << "String two IS a substring of string one" << endl;
    } else {
        cout << "String two is NOT a substring of string one" << endl;
    }
    cout << endl;

    return 0;
}
