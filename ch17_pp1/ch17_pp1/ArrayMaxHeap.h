//
//  ArrayMaxHeap.h
//  ch17_pp1
//
//  Created by Lucie Chevreuil on 10/7/24.
//

/**
 * Array-based implementation of the ADT heap.
 * @file ArrayMaxHeap.h
 */

#ifndef _ARRAY_MAX_HEAP
#define _ARRAY_MAX_HEAP

#include "HeapInterface.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType> {
private:
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 21;
    ItemType* items;
    int itemCount;
    int maxItems;

    int getLeftChildIndex(const int nodeIndex) const;
    int getRightChildIndex(int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    bool isLeaf(int nodeIndex) const;
    void heapRebuild(int subTreeRootIndex);
    void heapCreate();

public:
    ArrayMaxHeap();
    ArrayMaxHeap(const ItemType someArray[], const int arraySize);
    virtual ~ArrayMaxHeap();

    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    ItemType peekTop() const;
    bool add(const ItemType& newData);
    bool remove();
    void clear();
};

// Implementation of ArrayMaxHeap

// Constructor
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
    items = new ItemType[DEFAULT_CAPACITY];
}

// Parameterized constructor
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
    : itemCount(arraySize), maxItems(arraySize * 2) {
    items = new ItemType[maxItems];
    for (int i = 0; i < arraySize; i++) {
        items[i] = someArray[i];
    }
    heapCreate();
}

// Destructor
template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
    delete[] items;
}

// Check if heap is empty
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
    return itemCount == 0;
}

// Get number of nodes in the heap
template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
    return itemCount;
}

// Get height of the heap
template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {
    return static_cast<int>(ceil(log2(itemCount + 1)));
}

// Peek top item of the heap
template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const {
    if (isEmpty()) {
        throw std::runtime_error("Attempted to peek into an empty heap.");
    }
    return items[ROOT_INDEX];
}

// Add item to the heap
template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
    if (itemCount == maxItems) {
        maxItems *= 2;
        ItemType* oldArray = items;
        items = new ItemType[maxItems];
        for (int i = 0; i < itemCount; i++) {
            items[i] = oldArray[i];
        }
        delete[] oldArray;
    }
    
    items[itemCount] = newData;
    
    int newDataIndex = itemCount;
    bool inPlace = false;
    while ((newDataIndex > 0) && !inPlace) {
        int parentIndex = getParentIndex(newDataIndex);
        if (items[newDataIndex] > items[parentIndex]) {
            std::swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
        } else {
            inPlace = true;
        }
    }
    
    itemCount++;
    return true;
}

// Remove item from the heap
template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
    if (isEmpty()) {
        return false;
    }

    items[ROOT_INDEX] = items[itemCount - 1];
    itemCount--;

    heapRebuild(ROOT_INDEX);
    return true;
}

// Clear the heap
template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() {
    itemCount = 0;
}

// Get index of left child
template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
    return (2 * nodeIndex) + 1;
}

// Get index of right child
template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const {
    return (2 * nodeIndex) + 2;
}

// Get index of parent node
template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const {
    return (nodeIndex - 1) / 2;
}

// Check if node is a leaf
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {
    return (getLeftChildIndex(nodeIndex) >= itemCount);
}

// Rebuild the heap after deletion
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
    if (!isLeaf(subTreeRootIndex)) {
        int leftChildIndex = getLeftChildIndex(subTreeRootIndex);
        int rightChildIndex = getRightChildIndex(subTreeRootIndex);
        
        int largerChildIndex = leftChildIndex;
        if ((rightChildIndex < itemCount) && (items[rightChildIndex] > items[leftChildIndex])) {
            largerChildIndex = rightChildIndex;
        }

        if (items[subTreeRootIndex] < items[largerChildIndex]) {
            std::swap(items[subTreeRootIndex], items[largerChildIndex]);
            heapRebuild(largerChildIndex);
        }
    }
}

// Build a heap from an unordered array
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {
    for (int index = itemCount / 2 - 1; index >= 0; index--) {
        heapRebuild(index);
    }
}

#endif
