#include "Game.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>
#include "ListNode.h"

using namespace std;

int main(){
    vector<string> v;
    vector<string> v2;
    v.push_back("Hi");
    v.push_back("Bye");
    v2.push_back("Hello");
    v2.push_back("Goodbye");
    DLinkedList list;
    ListNode node(v);
    ListNode node2(v2);
    list.enque(node);
    list.enque(node2);
    cout << node.getLadder().at(0) << endl;
    cout << node.getLadder().at(1) << endl;
    cout << list.getListTail()->m_ladder.at(0) << endl;
}