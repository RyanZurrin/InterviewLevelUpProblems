//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_BT_NODE_H
#define LEETCODE_BT_NODE_H
#include <vector>
#include <queue>
using namespace std;

class bt_node{

public:
    int data;
    bt_node*left;
    bt_node*right;

    explicit bt_node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }

    // find target
    bt_node* findTarget(bt_node* root, bt_node* target, int& levFromRoot) {
        if(root == nullptr) return nullptr;
        if(root->data == target->data) return root;
        bt_node* left = findTarget(root->left, target, levFromRoot);
        if(left != nullptr) {
            levFromRoot += 1;
            return left;
        }
        bt_node* right = findTarget(root->right, target, levFromRoot);
        if(right != nullptr) {
            levFromRoot += 1;
            return right;
        }
        return nullptr;
    }

    void nodesAtDistanceK(bt_node* root, int k, vector<int>& v) {
        // k + levFromRoot is the distance from root to targets
        if(root == nullptr) return;
        if(k == 0) {
            v.push_back(root->data);
            return;
        }
        nodesAtDistanceK(root->left, k - 1, v);
        nodesAtDistanceK(root->right, k - 1, v);
        // sort the vector
        sort(v.begin(), v.end());
    }

    vector<int> nodesAtDistanceK(bt_node *root, bt_node *target, int k){
        vector<int> v;
        int levFromRoot = 0;
        bt_node* node = findTarget(root, target, levFromRoot);
        int newK = k + levFromRoot;
        if(node == nullptr) return v;
        nodesAtDistanceK(root, newK, v);
        return v;
    }

    vector<int> leftView(bt_node * root){
        // visit all node in the left subtree

        vector<int> v;
        if(root == nullptr) return v;
        queue<bt_node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                bt_node* node = q.front();
                q.pop();
                if(i == 0) v.push_back(node->data);
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }
        return v;
    }
/**
 * Determine if a binary tree can be converted to another by doing any number of
 * swaps of children.
 * @param root1  root of first tree
 * @param root2  root of second tree
 * @return     true if trees can  be converted, false otherwise
 */
    bool equal(bt_node * root1, bt_node * root2){
        if(root1 == root2) return true;
        return (root1 && root2) && (root1->data == root2->data) &&
               (equal(root1->left, root2->left) && equal(root1->right, root2->right)) ||
               (equal(root1->right, root2->left) && equal(root1->left, root2->right));

    }


};

#endif //LEETCODE_BT_NODE_H
