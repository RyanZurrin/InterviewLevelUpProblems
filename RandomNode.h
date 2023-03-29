//
// Created by ryanz on 3/29/2023.
//

#ifndef LEETCODE_RANDOMNODE_H
#define LEETCODE_RANDOMNODE_H
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

struct RandomNode {
    int val;
    RandomNode *left;
    RandomNode *right;
    RandomNode *random;
    RandomNode() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    explicit RandomNode(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    RandomNode(int x, RandomNode *left, RandomNode *right, RandomNode *random) :
            val(x), left(left), right(right), random(random) {}
};

struct RandomNodeCopy {
    int val;
    RandomNodeCopy *left;
    RandomNodeCopy *right;
    RandomNodeCopy *random;
    RandomNodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    explicit RandomNodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    RandomNodeCopy(int x, RandomNodeCopy *left, RandomNodeCopy *right, RandomNodeCopy *random) :
            val(x), left(left), right(right), random(random) {}
};


#endif //LEETCODE_RANDOMNODE_H
