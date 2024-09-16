//
//  Set.hpp
//  ch4-pp2-adtset-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#ifndef SET_H
#define SET_H

#include "LinkedList.h"

// Set class that inherits from LinkedList and provides set operations
class Set : public LinkedList {
public:
    void Insert(int newValue);               // Insert a new value into the set
    void Union(Set& a, Set& b);               // Compute the union of two sets
    void Intersection(Set& a, Set& b);        // Compute the intersection of two sets
};

#endif
