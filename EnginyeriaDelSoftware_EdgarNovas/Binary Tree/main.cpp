#include <iostream>
#include "BT.h"
int main()
{
	BT tree;

    tree.AddNode('\0', 'A', true);
    tree.AddNode('A', 'B', true); 
    tree.AddNode('A', 'C', false); 
    tree.AddNode('B', 'D', true); 
    tree.AddNode('B', 'E', false); 
    tree.AddNode('C', 'F', true); 
    tree.AddNode('C', 'G', false); 

    // Perform traversals.
    std::cout << "PreOrder: ";
    tree.PreOrder();
    std::cout << "\nInOrder: ";
    tree.InOrder();
    std::cout << "\nPostOrder: ";
    tree.PostOrder();
    std::cout << "\nDoes exist? " << (tree.Exist('A') ? "true" : "false");
    


}