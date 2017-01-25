#include "DLinkedList.h"
#include "ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

//default constructor
DLinkedList::DLinkedList(){
    m_size = 0;
    m_pListHead = NULL;
    m_pListTail = NULL;
    m_pCurrentNode = NULL;
}
//Destructor
DLinkedList::~DLinkedList(){
    ListNode* current = m_pListHead;
while( current != 0 ) {
    ListNode* next = current->getTail();
    delete current;
    current = next;
}
m_pListHead = 0;
}

//getters
ListNode* DLinkedList::getListHead(){
    return m_pListHead;
}
ListNode* DLinkedList::getListTail(){
    return m_pListTail;
}
int DLinkedList::getSize(){
    return m_size;
}

//creates a new node with vect as its ladder and adds it to the end of the array
void DLinkedList::enque(vector<string> vect){
    //Creates new ListNode
    ListNode *newNode = new ListNode(vect);
    //If list is empty, makes new node the listhead and listTail
    if(m_pListHead == NULL){
        m_pListHead = newNode;
        m_pListTail = newNode;
        m_pCurrentNode = m_pListHead;
    }
    //adds node to the end of the list
    else{
        ListNode* prevTail = m_pListTail;
        prevTail->m_pTail = newNode;
        newNode->m_pHead = prevTail;
        m_pListTail = newNode;
    }
    m_size++;
}

//prints ladder of listTail
void DLinkedList::deque(){
    if(m_pListTail->getLadder().size() > 0){
        for(int i = 0; i < m_pListTail->getLadder().size(); i++){
            cout << m_pListTail->getLadder().at(i) << endl;
        }
    }
}

//inserts node at position pos
void DLinkedList::insertAt(ListNode newNode, int pos){
    m_pCurrentNode = m_pListHead;
    ListNode* pPrevNode = NULL;
    for(int i = 0; i < pos; i++){
        pPrevNode = m_pCurrentNode;
        m_pCurrentNode = m_pCurrentNode->getTail();
    }
    newNode.setHead(m_pCurrentNode->getHead());
    newNode.setTail(m_pCurrentNode);
    m_pCurrentNode->setTail(&newNode);
}

//Moves m_pCurrentNode to next node in the list
ListNode* DLinkedList::next(){
    m_pCurrentNode = m_pCurrentNode->m_pTail;
    return m_pCurrentNode;
}
