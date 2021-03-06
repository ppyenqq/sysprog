#ifndef SYSPROG_NODE_H
#define SYSPROG_NODE_H

#include "RuleType.h"
#include "NodeType.h"
#include "../../Scanner/Token/Token.h"

class Information;

class Node {
public:
    Node();
    Node(Token* currentToken);

    virtual ~Node();

    int currentChildren;

    void setNodeType(NodeType type);
    NodeType getNodeType();

    void setSymbolType(SymbolType type);
    SymbolType getSymbolType();

    void setRuleType(RuleType ruleType);
    RuleType getRuleType();

    void addChild(Node *child);
    Node* getChildren(int position);

    long getIntegerValue();
    Token* getToken();

    void flagAsLeaf();
    bool isLeaf();

private:
    RuleType ruleType;
    SymbolType symbolType;
    NodeType nodeType;
    Node* children[9];
    bool leaf;

    Token* token;
};

#endif //SYSPROG_NODE_H
