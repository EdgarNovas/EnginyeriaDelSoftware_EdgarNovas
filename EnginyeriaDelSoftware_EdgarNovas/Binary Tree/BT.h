#pragma once
#include "Node.h"
class BT
{
public:
    BT() {
        
    }
    ~BT()
    {
        
    }

    Node* Search(char key) {

    }
    void PreOrder();
    void InOrder();
    void PostOrder();
    bool Exist(char key);

private:
    Node* root;
    Node* Search(Node* node, char key);
    void PreOrder(Node* node);
    void InOrder(Node* node);
    void PostOrder(Node* node);
};
