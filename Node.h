//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H


class Node {
public:
    int val{};
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


#endif //LEETCODE_NODE_H
