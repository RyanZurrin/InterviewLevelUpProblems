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

// A macro that defines the size of an integer
#define INT_SIZE sizeof(int) * 8
using namespace std;



class Solutions {
public:
    Solutions() = default;
    ~Solutions() = default;

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
     * given two sorted arrays find the median of the arrays
     * @param nums1 a sorted array of integers
     * @param nums2 a sorted array of integers
     * @return the median of the two arrays
     */
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
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
        while (left >= 0 && right < basicString.length() && basicString[left] == basicString[right]) {
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
     * You are given an m x n binary matrix grid. An island is a group of 1's
     * (representing land) connected 4-directionally (horizontal or vertical.)
     * You may assume all four edges of the grid are surrounded by water.
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


};


#endif //LEETCODE_SOLUTIONS_H
