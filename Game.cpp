#include "Game.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>
#include "ListNode.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Constructor creates Game object and calls parseDict()
Game::Game(){
    parseDict();
}

Game::Game(string file){
    parseDict(file);
}

//Parses dictionary.txt stores each word in m_dictionary
void Game::parseDict(){
    string str;
    ifstream in("dictionary.txt");
    if(in.is_open()){
        //grabs each line of the file and stores them at the current end of the vector
        while(getline(in, str)){
            m_dictionary.push_back(str);
        }
    }
    else{
        cout << "Unable to open file." << endl;
    }
}

//parses file specified for the dictionary
void Game::parseDict(string file){
    string str;
    ifstream in(file.c_str());
    if(in.is_open()){
        //grabs each line of the file and stores them at the current end of the vector
        while(getline(in, str)){
            m_dictionary.push_back(str);
        }
    }
    else{
        cout << "Unable to open file." << endl;
    }
    in.close();
}

//builds a word ladder between word1 and word2
void Game::play(string word1, string word2){
    //determines whether or not to stay in while loop
    bool done = false;
    //Creates Doubly linked list
    DLinkedList list;
    //Holds vector of current word ladder
    vector<string> currentVect;
    //used to determine whether the first word has any matches
    int newWords = 0;
    
    //initializes variables
    currentVect.push_back(word1);
    ListNode* currentNode;
    int diffs = 0;
    vector<string> sameSize;
    
    //Makes sure input words are of the same length
    if(word1.length() != word2.length()){
        cout << "Word ladders can only be built with words of the same length." << endl << endl;
        return;
    }
    //Adds initial word to beginning of the list
    list.enque(currentVect);
    currentNode = list.getListHead();
    //creates a vector of only words the same size as word1 and word2
    for(int i = 0; i < m_dictionary.size(); i++){
        if(m_dictionary.at(i).length() == word1.length() + 1){
            sameSize.push_back(m_dictionary.at(i));
        }
    }
    //runs until word2 is found, or there are no more possible matches
    while(!done){
        //moves to the next node in the list if the list has more than just the initial node
        if(list.getSize() > 1){
            currentNode = list.next();
            //detects if there is no solution
            if(currentNode == NULL){
                cout << "No Solution"<< endl << endl;
                return;
            }
            //assigns currentVect to hold the ladder of the current node in the list
            currentVect = currentNode-> m_ladder;
        }
        
        //checks last word in the current vector against all words in the vector of same-length words
        for(int i = 0; i < sameSize.size(); i++){
            //checks to see if word that was originally at this location has been used
            if(sameSize.at(i) != ""){
                //number of differences between the words being compared
                diffs = 0;
                string tmp1 = currentVect.at(currentVect.size() - 1);
                string tmp2 = sameSize.at(i);
                tmp2 = tmp2.substr(0, tmp2.length() - 1);
                
                //compares tmp1 and tmp2
                for(int j = 0; j < sameSize.at(i).length(); j++){
                    if(tmp1[j] != tmp2[j]){
                        diffs++;
                    }
                }
                //Executes if the words were only 1 letter apart
                if(diffs == 1){
                    //if tmp2 = word2 add the current ladder to the list, print out that ladder, and exit while loop
                    if(tmp2 == word2){
                        currentVect.push_back(tmp2);
                        list.enque(currentVect);
                        currentVect.pop_back();
                        cout << "Starting word: " << word1 << endl;
                        cout << "Ending word: " << word2 << endl;
                        cout << "Ladder: " << endl;
                        list.deque();
                        cout << endl << endl;
                        done = true;
                    }
                    //adds current ladder to the end of linked list
                    else{
                    currentVect.push_back(tmp2);
                    list.enque(currentVect);
                    currentVect.pop_back();
                    sameSize.at(i) = "";
                    newWords++;
                    }
                }
            }
        }
        //checks if the initial word has any matches
        if(newWords == 0){
            cout << "No words exist for " << word1 <<"." << endl << endl;
            return;
        }
    }
}