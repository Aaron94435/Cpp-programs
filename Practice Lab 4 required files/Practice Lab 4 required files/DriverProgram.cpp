// Chapter 18 assignments - Driver program
#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
	// Create an instance of IntList
	IntList list;

	// Build the list adding 2, 4 and 6
	list.appendNode(2);
	list.appendNode(4);
	list.appendNode(6);

	// Print the nodes (using your added function).
	list.displayList();

	// Insert the value 5 into the list.
	list.insertNode(5);

	// Print the nodes (using your added function).
	list.displayList();

	// Delete the node holding 6.
	list.deleteNode(6);

	// Print the nodes (using your added function).
	list.displayList();

	// Reverse the list (using your added function)
	list.reverse();

	// Print the nodes (using your added function).
	list.displayList();

	return 0;
}
