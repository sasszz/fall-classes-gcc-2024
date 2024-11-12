#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
private:
    BinaryNode<ItemType>* rootPtr;

protected:
    int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
    int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
    void destroyTree(BinaryNode<ItemType>* subTreePtr);
    BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
    BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

    void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
    BinaryNodeTree();
    BinaryNodeTree(const ItemType& rootItem);
    BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr);
    BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
    virtual ~BinaryNodeTree();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const;
    void setRootData(const ItemType& newData);
    bool add(const ItemType& newData);
    bool remove(const ItemType& data);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;

    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};

// Implementation Section

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem);
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr) {
    rootPtr = new BinaryNode<ItemType>(rootItem);
    rootPtr->setLeftChildPtr(copyTree(leftTreePtr->rootPtr));
    rootPtr->setRightChildPtr(copyTree(rightTreePtr->rootPtr));
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree) {
    rootPtr = copyTree(tree.rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    destroyTree(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) return 0;
    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) return 0;
    return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
    if (treePtr == nullptr) return nullptr;
    BinaryNode<ItemType>* newTree = new BinaryNode<ItemType>(treePtr->getItem());
    newTree->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTree->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    return newTree;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    }
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
    if (isEmpty()) throw PrecondViolatedExcep("Empty tree");
    return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) {
    if (isEmpty())
        rootPtr = new BinaryNode<ItemType>(newData);
    else
        rootPtr->setItem(newData);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target) {
    bool success = false;
    rootPtr = removeValue(rootPtr, target, success);
    return success;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear() {
    destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorder(visit, rootPtr);
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
    if (subTreePtr == nullptr) {
        return newNodePtr; // Insert node at this position
    }
    
    BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
    BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
    
    if (getHeightHelper(leftPtr) <= getHeightHelper(rightPtr)) {
        subTreePtr->setLeftChildPtr(balancedAdd(leftPtr, newNodePtr));
    } else {
        subTreePtr->setRightChildPtr(balancedAdd(rightPtr, newNodePtr));
    }
    
    return subTreePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    
    if (subTreePtr->getItem() == target) {
        success = true;
        return moveValuesUpTree(subTreePtr);
    } else {
        BinaryNode<ItemType>* tempPtr = nullptr;
        if (target < subTreePtr->getItem()) {
            tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
            subTreePtr->setLeftChildPtr(tempPtr);
        } else {
            tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
            subTreePtr->setRightChildPtr(tempPtr);
        }
        return subTreePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr) {
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
        bool unusedSuccess;
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), tempPtr->getItem(), unusedSuccess));
        return subTreePtr;
    }
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {
    bool found = false;
    findNode(rootPtr, anEntry, found);
    return found;
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const {
    bool found = false;
    BinaryNode<ItemType>* nodePtr = findNode(rootPtr, anEntry, found);

    if (found) {
        return nodePtr->getItem();
    } else {
        throw NotFoundException("Entry not found in the tree.");
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const {
    if (treePtr == nullptr) {
        success = false;
        return nullptr;
    }

    if (treePtr->getItem() == target) {
        success = true;
        return treePtr;
    } else if (target < treePtr->getItem()) {
        return findNode(treePtr->getLeftChildPtr(), target, success);
    } else {
        return findNode(treePtr->getRightChildPtr(), target, success);
    }
}


#endif // _BINARY_NODE_TREE
