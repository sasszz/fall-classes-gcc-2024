//
//  PriorityQueue.cpp
//  ch17_pp9
//
//  Created by Lucie Chevreuil on 10/7/24.
//

#include "PriorityQueue.hpp"
#include <stdexcept>

using namespace std;

PriorityQueue::PriorityQueue() : root(nullptr) {}

Node* PriorityQueue::insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

Node* PriorityQueue::findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

Node* PriorityQueue::remove(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

void PriorityQueue::insert(int key) {
    root = insert(root, key);
}

int PriorityQueue::extractMin() {
    if (root == nullptr) throw runtime_error("Priority queue is empty!");

    Node* minNode = findMin(root);
    int minValue = minNode->key;
    root = remove(root, minValue);

    return minValue;
}

bool PriorityQueue::isEmpty() {
    return root == nullptr;
}
