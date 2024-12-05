#pragma once
class Node
{
public:
    char key;
    Node* left;
    Node* right;

    Node() : key(' '), left(nullptr), right(nullptr) {}
    Node(char _key) : key(_key), left(nullptr), right(nullptr) {}
};
