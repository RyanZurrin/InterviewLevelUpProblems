//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_SOLUTIONS_H
#define LEETCODE_SOLUTIONS_H
#include<bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
#include <climits>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <stack>
#include <unordered_set>
#include "InvertTree.h"
#include "Node.h"
#include "LinkedList.h"
#include "bt_node.h"
#include "t_node.h"
#include "sll_node.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "BT.h"
#include "t_BST.h"
#include "SudokuSolver.h"
#include "WordDictionary.h"
#include "Graph.h"
#include "RandomNode.h"
#include "ParkingSystem.h"
#include "TicTacToe.h"


// A macro that defines the size of an integer
#define INT_SIZE sizeof(int) * 8
using namespace std;


class Solutions {
public:
    static string keypad[];
    // add smart pointers to all the classes that need to be accessed
    // from main.cpp

    template<typename T>
    static void printVector(vector<T> &v) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    template<typename T>
    static void printVector(vector<vector<T>> &v) {
        for (auto &i : v) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


public:
    Solutions() = default;
    ~Solutions() = default;

    /**
     * 1. Two Sum
     * @brief Given an array of integers numbers and an integer target,
     * return indices of the two numbers such that they add up to target.
     * @param numbers  The numbers array
     * @param target    The target number
     * @return  The indices of the two numbers such that they add up to target
     */
    static vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }

    /**
     * 2. Add Two Numbers
     * @brief Given two non-empty linked lists representing two non-negative integers.
     * The digits are stored in reverse order, and each of their nodes contains
     * a single digit. Add the two numbers and return the sum as a linked list.
     * You may assume the two numbers do not contain any leading zero, except
     * the number 0 itself.
     * @param l1 linked list 1
     * @param l2 linked list 2
     * @return sum of the two linked lists
     */
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto *result = new ListNode();
        ListNode *curr = result;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return result->next;
    }


    static int absDifference(int a, int b) {
        return abs(a - b);
    }

    /**
     * given a stream of characters (lowercase alphabets), find the first non-repeating
     * character from stream. you need to tell the first non-repeating character in O(1)
     * time at each index. if for a current index there is no such character return '0'
     * for that particular index.
     * @param S  a string of length N  containing lowercase alphabets
     * @return a vector of characters of length N where V[i] character represents first
     * non-repeating character from S[0] to S[i]
     */
    static vector<char> FindFirstNonRepeatingCharacter(const string& S){
        queue<char> q;
        vector<char> result;
        int freq[26] = {0};
        int index;
        for (char ch : S) {
            q.push(ch);
            freq[ch - 'a']++;
            while (!q.empty()) {
                index = q.front() - 'a';
                if (freq[index] > 1) {
                    q.pop();
                } else {
                    result.push_back(q.front());
                    break;
                }
            }
            if (q.empty()) {
                result.push_back('0');
            }
        }
        return result;
    }

    /**
     * Given two sorted arrays nums1 and nums2 of size m and n respectively,
     * return the median of the two sorted arrays.
     * The overall run time complexity should be O(log (m+n))
     * @param nums1 the first sorted array
     * @param nums2 the second sorted array
     * @return the median of the two sorted arrays
     */
    static double findMedianSortedArrays(
            std::vector<int>& nums1, std::vector<int>& nums2) {
        auto m = nums1.size();
        auto n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        size_t min = 0, max = m;
        while (min <= max) {
            size_t i = (min + max) / 2;
            size_t j = (m + n + 1) / 2 - i;
            if (i < max && nums2[j - 1] > nums1[i]) {
                min = i + 1;
            } else if (i > min && nums1[i - 1] > nums2[j]) {
                max = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = std::min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    static int expandAroundCenter(string basicString, int i, int i1) {
        int left = i, right = i1;
        while (left >= 0 && right < basicString.length() &&
               basicString[left] == basicString[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    static string longestPalindrome(const string& s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    static int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    static bool isBadVersion(int version) {
        return version >= 1702766719;
    }

    static int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    static int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    static int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(maxArea, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }

    static int maxPower(string s) {
        int max = 0;
        int cur = 1;
        for(int i = (int)s.size()-1; i > 0; i--) {
            if(s[i] == s[i - 1]) {
                cur++;
            } else {
                max = std::max(max, cur);
                cur = 1;
            }
        }
        return std::max(max, cur);
    }

    static vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        unsigned long left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                res.push_back(nums[left] * nums[left]);
                left++;
            } else {
                res.push_back(nums[right] * nums[right]);
                right--;
            }
        }
        vector<int> ans;
        for (size_t i = res.size() - 1; i >= 0; i--) {
            ans.push_back(res[i]);
        }
        return ans;
    }

    static void rotate(vector<int>& nums, size_t k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    static string intToRoman(int num) {
        string res;
        int cur = 0;
        while (num > 0) {
            if (num >= 1000) {
                res += "M";
                num -= 1000;
            } else if (num >= 900) {
                res += "CM";
                num -= 900;
            } else if (num >= 500) {
                res += "D";
                num -= 500;
            } else if (num >= 400) {
                res += "CD";
                num -= 400;
            } else if (num >= 100) {
                res += "C";
                num -= 100;
            } else if (num >= 90) {
                res += "XC";
                num -= 90;
            } else if (num >= 50) {
                res += "L";
                num -= 50;
            } else if (num >= 40) {
                res += "XL";
                num -= 40;
            } else if (num >= 10) {
                res += "X";
                num -= 10;
            } else if (num >= 9) {
                res += "IX";
                num -= 9;
            } else if (num >= 5) {
                res += "V";
                num -= 5;
            } else if (num >= 4) {
                res += "IV";
                num -= 4;
            } else if (num >= 1) {
                res += "I";
                num -= 1;
            }
            cur++;
        }
        return res;
    }

    static void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] == 0) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }

    static int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
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


    static void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    static void reverseString(string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    //method to print out the contents of a vector
    template <typename T>
    static void printVector(vector<T> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    static string reverseLettersInEachWord(const string& s) {
        vector<string> words;
        string res;
        string temp;
        for (char i : s) {
            if (i == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += i;
            }
        }
        words.push_back(temp);
        for (int i = 0; i < words.size(); i++) {
            temp = words[i];
            reverseString(temp);
            res += temp;
            if (i != words.size() - 1) {
                res += " ";
            }
        }
        cout << res << endl;
        return res;
    }


    static vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if (n == 1 && edges.empty()) {
            vector<int> res;
            res.push_back(0);
            return res;
        }
        for (auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int cur : leaves) {
                for (int j = 0; j < adj[cur].size(); j++) {
                    int neighbor = adj[cur][j];
                    adj[neighbor].erase(find(adj[neighbor].begin(), adj[neighbor].end(), cur));
                    if (adj[neighbor].size() == 1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }

    static int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int res = 0;
        int min = arrays[0][0];
        int max = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < n; i++) {
            res = max - min > res ? max - min : res;
            min = min > arrays[i][0] ? arrays[i][0] : min;
            max = max < arrays[i][arrays[i].size() - 1] ? arrays[i][arrays[i].size() - 1] : max;
        }
        return res;
    }

    static int lengthOfLongestSubstring(string s) {
        auto n = s.size();
        int res = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        while (right < n) {
            if (map.find(s[right]) != map.end()) {
                left = max(map[s[right]], left);
            }
            map[s[right]] = right + 1;
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }

    /**
     * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
     * or false otherwise. In other words, return true if one of s1's permutations
     * is the substring of s2.
     */
    static bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        vector<int> count(128, 0);
        for (int i = 0; i < n1; i++) {
            count[s1[i]]++;
        }
        for (int i = 0; i <= n2 - n1; i++) {
            vector<int> temp(128, 0);
            for (int j = 0; j < n1; j++) {
                temp[s2[i + j]]++;
            }
            if (temp == count) {
                return true;
            }
        }
        return false;
    }

    /**
     * An image is represented by an m x n integer grid image where image[i][j] represents
     * the pixel value of the image. You are also given three integers sr, sc, and newColor.
     * You should perform a flood fill on the image starting from the pixel image[sr][sc].
     * To perform a flood fill, consider the starting pixel, plus any pixels connected
     * 4-directionally to the starting pixel of the same color as the starting pixel,
     * plus any pixels connected 4-directionally to those pixels (also with the same color),
     * and so on. Replace the color of all of the aforementioned pixels with newColor.
     * @param image
     * @param sr
     * @param sc
     * @param newColor
     * @return the modified image after performing the flood fill.
     */
    static vector<vector<int>> floodFill(vector<vector<int>>& image, int sr,
                                         int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (image[r][c] == color) {
                image[r][c] = newColor;
                if (r - 1 >= 0 && image[r - 1][c] == color) {
                    q.emplace(r - 1, c);
                }
                if (r + 1 < n && image[r + 1][c] == color) {
                    q.emplace(r + 1, c);
                }
                if (c - 1 >= 0 && image[r][c - 1] == color) {
                    q.emplace(r, c - 1);
                }
                if (c + 1 < m && image[r][c + 1] == color) {
                    q.emplace(r, c + 1);
                }
            }
        }
        return image;
    }

    /**
     *  Prooblem 438. Find All Anagrams in a String
     *
     *   Given two strings s and p, return an array of all the start indices of p's
     *   anagrams in s. You may return the answer in any order.
     *
     *   An Anagram is a word or phrase formed by rearranging the letters of a
     *   different word or phrase, typically using all the original letters exactly once.
     *
     *   Example 1:
     *   Input: s = "cbaebabacd", p = "abc"
    Output: [0,6]
    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
     *
     * @param s:
     * @param p
     * @return
     */
    static vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> res;
        if (n < m) {
            return res;
        }
        vector<int> count(128, 0);
        for (int i = 0; i < m; i++) {
            count[p[i]]++;
        }
        for (int i = 0; i <= n - m; i++) {
            vector<int> temp(128, 0);
            for (int j = 0; j < m; j++) {
                temp[s[i + j]]++;
            }
            if (temp == count) {
                res.push_back(i);
            }
        }
        return res;
    }


    /**
     * 695. You are given an m x n binary matrix grid. An island is a group of
     * 1's (representing land) connected 4-directionally
     * (horizontal or vertical.) You may assume all four edges of the grid
     * are surrounded by water.
     * The area of an island is the number of cells with a value 1 in the island.
     * @return the maximum area of an island in grid. If there is no island, return 0.
     */
    static int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if (grid[r][c] == 1) {
                            grid[r][c] = 0;
                            area++;
                            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                                q.push(make_pair(r - 1, c));
                            }
                            if (r + 1 < n && grid[r + 1][c] == 1) {
                                q.push(make_pair(r + 1, c));
                            }
                            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                                q.push(make_pair(r, c - 1));
                            }
                            if (c + 1 < m && grid[r][c + 1] == 1) {
                                q.push(make_pair(r, c + 1));
                            }
                        }
                    }
                    res = max(res, area);
                }
            }
        }
        return res;
    }

    /**
     * 617. Merge Two Binary Trees
     * You are given two binary trees root1 and root2. Imagine that when you put
     * one of them to cover the other, some nodes of the two trees are overlapped
     * while the others are not. You need to merge the two trees into a new binary
     * tree. The merge rule is that if two nodes overlap, then sum node values up
     * as the new value of the merged node. Otherwise, the NOT nullptr node will be
     * used as the node of the new tree.
     * @param root1
     * @param root2
     * @return the merged tree.
     */
    static TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

    /**
     * Given the root of a binary tree, check whether it is a mirror of
     * itself (i.e, symmetric around its center)
     * @param root the root of the binary tree
     * @return bool: true if the BT is symmetric and false if it is not
     */
    static bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    /**
     * Helper function for isSymmetric
     * @param left
     * @param right
     * @return bool: true if the BT is symmetric and false if it is not
     */
     static bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    /**
     * Populate each next pointer to point to its next right node. If there is no
     * next right node, the next pointer should be set to nullptr.
     * Initially, all next pointers are set to nullptr.
     * @return
     */
    static Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* cur = q.front();
                q.pop();
                if (i < n - 1) {
                    cur->next = q.front();
                }
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
    /**
     * Given an m x n binary matrix mat, return the distance of the nearest 0 for
     * each cell. The distance between two adjacent cells is 1.
     * @param mat
     * @return
     */
    static vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                } else {
                    res[i][j] = min(res[i - 1][j], res[i][j - 1]) + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                } else {
                    res[i][j] = min(res[i][j], min(res[i + 1][j], res[i][j + 1])) + 1;
                }
            }
        }
        return res;
    }

    /**
     * You are given an m x n grid where each cell can have one of three values:
     * 0 representing an empty cell,
     * 1 representing a fresh orange, or
     * 2 representing a rotten orange.
     * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
     * orange becomes rotten.
     * @param grid
     * @return the minimum number of minutes that must elapse until no cell has a
     * fresh orange. If this is impossible, return -1.
     */
    static int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        int res = 0;
        while (!q.empty()) {
            int n_ = q.size();
            for (int i = 0; i < n_; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push(make_pair(r - 1, c));
                }
                if (r + 1 < n_ && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push(make_pair(r + 1, c));
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push(make_pair(r, c - 1));
                }
                if (c + 1 < m && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push(make_pair(r, c + 1));
                }
            }
            res++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }

    /**
     * Given an array of distinct integers arr, find all pairs of elements with the
     * minimum absolute difference of any two elements.
     * Return a list of pairs in ascending order(with respect to pairs), each pair
     * [a, b] follows
     * a, b are from arr
     * a < b
     * b - a equals to the minimum absolute difference of any two elements in arr
     * @param arr
     * @return  a list of pairs in ascending order(with respect to pairs)
     */
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, absDifference(arr[i], arr[i + 1]));
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            if (absDifference(arr[i], arr[i + 1]) == minDiff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }

    /**
     * print binary representation of a given number
     * @param n is the number whose binary representation will be printed
     */
    static void printBinary(unsigned int  n) {
        cout << n << " in binary is " << bitset<32>(n) << endl;
    }

    /**
     * reverse bits of a given number
     * @param n is the number whose bits will be reversed
     * @return the reversed number
     */
    static int reverseBits(int n){
        int pos = INT_SIZE - 1;     // maintains shift
        // store reversed bits of `n`. Initially, all bits are set to 0
        int reverse = 0;
        // do till all bits are processed
        while (pos >= 0 && n)    {
            // if the current bit is 1, then set the corresponding bit in the result
            if (n & 1) {
                reverse = reverse | (1 << pos);
            }
            n >>= 1;                // drop current bit (divide by 2)
            pos--;                  // decrement shift by 1
        }
        return reverse;
    }

    /**
     * classic fizzbuzz problem
     * @param n  is the number of elements in the result
     * @return  a vector of strings where each element is either "Fizz", "Buzz", "FizzBuzz" or the number
     */
    static vector<string> fizzbuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.emplace_back("FizzBuzz");
            } else if (i % 3 == 0) {
                res.emplace_back("Fizz");
            } else if (i % 5 == 0) {
                res.emplace_back("Buzz");
            } else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }

    /**
     *  finds the longest sequence of consecutive numbers in an array such as 1, 2, 3, 4, 5
     *  which would be a band of length 5. The sequence can start from any index in the array.
     *  and it must run in O(n) time.
     * @param arr  is the array of numbers
     * @return  the length of the longest band
     */
    static int longestBand(vector<int>& arr) {
        int steps = 0;
        // add array to unordered set
        unordered_set<int> set;
        for (auto i : arr) {
            set.insert(i);
        }
        int max = 1;
        for(auto i : set) {
            int parent = i - 1;
            int count = 1;
            while (set.find(parent) != set.end()) {
                count++;
                parent--;
                steps++;
            }
            max = max > count ? max : count;

            steps++;
        }
        cout << "steps: " << steps << endl;
        return max;
    }

    /**
     * trapped water problem find the amount of water that can be trapped between the bars
     * @param heights the heights of the bars
     * @return  the area of water that can be trapped
     */
    static int trappedWater(vector<int> heights) {
        int left = 0;
        int right = heights.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while (left < right) {
            if (heights[left] < heights[right]) {
                if (heights[left] > leftMax) {
                    leftMax = heights[left];
                } else {
                    water += leftMax - heights[left];
                }
                left++;
            } else {
                if (heights[right] > rightMax) {
                    rightMax = heights[right];
                } else {
                    water += rightMax - heights[right];
                }
                right--;
            }
        }
        return water;
    }


    static bool outOfOrder(vector<int>& arr, int i) {
        if (i == 0) {
            return arr[i] > arr[i + 1];
        } else if (i == arr.size() - 1) {
            return arr[i] < arr[i - 1];
        } else {
            return arr[i] < arr[i - 1] || arr[i] > arr[i + 1];
        }
    }

    static pair<int, int> subArraySort(vector<int> arr) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            if (outOfOrder(arr, i)) {
                smallest = min(smallest, x);
                largest = max(largest, x);
            }
        }
        if (smallest == INT_MAX) {
            return {-1, -1};
        }
        int start = 0;
        int end = arr.size() - 1;
        while (arr[start] < smallest) {
            start++;
        }
        while (arr[end] > largest) {
            end--;
        }
        return {start, end};

    }

    static int countMinSwaps(vector<int> arr) {
        int n = arr.size();
        int ans = 0;
        pair<int, int> ap[n];
        for (int i = 0; i < n; i++) {
            ap[i].first = arr[i];
            ap[i].second = i;
        }

        sort(ap, ap + n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            int old_pos = ap[i].second;
            if (visited[old_pos]) {
                continue;
            }
            int node = i;
            int cycle_size = 0;
            while (!visited[node]) {
                visited[node] = true;
                node = ap[node].second;
                cycle_size++;
            }
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

    static int maxSubarraySum(vector<int> arr){
        //Complete this function, your function should return the maximum subarray sum
        int n = arr.size();
        int max = INT_MIN;
        int max_end = 0;
        for (int i = 0; i < n; i++) {
            max_end = max_end + arr[i];
            if (max_end < 0) {
                max_end = 0;
            }
            if (max < max_end) {
                max = max_end;
            }
        }
        return max;
    }

    static pair<int,int> minDifference(vector<int> a,vector<int> b){
        //Complete this method
        int n = a.size();
        int m = b.size();
        int min_diff = INT_MAX;
        int min_a = INT_MAX;
        int min_b = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = abs(a[i] - b[j]);
                if (diff < min_diff) {
                    min_diff = diff;
                    min_a = a[i];
                    min_b = b[j];
                }
            }
        }
        return {min_a, min_b};
    }

    static vector<int> productArray(vector<int> arr){
        //Create an output Array
        int n = arr.size();
        vector<int> output(n,1);
        for (int i = 0; i < arr.size(); i++) {
            int index = arr.size() - 1;
            while(index >= 0) {
                if (index != i) {
                    output[i] *= arr[index];
                }
                index--;
            }
        }
        return output;
    }

    /**
     * computes how many of the given activities can be done on the given day.
     * each pair represents the start and end time of an activity.
     * @param activities a vector of pairs representing the start and end time of an activity.
     * @return the number of activities that can be done on the given day.
     */
    static int countActivities(vector<pair<int,int> > activities){
        // Complete this method
        // sort the activities by start time
        sort(activities.begin(), activities.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });
        int count = 1;
        int finish = activities[0].second;

        for(int i = 1; i < activities.size(); i++){
            if(activities[i].first >= finish){
                count++;
                finish = activities[i].second;
            }
        }
        return count;
    }

    // find all starting indices of each substring small that is within the given string large.
    // and return the starting indices in a vector. uses the find method.
    static vector<int> stringSearch(const string& big,const string& small){
        //store the occurrences in the result vector
        vector<int> result = {};
        int curr_index = 0;
        for(int i = 0; i < big.size(); i++){
            curr_index = big.find(small,curr_index);
            if(curr_index != string::npos){
                result.push_back(curr_index);
                curr_index++;
            }
        }
        return result;
    }

    // write a function that replaces all the spaces in a string with '%20'.
    static string urlify(char* str){
        // Complete this method
        string result;
        auto len = strlen(str);
        for(int i = 0; i < len; i++){
            if(str[i] == ' '){
                result += "%20";
            }else{
                result += str[i];
            }
        }
        return result;
    }

    static void printTokenizedString(){
        string input;
        cout << "Enter a string: ";
        getline(cin,input);
        stringstream ss(input);
        string token;
        vector<string> tokens;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
        }

        for(const auto& t : tokens){
            cout << t << ", ";
        }
        cout << endl;
    }

    static void printTokenizedString_strtok() {
        string input;
        cout << "Enter a string: ";
        getline(cin, input);
        char* str = new char[input.length() + 1];
        strcpy(str, input.c_str());
        char* token = strtok(str, " ");
        while (token != nullptr) {
            cout << token << ", ";
            token = strtok(nullptr, " ");
        }
        cout << endl;
    }

    static char* my_strtok(char* str, char delim) {
        static char* ptr = nullptr;
        if (str != nullptr) {
            ptr = str;
        }
        if (ptr == nullptr) {
            return nullptr;
        }
        char* token = new char[strlen(ptr) + 1];
        int i = 0;
        for (;str[i] != '\0'; i++) {
            if (str[i] != delim) {
                token[i] = str[i];
            } else {
                token[i] = '\0';
                ptr = ptr + i + 1;
                return token;
            }
        }
        token[i] = '\0';
        ptr = nullptr;
        return token;
    }
    
    static int convertToInt(string s) {
        int ans = 0;
        int p = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            ans += (s[i] - '0') * p;
            p *= 10;
        }
        return ans;
    }

    static bool lexicoCompare(const pair<string,string>& s1, const pair<string,string>& s2){
        string key1 = s1.second;
        string key2 = s2.second;
        return key1 < key2;
    }

    static bool numericCompare(const pair<string,string>& s1, const pair<string,string>& s2){
        string key1 = s1.second;
        string key2 = s2.second;
        return convertToInt(key1) < convertToInt(key2);
    }

    static string extractStringAtKey(const string& str, int key) {
        char *s = strtok((char *)str.c_str(), " ");
        while(key > 1) {
            s = strtok(nullptr, " ");
            key--;
        }
        return s;
    }

    /**
     * sort by key, takes input from stdin where the first value is the length
     * and the remaining pairs are key, value pairs.
     *
     * sample input:
     * 3
     * 92 022
     * 82 12
     * 77 13
     * sample output:
     * 82 12
     * 77 13
     * 92 022
     *
     * @param vp vector of pairs
     * @return  sorted vector of pairs
     */
    static vector<pair<string, string>> sortByKey() {
        int n;
        cin >> n;
        cin.get();

        string temp;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            v.push_back(temp);
        }
        int key;
        string reversal, ordering;
        cin >> key >> reversal >> ordering;
        cin.get();
        vector<pair<string, string>> vp;
        vp.reserve(n);
        for (int i = 0; i < n; i++) {
            vp.emplace_back(v[i], extractStringAtKey(v[i], key));
        }
        if (ordering == "numeric") {
            sort(vp.begin(), vp.end(), numericCompare);
        } else {
            sort(vp.begin(), vp.end(), lexicoCompare);
        }
        if (reversal == "true") {
            reverse(vp.begin(), vp.end());
        }
        for (int i = 0; i < n; i++) {
            cout << vp[i].first << endl;
        }
        return vp;
    }

    static bool isSubset(string s1, string s2) {
        auto i = s1.length() - 1;
        auto j = s2.length() - 1;
        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                i--;
            }
        }
        if (j == -1) {
            return true;
        } else {
            return false;
        }
    }

    static void subsequences(string s, const string& o, vector<string>& v) {
        if (s.length() == 0) {
            v.push_back(o);
            return;
        }
        subsequences(s.substr(1), o + s[0], v);
        subsequences(s.substr(1), o, v);
        // sort by length and then lexicographically
        sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
            if (s1.length() == s2.length()) {
                return s1 < s2;
            } else {
                return s1.length() < s2.length();
            }
        });
    }

    // has a leading 0 on hours if it is less than 10
    static string convert_to_digital_time(int minutes){
        //complete this function
        int hours = minutes / 60;
        int minute = minutes % 60;
        string ans;
        if(hours < 10){
            ans += "0";
        }
        ans += to_string(hours) + ":";
        if(minute < 10){
            ans += "0";
        }
        ans += to_string(minute);
        return ans;
    }

    // concatenate the two numbers in such a way that forms the largest number
    static string concatenate(vector<int> numbers){
        //complete this method and return the largest number you can form as a string
        string ans;
        // sort by largest first digit and if same use the one with fewer digits
        // and then lexicographically
        string s[numbers.size()];
        for(int i = 0; i < numbers.size(); i++){
            s[i] = to_string(numbers[i]);
        }
        sort(s, s + numbers.size(), [](string s1, string s2) {
            if(s1[0] == s2[0]){
                if (s1.length() == s2.length() && s1.length() > 1) {
                    return s1[1] > s2[1];
                } else {
                    return s1.length() < s2.length();
                }
                return s1.length() < s2.length();
            }
            return s1[0] > s2[0];
        });
        for(int i = 0; i < numbers.size(); i++){
            ans += s[i];
        }

        return ans;
    }

    //str is the input the string to compress using run length encoding
    static string compressString(const string &str){
        //complete the function to return output string
        string ans;
        int count = 1;
        for(int i = 0; i < str.length(); i++){
            if(i == str.length() - 1){
                ans += str[i];
                ans += to_string(count);
            }
            else if(str[i] == str[i+1]){
                count++;
            }
            else{
                ans += str[i];
                ans += to_string(count);
                count = 1;
            }
        }
        if(ans.length() >= str.length()){
            return str;
        }
        return ans;
    }

    /**
     * @brief checks if a string is a palindrome, removing all non-alphanumeric
     * characters and converting to lowercase.
     * @param basicString  string to check
     * @return  true if palindrome, false otherwise
     */
    static bool isPalindrome(string basicString) {
        // remove all non-alphanumeric characters and convert to lowercase
        basicString.erase(remove_if(basicString.begin(), basicString.end(), [](char c) {
            return !isalnum(c);
        }), basicString.end());
        transform(basicString.begin(), basicString.end(), basicString.begin(), ::tolower);
        if (basicString.length() == 1) {
            return true;
        }
        if (basicString.length() == 2) {
            return basicString[0] == basicString[1];
        }
        int i = 0;
        int j = basicString.length() - 1;
        while (i < j) {
            if (basicString[i] != basicString[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // replace one character in the palindrome with another character in a way that is
    // lexicographically smallest
    static string breakPalindrome(string palindrome) {
        //complete this method and return the smallest string you can form
        if (palindrome.length() == 1) {
            return "";
        }
        int i = 0;
        if (palindrome[0] != 'a') {
            palindrome[0] = 'a';
        } else {
            while (palindrome[i] == 'a') {
                i++;
            }
            char temp = palindrome[i];
            palindrome[i] = 'a';
            if (isPalindrome(palindrome)) {
                palindrome[i] = temp;
                palindrome[i + 1] = 'b';
            }
        }
        return palindrome;
    }


    // given a sentence, return the sentence with the words so only the first letter
    // of each word is capitalized and the rest are lowercase.
    static string normalize(const string &sentence) {
        string copy = sentence;
        //Make the changes in copy, and return it
        // turn all the letters to lowercase except the first letter of each word
        for (char & i : copy) {
            if (i >= 'A' && i <= 'Z') {
                i += 32;
            }
        }
        // turn the first letter of each word to uppercase by looking for the word
        // after each last blank space
        int i = 0;
        if (copy[0] >= 'a' && copy[0] <= 'z') {
            copy[0] -= 32;
        }
        while (i < copy.length()) {
            if (copy[i] == ' ') {
                i++;
                while (copy[i] == ' ') {
                    i++;
                }
                if (copy[i] >= 'a' && copy[i] <= 'z') {
                    copy[i] -= 32;
                }
            }
            i++;
        }
        return copy;
    }

    static void housing(const int* arr, int n, int k) {
        //complete this method
        int i = 0;
        int j = 0;
        int cs = 0;
        while(j<n) {
            cs+=arr[j];
            j++;
            while(cs > k && i < j) {
                cs-=arr[i];
                i++;
            }
            if(cs == k) {
                cout << i << " - " << j-1 << endl;
            }
        }
    }

    static string unique_substring(string str) {
        //complete this method
        int i = 0;
        int j = 0;
        int window_length = 0;
        int max_window_length = 0;
        int start_window = -1;
        unordered_map<char, int> m;
        while(j < str.length()) {
            char ch = str[j];
            if(m.count(ch) && m[ch] >= i) {
                i = m[ch] + 1;
                window_length = j - i;
            }
            m[ch] = j;
            window_length++;
            j++;
            // update max_window_length
            if(window_length > max_window_length) {
                max_window_length = window_length;
                start_window = i;
            }
        }
        return str.substr(start_window, max_window_length);
    }

    static string find_window(string s, const string& p) {
        int FP[256] = {0};
        int FS[256] = {0};
        int count = 0;
        int start = 0;
        int start_index = -1;
        int min_so_far = INT_MAX;
        int window_size = 0;
        for (char i : p) {
            FP[i]++;
        }

        // sliding window algorithm
        for(int i = 0; i < s.length(); i++) {
            // expand the window
            char ch = s[i];
            FS[ch]++;
            // count how many characters in the pattern are matched
            if (FP[ch] != 0 && FS[ch] <= FP[ch]) {
                count++;
            }
            // if all the characters in the pattern are matched, then start to
            // shrink the window
            if (count == p.length()) {
                // start contracting from the left to remove unwanted characters
                while (FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]) {
                    FS[s[start]]--;
                    start++;
                }

                // note the window size
                window_size = i - start + 1;
                // if the window size is the largest so far, then update the
                // start and window size
                if (window_size < min_so_far) {
                    min_so_far = window_size;
                    start_index = start;
                }
            }
        }
        if (start_index == -1) {
            return "";
        }
        return s.substr(start_index, min_so_far);
    }

    static string smallest_window(string str){
        //Complete this method
        int i = 0;
        int j = 0;
        int window_length = 0;
        int max_window_length = 0;
        int start_window = -1;
        if (str.length() == 0) {
            return "";
        }
        unordered_map<char, int> m;
        while(j < str.length()) {
            char ch = str[j];
            if(m.count(ch) && m[ch] >= i) {
                i = m[ch] + 1;
                window_length = j - i;
            }
            m[ch] = j;
            window_length++;
            j++;
            // update max_window_length
            if(window_length > max_window_length) {
                max_window_length = window_length;
                start_window = i;
            }
        }
        return str.substr(start_window, max_window_length);
    }

    static vector<int> maxInWindow(vector<int> input,int k){
        //complete this method
        vector<int> result;
        if (input.empty() || k == 0) {
            return result;
        }
        // looks at every k elements sliding over one by one and finds the max of
        // the k elements in each move adding it to the result vector, using a deque
        deque<int> dq;
        for (int i = 0; i < input.size(); ++i) {
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while (!dq.empty() && input[dq.back()] < input[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(input[dq.front()]);
            }
        }
        return result;
    }

    // given an unsorted array of integers, find the number of sub-arrays having a sum
    // exactly equal to the given number k. Use a HashMap.
    static int cnt_sub_arrays(const vector<int>& arr,int k){
        //complete this method
        unordered_map<int, int> m;
        int sum = 0;
        int count = 0;
        for (int i : arr) {
            sum += i;
            if (sum == k) {
                count++;
            }
            if (m.count(sum - k)) {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }

    template <typename T>
    static void merge(vector<T> &arr, int l, int r) {
        int mid = l + (r - l) / 2;
        int i = l;
        int j = mid + 1;
        int k = l;
        vector<T> temp(arr.size());
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (i = l; i <= r; ++i) {
            arr[i] = temp[i];
        }
    }


    template <typename T>
    static void mergesort(vector<T>& arr, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, high);
    }

    template <typename T>
    static int inversion_count(vector<T> &arr, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = (l + r) / 2;
        int left_count = inversion_count(arr, l, mid);
        int right_count = inversion_count(arr, mid + 1, r);
        int count = left_count + right_count;
        int i = l;
        int j = mid + 1;
        int k = l;
        vector<T> temp(arr.size());
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += mid - i + 1;
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (i = l; i <= r; ++i) {
            arr[i] = temp[i];
        }
        return count;
    }

    template<typename T>
    static int partition(vector<T> &arr, int l, int r) {
        int i = l;
        int j = r;
        T pivot = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= pivot) {
                j--;
            }
            arr[i] = arr[j];
            while (i < j && arr[i] <= pivot) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = pivot;
        return i;
    }

    template <typename T>
    static void quicksort(vector<T>& arr, int low, int high) {
        if (low >= high) {
            return;
        }
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }

    template <typename T>
    static T quick_select(vector<T>& arr,int start, int end, int k) {
        if (start == end) {
            return arr[start];
        }
        int pivot = partition(arr, start, end);
        if (pivot == k) {
            return arr[pivot];
        } else if (pivot > k) {
            return quick_select(arr, start, pivot - 1, k);
        } else {
            return quick_select(arr, pivot + 1, end, k);
        }
    }

    bool compareStrings(const string& a, const string& b) {
        return a + b < b + a;
    }

    // uses a modified binary search to search an array that has empty strings in it.
    static int sparse_search(string a[], int n, const string& key) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            cout << "low: " << low << " high: " << high << endl;
            int mid = (high + low) / 2;
            if (a[mid].empty()) {
                cout << "mid == "" : " << mid << endl;
                int left = mid - 1;
                int right = mid + 1;
                if (a[high] == key) {
                    return high;
                } else if (a[low] == key) {
                    return low;
                }
                while (left >= 0 && a[left].empty()) {
                    cout << "left: " << left << endl;
                    left--;
                }
                while (right <= n-1 && a[right].empty()) {
                    cout << "right: " << right << endl;
                    right++;
                }
                if (left < 0) {
                    cout << "left < 0" << endl;
                    return right;
                } else if (right >= n) {
                    cout << "right >= n" << endl;
                    return left;
                } else {
                    cout << "left: " << left << " right: " << right << endl;
                    if (key < a[left]) {
                        cout << "key < a[left]" << endl;
                        high = left;
                    } else if (key > a[right]) {
                        cout << "key > a[right]" << endl;
                        low = right;
                    } else {
                        cout << "key == a[left]" << endl;
                        return key == a[left] ? left : right;
                    }
                }
            } else if (a[mid] < key) {
                cout << "a[mid] < key" << endl;
                low = mid + 1;
            } else {
                cout << "a[mid] > key" << endl;
                high = mid - 1;
            }
        }
        cout << "about to return -1 and low: " << low << " high: " << high << endl;
        return -1;
    }

    // searches an unsorted matrix for a target and returns the row and column of the target.
    static pair<int, int> searchMatrix(int rows, int cols, vector<vector<int>> matrix, int key) {
        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0) {
            if (matrix[row][col] == key) {
                return make_pair(row, col);
            } else if (matrix[row][col] > key) {
                col--;
            } else {
                row++;
            }
        }
        return make_pair(-1, -1);
    }
    // implements in a way that is O(N).
    static int badness(vector<pair<string,int> > teams){
        vector<pair<string,int> > rankList;
        rankList.emplace_back("WinOrBooze",1);
        rankList.emplace_back("BallOfDuty",2);
        rankList.emplace_back("WhoKnows",3);
        rankList.emplace_back("BooleCreature",4);
        rankList.emplace_back("DCECoders",5);
        rankList.emplace_back("WhoKnows",6);
        rankList.emplace_back("StrangeCase",7);


        // initialize the badness to 0
        int badness = 0;
        // iterate through the teams
        for (int i = 0; i < teams.size(); i++) {
            // compute the distance between the teams preferred rank and the actual rank
            int distance = abs(teams[i].second - rankList[i].second);
            // add the distance to the badness
            badness += distance;
        }
        return badness;
    }

    //sort the balls in place in a single pass (O(N) time, O(1) space)
    static vector<int> sortBalls(vector<int> balls){
        //sort the balls in place in a single pass (O(N) time, O(1) space)
        int n = balls.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j > 0 && balls[j] < balls[j-1]) {
                swap(balls[j], balls[j-1]);
                j--;
            }
        }
        return balls;
    }

    /**
     *  find the smallest subarray that needs to be sorted to sort the entire array and
     *  put the starting and ending indices in start and end respectively, and add to a
     *  pair and return the pair.
     * @param a  the array to be sorted
     * @return
     */
    static pair<int,int> subarraySorting(vector<int> a){
        // find the starting index and ending index of the smallest subarray that needs to be sorted
        // to sort the entire array and return {-1,-1} if the array is already sorted
        int start = -1;
        int end = -1;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i+1]) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            return make_pair(-1, -1);
        }
        for (int i = n-1; i >= 0; i--) {
            if (a[i] < a[i-1]) {
                end = i;
                break;
            }
        }
        return make_pair(start, end + 1);
    }

    template<typename T>
    static int lowerbound(vector<T> a, T key) {
        int low = 0;
        int high = a.size() - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == key) {
                index = mid;
                high = mid - 1;
            } else if (a[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return index;
    }

    template <typename T>
    static int upperbound(vector<T> a, T key) {
        int low = 0;
        int high = a.size() - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == key) {
                index = mid;
                low = mid + 1;
            } else if (a[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return index;
    }

    template <typename T>
    static int frequency(vector<T> a, T key) {
        int low = lowerbound(a, key);
        int high = upperbound(a, key);
        if (low == -1 || high == -1) {
            return 0;
        }
        return high - low + 1;
    }

    template <typename T>
    static int rotated_search(vector<T> a, T key) {
        int low = 0;
        int high = a.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == key) {
                return mid;
            } else if (a[low] <= a[mid]) {
                // left half is sorted
                if (key >= a[low] && key <= a[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // right half is sorted
                if (key >= a[mid] && key <= a[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }

    // uses a binary search to find the square root of a number
    static double square_root(int n, int p) {
        int low = 0;
        int high = n;
        double ans = 0;
        // binary search for the int part
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid * mid == n) {
                return (double) mid;
            } else if (mid * mid < n) {
                ans = (double) mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // linear search for the decimal part
        double inc = 0.1;
        for (int i = 1; i <= p; i++) {
            while (ans * ans <= n) {
                ans += inc;
            }
            ans = ans - inc;
            inc = inc / 10.0;
        }
        return ans;
    }

    static bool canPlaceBirds(int B, int N, vector<int> nests, int sep) {
        int birds = 1;
        int location = nests[0];

        for(int i = 1; i <= N-1; i++) {
            int current_location = nests[i];
            if(current_location - location >= sep) {
                birds++;
                location = current_location;
                if (birds == B) {
                    return true;
                }
            }
        }
        return false;
    }

    static int angryBirds(int B,vector<int> nests) {
        // sorting the array if it is not sorted
        sort(nests.begin(), nests.end());
        int N = nests.size();
        int s = 0;
        int e = nests[N-1] - nests[0];
        int ans = -1;
        while(s<=e) {
            int mid = (e+s)/2;
            bool canPlace = canPlaceBirds(B,N,nests,mid);
            if(canPlace) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    template <typename T>
    static pair<T, T> min_pair(vector<T> a1, vector<T> a2) {
        // sort a2 arrays
        sort(a2.begin(), a2.end());
        int p1, p2;
        int diff = INT_MAX;
        // iterate over a1 and look for closest elements in a2
        for (T x : a1) {
            auto lb = lowerbound(a2.begin(), a2.end(), x) - a2.begin();

            if (lb >= 1 && x - a2[lb-1] < diff) {
                diff = x - a2[lb-1];
                p2 = x;
                p1 = a2[lb-1];
            }
            // greater / right
            if (lb != a2.size() && a2[lb] - x < diff) {
                diff = a2[lb] - x;
                p1 = x;
                p2 = a2[lb];
            }
        }
        return make_pair(p1, p2);
    }

    static bool isDividableByK(vector<int> a,int n,int k,int l){
        //return true if every partition gets at least limit no of coins
        int count = 0;
        int sum = 0;
        for(int i = 0;i < n;i++){
            if(sum + a[i] >= l){
                count++;
                sum = 0;
            }
            else {
                sum += a[i];
            }
        }
        return count >= k;

    }

    static int getCoins(vector<int> arr,int k){
        int n = arr.size();
        int hi = 0;
        int lo = 0;
        for(int i=0;i<n;i++){
            hi += arr[i];
        }
        int mid;
        int ans;
        while(lo<=hi){
            mid = lo + (hi - lo)/2;
            bool willWork = isDividableByK(arr,n,k,mid);
            if(willWork){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }

    static bool isDoable(vector<int>& books, int m, int l) {
        int n = books.size();
        int sum = 0;
        int students = 1;
        for (int i = 0; i < n; i++) {
            if (sum + books[i] > l) {
                students++;
                sum = books[i];
                if (students > m) {
                    return false;
                }
            } else {
                sum += books[i];
            }
        }
        return true;
    }

    // divide the array into m parts and find the maximum sum of a partition
    static int minPages(vector<int> books, int m){
        int n = books.size();
        int lo = 0;
        int hi = 0;
        for (int i = 0; i < n; i++) {
            hi += books[i];
            lo = max(lo, books[i]);
        }
        int ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(isDoable(books, m, mid)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    static int countWays(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    }

    // uses recursion to find if the subset sum is possible
    template <typename T>
    static bool isSubsetSum(vector<T> a, T sum) {
        // use recursion to find if the subset sum is possible
        if (sum == 0) {
            return true;
        }
        if (a.empty()) {
            return false;
        }
        T head = a.back();
        a.pop_back();
        if (isSubsetSum(a, sum - head)) {
            return true;
        }
        return isSubsetSum(a, sum);
    }

    template <typename T>
    static int countSubsets(vector<T> a,int size, int i, T sum) {
        // use recursion to find the number of subsets
        if (i == size) {
            if (sum == 0) {
                return 1;
            }
            return 0;
        }
        int inc = countSubsets(a, size, i + 1, sum - a[i]);
        int exc = countSubsets(a, size, i + 1, sum);
        return inc + exc;
    }

    static void generateBrackets(const string& output, int n, int open, int close, int i) {
        // use recursion to generate all possible brackets
        if (i == n * 2) {
            cout << output << endl;
            return;
        }
        if (open < n) { // open bracket
            generateBrackets(output + "(", n, open + 1, close, i + 1);
        }
        if (close < open)  { // close bracket
            generateBrackets(output + ")", n, open, close + 1, i + 1);
        }
    }


    static void printKeypadOutput(string input, const string& output, int i = 0) {
        // use recursion to generate all possible keypad outputs
        if (input[i] == '\0') {
            cout << output << endl;
            return;
        }
        // rec case
        int digit = input[i] - '0';
        if (digit == 0 || digit == 1) {
            printKeypadOutput(input, output, i + 1);
        }
        for (char k : keypad[digit]) {
            printKeypadOutput(input, output + k, i + 1);
        }
    }

    static set<string> buildPermutations(string s) {
        // use recursion to generate all possible permutations
        set<string> ans;
        if (s.empty()) {
            ans.insert("");
            return ans;
        }
        int i = 0;
        char c = s[i];
        string rest = s.substr(1);
        set<string> words = buildPermutations(rest);
        for (const string& word : words) {
            for (int j = 0; j <= word.size(); j++) {
                string new_word = word.substr(0, j) + c + word.substr(j);
                ans.insert(new_word);
            }
        }
        return ans;
    }

    // use recursion to generate all possible permutations of the string s using a set
    // to avoid duplicates
    static vector<string> findSortedPermutations(string s){
        // use helper function buildPermutations to generate all possible permutations
        set<string> permutations = buildPermutations(std::move(s));
        vector<string> ans;
        ans.reserve(permutations.size());
        for (const string& permutation : permutations) {
            ans.push_back(permutation);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    static void printBoard(int n, int board[][20]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    static bool isSafe(int board[][20], int n, int row, int col) {
        // check column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }
        // left diagonal
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }
        // right diagonal
        i = row;
        j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    // N queens problem
    static bool solveNQueen(int n, int board[][20], int i) {
        // base case
        if (i == n) {
            printBoard(n, board);
            return true;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, n, i, j)) {
                board[i][j] = 1;
                if (solveNQueen(n, board, i + 1)) {
                    return true;
                }
                board[i][j] = 0;
            }
        }
        return false;
    }

    static void solveNQueen(int n, int board[][20], int row, int& count) {
        // base case
        if (row == n) {
            count++;
            printBoard(n, board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, n, row, col)) {
                board[row][col] = 1;
                solveNQueen(n, board, row + 1, count);
                board[row][col] = 0;
            }
        }
    }

    // prints how many ways there are to place n queens on a board of size n
    static int nQueen(int n){
        int board[20][20] = {0};
        int count = 0;
        solveNQueen(n, board, 0, count);
        return count;
    }

    static void printSudoBoard(int board[][9], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    static bool isValidSudokuMove(int mat[][9], int i, int j, int num, int n) {
        // check row
        for (int k = 0; k < n; k++) {
            if (mat[i][k] == num) {
                return false;
            }
        }
        // check column
        for (int k = 0; k < n; k++) {
            if (mat[k][j] == num) {
                return false;
            }
        }
        // check 3x3 box
        int box_i = i - i % 3;
        int box_j = j - j % 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (mat[box_i + k][box_j + l] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    static bool solveSudoku(int mat[0][9], int i, int j, int n) {
        // base case
        if (i == n) {
            printSudoBoard(mat, n);
            return true;
        }
        // rec case
        if (j == n) {
            return solveSudoku(mat, i + 1, 0, n);
        }
        // skip if already filled
        if (mat[i][j] != 0) {
            return solveSudoku(mat, i, j + 1, n);
        }
        // cell to be filled
        for (int no = 1; no <= n; no++) {
            if (isValidSudokuMove(mat, i, j, no, n)) {
                mat[i][j] = no;
                bool solveSubProblem = solveSudoku(mat, i, j + 1, n);
                if (solveSubProblem) {
                    return true;
                }
            }
        }
        // if no option is found, backtrack
        mat[i][j] = 0;
        return false;
    }

    static vector<vector<int> > solveSudoku(vector<vector<int> > input){
        int n = input.size();
        int board[9][9];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = input[i][j];
            }
        }
        solveSudoku(board, 0, 0, n);
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            vector<int> row;
            row.reserve(n);
            for (int j = 0; j < n; j++) {
                row.push_back(board[i][j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
//===============================================================================
    static bool isValidSudokuMove(
            std::vector<vector<char> >& board, int& i, int& j, int& num, int& n) {
        // check row
        for (int k = 0; k < n; k++) {
            if (board[i][k] == num) {
                return false;
            }
        }
        // check column
        for (int k = 0; k < n; k++) {
            if (board[k][j] == num) {
                return false;
            }
        }
        // check 3x3 box
        int box_i = i - i % 3;
        int box_j = j - j % 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[box_i + k][box_j + l] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    // print the sudoku board
    static  void printSudoku(const std::vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << (board[i][j]) << " ";
            }
            cout << endl;
        }
    }

    static std::vector<vector<char>>& solveSudoku(
            std::vector<vector<char> >& board, int& i, int& j, int& n) {
        // base case
        if (i == n) {
            cout << "Solved Sudoku about to return the following board" << endl;
            for (int i_ = 0; i_ < 9; i_++) {
                for (int j_ = 0; j_ < 9; j_++) {
                    cout << (board[i_][j_]) << " ";
                }
                cout << endl;
            }

            printSudoku(board);
            return board;
        }
        // rec case
        if (j == n) {
            int val = i + 1;
            int val2 = 0;
            return solveSudoku(board, val, val2, n);
        }
        // skip if already filled
        if (board[i][j] != '.') {
            int val = j + 1;
            return solveSudoku(board, i, val, n);
        }
        // cell to be filled
        for (int no = 1; no <= n; no++) {
            int val = no + '0';
            if (isValidSudokuMove(board, i, j, val, n)) {
                board[i][j] = no + '0';
                int val2 = j + 1;
                solveSudoku(board, i, val2, n);
            }
        }
        // if no option is found, backtrack
        board[i][j] = '.';
        return board;
    }

    /**
     * Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.
    EXAMPLE:
     Input: board =
     [["5","3",".",".","7",".",".",".","."],
     ["6",".",".","1","9","5",".",".","."],
     [".","9","8",".",".",".",".","6","."],
     ["8",".",".",".","6",".",".",".","3"],
     ["4",".",".","8",".","3",".",".","1"],
     ["7",".",".",".","2",".",".",".","6"],
     [".","6",".",".",".",".","2","8","."],
     [".",".",".","4","1","9",".",".","5"],
     [".",".",".",".","8",".",".","7","9"]]
    Output:
     [["5","3","4","6","7","8","9","1","2"],
     ["6","7","2","1","9","5","3","4","8"],
     ["1","9","8","3","4","2","5","6","7"],
     ["8","5","9","7","6","1","4","2","3"],
     ["4","2","6","8","5","3","7","9","1"],
     ["7","1","3","9","2","4","8","5","6"],
     ["9","6","1","5","3","7","2","8","4"],
     ["2","8","7","4","1","9","6","3","5"],
     ["3","4","5","2","8","6","1","7","9"]]
     */
    static void solveSudoku(std::vector<vector<char> >& board) {
        int n = board.size();
        int i = 0;
        int j = 0;

        // solve the sudoku
        board = solveSudoku(board, i, j, n);

        // print the solved sudoku in loop here to make sure it is solved
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << (board[i][j]) << " ";
            }
            cout << endl;
        }
    }

    // given two numbers a and b, compute a raised to power of b. As this value can
    // be very large, compute it to modulo 10^9 + 7.
    static long long int powerModulo(int a, int b){
        long long int MOD = 1000000007;
        long long int ans = 1;
        while(b > 0){
            if(b & 1){
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }

    //Oswald and Henry are playing a game of coins. They have a row of n coins [C1, C2, ..., Cn]
    // with values [V1, V2, ..., Vn]. where Ci coin has Vi value. They take turns alternatively.
    // In one turn the player can pick either the first or the last coin of the row. Given both
    // Oswald and Henry are very smart players, you need to find the maximum possible value Oswald
    // can earn if he plays first.
    static int gameOfCoins(int n, vector<int> v){
        int Henry = 0;
        int Oswald = 0;

        // Oswald goes first and picks the coin n from front or back
        if (v[0] == n) {
            Oswald += v[0];
            v.erase(v.begin());
        } else {
            Oswald += v[v.size() - 1];
            v.erase(v.begin() + v.size() - 1);
        }

        // look at front and back of the vector and pop off the highest value each time
        // and add it to the sum of one of the player, Henry or Oswald
        for (int i = 1; !v.empty(); i++) {
            if (i%2 == 1) {
                // Henry's turn, look at both ends of the vector and remove and add
                // the highest value to the sum of Henry
                if (v[0] > v[v.size() - 1]) {
                    Henry += v[0];
                    v.erase(v.begin());
                } else {
                    Henry += v[v.size() - 1];
                    v.erase(v.begin() + v.size() - 1);
                }
            } else {
                // Oswald's turn, look at both ends of the vector and remove and add
                // the highest value to the sum of Oswald
                if (v[0] > v[v.size() - 1]) {
                    Oswald += v[0];
                    v.erase(v.begin());
                } else {
                    Oswald += v[v.size() - 1];
                    v.erase(v.begin() + v.size() - 1);
                }
            }
        }
        return Oswald;
    }

    //Oswald and Henry are playing a game of coins. They have a row of n coins [C1, C2, ..., Cn]
    // with values [V1, V2, ..., Vn]. where Ci coin has Vi value. They take turns alternatively.
    // In one turn the player can pick either the first or last coin of the row, and he is
    // supposed to do it 'k' times. Given both Oswald and Henry are very smart players, you need
    // to find the maximum possible value Oswald can earn if he plays first.
    static int gameOfCoinsAdvanced(int n, int k, vector<int> v){
        int Oswald = 0;
        // look at front and back of the vector and pop off the highest value each time
        // and add it to the sum of one of the player, Henry or Oswald
        for (int i = 0; !v.empty(); i++) {
            if (i%2 == 1) {
                // Henry's turn, look at both ends of the vector and remove and add
                // the highest value to the sum of Henry
                for (int j = 0; j < k; j++) {
                    if (v[0] > v[v.size() - 1]) {
                        v.erase(v.begin());
                    } else {
                        v.erase(v.begin() + v.size() - 1);
                    }
                }
            } else {
                // Oswald's turn, look at both ends of the vector and remove and add
                // the highest value to the sum of Oswald
                for (int j = 0; j < k; j++) {
                    if (v[0] > v[v.size() - 1]) {
                        Oswald += v[0];
                        v.erase(v.begin());
                    } else {
                        Oswald += v[v.size() - 1];
                        v.erase(v.begin() + v.size() - 1);
                    }
                }
            }
        }
        return Oswald;
    }

    static bool saveMove(int row, int col, vector<vector<char>> maze) {
        if (row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size()) {
            return false;
        }
        if (maze[row][col] == 'X') {
            return false;
        }
        return true;
    }

    static int encode(int row, int col, int n) {
        return row * n + col + 1;
    }
    /**
     * Given an integer N and a grid of size N x N. The cells of the grid are numbered
     * row wise from 1 to N^2. Rat wants to travel from cell number 1 to cell number N^2,
     * and it can move in only right and down directions from a particular cell. There
     * is exactly one path from the source to destination as some cells are blocked.
     * Help rat to find the path. Use backtracking to solve.
     * @param n  size of the grid
     * @param c  a 2D vector consisting of only 'O's and 'X's where 'O' represents a
     * open cell and 'X' represents a blocked cell.
     * @return the path from source to destination
     */
    static vector<int> ratInAMaze(int n, vector<vector<char>> c){
        vector<int> path;
        int row = 0;
        int col = 0;
        c[row][col] = '*'; // mark the starting cell as visited
        path.push_back(encode(row, col, n));
        while (row < n - 1 || col < n - 1) {
            if (saveMove(row + 1, col, c)) {
                row++;
                c[row][col] = '*';
                path.push_back(encode(row, col, n));
            } else if (saveMove(row, col + 1, c)) {
                col++;
                c[row][col] = '*';
                path.push_back(encode(row, col, n));
            } else {
                // backtrack
                row = path[path.size() - 1] / n;
                col = path[path.size() - 1] % n;
                path.pop_back();
            }
        }
        return path;
    }

    static pair<bool, int> seekPath(int m, int n, int i, int j, vector<vector<int>> v, bool visited[][100]) {
        if (i == m - 1 && j == n - 1) {
            pair <bool, int> maxPath={true, 0};
            return maxPath;
        }
        if (i >= m || i < 0 || j >= n || j < 0) {
            pair <bool, int> maxPath{false, -1};
            return maxPath;
        } else {
            visited[i][j] = true;
            pair <bool, int> mp{false, -1};
            // check down
            if (i < m-1 && v[i+1][j] == 1 && !visited[i+1][j]) {
                pair <bool, int> down = seekPath(m, n, i+1, j, v, visited);
                if (down.first) {
                    mp.first = true;
                    mp.second = max(mp.second, down.second);
                }
            }
            // check right
            if (j < n-1 && v[i][j+1] == 1 && !visited[i][j+1]) {
                pair <bool, int> right = seekPath(m, n, i, j+1, v, visited);
                if (right.first) {
                    mp.first = true;
                    mp.second = max(mp.second, right.second);
                }
            } // check up
            if (i > 0 && v[i-1][j] == 1 && !visited[i-1][j]) {
                pair <bool, int> up = seekPath(m, n, i-1, j, v, visited);
                if (up.first) {
                    mp.first = true;
                    mp.second = max(mp.second, up.second);
                }
            }
            // check left
            if (i > 0 && v[i][j-1] == 1 && !visited[i][j-1]) {
                pair <bool, int> left = seekPath(m, n, i, j-1, v, visited);
                if (left.first) {
                    mp.first = true;
                    mp.second = max(mp.second, left.second);
                }
            }
            visited[i][j] = false;
            mp.second += 1;
            return mp;
        }
    }
    /**
     * Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the longest
     * possible route possible from top left position (0,0) to bottom right position (M-1, N-1)
     * within the matrix. We are allowed to move to only adjacent cells which are not
     * hurdles. The route cannot contain any diagonal moves and a location once visited
     * in a particular path cannot be visited again.
     * @param m  is the number of rows in the matrix
     * @param n  is the number of columns in the matrix
     * @param v  is a 2D vector (m x n) where each element is either 0 or 1 and 0 represents
     * the hurdle and 1 represents the open cell.
     * @return a single integer which is the length of the longest path possible.
     */
    static int findLongestPath(int m, int n, vector<vector<int>> v){
        bool visited[100][100] = {{false}};
        pair<bool, int> p = seekPath(m, n, 0, 0, std::move(v), visited);
        return p.second;
    }

    static vector<string> split(const string &basicString, char i) {
        vector<string> result;
        stringstream ss(basicString);
        string intermediate;
        while (getline(ss, intermediate, i)) {
            result.push_back(intermediate);
        }
        return result;
    }

    static string simplifyPath(const string& path){
        istringstream iss(path);
        string intermediate;
        vector<string> result;
        bool isRoot = path[0] == '/';

        while (getline(iss, intermediate, '/')) {
            if (intermediate != "." && !intermediate.empty()) {
                result.push_back(intermediate);
            }
        }
        vector<string> s;
        if (isRoot) {
            s.emplace_back("");
        }
        for (auto& i : result) {
            if (i == "..") {
                if (s.empty() || s.back() == "..") {
                    s.push_back(i);
                }else if(!s[s.size()-1].empty()) {
                    s.pop_back();
                }
            } else {
                s.push_back(i);
            }
        }
        if (s.size() == 1 && s[0].empty()) {
            return "/";
        }
        ostringstream oss;
        int i = 0;
        for (auto &j : s) {
            if (i != 0) {
                oss << "/";
            }
            i++;
            oss << j;
        }
        return oss.str();
    }

    /**
     * Given the price of a stock over the next n days, calculate the span of the
     * stocks price for all n days. The span of a stock's price today is defined as
     * the maximum number of consecutive days (starting from today) for which the
     * price of the stock was less than or equal to today's price.
     * @param v  is a vector of integers representing the price of the stock over the next n days.
     * @return  a vector of integers representing the span of the stock's price for all n days.
     */
    static vector<int> stockSpan(vector<int> v) {
        vector<int> result;
        Stack<pair<int, int>> s;
        for (int i = 0; i < v.size(); i++) {
            while (!s.isEmpty() && s.peek().first <= v[i]) {
                s.pop();
            }
            if (s.isEmpty()) {
                result.push_back(i+1);
            } else {
                result.push_back(i - s.peek().second);
            }
            s.push({v[i], i});
        }
        return result;
    }

    class MinimumDifficultyJobScheduler {
    public:
        static int minDifficulty(vector<int>& jobDifficulty, int d) {
            int n = jobDifficulty.size();
            if (n < d) return -1;
            vector<vector<int>> dp(n, vector<int>(d, INT_MAX));
            dp[0][0] = jobDifficulty[0];
            for (int i = 1; i < n; ++i) {
                dp[i][0] = max(dp[i - 1][0], jobDifficulty[i]);
            }
            for (int i = 1; i < n; ++i) {
                for (int j = 1; j < d; ++j) {
                    int maxVal = jobDifficulty[i];
                    for (int k = i; k >= j; --k) {
                        maxVal = max(maxVal, jobDifficulty[k]);
                        dp[i][j] = std::min(dp[i][j], dp[k - 1][j - 1] + maxVal);
                    }
                }
            }
            return dp[n - 1][d - 1];

        }
    };

    static int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

    static bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];

    }

    static int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (k >= n / 2) {
            int result = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    result += prices[i] - prices[i - 1];
                }
            }
            return result;
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j] + diff, dp[i - 1][j - 1] + max(diff, 0));
            }
        }
        return dp[n - 1][k];
    }

    /**
     * Given an input string s and a pattern p, implement regular expression
     * matching with support for '.' and '*' where:
     * '.' Matches any single  character.
     * '*' Matches zero or more of the preceding elements
     * The matching should cover the entire input string (not partial)
     *
     * example 1:
     * Input: s = "aa", p = "a"
     * Output: false
     * Explanation: "a" does not match the entire string "aa".
     *
     * example 2:
     * Input: s = "aa", p = "a*"
     * Output: true
     * Explanation: '*' means zero or more of the preceding element, 'a'.
     *               Therefore, by repeating 'a' once, it becomes "aa".
     *
     * example 3:
     * Input: s = "ab", p = ".*"
     * Output: true
     * Explanation: ".*" means "zero or more (*) of any character (.)".
     *
     * @param s the input string
     * @param p the regular expression pattern
     *
     * @return bool: true if the pattern matches the regular expression, else
     * false
     */
    static bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (matches(s, p, i, j - 1)) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (matches(s, p, i, j)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];

    }
     // matches helper function for isMatch
    static bool matches(string s, string p, int i, int j) {
        if (i == 0) return false;
        if (p[j - 1] == '.') return true;
        return s[i - 1] == p[j - 1];
    }

    /**
     * Given an array of k linked-lists lists, each linked-list is sorted is
     * ascending order. Merge all the linked-lists into one sorted linked-list
     * and return it.
     * @param lists the vector of linked-lists
     */
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto* dummy = new ListNode(0);
        ListNode* tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next) {
                pq.push(tail->next);
            }
        }
        return dummy->next;
    }
    // comparator for mergeKLists
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    /**
     * A subsequence of a string is a new string that is formed from the
     * original string by deleting some (can be none) of the characters
     * without disturbing the relative positions of the remaining characters.
     * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
     *
     * Given two strings s and t, return the minimum number of subsequences
     * of s such that their concatenation equals t. If the task is
     * impossible, return -1.
     *
     * @param s the string source
     * @param t the string target
     * @return int the minimum number of subsequences of s such that their
     * concatenation equals t. If the task is impossible, return -1.
     */
     int shortestWay(string s, string t) {
        int result = 0;
        int i = 0, j = 0;
        while (j < t.size()) {
            result++;
            int prev = j;
            while (i < s.size() && j < t.size()) {
                if (s[i] == t[j]) {
                    j++;
                }
                i++;
            }
            if (prev == j) {
                return -1;
            }
            i = 0;
        }
        return result;
    }

    /**
     * Given the root of a binary tree containing digits from 0 to 9 only. Each
     * root-to-leaf path in the tree represents a number.
     * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
     * Return the total sum of all root-to-leaf numbers. Test cases are
     * generated so that the answer will fit in a 32-bit integer.
     * A leaf node is a node with no children.
     * @param root the root of the binary tree
     * @return int the total sum of all root-to-leaf numbers
     */
     int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    // sumNumbers helper function
    int sumNumbers(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            return sum;
        }
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }

    /**
     * You have a long flowerbed in which some of the plots are planted, and
     * some are not. However, flowers cannot be planted in adjacent plots.
     * Given an integer array flowerbed containing 0's and 1's, where 0 means
     * empty and 1 means not empty, and an integer n, return if n new flowers
     * can be planted in the flowerbed without violating the no-adjacent-flowers
     * rule.
     * @param flowerbed the flowerbed array
     * @param n the number of flowers to be planted
     * @return bool true if n new flowers can be planted in the flowerbed
     * without violating the no-adjacent-flowers rule, else false
     */
     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        if (m == 1) {
            return (flowerbed[0] == 0 && n <= 1) || (flowerbed[0] == 1 && n == 0);
        }
        if (m == 2) {
            return (flowerbed[0] == 0 && flowerbed[1] == 0 && n <= 1) ||
                   (flowerbed[0] == 1 && flowerbed[1] == 0 && n == 0) ||
                   (flowerbed[0] == 0 && flowerbed[1] == 1 && n == 0);
        }
        for (int i = 0; i < m && count < n; i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            int next = (i == m - 1) ? 0 : flowerbed[i + 1];
            if (prev == 0 && next == 0) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count == n;
    }

    /**
     * There are n computers numbered from 0 to n - 1 connected by ethernet cables
     * connections forming a network where connections[i] = [ai, bi] represents a
     * connection between computers ai and bi. Any computer can reach any other
     * computer directly or indirectly through the network.
     *
     * You are given an initial computer network connections. You can extract
     * certain cables between two directly connected computers, and place them
     * between any pair of disconnected computers to make them directly connected.
     *
     * Return the minimum number of times you need to do this in order to make
     * all the computers connected. If it is not possible, return -1.
     *
     * @param n the number of computers
     * @param connections the initial computer network connections
     * @return int the minimum number of times you need to do this in order to
     * make all the computers connected. If it is not possible, return -1.
     */
     int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto connection : connections) {
            int x = _find(parent, connection[0]);
            int y = _find(parent, connection[1]);
            if (x != y) {
                parent[x] = y;
                n--;
            }
        }
        return n - 1;

    }
    // makeConnected helper function
    int _find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = _find(parent, parent[i]);
        }
        return parent[i];
    }

    /**
     * Reducing Dishes.
     * A chef has collected data on the satisfaction level of his n dishes. Chef
     * can cook any dish in 1 unit of time. Like-time coefficient of a dish
     * is defined as the time taken to cook that dish including previous dishes
     * multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
     * Return the maximum sum of like-time coefficient that the chef can
     * obtain after dishes preparation. Dishes can be prepared in any order
     * and the chef can discard some dishes to get this maximum value.
     * @param satisfaction the satisfaction level of the dishes
     * @return int the maximum sum of like-time coefficient
     */
     static int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int result = 0;
        int sum = 0;
        for (int i = satisfaction.size() - 1; i >= 0 && satisfaction[i] > -sum; i--) {
            sum += satisfaction[i];
            result += sum;
        }
        return result;
    }

    /**
     * 983. You have planned some train traveling one year in advance. The
     * days of the year in which you will travel are given as an integer
     * array days. Each day is an integer from 1 to 365.
     * Train tickets are sold in three different ways:
     * a 1-day pass is sold for costs[0] dollars;
     * a 7-day pass is sold for costs[1] dollars;
     * a 30-day pass is sold for costs[2] dollars.
     * The passes allow that many days of consecutive travel. For example, if we
     * get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5,
     * 6, 7, and 8.
     *
     * Return the minimum number of dollars you need to travel every day in the
     * given list of days.
     */
    int mincostTickets(vector<int>& days,
                       vector<int>& costs,
                       vector<int> durations = {1, 7, 30}) {
        int n = days.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MAX;
            int j = i;
            for (int k = 0; k < 3; k++) {
                while (j < n && days[j] < days[i] + durations[k]) {
                    j++;
                }
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }
        return dp[0];
    }

    /**
     * 1485. Clone Binary Tree With Random Pointer
     * A binary tree is given such that each node contains an additional random
     * pointer which could point to any node in the tree or null.
     * Return a deep copy of the tree.
     * The tree is represented in the same input/output way as normal binary
     * trees where each node is represented as a pair of [val, random_index]
     * where:
     * val: an integer representing Node.val
     * random_index: the index of the node (in the input) where the random
     * pointer points to, or null if it does not point to any node.
     * You will be given the tree in class Node and you should return the
     * cloned tree in class NodeCopy. NodeCopy class is just a clone of Node
     * class with the same attributes and constructors.
     * @param root the root of the binary tree
     *
     * @return NodeCopy* the root of the cloned binary tree
     */
    RandomNodeCopy* copyRandomBinaryTree(RandomNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        unordered_map<RandomNode*, RandomNodeCopy*> m;
        queue<RandomNode*> q;
        q.push(root);
        while (!q.empty()) {
            RandomNode* node = q.front();
            q.pop();
            if (m.find(node) == m.end()) {
                m[node] = new RandomNodeCopy(node->val);
            }
            if (node->left != nullptr) {
                if (m.find(node->left) == m.end()) {
                    m[node->left] = new RandomNodeCopy(node->left->val);
                    q.push(node->left);
                }
                m[node]->left = m[node->left];
            }
            if (node->right != nullptr) {
                if (m.find(node->right) == m.end()) {
                    m[node->right] = new RandomNodeCopy(node->right->val);
                    q.push(node->right);
                }
                m[node]->right = m[node->right];
            }
            if (node->random != nullptr) {
                if (m.find(node->random) == m.end()) {
                    m[node->random] = new RandomNodeCopy(node->random->val);
                    q.push(node->random);
                }
                m[node]->random = m[node->random];
            }
        }
        return m[root];
    }
    /**
     * 1444. Number of Ways of Cutting a Pizza
     * Given a rectangular pizza represented as a rows x cols matrix containing
     * the following characters: 'A' (an apple) and '.' (empty cell) and given
     * the integer k. You have to cut the pizza into k pieces using k-1 cuts.
     * For each cut you choose the direction: vertical or horizontal, then you
     * choose a cut position at the cell boundary and cut the pizza into two
     * pieces. If you cut the pizza vertically, give the left part of the pizza
     * to a person. If you cut the pizza horizontally, give the upper part of
     * the pizza to a person. Give the last piece of pizza to the last person.
     * Return the number of ways of cutting the pizza such that each piece
     * contains at least one apple. Since the answer can be a huge number,
     * return this modulo 10^9 + 7.
     * @param pizza the pizza
     * @param k the number of cuts
     * @return int the number of ways of cutting the pizza
     * such that each piece contains at least one apple
     * modulo 10^9 + 7
     */
     static int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] +
                            (pizza[i][j] == 'A');
            }
        }
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1)));
        return _ways(pizza, sum, dp, 0, 0, k);
    }

    static int _ways(vector<string>& pizza,
              vector<vector<int>>& sum,
              vector<vector<vector<int>>>& dp,
              int i,
              int j,
              int k,
              int MOD = 1e9 + 7) {
        int m = pizza.size();
        int n = pizza[0].size();
        if (sum[i][j] == 0) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        int ways = 0;
        for (int x = i + 1; x < m; x++) {
            if (sum[i][j] - sum[x][j] > 0) {
                ways = (ways + _ways(pizza, sum, dp, x, j, k - 1)) % MOD;
            }
        }
        for (int y = j + 1; y < n; y++) {
            if (sum[i][j] - sum[i][y] > 0) {
                ways = (ways + _ways(pizza, sum, dp, i, y, k - 1)) % MOD;
            }
        }
        dp[i][j][k] = ways;
        return ways;
    }

    /**
     * 2405.
     * Optimal Partition of String
     * Given a string s, partition the string into one or more substrings such
     * that the characters in each substring are unique. That is, no letter
     * appears in a single substring more than once.
     *
     * Return the minimum number of substrings in such a partition. Note that
     * each character should belong to exactly one substring in a partition.
     *
     * Example 1:
        Input: s = "abacaba"
        Output: 4
        Explanation:
        Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
        It can be shown that 4 is the minimum number of substrings needed.


     * Example 2:
        Input: s = "ssssss"
        Output: 6
        Explanation:
        The only valid partition is ("s","s","s","s","s","s").

     * @param s the string
     * @return int the minimum number of substrings in such a partition
     * such that each character should belong to exactly one substring
     * in a partition
     */
    static int minPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            unordered_set<char> seen;
            for (int j = i; j >= 1; j--) {
                if (seen.find(s[j - 1]) != seen.end()) {
                    break;
                }
                seen.insert(s[j - 1]);
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        return dp[n];
    }

    /**
     * 1964 Find the Longest Valid Obstacle Course at Each Position
     *
     You want to build some obstacle courses. You are given a 0-indexed integer
     array obstacles of length n, where obstacles[i] describes the height of the
     ith obstacle.

     For every index i between 0 and n - 1 (inclusive), find the length of the
     longest obstacle course in obstacles such that:
        - You choose any number of obstacles between 0 and i inclusive.
        - You must include the ith obstacle in the course.
        - You must put the chosen obstacles in the same order as they appear
          in obstacles.
     Every obstacle (except the first) is taller than or the same height as the
     obstacle immediately before it.
     Return an array ans of length n, where ans[i] is the length of the
     longest obstacle course for index i as described above.
     *
     * Example 1:
        Input: obstacles = [1,2,3,2]
        Output: [1,2,3,3]
        Explanation: The longest valid obstacle course at each position is:
        - i = 0: [1], [1] has length 1.
        - i = 1: [1,2], [1,2] has length 2.
        - i = 2: [1,2,3], [1,2,3] has length 3.
        - i = 3: [1,2,3,2], [1,2,2] has length 3.

     * Example 2:
        Input: obstacles = [2,2,1]
        Output: [1,2,1]
        Explanation: The longest valid obstacle course at each position is:
        - i = 0: [2], [2] has length 1.
        - i = 1: [2,2], [2,2] has length 2.
        - i = 2: [2,2,1], [1] has length 1.

     * Example 3:
        Input: obstacles = [3,1,5,6,4,2]
        Output: [1,1,2,3,2,2]
        Explanation: The longest valid obstacle course at each position is:
        - i = 0: [3], [3] has length 1.
        - i = 1: [3,1], [1] has length 1.
        - i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
        - i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
        - i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
        - i = 5: [3,1,5,6,4,2], [1,2] has length 2.

     * Constraints:
        n == obstacles.length
        1 <= n <= 105
        1 <= obstacles[i] <= 107
     *
     * @param obstacles the obstacles
     * @return vector<int> the length of the longest obstacle course for index i
     * as described above
     */
    static vector<int> longestObstacleCourseAtEachPositionTU(vector<int>&
            obstacles) {
        // use dynamic programming top-down approach
        int n = obstacles.size();
        vector<int> dp(n + 1, 0);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = _longestObstacleCourseAtEachPosition(obstacles, dp, i);
        }
        return ans;
    }
    // helper function for longestObstacleCourseAtEachPosition
    static int _longestObstacleCourseAtEachPosition(vector<int>& obstacles,
                                                    vector<int>& dp, int i) {
        if (dp[i] > 0) {
            return dp[i];
        }
        int ans = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (obstacles[j] <= obstacles[i]) {
                ans = max(ans, _longestObstacleCourseAtEachPosition(obstacles, dp, j) + 1);
            }
        }
        dp[i] = ans;
        return ans;
    }

    // use dynamic programming bottom-up approach
    static vector<int> longestObstacleCourseAtEachPosition(vector<int>&
            obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> tails;
        tails.reserve(n);

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(tails.begin(), tails.end(), obstacles[i] + 1);
            int len = it - tails.begin() + 1;
            ans[i] = len;
            if (it == tails.end()) {
                tails.push_back(obstacles[i]);
            } else {
                *it = obstacles[i];
            }
        }
        return ans;
    }

    /**
     * 311. Sparse Matrix Multiplication
     * Given two sparse matrices mat1 of size m x k and mat2 of size k x n,
     * return the result of mat1 x mat2. You may assume that multiplication
     * is always possible.
     * Example 1:
     * Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
     * Output: [[7,0,0],[-7,0,3]]
     * Example 2:
     * Input: mat1 = [[0]], mat2 = [[0]]
     * Output: [[0]]
     * Constraints:
     * m == mat1.length
     * k == mat1[i].length == mat2.length
     * n == mat2[i].length
     * 1 <= m, n, k <= 100
     * -100 <= mat1[i][j], mat2[i][j] <= 100
     * @param mat1 the first matrix
     * @param mat2 the second matrix
     * @return the result of mat1 x mat2
     */
    static vector<vector<int>> multiply(vector<vector<int>>& mat1,
                                         vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int p = 0; p < k; p++) {
                if (mat1[i][p] != 0) {
                    for (int j = 0; j < n; j++) {
                        ans[i][j] += mat1[i][p] * mat2[p][j];
                    }
                }
            }
        }
        return ans;
    }


    /**
     * 2466. Count Ways To Build Good Strings
     * @brief Given the integers zero, one, low, nad high, we can construct a
     * string by starting with an empty string, and then at each step perform
     * either of the following:
     * 1. Append the character '0' zero times.
     * 2. Append the character '1' one time.
     * This can be performed any number of time.
     * A good string is a string constructed by the above process having a
     * length between low and high, inclusive.
     * Return the number of different good strings that can be constructed
     * satisfying these properties. Since the answer can be large, return it
     * modulo 10^9 + 7.
     *
     * Example 1:
     * Input: low = 3, high = 3, zero = 1, one = 1
     * Output: 8
     * Explanation:
     * One possible valid good string is "011". It can be constructed as
     * follows: "" -> "0" -> "01" -> "011". All binary strings from "000" to
     * "111" are good strings in this example.
     *
     * Example 2:
     * Input: low = 2, high = 3, zero = 1, one = 2
     * Output: 5
     * Explanation:
     * The good strings are "00", "11", "000", "110", and "011".
     *
     * Constraints:
     * 1 <= low <= high <= 10^5
     * 1 <= zero, one <= low
     */
    static int countGoodStrings(int low, int high, int zero, int one) {
        constexpr int kMod = 1e9 + 7;
        int ans = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;

        for (int i = 1; i <= high; i++) {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % kMod;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % kMod;
            if (i >= low)
                ans = (ans + dp[i]) % kMod;
        }

        return ans;
    }

    /**
     * 1799. Maximize Score After N Operations
     * You are given nums, an array of positive integers of size 2 * n. You
     * must perform n operations on this array.
     * In the ith operation (1-indexed), you will:
     * Choose two elements, x and y.
     * Receive a score of i * gcd(x, y).
     * Remove x and y from nums.
     * Return the maximum score you can receive after performing n operations.
     * The function gcd(x, y) is the greatest common divisor of x and y.
     */
    static int maxScore(vector<int>& nums) {
        int n = nums.size(), N = 1 << n, M = n / 2;
        vector<vector<int>> gcd(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; ++j)
                gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);

        vector<int> dp(N);
        for (int mask = 0; mask < N; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2) continue;
            cnt /= 2;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) continue;
                for (int j = i + 1; j < n; ++j) {
                    if ((mask >> j) & 1) continue;
                    dp[mask | (1 << i) | (1 << j)] =
                            max(dp[mask | (1 << i) | (1 << j)],
                                dp[mask] + (cnt + 1) * gcd[i][j]);
                }
            }
        }
        return dp[N - 1];
    }

    /**
     * 1230. Toss Strange Coins
     * You have some coins.  The i-th coin has a probability prob[i] of facing
     * heads when tossed.
     * Return the probability that the number of coins facing heads equals
     * target if you toss every coin exactly once.
     *
     * Example 1:
     * Input: prob = [0.4], target = 1
     * Output: 0.40000
     *
     * Example 2:
     * Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
     * Output: 0.03125
     *
     * Constraints:
     * 1 <= prob.length <= 1000
     * 0 <= prob[i] <= 1
     * 0 <= target <= prob.length
     * Answers will be accepted as correct if they are within 10^-5 of the
     */
    static double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = min(i + 1, target); j >= 0; j--) {
                dp[j] = (j > 0 ? dp[j - 1] : 0) * prob[i] + dp[j] * (1 - prob[i]);
            }
        }
        return dp[target];
    }

    /**
     * @brief 1376. Time Needed to Inform All Employees
     * A company has n employees with a unique ID for each employee from 0 to
     * n - 1. The head of the company is the one with headID.
     * Each employee has one direct manager given in the manager array where
     * manager[i] is the direct manager of the i-th employee, manager[headID] =
     * -1. Also it's guaranteed that the subordination relationships have a tree
     * structure.
     * The head of the company wants to inform all the employees of the company
     * of an urgent piece of news. He will inform his direct subordinates and
     * they will inform their subordinates and so on until all employees know
     * about the urgent news.
     * The i-th employee needs informTime[i] minutes to inform all of his
     * direct subordinates (i.e After informTime[i] minutes, all his direct
     * subordinates can start spreading the news).
     * Return the number of minutes needed to inform all the employees about
     * the urgent news.
     *
     * Example 1:
     * Input: n = 1, headID = 0, manager = [-1], informTime = [0]
     * Output: 0
     * Explanation: The head of the company is the only employee in the company.
     *
     * Example 2:
     * Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0, 1,0,0,0]
     * Output: 1
     * Explanation: The head of the company with id = 2 is the direct manager of
     * all the employees in the company and needs 1 minute to inform them all.
     *
     * constraints:
     * 1 <= n <= 10^5
     * 0 <= headID < n
     * manager.length == n
     * 0 <= manager[i] < n
     * manager[headID] == -1
     * informTime.length == n
     * 0 <= informTime[i] <= 1000
     * informTime[i] == 0 if employee i has no subordinates.
     * It is guaranteed that all the employees can be informed.
     */
    static int numOfMinutes(
            int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        return _numOfMinutes(adj, headID, informTime);
    }
    static int _numOfMinutes(
            vector<vector<int>>& adj, int headID, vector<int>& informTime) {
        int res = 0;
        for (int i = 0; i < adj[headID].size(); i++) {
            res = max(res, _numOfMinutes(adj, adj[headID][i], informTime));
        }
        return res + informTime[headID];
    }

    /**
     * @brief 1377. Frog Position After T Seconds
     * Given an undirected tree consisting of n vertices numbered from 1 to n.
     * A frog starts jumping from the vertex 1. In one second, the frog jumps
     * from its current vertex to another unvisited vertex if they are directly
     * connected. The frog can not jump back to a visited vertex. In case the
     * frog can jump to several vertices it jumps randomly to one of them with
     * the same probability, otherwise, when the frog can not jump to any
     * unvisited vertex it jumps forever on the same vertex.
     * The edges of the undirected tree are given in the array edges, where
     * edges[i] = [fromi, toi] means that exists an edge connecting directly
     * the vertices fromi and toi.
     * Return the probability that after t seconds the frog is on the vertex
     * target.
     *
     * Example 1:
     * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2,
     * target = 4
     * Output: 0.16666666666666666
     * Explanation: The figure above shows the given graph. The frog starts at
     * vertex 1, jumping with 1/3 probability to the vertex 2 after second 1
     * and then jumping with 1/2 probability to vertex 4 after second 2. Thus
     * the probability for the frog is on the vertex 4 after 2 seconds is
     * 1/3 * 1/2 = 1/6 = 0.16666666666666666.
     *
     * Example 2:
     * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1,
     * target = 7
     * Output: 0.3333333333333333
     * Explanation: The figure above shows the given graph. The frog starts at
     * vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex
     * 7
     * after second 1.
     * Example 3:
     * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20,
     * target = 6
     * Output: 0.16666666666666666
     *
     * Constraints:
     * 1 <= n <= 100
     * edges.length == n-1
     * edges[i].length == 2
     * 1 <= edges[i][0], edges[i][1] <= n
     * 1 <= t <= 50
     * 1 <= target <= n
     * Answers within 10^-5 of the actual value will be accepted as correct.
     */
    static double frogPosition(
            int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        return _frogPosition(adj, visited, 1, t, target);
    }

    static double _frogPosition(
            vector<vector<int>>& adj, vector<bool>& visited, int cur, int t,
            int target) {
        if (t == 0) {
            if (cur == target) return 1.0;
            else return 0.0;
        }
        double res = 0.0;
        int count = 0;
        for (int i = 0; i < adj[cur].size(); i++) {
            if (!visited[adj[cur][i]]) count++;
        }
        if (count == 0) {
            if (cur == target) return 1.0;
            else return 0.0;
        }
        for (int i = 0; i < adj[cur].size(); i++) {
            if (!visited[adj[cur][i]]) {
                visited[adj[cur][i]] = true;
                res += _frogPosition(adj, visited, adj[cur][i], t - 1, target);
                visited[adj[cur][i]] = false;
            }
        }
        return res / count;
    }

    /**
     * 1232. Check If It Is a Straight Line
     * You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
     * represents the coordinate of a point. Check if these points make a
     * straight line in the XY plane.
     *
     * Example 1:
     * Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
     * Output: true
     *
     * Example 2:
     * Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
     * Output: false
     *
     * Constraints:
     * 2 <= coordinates.length <= 1000
     * coordinates[i].length == 2
     * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
     * coordinates contains no duplicate point.
     */
    static bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); i++) {
            int x2 = coordinates[i][0], y2 = coordinates[i][1];
            if ((y1 - y0) * (x2 - x1) != (y2 - y1) * (x1 - x0)) return false;
        }
        return true;
    }

    /**
     * 744. Find Smallest Letter Greater Than Target
     * You are given an array of characters letters that is sorted in
     * non-decreasing order, and a character target. There are at least two
     * different characters in letters.
     * Return the smallest character in letters that is lexicographically greater
     * than target. If such a character does not exist, return the first character
     * in letters.
     *
     * Example 1:
     * Input: letters = ["c","f","j"], target = "a"
     * Output: "c"
     *
     * Example 2:
     * Input: letters = ["c","f","j"], target = "c"
     * Output: "f"
     *
     * Example 3:
     * Input: letters = ["x","x","y", "y"], target = "z"
     * Output: "x"
     */
    static char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return letters[left % letters.size()];
    }

    /**
     * 1150. Check If a Number Is Majority Element in a Sorted Array
     * Given an integer array nums sorted in non-decreasing order, and an integer
     * target, return true if target is a majority element, or false otherwise.
     * A majority element in an array nums is an element that appears more than
     * nums.length / 2 times in the array.
     *
     * Example 1:
     * Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
     * Output: true
     *
     * Example 2:
     * Input: nums = [10,100,101,101], target = 101
     * Output: false
     */
    static bool isMajorityElement(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        if (left >= nums.size() || nums[left] != target) return false;
        return left + nums.size() / 2 < nums.size() && nums[left + nums.size() / 2] == target;
    }

    /**
     * 14. Longest Common Prefix
     * Write a function to find the longest common prefix string amongst an array
     * of strings. If there is no common prefix, return an empty string "".
     *
     * Example 1:
     * Input: ["flower","flow","flight"]
     * Output: "fl"
     *
     * Example 2:
     * Input: ["dog","racecar","car"]
     * Output: ""
     */
    static string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            for (; j < res.size() && j < strs[i].size(); j++) {
                if (res[j] != strs[i][j]) break;
            }
            res = res.substr(0, j);
        }
        return res;
    }

    /**
     * 25. Reverse Nodes in k-Group
     * Given the head of a linked list, reverse the nodes of the list k at a
     * time, and return the modified list.
     * k is a positive integer and is less than or equal to the length of the
     * linked list. If the number of nodes is not a multiple of k then left-out
     * nodes, in the end, should remain as it is.
     * You may not alter the values in the list's nodes, only nodes themselves
     * may be changed.
     *
     * Example 1:
     * Input: head = [1,2,3,4,5], k = 2
     * Output: [2,1,4,3,5]
     *
     * Example 2:
     * Input: head = [1,2,3,4,5], k = 3
     * Output: [3,2,1,4,5]
     */
    static ListNode* reverseKGroup(ListNode* head, int k) {
        auto* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> res = _rev(head, tail);
            head = res.first;
            tail = res.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
    /**
     * helper function for reverseKGroup
     */
    static pair<ListNode*, ListNode*> _rev(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next;
        ListNode* p = head;
        while (pre != tail) {
            ListNode* nex = p->next;
            p->next = pre;
            pre = p;
            p = nex;
        }
        return {tail, head};
    }

    /**
     * 1751. Maximum Number of Events That Can Be Attended II
     * You are given an array of events where events[i] =
     * [startDay_i, endDay_i, value_i]. The ith event starts at startDay_i and
     * ends at endDay_i, and if you attend this event, you will receive a
     * value of value_i. You are also given an integer k which represents the
     * maximum number of events you can attend.
     *
     * You can only attend one event at a time. If you choose to attend an
     * event, you must attend the entire event. Note that the end day is
     * inclusive: that is, you cannot attend two events where one of them
     * starts and the other ends on the same day.
     *
     * Return the maximum sum of values that you can receive by attending events.
     *
     * Example 1:
     * Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
     * Output: 7
     * Explanation: Choose the green events, 0 and 1 (0-indexed) for a total
     * value of 4 + 3 = 7.
     *
     * Example 2:
     * Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
     * Output: 10
     * Explanation: Choose event 2 for a total value of 10.
     *
     * Example 3:
     * Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
     * Output: 9
     * Explanation: Although the events do not overlap, you can only attend 3
     * events. Pick the highest valued three.
     *
     * Constraints:
     * 1 <= k <= events.length
     * 1 <= k * events.length <= 10^6
     * 1 <= startDay_i <= endDay_i <= 10^9
     * 1 <= value_i <= 10^6
     *
     * @param events 2D array of events
     * @param k maximum number of events you can attend
     *
     * @return maximum sum of values that you can receive by attending events
     */
    static int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (events[mid][1] < events[i - 1][0]) l = mid + 1;
                else r = mid;
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[l][j - 1] + events[i - 1][2]);
            }
        }
    return dp[n][k];
    }

    /**
     * 735. Asteroid Collision
     * We are given an array asteroids of integers representing asteroids in a
     * row.
     * For each asteroid, the absolute value represents its size, and the sign
     * represents its direction (positive meaning right, negative meaning left).
     * Each asteroid moves at the same speed.
     * Find out the state of the asteroids after all collisions. If two
     * asteroids
     * meet, the smaller one will explode. If both are the same size, both will
     * explode. Two asteroids moving in the same direction will never meet.
     *
     * Example 1:
     * Input: asteroids = [5,10,-5]
     * Output: [5,10]
     * Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never
     *
     * Example 2:
     * Input: asteroids = [8,-8]
     * Output: []
     * Explanation: The 8 and -8 collide exploding each other.
     *
     * Example 3:
     * Input: asteroids = [10,2,-5]
     * Output: [10]
     * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
     *
     * Constraints:
     * 2 <= asteroids.length <= 10^4
     * -1000 <= asteroids[i] <= 1000
     * asteroids[i] != 0
     *
     * @param asteroids the asteroids
     * @return the state of the asteroids after all collisions
     */
    static vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) res.push_back(asteroids[i]);
            else {
                while (!res.empty() && res.back() > 0 && res.back() < -asteroids[i]) {
                    res.pop_back();
                }
                if (res.empty() || res.back() < 0) res.push_back(asteroids[i]);
                else if (res.back() == -asteroids[i]) res.pop_back();
            }
        }
        return res;
    }

    /**
     * 46. Permutations
     * Given an array nums of distinct integers, return all the possible
     * permutations. You can return the answer in any order.
     *
     * Example 1:
     * Input: nums = [1,2,3]
     * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
     *
     * Example 2:
     * Input: nums = [0,1]
     * Output: [[0,1],[1,0]]
     *
     * Example 3:
     * Input: nums = [1]
     * Output: [[1]]
     *
     * Constraints:
     * 1 <= nums.length <= 6
     * -10 <= nums[i] <= 10
     * All the integers of nums are unique.
     *
     * @param nums the array of distinct integers
     * @return all the possible permutations
     */
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        _permute(nums, res, cur, visited);
        return res;
    }
    static void _permute(vector<int>& nums, vector<vector<int>>& res,
                            vector<int>& cur, vector<bool>& visited) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                cur.push_back(nums[i]);
                _permute(nums, res, cur, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }

    /**
     * 1870. Minimum Speed to Arrive on Time
     * Yor are given a floating-point number 'hour', representing the amount of
     * time you have to reach the office. To commute to the office, you must
     * take 'n' trains in sequential order. You are also given an integer array
     * 'dist' of length 'n', where dist[i] describes the distance (in kilometers)
     * of the ith train ride.
     * Each train can only depart at an integer hour, so you may need to wait in
     * between each train ride.
     * For example, if the 1st train ride takes 1.5 hours, you must wait for an
     * additional 0.5 hours before you can depart on the 2nd train ride at the
     * 2 hour mark.
     *
     * Return the minimum positive integer speed (in kilometers per hour) that
     * all the trains must travel at for you to reach the office on time, or -1
     * if it is impossible to be on time.
     * Tests are generated such that the answer will not exceed 10^7 and hour
     * will have at most two digits after the decimal point.
     *
     * Example 1:
     * Input: dist = [1,3,2], hour = 6
     * Output: 1
     * Explanation: At speed 1:
     * - The first train ride takes 1/1 = 1 hour.
     * - Since we are already at an integer hour, we depart immediately at the
     * 1 hour mark. The second train takes 3/1 = 3 hours.
     * - Since we are already at an integer hour, we depart immediately at the
     * 4 hour mark. The third train takes 2/1 = 2 hours.
     * - You will arrive at exactly the 6 hour mark.
     *
     * Example 2:
     * Input: dist = [1,3,2], hour = 2.7
     * Output: 3
     * Explanation: At speed 3:
     * - The first train ride takes 1/3 = 0.33333 hours.
     * - Since we are not at an integer hour, we wait until the 1 hour mark to
     * depart. The second train ride takes 3/3 = 1 hour.
     * - Since we are already at an integer hour, we depart immediately at the
     * 2 hour mark. The third train takes 2/3 = 0.66667 hours.
     * - You will arrive at the 2.66667 hour mark.
     *
     * Example 3:
     * Input: dist = [1,3,2], hour = 1.9
     * Output: -1
     * Explanation: It is impossible because the earliest the third train can
     * depart is at the 2 hour mark.
     *
     * Constraints:
     * n == dist.length
     * 1 <= n <= 10^5
     * 1 <= dist[i] <= 10^5
     * 1 <= hour <= 10^9
     *
     * @param dist the distance of each train ride
     * @param hour the amount of time you have to reach the office
     * @return the minimum positive integer speed that all the trains must travel
     */
    static int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;
        int left = 1, right = 1e7;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double time = 0;
            for (int i = 0; i < n - 1; i++) {
                time += ceil((double)dist[i] / mid);
            }
            time += (double)dist[n - 1] / mid;
            if (time <= hour) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    /**
     * 439. Ternary Expression Parser
     * Given a string expression representing arbitrarily nested ternary
     * expressions, evaluate the expression, and return the result of it.
     *
     * You can always assume that the given expression is valid and only
     * contains digits, '?', ':', 'T', and 'F' where 'T' is true and 'F' is
     * false. All the numbers in the expression are one-digit numbers  (i.e.,
     * in the range [0, 9]).
     *
     * The conditional expressions group right-to-left (as usual in most
     * languages), and the result of the expression will always evaluate to
     * either a digit, 'T' or 'F'.
     *
     * Example 1:
     * Input: expression = "T?2:3"
     * Output: "2"
     * Explanation: If true, then result is 2; otherwise result is 3.
     *
     * Example 2:
     * Input: expression = "F?1:T?4:5"
     * Output: "4"
     * Explanation: The conditional expressions group right-to-left. Using
     * parenthesis, it is read/evaluated as:
     * "(F ? 1 : (T ? 4 : 5))" --> "(F ? 1 : 4)" --> "4"
     * or "(F ? 1 : (T ? 4 : 5))" --> "(T ? 4 : 5)" --> "4"
     *
     * Example 3:
     * Input: expression = "T?T?F:5:3"
     * Output: "F"
     * Explanation: The conditional expressions group right-to-left. Using
     * parenthesis, it is read/evaluated as:
     * "(T ? (T ? F : 5) : 3)" --> "(T ? F : 3)" --> "F"
     * or "(T ? (T ? F : 5) : 3)" --> "(T ? F : 5)" --> "F"
     *
     * Constraints:
     * 5 <= expression.length <= 10^4
     * expression consists of digits, 'T', 'F', '?', and ':'.
     * It is guaranteed that expression is a valid ternary expression and that
     * each number is a one-digit number.
     *
     * @param expression the expression
     * @return the result of the expression
     */
    static string parseTernary(string expression) {
        stack<char> stk;
        for (int i = expression.size() - 1; i >= 0; i--) {
            if (!stk.empty() && stk.top() == '?') {
                stk.pop();
                char first = stk.top();
                stk.pop();
                stk.pop();
                char second = stk.top();
                stk.pop();
                if (expression[i] == 'T') stk.push(first);
                else stk.push(second);
            } else stk.push(expression[i]);
        }
        return string(1, stk.top());
    }

    /**
     * 95. Unique Binary Search Trees II
     * Given an integer n, return all the structurally unique BST's (binary
     * search trees), which has exactly n nodes of unique values from 1 to n.
     * Return the answer in any order.
     *
     * Example 1:
     * Input: n = 3
     * Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
     *
     * Example 2:
     * Input: n = 1
     * Output: [[1]]
     *
     * Constraints:
     * 1 <= n <= 8
     *
     * @param n the number of nodes
     * @return all the structurally unique BST's
     */
    static vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

    static vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    /**
     * 86. Partition List
     * Given the head of a linked list and a value x, partition it such that
     * all nodes less than x come before nodes greater than or equal to x.
     * You should preserve the original relative order of the nodes in each
     * of the two partitions.
     *
     * Example 1:
     * Input: head = [1,4,3,2,5,2], x = 3
     * Output: [1,2,2,4,3,5]
     *
     * Example 2:
     * Input: head = [2,1], x = 2
     * Output: [1,2]
     *
     * Constraints:
     * The number of nodes in the list is in the range [0, 200].
     * -100 <= Node.val <= 100
     * -200 <= x <= 200
     *
     * @param head the head of the linked list
     * @param x the value
     * @return the partitioned linked list
     */
    static ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && cur->val < x) {
            pre = cur;
            cur = cur->next;
        }
        ListNode* p = cur;
        while (p && p->next) {
            if (p->next->val < x) {
                ListNode* tmp = p->next;
                p->next = tmp->next;
                tmp->next = cur;
                pre->next = tmp;
                pre = tmp;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }

    /**
     * 490. The Maze
     * There is a ball in a maze with empty spaces (represented as 0) and walls
     * (represented as 1). The ball can go through the empty spaces by rolling
     * up, down, left or right, but it won't stop rolling until hitting a wall.
     * When the ball stops, it could choose the next direction.
     * Given the m x n maze, the ball's start position and the destination,
     * where start = [startrow, startcol] and destination = [destinationrow,
     * destinationcol], return true if the ball can stop at the destination,
     * otherwise return false.
     * You may assume that the borders of the maze are all walls (see examples).
     *
     * Example 1:
     * Input: maze = [[0,0,1,0,0], [0,0,0,0,0], [0,0,0,1,0], [1,1,0,1,1],
     * [0,0,0,0,0]], start = [0,4], destination = [4,4]
     * Output: true
     * Explanation: One possible way is : left -> down -> left -> down ->
     * right -> down -> right.
     *
     * Example 2:
     * Input: maze = [[0,0,1,0,0], [0,0,0,0,0], [0,0,0,1,0], [1,1,0,1,1],
     * [0,0,0,0,0]], start = [0,4], destination = [3,2]
     * Output: false
     * Explanation: There is no way for the ball to stop at the destination.
     * Notice that you can pass through the destination but you cannot stop there.
     *
     * Example 3:
     * Input: maze = [[0,0,0,0,0], [1,1,0,0,1], [0,0,0,0,0], [0,1,0,0,1],
     * [0,1,0,0,0]], start = [4,3], destination = [0,1]
     * Output: false
     *
     * Constraints:
     * m == maze.length
     * n == maze[i].length
     * 1 <= m, n <= 100
     * maze[i][j] is 0 or 1.
     * start.length == 2
     * destination.length == 2
     * 0 <= startrow, destinationrow <= m
     * 0 <= startcol, destinationcol <= n
     * Both the ball and the destination exist in an empty space, and they will
     * not be in the same position initially.
     * The maze contains at least 2 empty spaces.
     *
     * @param maze the maze
     * @param start the start position
     * @param destination the destination
     * @return whether the ball can stop at the destination
     */
    static bool hasPath(vector<vector<int>>& maze, vector<int>& start,
                        vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(maze, start[0], start[1], destination, visited);
    }

    static bool dfs(vector<vector<int>>& maze, int i, int j,
                    vector<int>& destination, vector<vector<bool>>& visited) {
        if (visited[i][j]) return false;
        if (i == destination[0] && j == destination[1]) return true;
        visited[i][j] = true;
        int m = maze.size();
        int n = maze[0].size();
        int up = i;
        while (up > 0 && maze[up - 1][j] == 0) up--;
        int down = i;
        while (down < m - 1 && maze[down + 1][j] == 0) down++;
        int left = j;
        while (left > 0 && maze[i][left - 1] == 0) left--;
        int right = j;
        while (right < n - 1 && maze[i][right + 1] == 0) right++;
        return dfs(maze, up, j, destination, visited) ||
               dfs(maze, down, j, destination, visited) ||
               dfs(maze, i, left, destination, visited) ||
               dfs(maze, i, right, destination, visited);
    }





};

string Solutions::keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                    "pqrs", "tuv", "wxyz"};

#endif //LEETCODE_SOLUTIONS_H
