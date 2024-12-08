#pragma once
#include "Node.h"
#include "functional"
class BT
{
public:
    BT() { root = nullptr; }

    ~BT()
    {
        // Implement a helper function to delete all nodes.
        std::function<void(Node*)> deleteTree = [&](Node* node) {
            if (node == nullptr) return;
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
            };
        deleteTree(root);
    }



    Node* Search(char key) {

    }

    void PreOrder() {

    }
    void InOrder();
    void PostOrder();
    bool Exist(char key);

    void AddNode(char parentKey , char key, bool isLeft) {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        // Search for the parent node.
        Node* parent = Search(root, parentKey);
        if (parent == nullptr) {
            std::cout << "Parent key " << parentKey << " not found!" << std::endl;
            return;
        }

        // Add the new node as the left or right child.
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
        
    }

    void PreOrder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->key << " "; // Visit root
        PreOrder(node->left);          // Traverse left
        PreOrder(node->right);         // Traverse right
    }
    void InOrder(Node* node) {
        if (node == nullptr) return;
        InOrder(node->left);           // Traverse left
        std::cout << node->key << " "; // Visit root
        InOrder(node->right);          // Traverse right
    }
    void PostOrder(Node* node) {
        if (node == nullptr) return;
        PostOrder(node->left);         // Traverse left
        PostOrder(node->right);        // Traverse right
        std::cout << node->key << " "; // Visit root
    }
};
