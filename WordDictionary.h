//
// Created by ryanz on 3/18/2023.
//

#ifndef LEETCODE_WORDDICTIONARY_H
#define LEETCODE_WORDDICTIONARY_H

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

#include "TrieNode.h"


class WordDictionary {
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, TrieNode *node) {
        if (index == word.size()) {
            return node->isWord;
        }
        char c = word[index];
        if (c != '.') {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[c]);
        } else {
            for (auto &child : node->children) {
                if (searchHelper(word, index + 1, child.second)) {
                    return true;
                }
            }
            return false;
        }
    }

};


#endif //LEETCODE_WORDDICTIONARY_H
