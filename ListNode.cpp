#include "ListNode.h"
#include <string>
#include <vector>
using namespace std;

ListNode::ListNode(vector<string> ladder, ListNode* tail, ListNode* head){
    m_ladder = ladder;
    m_pTail = tail;
    m_pHead = head;
}

vector<string> ListNode::getLadder(){
    return m_ladder;
}
void ListNode::setLadder(vector<string> newLadder){
    m_ladder = newLadder;
}

ListNode* ListNode::getTail(){
    return m_pTail;
}
void ListNode::setTail(ListNode* newTail){
    m_pTail = newTail;
}

ListNode* ListNode::getHead(){
    return m_pHead;
}
void ListNode::setHead(ListNode* newHead){
    m_pHead = newHead;
}
