/* 
 * File:   NonTerminalNode.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:45 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include <iostream>
#include <vector>
#include "Node.h"

class NonTerminalNode: public Node {
public:
    NonTerminalNode(): Node() {}
    NonTerminalNode(int num): Node(num) {}
    virtual ~NonTerminalNode() {
        for (int i = 0; i < getChildSize(); ++i)
            delete m_Children[i];
    }
    void addChild(Node* x) {m_Children.push_back(x);}
    virtual void Accept(Visitor* v) {v->VisitNonTerminalNode(this);}
    int getChildSize() {return m_Children.size();}
    Node* getChild(int i) {return m_Children[i];}
protected:
      vector<Node*> m_Children;  
};
#endif /* NONTERMINALNODE_H */

