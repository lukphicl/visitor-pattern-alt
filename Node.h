/* 
 * File:   Node.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:44 PM
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Visitor.h"

class Node {
public:
    Node() {data = 0;}
    virtual ~Node() {}
    Node(int num) {data = num;}
    int getData() {return data;}
    virtual void Accept(Visitor*) = 0;
protected:
    int data;
};

#endif /* NODE_H */

