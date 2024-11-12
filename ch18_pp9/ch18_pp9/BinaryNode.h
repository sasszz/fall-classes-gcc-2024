//
//  BinaryNode.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * A class of nodes for a link-based binary tree.
 * @file BinaryNode.h
 */

#ifndef _BINARY_NODE
#define _BINARY_NODE

template <class ItemType>
class BinaryNode {
private:
    ItemType item;                             // Data portion
    BinaryNode<ItemType>* leftChildPtr;        // Pointer to left child
    BinaryNode<ItemType>* rightChildPtr;       // Pointer to right child

public:
    // Constructors
    BinaryNode();
    BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

    // Accessors and Mutators
    void setItem(const ItemType& anItem);
    ItemType getItem() const;
    bool isLeaf() const;

    BinaryNode<ItemType>* getLeftChildPtr() const;
    BinaryNode<ItemType>* getRightChildPtr() const;

    void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
    void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
};

// Implementation of template methods directly in the header file

// Default constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
    : item(ItemType()), leftChildPtr(nullptr), rightChildPtr(nullptr) {}

// Parameterized constructor for a single node
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
    : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {}

// Parameterized constructor for a node with children
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr)
    : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {}

// Sets the data item in this node
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

// Gets the data item in this node
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return item;
}

// Checks if this node is a leaf (no children)
template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
    return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}

// Gets the left child pointer
template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

// Gets the right child pointer
template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

// Sets the left child pointer
template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
    leftChildPtr = leftPtr;
}

// Sets the right child pointer
template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
    rightChildPtr = rightPtr;
}

#endif // _BINARY_NODE
