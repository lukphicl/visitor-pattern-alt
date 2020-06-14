/* 
 * File:   TerminalNode.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:45 PM
 */

#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include <iostream>
#include <vector>
#include "Node.h"

class TerminalNode: public Node {
public:
    TerminalNode(int num): Node(num) {}
    virtual ~TerminalNode() {};
    virtual void Accept(Visitor* v) {v->VisitTerminalNode(this);}
};

#endif /* TERMINALNODE_H */

