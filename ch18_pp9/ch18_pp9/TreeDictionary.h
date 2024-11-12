#ifndef _TREE_DICTIONARY
#define _TREE_DICTIONARY

#include "DictionaryInterface.h"
#include "BinarySearchTree.h"
#include "Entry.h"
#include "NotFoundException.h"

template <class KeyType, class ItemType>
class TreeDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    BinarySearchTree<Entry<KeyType, ItemType>> itemTree;

public:
    // Constructor and Destructor
    TreeDictionary() {}
    virtual ~TreeDictionary() {}

    // Public Methods
    bool isEmpty() const override {
        return itemTree.isEmpty();
    }

    int getNumberOfItems() const override {
        return itemTree.getNumberOfNodes();
    }

    bool add(const KeyType& searchKey, const ItemType& newItem) override {
        Entry<KeyType, ItemType> newEntry(searchKey, newItem);
        return itemTree.add(newEntry);
    }

    bool remove(const KeyType& searchKey) override {
        Entry<KeyType, ItemType> targetEntry(searchKey, ItemType());
        return itemTree.remove(targetEntry);
    }

    void clear() override {
        itemTree.clear();
    }

    ItemType getItem(const KeyType& searchKey) const override {
        Entry<KeyType, ItemType> targetEntry(searchKey, ItemType());
        Entry<KeyType, ItemType> foundEntry = itemTree.getEntry(targetEntry);
        return foundEntry.getItem();
    }

    bool contains(const KeyType& searchKey) const override {
        try {
            getItem(searchKey);
            return true;
        } catch (const NotFoundException&) {
            return false;
        }
    }

//    void traverse(void visit(ItemType&)) const override {
//        itemTree.inorderTraverse(visit);
//    }

};

#endif // _TREE_DICTIONARY
