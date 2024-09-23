//
//  main.cpp
//  ch5e14_recursivegrammar
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#include <iostream>
#include <string>

using namespace std;

// first_index represents the position of the current character we're checking from the beginning of the string.
// last_index represents the position of the current character we're checking from the end of the string.

bool isBelongs(string userString, string::size_type first_index, string::size_type last_index) {
    // If first_index becomes greater than last_index, return false
    // This means it is unbalanced, one side is longer than the other
    if (first_index > last_index)
        return false;

    // If there is only a single character and it is '$', return true
    else if (first_index == last_index && userString[first_index] == '$')
        return true;

    // If first and last characters are the same, continue checking string
    else if (userString[first_index] == userString[last_index])
        return isBelongs(userString, first_index + 1, last_index - 1);

    // Otherwise, the string does not belong to the language
    return false;
}

int main() {
    string userString;
    int choice = 1;

    while (choice == 1) {
        cout << "Enter the string: ";
        getline(cin, userString);

        string::size_type length = userString.size();

        if (isBelongs(userString, 0, length - 1))
            cout << "The string belongs to the language" << endl;
        else
            cout << "The string does not belong to the language" << endl;

        cout << "Do you want to continue? (1 for Yes / 0 for No): ";
        cin >> choice;
        cin.ignore(); // Ignore newline left in input buffer
    }

    return 0;
}
