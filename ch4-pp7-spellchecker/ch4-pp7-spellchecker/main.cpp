//
//  main.cpp
//  ch4-pp7-spellchecker
//
//  Created by Lucie Chevreuil on 9/15/24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Set.h"

using namespace std;

void checkSpelling(Set<string>& dictionary, const string& filename) {
    ifstream inputFileStream(filename);
    string temp;
    vector<string> correctlySpelled;
    vector<string> misspelled;

    if (inputFileStream.is_open()) {
        while (inputFileStream >> temp) {
            if (dictionary.containsItem(temp)) {
                // push_back adds an element to the end of the vector
                correctlySpelled.push_back(temp);
            } else {
                misspelled.push_back(temp);
            }
        }
        inputFileStream.close();
    } else {
        cout << "Failed to open the file." << endl;
        return;
    }

    // Print header
    cout << left << setw(30) << "Correctly Spelled" << setw(30) << "Misspelled" << endl;
    cout << string(60, '-') << endl;

    // Print words in columns
    size_t maxSize = max(correctlySpelled.size(), misspelled.size());
    for (size_t i = 0; i < maxSize; ++i) {
        string correctWord = (i < correctlySpelled.size()) ? correctlySpelled[i] : "";
        string misspelledWord = (i < misspelled.size()) ? misspelled[i] : "";

        cout << left << setw(30) << correctWord << setw(30) << misspelledWord << endl;
    }
}


int main() {
    Set<string> dictionary;
    
    string filename;
    string items[35] = {
        "apple", "banana", "cherry", "date",  "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "pear", "raspberry", "strawberry", "tomato",
        "watermelon", "avocado", "blueberry", "cantaloupe", "dragonfruit", "eggplant", "garlic", "honeydew", "jalapeno",
        "kale", "leek", "mushroom", "cabbage", "onion", "potato", "radish", "spinach", "turnip", "zucchini"
    };

    for (int kk = 0; kk < 35; kk++) {
        dictionary.addItems(items[kk]);
    }

    cout << "Enter a filename to check spelling: ";
    cin >> filename;

    checkSpelling(dictionary, filename);
    cout << endl;
    
    return 0;
}
