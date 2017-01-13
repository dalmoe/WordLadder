#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "ListNode.h"
//#include <string>
//#include <vector>

using namespace std;

class DLinkedList{
   public:
    DLinkedList();
    ~DLinkedList();
    
    ListNode* getListHead();
    void setListHead();
    ListNode* getListTail();
    void setListTail();
    int getSize();
    
    void insertAt(ListNode newNode, int pos);
    void enque(ListNode newNode);
    void deque();
    
   private:
    int m_size;
    ListNode* m_pListHead;
    ListNode* m_pListTail;
    ListNode* m_pCurrentNode;
};

#endif //DLINKEDLIST_H