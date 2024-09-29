//
//  StackInterface.h
//  ch6_2pp_bracebalance
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

template<typename ItemType>
class StackInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const ItemType& newEntry) = 0;
    virtual bool pop() = 0;
    virtual ItemType peek() const = 0;
    virtual void printStack() const = 0;
};

#endif
