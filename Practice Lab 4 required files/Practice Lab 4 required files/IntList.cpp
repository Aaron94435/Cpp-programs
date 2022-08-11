// Implementation file for the IntList class
#include <iostream>
#include "IntList.h"
using namespace std;   

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void IntList::appendNode(int num)
{
   ListNode *newNode, *nodePtr = nullptr;

   // Allocate a new node & store num
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Find the last node in the list
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList function: It should show the value  *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void IntList::displayList() {
     ListNode* node;
     if (!head)
          cout << "No items in the list" << endl;
     else {
          node = head;
          while (node->next) {
               cout << node->value << " ";
               node = node->next;
          }
          cout << node->value << endl;
     }
}

//**************************************************
// Reverse function: It should rearrange the nodes *
//in the list so their order is reversed           *
//**************************************************

void IntList::reverse() {
     ListNode* node = nullptr; //traverses the list
     ListNode* holder = nullptr; //holds the original spot for head
     ListNode* tail = nullptr; //start at end and move towards beginning
     if (!head || !head->next) {
          cout << "This list cannot be reversed" << endl;
     }
     else {
          node = head;
          holder = head;
          while (node->next) {     //find the tail
               node = node->next;
          }
          tail = node;
          head = tail;   //list starts at end for now on
          while (holder != tail) {   //while the end is not reached
               node = holder;
               while (node->next != tail) {  //traverses until it reaches tail
                   node = node->next;
               }
               tail->next = node;  //sets next pointer to go backwards, same as head->next at first
               tail = tail->next;  //moves tail closer to beginning, now it's not pointing to the same node as head
          }
          tail->next = nullptr; //ends the list
     }
}




//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void IntList::insertNode(int num)
{
   ListNode *newNode, *nodePtr, *previousNode = nullptr;

   // Allocate a new node & store num
   newNode = new ListNode;
   newNode->value = num;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Initialize nodePtr to head of list and
      // previousNode to a null pointer.
      nodePtr = head;
      previousNode = nullptr;

      // Skip all nodes whose value member is less
      // than num.
      while (nodePtr != nullptr && nodePtr->value < num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise, insert it after the prev node
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void IntList::deleteNode(int num)
{
   ListNode *nodePtr, *previousNode = nullptr;

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == num)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to num.
      while (nodePtr != nullptr && nodePtr->value != num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

IntList::~IntList()
{
   ListNode *nodePtr, *nextNode = nullptr;

   nodePtr = head;
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}