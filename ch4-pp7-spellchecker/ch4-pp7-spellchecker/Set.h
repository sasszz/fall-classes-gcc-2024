//
//  Set.hpp
//  ch4-pp7-spellchecker
//
//  Created by Lucie Chevreuil on 9/15/24.
//

/** @file Set.h */

#ifndef _SET
#define _SET

template <typename ItemType>
class Set {
private:
    static const int defaultSetCapacity = 100;
    ItemType setItems[defaultSetCapacity];
    int setCount;
    int setCapacity;

public:
    Set();
    int getSetCurrentSize() const;
    void addItems(const ItemType& newItem);
    void deleteItems(const ItemType& anItem);
    bool containsItem(const ItemType& anItem);
    void emptySet();
    bool isSetEmpty() const;
    ItemType getItemsAtIndex(int id);
};

#include "Set.cpp"
#endif
