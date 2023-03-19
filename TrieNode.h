//
// Created by ryanz on 3/18/2023.
//

#ifndef LEETCODE_TRIENODE_H
#define LEETCODE_TRIENODE_H

#include <unordered_map>
using namespace std;

class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false) {}

};


#endif //LEETCODE_TRIENODE_H
