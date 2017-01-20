#include "Game.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>
#include "ListNode.h"
#include <fstream>

using namespace std;

void Game::parseDict(){
    string str;
    //vector<string> vect;
    ifstream in("dictionary.txt");
    if(in.is_open()){
        while(getline(in, str)){
            m_dictionary.push_back(str);
        }
    }
    else{
        cout << "Unable to open file." << endl;
    }
    //return vect;
}

void Game::play(string word1, string word2){
    bool done = false;
    DLinkedList list;
    vector<string> tmpVect;
    tmpVect.push_back(word1);
    ListNode* tmpNode;
    tmpNode->setLadder(tmpVect);
    list.enque(*tmpNode);
    while(!done){
        if(word2.compare(list.getListTail()->getLadder().at(list.getListTail()->getLadder().size() - 1)) == 0){
            done = true;
        }
        else{
            tmpNode = list.next();
            for(int i = 0; i < m_dictionary.size(); i++){

            }
        }
    }
}
//int main(){
    /*vector<string> v;
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

    list.deque();*/

    //cout << list.getListHead()->getLadder().at(0);
//}
