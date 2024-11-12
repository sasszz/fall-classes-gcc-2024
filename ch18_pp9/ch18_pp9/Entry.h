//
//  Entry.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * A class of entry objects for an array-based implementation of the ADT dictionary.
 * @file Entry.h
 */

#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry {
private:
    KeyType searchKey; // The key for the entry
    ItemType item;     // The value associated with the key

public:
    // Default constructor
    Entry() : searchKey(KeyType()), item(ItemType()) {}

    // Constructor with key and value
    Entry(const KeyType& key, const ItemType& value) : searchKey(key), item(value) {}

    // Getters
    KeyType getKey() const { return searchKey; }
    ItemType getItem() const { return item; }

    // Setters
    void setKey(const KeyType& key) { searchKey = key; }
    void setItem(const ItemType& value) { item = value; }

    // Comparison operators for use in BinarySearchTree
    bool operator==(const Entry<KeyType, ItemType>& other) const {
        return searchKey == other.searchKey;
    }

    bool operator<(const Entry<KeyType, ItemType>& other) const {
        return searchKey < other.searchKey;
    }

    bool operator>(const Entry<KeyType, ItemType>& other) const {
        return searchKey > other.searchKey;
    }
};

#endif // _ENTRY
