/* 
 * File:   Visitor.h
 * Author: Luke Clover
 *
 * Created on March 18, 2019, 4:45 PM
 */

#ifndef VISITOR_H
#define VISITOR_H
class NonTerminalNode;
class TerminalNode;

class Visitor {
public:
    Visitor() {}
    virtual ~Visitor() {}
    virtual void VisitNonTerminalNode(NonTerminalNode*) = 0;
    virtual void VisitTerminalNode(TerminalNode*) = 0;
};

#endif /* VISITOR_H */

