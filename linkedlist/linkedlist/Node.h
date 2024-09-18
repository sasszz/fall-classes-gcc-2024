//
//  Node.h
//  linkedlist
//
//  Created by Lucie Chevreuil on 9/17/24.
//

#ifndef NODE_H
#define NODE_H

template <typename DataType>
class Node {
public:
    DataType value;
    Node<DataType>* next;
    Node<DataType>* prev;

    Node(DataType val) : value(val), next(nullptr), prev(nullptr) {}
};

#endif
