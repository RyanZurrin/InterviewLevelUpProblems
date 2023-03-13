//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_INVERTTREE_H
#define LEETCODE_INVERTTREE_H

#include "TreeNode.h"

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
