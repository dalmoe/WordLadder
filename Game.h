#ifndef GAME_H
#define GAME_H

#include "ListNode.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
//Creates object that plays the wordLadder game
class Game{
    public:
        //constructor
        Game();
        //creates game object using file as the file it uses for the dictionary
        Game(string file);
        //parses dictionary.txt and stores it in a vector
        void parseDict();
        //parses file as dictionary
        void parseDict(string file);
        //Creates a word ladder from word1 to word 2
        void play(string word1, string word2);
        //Creates a word ladder of 2 random words with the same length as word
        void play(string word);
    private:
        //holds every word in dictionary.txt
        vector<string> m_dictionary;
};

#endif // GAME_H
