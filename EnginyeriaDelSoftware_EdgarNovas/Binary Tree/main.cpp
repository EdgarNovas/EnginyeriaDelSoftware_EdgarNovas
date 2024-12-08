#include <iostream>
#include "BT.h"
int main()
{
	BT tree;

    tree.AddNode('\0', 'A', true);  // Create root 'A'.
    tree.AddNode('A', 'B', true);  // Add 'B' as left child of 'A'.
    tree.AddNode('A', 'C', false); // Add 'C' as right child of 'A'.
    tree.AddNode('B', 'D', true);  // Add 'D' as left child of 'B'.
    tree.AddNode('B', 'E', false); // Add 'E' as right child of 'B'.
    tree.AddNode('C', 'F', true);  // Add 'F' as left child of 'C'.
    tree.AddNode('C', 'G', false); // Add 'G' as right child of 'C'.

    // Perform traversals.
    std::cout << "PreOrder: ";
    tree.PreOrder();
    std::cout << "\nInOrder: ";
    tree.InOrder();
    std::cout << "\nPostOrder: ";
    tree.PostOrder();


}