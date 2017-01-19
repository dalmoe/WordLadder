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

void DLinkedList::enque(ListNode newNode){
    if(m_pListHead == NULL){
        m_pListHead = &newNode;
        m_pListTail = &newNode;
    }
    else{
        m_pListTail->setTail(&newNode);
        newNode.setHead(m_pListTail);
        m_pListTail = &newNode;
    }
    m_size++;
}

void DLinkedList::deque(){
    vector<string> output(m_pListTail->m_ladder);
    if(output.size() > 0){
        /*for(int i = 0; i < output.size(); i++){
            cout << output.at(i);
        }*/
        cout << output.at(0);
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