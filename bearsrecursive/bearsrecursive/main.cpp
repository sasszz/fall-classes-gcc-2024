//
//  main.cpp
//  bearsrecursive
//
//  Created by Lucie Chevreuil on 9/7/24.
//

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

const int MAX_RECURSION_DEPTH = 100;
const int MAX_NUMBERS = 1000;

// Recursive function to check if we can reach exactly 42 bears
bool canReach42(int n, unordered_set<int>& visited, int depth) {
    // TESTING
    cout << "DEPTH: " << depth << ", NUM:" << n << endl;
    
    if (n == 42) return true;
    if (n < 42 || visited.find(n) != visited.end() || depth > MAX_RECURSION_DEPTH) return false;  // Avoid revisiting states and exceeding depth

    visited.insert(n);  // Mark this number as visited

    // If n is even, we can give back exactly n/2 bears.
    if (n % 2 == 0) {
        if (canReach42(n / 2, visited, depth + 1)) return true;
    }

    // If n is divisible by 3 or 4, we can give back the product of the last two digits.
    if (n % 3 == 0 || n % 4 == 0) {
        int lastDigit = n % 10;
        int nextToLastDigit = (n % 100) / 10;
        int product = lastDigit * nextToLastDigit;
        if (n - product >= 42 && canReach42(n - product, visited, depth + 1)) return true;
    }

    // If n is divisible by 5, we can give back exactly 42 bears.
    if (n % 5 == 0) {
        if (n - 42 >= 42 && canReach42(n - 42, visited, depth + 1)) return true;
    }

    return false;
}

void checkNumber() {
    int number;
    cout << "Enter the number of bears: ";
    cin >> number;

    unordered_set<int> visited;  // Create a new set for each check
    if (canReach42(number, visited, 0)) {
        cout << "Starting with " << number << " bears, you CAN reach 42 bears.\n";
    } else {
        cout << "Starting with " << number << " bears, you canNOT reach 42 bears.\n";
    }
    cout << endl;
}

void generateNumbers() {
    int start, end;
    cout << "Enter the range (start end): ";
    cin >> start >> end;

    int reachableNumbers[MAX_NUMBERS];  // Array to store numbers that can reach 42
    int count = 0;  // Number of valid numbers found

    for (int i = start; i <= end; ++i) {
        if (count >= MAX_NUMBERS) break;  // Prevent overflow of the array

        unordered_set<int> visited;  // Create a new set for each number
        if (canReach42(i, visited, 0)) {
            reachableNumbers[count++] = i;  // Add number to the array
        }
    }

    // Print the list of numbers in a single line separated by commas
    if (count > 0) {
        cout << "Numbers that can reach 42 bears:\n";
        for (int i = 0; i < count; ++i) {
            cout << reachableNumbers[i];
            if (i < count - 1) cout << ", ";  // Add a comma between numbers
        }
        cout << endl;
    } else {
        cout << "No numbers in the range can reach 42 bears.\n";
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Check if a number reaches 42\n";
        cout << "2. Generate numbers that reach 42\n";
        cout << "3. Quit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                checkNumber();
                break;
            case 2:
                generateNumbers();
                break;
            case 3:
                cout << "Quitting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
