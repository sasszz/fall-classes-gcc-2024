//
//  main.cpp
//  ch4-pp2-adtset-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include "Set.h"
#include <iostream>

using namespace std;

int main() {
    Set setA, setB, unionAB, intersectionAB;

    int numbersA[] = {5, 2, 3, 7, 9, 11, 15, 18, 21};
    int sizeA = sizeof(numbersA) / sizeof(numbersA[0]);

    // Insert elements into setA using a for loop
    for (int i = 0; i < sizeA; ++i) {
        setA.Insert(numbersA[i]);
    }

    cout << "Contents of setA: ";
    setA.Output();
    cout << endl;
    cout << endl;

    int numbersB[] = {1, 2, 4, 8, 10, 15, 18};
    int sizeB = sizeof(numbersB) / sizeof(numbersB[0]);

    // Insert elements into setB using a for loop
    for (int i = 0; i < sizeB; ++i) {
        setB.Insert(numbersB[i]);
    }

    cout << "Contents of setB: ";
    setB.Output();
    cout << endl;
    cout << endl;
    
    // Compute the union of setA and setB
    unionAB.Union(setA, setB);
    cout << "Contents of setA union setB: ";
    unionAB.Output();
    cout << endl;
    cout << endl;
    
    // Compute the intersection of setA and setB
    intersectionAB.Intersection(setA, setB);
    cout << "Contents of setA intersection setB: ";
    intersectionAB.Output();
    cout << endl;
    cout << endl;
    
    return 0;
}

