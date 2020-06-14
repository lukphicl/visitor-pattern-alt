/* 
 * File:   NonStackBasedSumVisitor.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:46 PM
 */

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H
#include <iostream>
using namespace std;

#include "Node.h"
#include "Visitor.h"
class NonStackBasedSumVisitor: public Visitor {
protected:
    int sum;
public:
    NonStackBasedSumVisitor() {sum = 0;}
    virtual ~NonStackBasedSumVisitor(){}
    virtual void VisitTerminalNode(TerminalNode* trn) {sum += trn->getData();}
    virtual void VisitNonTerminalNode(NonTerminalNode* ntrn) {
        sum += ntrn->getData();
        for (int i = 0; i < ntrn->getChildSize(); i++) {
            ntrn->getChild(i)->Accept(this);
        }
    }
    int getResult() {
        int result = sum;
        sum = 0;
        return result;
    }    
};

#endif /* NONSTACKBASEDSUMVISITOR_H */

