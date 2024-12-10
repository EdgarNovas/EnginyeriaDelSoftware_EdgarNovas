#pragma once
#include "Node.h"
#include "functional"
class BT
{
public:
    BT() { root = nullptr; }

    ~BT()
    {
        std::function<void(Node*)> deleteTree = [&](Node* node) {
            if (node == nullptr) return;
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
            };
        deleteTree(root);
    }



    inline Node* Search(char key) {
        
        return Search(root, key);
    }

    void PreOrder() {
        PreOrder(root);
    }
    void InOrder()
    {
        InOrder(root);
    }
    void PostOrder()
    {
        PostOrder(root);
    }
    bool Exist(char key)
    {
        return Search(key) != nullptr;
    }

    void AddNode(char parentKey , char key, bool isLeft) {

        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        Node* parent = Search(root, parentKey);
        if (parent == nullptr) {
            std::cout << "Parent key " << parentKey << " not found!" << std::endl;
            return;
        }

        if (isLeft) {
            if (parent->left == nullptr)
                parent->left = new Node(key);
            else
                std::cout << "Left child of " << parentKey << " already exists!" << std::endl;
        }
        else {
            if (parent->right == nullptr)
                parent->right = new Node(key);
            else
                std::cout << "Right child of " << parentKey << " already exists!" << std::endl;
        }

    }

private:
    Node* root;
    Node* Search(Node* node, char key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }


        if (node->key == key) {
           
            return node;
        }

        
        Node* leftResult = Search(node->left, key);
        if (leftResult != nullptr) {
            return leftResult; 
        }

        return Search(node->right, key);

    }

    void PreOrder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->key << " ";
        PreOrder(node->left);         
        PreOrder(node->right);         
    }
    void InOrder(Node* node) {
        if (node == nullptr) return;
        InOrder(node->left);          
        std::cout << node->key << " ";
        InOrder(node->right);          
    }
    void PostOrder(Node* node) {
        if (node == nullptr) return;
        PostOrder(node->left);        
        PostOrder(node->right);        
        std::cout << node->key << " ";
    }
};
