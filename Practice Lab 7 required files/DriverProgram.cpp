// Chapter 21 Assignment-Driver Program
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	// Create an instace of BinaryTree.
	BinaryTree<int> tree;

	// Insert some nodes into the tree.

	tree.insertNode(1);
	tree.insertNode(5);
	tree.insertNode(2);
	tree.insertNode(4);
	tree.insertNode(8);
	tree.insertNode(10);
	// Display the values of the nodes.
	tree.displayInOrder();

	// Get the number of the nodes
	cout <<"Node count: " << tree.getNodeCount() << endl;

	// Display the number of the leaf nodes.
	cout << "Leaf count: " << tree.getLeafCount() << endl;

	// Remove the 8 node.
	tree.remove(8);

	// Display the values of the nodes again.

	tree.displayInOrder();
	// Get the number of the nodes again.
	cout << "Node count: " << tree.getNodeCount() << endl;

	// Display the number of leaf nodes again.
	cout << "Leaf count: " << tree.getLeafCount() << endl;
	return 0;
}
