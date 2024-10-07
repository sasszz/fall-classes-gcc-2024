//
//  main.cpp
//  ch17_pp9
//
//  Created by Lucie Chevreuil on 10/7/24.
//
// Implement a class of priority queues using a binary search tree to contain its items.
// Discuss the appropriateness and efficiency of this implementation.

#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;

int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);

    cout << "Min: " << pq.extractMin() << endl;
    cout << "Min: " << pq.extractMin() << endl;

    return 0;
}
