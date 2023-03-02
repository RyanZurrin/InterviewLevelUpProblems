//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_BT_H
#define LEETCODE_BT_H
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "Pair.h"
using namespace std;


template <typename T>
class BTNode {
public:
    T data;
    BTNode<T> *left;
    BTNode<T> *right;
    BTNode() : data(0), left(nullptr), right(nullptr) {}
    explicit BTNode(T data) : data(data), left(nullptr), right(nullptr) {}
    T getData() {
        return data;
    }
    BTNode<T> *getLeft() {
        return left;
    }
    BTNode<T> *getRight() {
        return right;
    }
    void setLeft(BTNode<T> *left_) {
        this->left = left_;
    }
    void setRight(BTNode<T> *right_) {
        this->right = right_;
    }
};


template <typename T>
class BT {
public:
    BT() : root(nullptr) {}

    // buildTree from stdin
    BTNode<T> *buildTree() {
        T data;
        cin >> data;
        if (data == -1) {
            return nullptr;
        }
        auto *root_ = new BTNode<T>(data);
        root_->left = buildTree();
        root_->right = buildTree();
        return root_;
    }

    BTNode<T> *getRoot() {
        return root;
    }

    void setRoot(BTNode<T> *root_) {
        this->root = root_;
    }

    void insert(T data) {
        auto *newNode = new BTNode<T>(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        BTNode<T> *temp = root;
        while (true) {
            if (data < temp->getData()) {
                if (temp->getLeft() == nullptr) {
                    temp->setLeft(newNode);
                    return;
                }
                temp = temp->getLeft();
            } else {
                if (temp->getRight() == nullptr) {
                    temp->setRight(newNode);
                    return;
                }
                temp = temp->getRight();
            }
        }
    }
    // insert in level order
    void insertLevelOrder(T data) {
        auto *newNode = new BTNode<T>(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        queue<BTNode<T> *> q;
        q.push(root);
        while (!q.empty()) {
            auto *temp = q.front();
            q.pop();
            if (temp->getLeft() == nullptr) {
                temp->setLeft(newNode);
                return;
            } else {
                q.push(temp->getLeft());
            }
            if (temp->getRight() == nullptr) {
                temp->setRight(newNode);
                return;
            } else {
                q.push(temp->getRight());
            }
        }
    }
    //insert in pre order
    void insertPreOrder(T data) {
        auto *newNode = new BTNode<T>(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        stack<BTNode<T> *> s;
        s.push(root);
        while (!s.empty()) {
            auto *temp = s.top();
            s.pop();
            if (temp->getRight() == nullptr) {
                temp->setRight(newNode);
                return;
            } else {
                s.push(temp->getRight());
            }
            if (temp->getLeft() == nullptr) {
                temp->setLeft(newNode);
                return;
            } else {
                s.push(temp->getLeft());
            }
        }
    }
    //insert in post order
    void insertPostOrder(T data) {
        auto *newNode = new BTNode<T>(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        stack<BTNode<T> *> s;
        s.push(root);
        BTNode<T> *prev = nullptr;
        while (!s.empty()) {
            auto *temp = s.top();
            if ((temp->getLeft() == nullptr && temp->getRight() == nullptr) ||
                (prev != nullptr && (prev == temp->getLeft() || prev == temp->getRight()))) {
                s.pop();
                prev = temp;
                temp->setData(data);
                return;
            } else {
                if (temp->getRight() != nullptr) {
                    s.push(temp->getRight());
                }
                if (temp->getLeft() != nullptr) {
                    s.push(temp->getLeft());
                }
            }
        }
    }

    void inOrder(BTNode<T> *root_) {
        if (root_ == nullptr) {
            return;
        }
        inOrder(root_->getLeft());
        cout << root_->getData() << " ";
        inOrder(root_->getRight());
    }

    void preOrder(BTNode<T> *root_) {
        if (root_ == nullptr) {
            return;
        }
        cout << root_->getData() << " ";
        preOrder(root_->getLeft());
        preOrder(root_->getRight());
    }

    void postOrder(BTNode<T> *root_) {
        if (root_ == nullptr) {
            return;
        }
        postOrder(root_->getLeft());
        postOrder(root_->getRight());
        cout << root_->getData() << " ";
    }

    void levelOrder(BTNode<T> *root_) {
        if (root_ == nullptr) {
            return;
        }
        queue<BTNode<T> *> q;
        q.push(root_);
        q.push(nullptr);
        while (!q.empty()) {
            BTNode<T> *temp = q.front();
            if (temp == nullptr) {
                cout << endl;
                q.pop();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                q.pop();
                cout << temp->getData() << " ";
                if (temp->getLeft() != nullptr) {
                    q.push(temp->getLeft());
                }
                if (temp->getRight() != nullptr) {
                    q.push(temp->getRight());
                }
            }
        }
    }

    void deleteTree(BTNode<T> *root_) {
        if (root_ == nullptr) {
            return;
        }
        deleteTree(root_->getLeft());
        deleteTree(root_->getRight());
        delete root_;
    }

    Pair<T> maxSubsetSum(BTNode<T> * root_) {
        Pair<T> p;
        if (root_ == nullptr) {
            p.setInc(0);
            p.setExc(0);
            return p;
        }
        Pair<T> left = maxSubsetSum(root_->getLeft());
        Pair<T> right = maxSubsetSum(root_->getRight());
        p.setInc(root_->getData() + left.getExc() + right.getExc());
        p.setExc(max(left.getInc(), left.getExc()) + max(right.getInc(), right.getExc()));
        return p;
    }

    BTNode<T> *root;
};

#endif //LEETCODE_BT_H
