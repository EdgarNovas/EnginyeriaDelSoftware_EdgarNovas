#pragma once
#include "Node.h"
class BT
{
public:
    BT() { root = nullptr; }

    ~BT()
    {
        
    }



    Node* Search(char key) {

    }
    void PreOrder();
    void InOrder();
    void PostOrder();
    bool Exist(char key);

    void AddNode(char key) {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }
    }

private:
    Node* root;
    Node* Search(Node* node, char key);
    void PreOrder(Node* node);
    void InOrder(Node* node);
    void PostOrder(Node* node);
};
