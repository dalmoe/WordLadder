#include "Game.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>
#include "ListNode.h"
#include <fstream>

using namespace std;

Game::Game(){
    parseDict();
}

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
    /*bool done = false;
    DLinkedList list;
    vector<string> tmpVect;
    tmpVect.push_back(word1);
    ListNode* currentNode;
    //ListNode tmpNode(currentNode);
    vector<string> newVect;
    int test = 0;
    //tmpNode->m_ladder = tmpVect;
    list.enque(newVect);
    int diffs = 0;
    while(!done) {
        //if(word2.compare(list.getListTail()->getLadder().at(list.getListTail()->getLadder().size() - 1)) == 0){
            //done = true;
        //}
        //else{
            if(list.getSize() > 1)
                //tmpNode = currentNode.getHead();
                currentNode = list.next();
            tmpVect = currentNode->getLadder();
            newVect = tmpVect;
            for(int i = 0; i < m_dictionary.size(); i++){
                newVect = tmpVect;
                if(tmpVect.at(tmpVect.size() - 1).length() + 1 == m_dictionary.at(i).length()){
                    string tmp1 = tmpVect.at(tmpVect.size() - 1);
                    string tmp2 = m_dictionary.at(i);
                    tmp2 = tmp2.substr(0, tmp2.length() - 1);

                    for(int j = 0; j < m_dictionary.at(i).length(); j++){
                        if(tmp1[j] != tmp2[j]){
                            diffs++;
                        }
                    }
                    if(diffs == 1){
                        if(tmp2 == word2){
                            newVect.push_back(tmp2);
                            //tmpNode.setLadder(newVect);
                            list.enque(newVect);
                            list.deque();
                            done = true;
                        }
                    newVect.push_back(tmp2);
                    //tmpNode.setLadder(newVect);
                    list.enque(newVect);
                    }
                    diffs = 0;
                }
            }
        //}

    }
    //list.deque();*/

    bool done = false;
    DLinkedList list;
    vector<string> loopVect;
    vector<string> currentVect;
    loopVect.push_back(word1);
    currentVect.push_back(word1);
    ListNode* currentNode;
    int diffs = 0;
    vector<string> sameSize;

    list.enque(currentVect);
    currentNode = list.getListHead();
    for(int i = 0; i < m_dictionary.size(); i++){
        if(m_dictionary.at(i).length() == word1.length() + 1){
            sameSize.push_back(m_dictionary.at(i));
        }
    }
    while(!done){
        if(list.getSize() > 1){
            currentNode = list.next();
            currentVect = currentNode-> m_ladder;
        }
        //currentVect = *loopVect;

        for(int i = 0; i < sameSize.size(); i++){
            diffs = 0;
            //currentVect = loopVect;
            //if(loopVect.at(loopVect.size() - 1).length() + 1 == sameSize.at(i).length()){
                string tmp1 = currentVect.at(currentVect.size() - 1);
                string tmp2 = sameSize.at(i);
                tmp2 = tmp2.substr(0, tmp2.length() - 1);

                for(int j = 0; j < sameSize.at(i).length(); j++){
                    if(tmp1[j] != tmp2[j]){
                        diffs++;
                    }
                }
                if(diffs == 1){
                    if(tmp2 == word2){
                        currentVect.push_back(tmp2);
                        list.enque(currentVect);
                        currentVect.pop_back();
                        list.deque();
                        done = true;
                    }
                    else{
                    currentVect.push_back(tmp2);
                    list.enque(currentVect);
                    currentVect.pop_back();
                    }
                }

           // }
        }
    }
}
/*int main(){
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
