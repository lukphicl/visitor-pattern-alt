/* 
 * File:   StackBasedSumVisitor.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:46 PM
 */

#ifndef STACKBASEDSUMVISITOR_H
#define STACKBASEDSUMVISITOR_H
#include <iostream>
#include <stack>
using namespace std;

#include "Node.h"
#include "Visitor.h"

class StackBasedSumVisitor: public Visitor {
protected:
    stack <int> m_Stack;
public:
    StackBasedSumVisitor() {}
    virtual ~StackBasedSumVisitor() {}
    virtual void VisitTerminalNode(TerminalNode* trn) {
        m_Stack.push(trn->getData());
    }
    virtual void VisitNonTerminalNode(NonTerminalNode* ntrn) {
        int sum = ntrn->getData();
        for (int i = 0; i < ntrn->getChildSize(); i++) {
            ntrn->getChild(i)->Accept(this);
        }
        for (int i = 0; i < ntrn->getChildSize(); i++) {
            sum += m_Stack.top();
            m_Stack.pop();
        }
        m_Stack.push(sum);
    }
    int getResult() {
        int result = m_Stack.top();
        m_Stack.pop();
        return result;
    }
    
};

#endif /* STACKBASEDSUMVISITOR_H */

