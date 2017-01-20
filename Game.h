#ifndef GAME_H
#define GAME_H

#include "ListNode.h"
#include "DLinkedList.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Game{
    public:
        //Game();

        void init();
        void parseDict();
        int main();
        void play(string word1, string word2);

    private:
        vector<string> m_dictionary;
};

#endif // GAME_H
