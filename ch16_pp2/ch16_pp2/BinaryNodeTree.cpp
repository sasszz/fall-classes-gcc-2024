//
//  BinaryNodeTree.cpp
//  ch16_pp2
//
//  Created by Lucie Chevreuil on 10/7/24.
//

#include "BinaryNodeTree.h"
#include "NotFoundException.h"  // Ensure NotFoundException is included

// Constructor
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {}

// Parameterized constructor
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

// Copy constructor
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree) {
    rootPtr = this->copyTree(tree.rootPtr);
}

// Destructor
template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    this->destroyTree(rootPtr);
}

// Check if tree is empty
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

// Get tree height
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

// Get number of nodes
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

// Get root data
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("getRootData() called on empty tree.");
    }
    return rootPtr->getItem();
}

// Set root data
template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) const {
    if (isEmpty()) {
        // Can't modify rootPtr because the function is const
        // You may want to throw an exception here if the tree is empty
        throw PrecondViolatedExcep("setRootData() called with empty tree.");
    } else {
        rootPtr->setItem(newData);
    }
}



// Add node
template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}

// Remove node
template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target) {
    bool success = false;
    rootPtr = removeValue(rootPtr, target, success);
    return success;
}

// Clear tree
template<class ItemType>
void BinaryNodeTree<ItemType>::clear() {
    destroyTree(rootPtr);
    rootPtr = nullptr;
}

// Get specific entry
template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const {
    bool success = false;
    BinaryNode<ItemType>* node = findNode(rootPtr, anEntry, success);
    if (success) {
        return node->getItem();
    }
}

// Check if tree contains an entry
template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {
    bool success = false;
    findNode(rootPtr, anEntry, success);
    return success;
}

// Preorder traversal
template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorder(visit, rootPtr);
}

// Inorder traversal
template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorder(visit, rootPtr);
}

// Postorder traversal
template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorder(visit, rootPtr);
}

// Overloaded assignment operator
template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide) {
    if (this != &rightHandSide) {
        this->clear();
        rootPtr = this->copyTree(rightHandSide.rootPtr);
    }
    return *this;
}

//------------------------------------------------------------
// Protected Utility Methods Section
//------------------------------------------------------------

// Recursively get the height of the tree
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    } else {
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

// Recursively count the number of nodes in the tree
template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    } else {
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }
}

// Recursively delete all nodes in the tree
template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }
}

// Recursively add a new node in a balanced fashion
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
    if (subTreePtr == nullptr) {
        return newNodePtr;
    } else {
        BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
        BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) <= getHeightHelper(rightPtr)) {
            subTreePtr->setLeftChildPtr(balancedAdd(leftPtr, newNodePtr));
        } else {
            subTreePtr->setRightChildPtr(balancedAdd(rightPtr, newNodePtr));
        }
        return subTreePtr;
    }
}

// Recursively find and remove a node
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    } else if (target == subTreePtr->getItem()) {
        subTreePtr = moveValuesUpTree(subTreePtr);
        success = true;
        return subTreePtr;
    } else if (target < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    } else {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    }
    return subTreePtr;
}

// Move values up the tree to overwrite current node and remove leaf
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr) {
    bool success = false;  // Declare success here
    if (subTreePtr->isLeaf()) {
        delete subTreePtr;
        return nullptr;
    } else if (subTreePtr->getLeftChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnectPtr = subTreePtr->getRightChildPtr();
        delete subTreePtr;
        return nodeToConnectPtr;
    } else if (subTreePtr->getRightChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnectPtr = subTreePtr->getLeftChildPtr();
        delete subTreePtr;
        return nodeToConnectPtr;
    } else {
        BinaryNode<ItemType>* tempPtr = subTreePtr->getRightChildPtr();
        while (tempPtr->getLeftChildPtr() != nullptr) {
            tempPtr = tempPtr->getLeftChildPtr();
        }
        subTreePtr->setItem(tempPtr->getItem());
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), tempPtr->getItem(), success));
        return subTreePtr;
    }
}

// Recursively search for a node
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const {
    if (treePtr == nullptr) {
        success = false;
        return nullptr;
    } else if (target == treePtr->getItem()) {
        success = true;
        return treePtr;
    } else if (target < treePtr->getItem()) {
        return findNode(treePtr->getLeftChildPtr(), target, success);
    } else {
        return findNode(treePtr->getRightChildPtr(), target, success);
    }
}
