#include "DLinkedList.h"
#include "ListNode.h"

using nammespace std;

DLinkedList::DLinkedList(){
    m_size = 0;
    m_pListHead = NULL;
    m_pListTail = NULL;
    m_pCurrentNode = NULL;
}