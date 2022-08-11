// Specification file for the IntList class
#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      int value;
      struct ListNode *next;  
   }; 

   ListNode *head;   // List head pointer

public:
   IntList()   // Constructor
      { head = nullptr; }
   ~IntList(); // Destructor
   void appendNode(int);
   void insertNode(int);
   void deleteNode(int);
   void displayList();
   void reverse();
};

#endif