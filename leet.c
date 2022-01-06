//
// Created by Ryan.Zurrin001 on 12/12/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma ide diagnostic ignored "ConstantFunctionResult"
#pragma ide diagnostic ignored "OCDFAInspection"
#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct Node {
    __attribute__((unused)) int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

__attribute__((unused))
int maxPower(const char* s) {
    int max = 0;
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '0') {
            count = 0;
        } else {
            count++;
        }
        if (count > max) {
            max = count;
        }
        i++;
    }
    return max;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
__attribute__((unused))
int* sortedSquares(const int* nums, int numsSize, int* returnSize){
    int* result = malloc(sizeof(int) * numsSize);
    int i = 0;
    int j = numsSize - 1;
    int k = numsSize - 1;
    while (i <= j) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            result[k--] = nums[i] * nums[i];
            i++;
        } else {
            result[k--] = nums[j] * nums[j];
            j--;
        }
    }
    *returnSize = numsSize;
    return result;
}
// remove the elements from the back and add to front k times
__attribute__((unused))
void rotate(int* nums, int numsSize, int k){
    int* temp = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
}

__attribute__((unused))
char * intToRoman(int num){
    char* result = malloc(sizeof(char) * 10);
    int i = 0;
    while (num > 0) {
        if (num >= 1000) {
            result[i++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            result[i++] = 'C';
            result[i++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            result[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            result[i++] = 'C';
            result[i++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            result[i++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            result[i++] = 'X';
            result[i++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            result[i++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            result[i++] = 'X';
            result[i++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            result[i++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            result[i++] = 'I';
            result[i++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            result[i++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            result[i++] = 'I';
            result[i++] = 'V';
            num -= 4;
        } else if (num >= 1) {
            result[i++] = 'I';
            num -= 1;
        }
    }
    result[i] = '\0';
    return result;
}

__attribute__((unused))
void moveZeroes(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    while (i < numsSize) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
        i++;
    }
    while (j < numsSize) {
        nums[j++] = 0;
    }
}

int rangeSumBST(struct TreeNode* root, int low, int high){
    if (root == NULL) {
        return 0;
    }
    int sum = 0;
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }
    sum += rangeSumBST(root->left, low, high);
    sum += rangeSumBST(root->right, low, high);
    return sum;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
__attribute__((unused))
int* twoSum(const int* numbers, int numbersSize, int target, int* returnSize){
    int* result = malloc(sizeof(int) * 2);
    int i = 0;
    int j = numbersSize - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            result[0] = i + 1;
            result[1] = j + 1;
            break;
        } else if (numbers[i] + numbers[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    *returnSize = 2;
    return result;
}

__attribute__((unused))
void reverseString(char* s, int sSize){
    int i = 0;
    int j = sSize - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}


__attribute__((unused))
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

__attribute__((unused))
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* slow = dummy;
    struct ListNode* fast = dummy;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

__attribute__((unused))
int lengthOfLongestSubstring(char * s){
    int i = 0;
    int j = 0;
    int max = 0;
    int len = strlen(s);
    int* map = malloc(sizeof(int) * 256);
    memset(map, 0, sizeof(int) * 256);
    while (i < len && j < len) {
        if (map[s[j]] == 0) {
            map[s[j]] = 1;
            j++;
            max = max > j - i ? max : j - i;
        } else {
            map[s[i]] = 0;
            i++;
        }
    }
    return max;
}
/*
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise. In other words, return true if one of s1's permutations
 * is the substring of s2.
 */
__attribute__((unused))
bool checkInclusion(char * s1, char * s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }
    int* map = malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i++) {
        map[i] = 0;
    }
    for (int i = 0; i < len1; i++) {
        map[s1[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < len2) {
        if (map[s2[j]] > 0) {
            map[s2[j]]--;
            j++;
            if (j - i == len1) {
                return true;
            }
        } else {
            map[s2[i]]++;
            i++;
        }
    }
    return false;
}


int max(int dfs, int dfs1) {
    return dfs > dfs1 ? dfs : dfs1;
}

int dfs(int **pInt, int size, int *pInt1, int i, int j, int *pInt2) {
    if (i == size) {
        return 0;
    }
    if (j == size) {
        return 1;
    }
    if (pInt[i][j] != -1) {
        return pInt[i][j];
    }
    int res;
    if (pInt1[i] == pInt2[j]) {
        res = dfs(pInt, size, pInt1, i + 1, j + 1, pInt2) + 1;
    } else {
        res = max(dfs(pInt, size, pInt1, i + 1, j, pInt2), dfs(pInt, size, pInt1, i, j + 1, pInt2));
    }
    pInt[i][j] = res;
    return res;
}
/**
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 * The area of an island is the number of cells with a value 1 in the island.
 * @return the maximum area of an island in grid. If there is no island, return 0.
 */
__attribute__((unused))
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int** pInt = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        pInt[i] = malloc(sizeof(int) * gridColSize[i]);
        for (int j = 0; j < gridColSize[i]; j++) {
            pInt[i][j] = -1;
        }
    }
    int max = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                max = max > dfs(pInt, gridSize, gridColSize, i, j, grid[i]) ? max : dfs(pInt, gridSize, gridColSize, i, j, grid[i]);
            }
        }
    }
    return max;
}



/**
 * You are given two binary trees root1 and root2. Imagine that when you put
 * one of them to cover the other, some nodes of the two trees are overlapped
 * while the others are not. You need to merge the two trees into a new binary
 * tree. The merge rule is that if two nodes overlap, then sum node values up
 * as the new value of the merged node. Otherwise, the NOT null node will be
 * used as the node of the new tree.
 * @param root1
 * @param root2
 * @return the merged tree.
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (root1 == NULL) {
        return root2;
    }
    if (root2 == NULL) {
        return root1;
    }
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

/**
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * @return
 */
__attribute__((unused))
struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* cur = root;
    while (cur != NULL) {
        struct Node* head = cur;
        while (head != NULL) {
            if (head->left != NULL) {
                head->left->next = head->right;
            }
            if (head->right != NULL && head->next != NULL) {
                head->right->next = head->next->left;
            }
            head = head->next;
        }
        cur = cur->left;
    }
    return root;
}

// print binary from num
void printBinary(unsigned int num) {
    if (num == 0) {
        return;
    }
    printBinary(num / 2);
    printf("%d", num % 2);
}

// a bit reversal function
__attribute__((unused))
unsigned int reverseBits(unsigned int n) {
    unsigned int count = (INT_BITS - 1);
    unsigned int temp = n;
    n >>= 1;
    while (n) {
        temp <<= 1;
        temp |= n & 1;
        n >>= 1;
        count--;
    }
    temp <<= count;
    return temp;
}