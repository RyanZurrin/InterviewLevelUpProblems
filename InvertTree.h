//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_INVERTTREE_H
#define LEETCODE_INVERTTREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
            val(x), left(left), right(right) {}
};

class InvertTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

#endif //LEETCODE_INVERTTREE_H
