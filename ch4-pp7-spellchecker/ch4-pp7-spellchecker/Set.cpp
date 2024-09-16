//
//  Set.cpp
//  ch4-pp7-spellchecker
//
//  Created by Lucie Chevreuil on 9/15/24.
//

/** @file Set.cpp */

#include "Set.h"
#include <iostream>

#ifndef SET_CPP
#define SET_CPP

using namespace std;

template <typename ItemType>
Set<ItemType>::Set() : setCount(0), setCapacity(defaultSetCapacity) {}

template <typename ItemType>
int Set<ItemType>::getSetCurrentSize() const {
    return setCount;
}

template <typename ItemType>
void Set<ItemType>::addItems(const ItemType& newItem) {
    if (!containsItem(newItem)) {
        if (setCount < setCapacity) {
            setItems[setCount] = newItem;
            setCount++;
        } else {
            cout << "Sorry! No Space." << endl;
        }
    }
}

template <typename ItemType>
void Set<ItemType>::deleteItems(const ItemType& anItem) {
    if (containsItem(anItem)) {
        for (int kk = 0; kk < setCount; kk++) {
            if (setItems[kk] == anItem) {
                setItems[kk] = setItems[setCount - 1];
                setCount--;
                break;
            }
        }
    } else {
        cout << "Item not found." << endl;
    }
}

template <typename ItemType>
bool Set<ItemType>::containsItem(const ItemType& anItem) {
    for (int kk = 0; kk < setCount; kk++) {
        if (setItems[kk] == anItem) {
            return true;
        }
    }
    return false;
}

template <typename ItemType>
void Set<ItemType>::emptySet() {
    setCount = 0;
}

template <typename ItemType>
bool Set<ItemType>::isSetEmpty() const {
    return setCount == 0;
}

template <typename ItemType>
ItemType Set<ItemType>::getItemsAtIndex(int id) {
    if (id >= 0 && id < setCount) {
        return setItems[id];
    }
    return ItemType(); // Return default ItemType
}

#endif
