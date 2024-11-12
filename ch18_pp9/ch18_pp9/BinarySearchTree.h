//
//  BinarySearchTree.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * Link-based implementation of the ADT binary search tree.
 * @file BinarySearchTree.h
 */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
    BinaryNode<ItemType>* rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    //------------------------------------------------------------

    BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);

    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);

    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);

    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section:
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section:
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const;
    void setRootData(const ItemType& newData) const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;

    //------------------------------------------------------------
    // Public Traversals Section:
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    //------------------------------------------------------------
    // Overloaded Operator Section:
    //------------------------------------------------------------
    BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
};

// Implementation of templated member functions

//------------------------------------------------------------
// Constructor and Destructor Section:
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
    : rootPtr(new BinaryNode<ItemType>(rootItem)) {}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) {
    rootPtr = this->copyTree(tree.rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section:
//------------------------------------------------------------
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("Attempted to access root data in an empty tree.");
    }
    return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("Cannot set root data in an empty tree.");
    }
    rootPtr->setItem(newData);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newEntry);
    rootPtr = insertInorder(rootPtr, newNode);
    return true;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry) {
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear() {
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const {
    BinaryNode<ItemType>* node = findNode(rootPtr, anEntry);
    if (node == nullptr) {
        throw NotFoundException("Entry not found.");
    }
    return node->getItem();
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
    return findNode(rootPtr, anEntry) != nullptr;
}

//------------------------------------------------------------
// Public Traversals Section:
//------------------------------------------------------------
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    this->preorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    this->inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    this->postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Protected Utility Methods Section:
//------------------------------------------------------------
template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode) {
    if (subTreePtr == nullptr) {
        return newNode;
    }
    if (newNode->getItem() < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
    } else {
        subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
    }
    return subTreePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    if (target == subTreePtr->getItem()) {
        subTreePtr = removeNode(subTreePtr);
        success = true;
    } else if (target < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    } else {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    }
    return subTreePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
    if (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() == nullptr) {
        delete nodePtr;
        return nullptr;
    } else if (nodePtr->getLeftChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnect = nodePtr->getRightChildPtr();
        delete nodePtr;
        return nodeToConnect;
    } else if (nodePtr->getRightChildPtr() == nullptr) {
        BinaryNode<ItemType>* nodeToConnect = nodePtr->getLeftChildPtr();
        delete nodePtr;
        return nodeToConnect;
    } else {
        ItemType newItem;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newItem));
        nodePtr->setItem(newItem);
        return nodePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor) {
    if (subTreePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
        return subTreePtr;
    }
}

template <class ItemType>
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

#endif // _BINARY_SEARCH_TREE

