#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
#include <string>

using namespace std;

//Implements a node for a doubly linked list data structure
class ListNode{
    public:
        //Points to previous node
        ListNode* m_pTail;
        //Points to next node
        ListNode* m_pHead;
        //Holds word ladder vector
        vector<string> m_ladder;
        
        //Constructor.  Tail and Head are NULL by default
        ListNode(vector<string> ladder, ListNode* tail = NULL, ListNode* head = NULL);
        
        //Getter methods
        vector<string> getLadder();
        ListNode* getTail();
        ListNode* getHead();
        
        //setter methods
        void setLadder(vector<string> newLadder);
        void setTail(ListNode* newTail);
        void setHead(ListNode* newHead);



        

};
#endif //LISTNODE_H
