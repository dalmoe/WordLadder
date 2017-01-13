#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
#include <string>

using namespace std;

class ListNode{
    public:
      ListNode(vector<string> ladder, ListNode* tail = NULL, ListNode* head = NULL);
       
        vector<string> getLadder();
        ListNode* getTail();
        ListNode* getHead();
        
        void setLadder(vector<string> newLadder);
        void setTail(ListNode* newTail);
        void setHead(ListNode* newHead);
      
    private:
        ListNode* m_pTail;
        ListNode* m_pHead;
        vector<string> m_ladder;
};
#endif //LISTNODE_H