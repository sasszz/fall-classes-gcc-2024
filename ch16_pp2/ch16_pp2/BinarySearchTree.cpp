//
//  BinarySearchTree.cpp
//  ch16_pp2
//
//  Created by Lucie Chevreuil on 10/7/24.
//


#include "BinarySearchTree.h"
#include "PrecondViolatedExcep.h"

using namespace std;

// Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {
}

// Parameterized constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

// Copy constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) {
    rootPtr = this->copyTree(tree.rootPtr);
}

// Destructor
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(rootPtr);
}

// Check if tree is empty
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

// Get tree height
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

// Get number of nodes
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}

// Get root data
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("getRootData() called with empty tree.");
    }
    return rootPtr->getItem();
}

// Set root data
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("setRootData() called with empty tree.");
    }
    rootPtr->setItem(newData);
}

// Add node (public method)
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newEntry);
    rootPtr = insertInorder(rootPtr, newNode);
    return true;
}

// Insert node (private helper)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode) {
    if (subTreePtr == nullptr) {
        return newNode;
    } else if (newNode->getItem() < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
    } else {
        subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
    }
    return subTreePtr;
}

// Remove node (public method)
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target) {
    bool success = false;
    rootPtr = removeValue(rootPtr, target, success);
    return success;
}

// Remove value (private helper)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    } else if (target == subTreePtr->getItem()) {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    } else if (target < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    } else {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    }
    return subTreePtr;
}

// Remove node (private helper)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
    if (nodePtr->isLeaf()) {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    } else if (nodePtr->getLeftChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        return nodeToConnectPtr;
    } else if (nodePtr->getRightChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        return nodeToConnectPtr;
    } else {
        ItemType newNodeValue;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

// Remove leftmost node (private helper)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor) {
    if (subTreePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
        return subTreePtr;
    }
}

// Clear the tree
template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

// Find node (private helper)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const {
    if (treePtr == nullptr) {
        return nullptr;
    } else if (target == treePtr->getItem()) {
        return treePtr;
    } else if (target < treePtr->getItem()) {
        return findNode(treePtr->getLeftChildPtr(), target);
    } else {
        return findNode(treePtr->getRightChildPtr(), target);
    }
}

// Check if tree contains a value
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
    return findNode(rootPtr, anEntry) != nullptr;
}

// Traversals
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    this->preorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    this->inorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    this->postorder(visit, rootPtr);
}

// Assignment operator overloading
template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide) {
    if (this != &rightHandSide) {
        this->clear();
        rootPtr = this->copyTree(rightHandSide.rootPtr);
    }
    return *this;
}
