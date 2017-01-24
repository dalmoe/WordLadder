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

DLinkedList::~DLinkedList(){
    //add later
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

void DLinkedList::enque(vector<string> vect){
    ListNode newNode(vect);
    
    if(m_pListHead == NULL){
        m_pListHead = &newNode;
        m_pListTail = &newNode;
        m_pCurrentNode = m_pListHead;
    }
    else{
        ListNode* prevTail = m_pListTail;
        prevTail->m_pTail = &newNode;
        newNode.m_pHead = prevTail;
        m_pListTail = &newNode;
    }
    m_size++;
}

void DLinkedList::deque(){
     //vector<string> output(m_pListTail->m_ladder);
    if(m_pListTail->getLadder().size() > 0){
        for(int i = 0; i < m_pListTail->getLadder().size(); i++){
            cout << m_pListTail->getLadder().at(i) << endl;
        }
    }
}

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

ListNode* DLinkedList::next(){
    m_pCurrentNode = m_pCurrentNode->m_pTail;
    return m_pCurrentNode;
}
