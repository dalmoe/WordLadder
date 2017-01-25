#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "ListNode.h"
#include <string>
#include <vector>

using namespace std;

//Implements a doubly linked list data structure
class DLinkedList{
  public:
   //default contructor
   DLinkedList();
   //destructor
   ~DLinkedList();
 
    //getter methods
   ListNode* getListHead();
   ListNode* getListTail();
   int getSize();
   
   //Inserts a node at position pos
   void insertAt(ListNode newNode, int pos);
   //Adds node to the end of the list
   void enque(vector<string> vect);
   //Prints out word ladder of final node
   void deque();
   //Changes value of m_pCurrentNode to point at the next node in the list
   ListNode* next();

  private:
   //size of the linked list
   int m_size;
   //Points to the first item in the linked list
   ListNode* m_pListHead;
   //points to last item in the linked list
   ListNode* m_pListTail;
   //Pointer that helps iterate through the linked list
   ListNode* m_pCurrentNode;
};

#endif //DLINKEDLIST_H
