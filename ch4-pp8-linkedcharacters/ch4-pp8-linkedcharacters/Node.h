//
//  ListNode.h
//  ch4-pp8-linkedcharacters
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#ifndef NODE_H
#define NODE_H

class Node {
public:
    char item;
    Node *next;

    Node(char ch) : item(ch), next(nullptr) {}
    Node(char ch, Node *next) : item(ch), next(next) {}
};

#endif
