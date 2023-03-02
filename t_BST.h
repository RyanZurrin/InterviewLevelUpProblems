//
// Created by Ryan.Zurrin001 on 1/6/2022.
//
#ifndef LEETCODE_T_BST_H
#define LEETCODE_T_BST_H

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
#include <unordered_map>


// A macro that defines the size of an integer
#define INT_SIZE sizeof(int) * 8
using namespace std;


// ____________________start Udemy course binary search tree ___________________
template<class T>
class t_treeNode {
public:
    T data;
    t_treeNode<T> *left;
    t_treeNode<T> *right;
    t_treeNode<T> *parent;
    explicit t_treeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
}; // end of class t_treeNode

template <class T>
class t_BST {
private:
    t_treeNode<T> *root;
    int size{};
    void insert(t_treeNode<T> *&root_, t_treeNode<T> *&newNode) {
        if (root_ == nullptr) {
            root_ = newNode;
            size++;
            return;
        }
        if (newNode->data < root_->data) {
            insert(root_->left, newNode);
        } else {
            insert(root_->right, newNode);
        }
        balance(root_);
    }
    void remove(t_treeNode<T> *&node, T data) {
        if (node == nullptr) {
            return;
        }
        if (data < node->data) {
            remove(node->left, data);
        } else if (data > node->data) {
            remove(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
                size--;
            } else if (node->left == nullptr) {
                t_treeNode<T> *temp = node;
                node = node->right;
                delete temp;
                size--;
            } else if (node->right == nullptr) {
                t_treeNode<T> *temp = node;
                node = node->left;
                delete temp;
                size--;
            } else {
                t_treeNode<T> *temp = findMin(node->right);
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
        balance(node);
    }

    void removeAll(t_treeNode<T> *&node, T data) {
        if (node == nullptr) {
            return;
        }
        do {
            remove(node, data);
        }while(count(data) > 0);
    }

    void printTree(t_treeNode<T> *node) {
        if (node != nullptr) {
            printTree(node->left);
            cout << node->data << " ";
            printTree(node->right);
        }
    }
    void inOrder(t_treeNode<T> *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
    void preOrder(t_treeNode<T> *node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void postOrder(t_treeNode<T> *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    void levelOrder(t_treeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        queue<t_treeNode<T> *> q;
        q.push(node);
        q.push(nullptr);
        while (!q.empty()) {
            t_treeNode<T> *temp = q.front();
            if (temp == nullptr) {
                cout << endl;
                q.pop();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                q.pop();
                cout << temp->data << " ";
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }
    }
    // print the tree as a 2d tree
    void print2DUtil(t_treeNode<T> *root_, int space) {
        if (root_ == nullptr) {
            return;
        }
        space += 10;
        print2DUtil(root_->right, space);
        cout << endl;
        for (int i = 10; i < space; i++) {
            cout << " ";
        }
        cout << root_->data << endl;
        print2DUtil(root_->left, space);
    }

    [[maybe_unused]]
    void verticalOrder(t_treeNode<T> *node, map<int, vector<T>> &m, int level) {
        if (node == nullptr) {
            return;
        }
        m[level].push_back(node->data);
        verticalOrder(node->left, m, level - 1);
        verticalOrder(node->right, m, level + 1);
    }

    /**
 * @brief finds the parent of the node, if the node is not in the tree,
 * returns nullptr
 * @param node the node to find the parent of
 * @param data  the data of the node to find the parent of
 * @return  the parent of the node, if the node is not in the tree,
 *  returns nullptr
 */
    t_treeNode<T> *findParent(t_treeNode<T> *node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left != nullptr && node->left->data == data) {
            return node;
        } else if (node->right != nullptr && node->right->data == data) {
            return node;
        } else if (data < node->data) {
            return findParent(node->left, data);
        } else {
            return findParent(node->right, data);
        }
    }
    /**
     * @brief finds the successor of a node, or the leftmost node of the right subtree
     * @param node  the node to find the successor of
     * @return the successor of the node
     */
    t_treeNode<T> *findSuccessor(t_treeNode<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->right != nullptr) {
            return findMin(node->right);
        }
        t_treeNode<T> *parent = findParent(root, node->data);
        while (parent != nullptr && parent->right != nullptr &&
               parent->right->data != node->data) {
            node = parent;
            parent = findParent(root, node->data);
        }
        return parent;
    }
    /**
     * @brief finds the predecessor of a node, or the right most child of the
     * left subtree of the node
     * @param node  the node to find the predecessor of
     * @return the predecessor of the node
     */
    t_treeNode<T> *findPredecessor(t_treeNode<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left != nullptr) {
            return findMax(node->left);
        }
        t_treeNode<T> *parent = findParent(root, node->data);
        while (parent != nullptr && parent->left != nullptr &&
               parent->left->data != node->data) {
            node = parent;
            parent = findParent(root, node->data);
        }
        return parent;
    }

    // private balance methods
    // right rotate
    void rightRotate(t_treeNode<T> *&node) {
        t_treeNode<T> *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }
    // left rotate
    void leftRotate(t_treeNode<T> *&node) {
        t_treeNode<T> *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }
    // rotate left right
    void leftRightRotate(t_treeNode<T> *&node) {
        leftRotate(node->left);
        rightRotate(node);
    }
    // rotate right left
    void rightLeftRotate(t_treeNode<T> *&node) {
        rightRotate(node->right);
        leftRotate(node);
    }
    // balance tree
    void balance(t_treeNode<T> *&node) {
        if (node == nullptr) {
            return;
        }
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                leftRotate(node->left);
            }
            rightRotate(node);
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                rightRotate(node->right);
            }
            leftRotate(node);
        }
    }
    // get leaves
    int getLeaves(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return getLeaves(node->left) + getLeaves(node->right);
    }

    t_treeNode<T> *find(t_treeNode<T> *node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            return find(node->left, data);
        } else {
            return find(node->right, data);
        }
    }
    t_treeNode<T> *findMin(t_treeNode<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    t_treeNode<T> *findMax(t_treeNode<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    void destroyTree(t_treeNode<T> *node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    int getBalanceFactor(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    int getHeight(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
    int getDiameter(t_treeNode<T>* root_) {
        if (root_ == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(root_->left);
        int rightHeight = getHeight(root_->right);
        int leftDiameter = getDiameter(root_->left);
        int rightDiameter = getDiameter(root_->right);
        return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
    }

    int getCount(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return getCount(node->left) + getCount(node->right) + 1;
    }

    T replaceWithSums(t_treeNode<T> *&node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }

        T leftSum = replaceWithSums(node->left);
        T rightSum = replaceWithSums(node->right);
        T temp = node->data;
        node->data = leftSum + rightSum;
        return node->data + temp;
    }

    double sum(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }

        double leftSum = sum(node->left);
        double rightSum = sum(node->right);
        return node->data + leftSum + rightSum;
    }

    double median(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        int currCount = 0;
        auto *current = node;
        double median = 0;
        t_treeNode<T> *pre = nullptr;
        t_treeNode<T> *prev = nullptr;
        while (current != nullptr) {
            if (current->left == nullptr) {
                if (currCount == count / 2) {
                    median = current->data;
                }
                currCount++;
                current = current->right;
            } else {
                pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    if (currCount == count / 2) {
                        median = current->data;
                    }
                    currCount++;
                    current = current->right;
                }
            }
        }
        return median;
    }

    double average(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double sum = this->sum(node);
        return sum / count;
    }

    double standardDeviation(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double average = this->average();
        double sum = 0;
        auto *current = node;
        while (current != nullptr) {
            if (current->left == nullptr) {
                sum += pow(current->data - average, 2);
                current = current->right;
            } else {
                auto *pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    sum += pow(current->data - average, 2);
                    current = current->right;
                }
            }
        }
        return sqrt(sum / count);
    }

    double standardError(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double standardDeviation = this->standardDeviation();
        return standardDeviation / sqrt(count);
    }

    double variance(t_treeNode<T> *node, const string& type) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double average = this->average();
        double sum = 0;
        auto *current = node;
        while (current != nullptr) {
            if (current->left == nullptr) {
                sum += pow(current->data - average, 2);
                current = current->right;
            } else {
                auto *pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    sum += pow(current->data - average, 2);
                    current = current->right;
                }
            }
        }
        if (type == "population") {
            return sum / count;
        } else {
            return sum / (count - 1);
        }
    }

    double covariance(t_treeNode<T> *root_, t_treeNode<T> *node, const string& type) {
        if (root_ == nullptr || node == nullptr) {
            return 0;
        }
        int count = getCount(root_);
        double sum_XY = 0;
        double rootAvg = average(root);
        double nodeAvg = average(node);
        double squareSum_X = this->sumOfSquaredMeanDifferences(root);
        double squareSum_Y = this->sumOfSquaredMeanDifferences(node);
        vector<T> x;
        vector<T> y;
        // adding the root data to the vector x
        while (root_ != nullptr) {
            if (root_->left == nullptr) {
                x.push_back(root_->data);
                root_ = root_->right;
            } else {
                auto *pre = root_->left;
                while (pre->right != nullptr && pre->right != root_) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = root_;
                    root_ = root_->left;
                } else {
                    pre->right = nullptr;
                    x.push_back(root_->data);
                    root_ = root_->right;
                }
            }
        }
        // adding the node data to the vector y
        while (node != nullptr) {
            if (node->left == nullptr) {
                y.push_back(node->data);
                node = node->right;
            } else {
                auto *pre = node->left;
                while (pre->right != nullptr && pre->right != node) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = node;
                    node = node->left;
                } else {
                    pre->right = nullptr;
                    y.push_back(node->data);
                    node = node->right;
                }
            }
        }
        // sort the vectors
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        // calculate the sum of the x-xAvg * y-yAvg
        for (int i = 0; i < x.size(); i++) {
            sum_XY += (x[i] - rootAvg) * (y[i] - nodeAvg);
        }
        if (type == "population") {
            return sum_XY / count;
        } else {
            return sum_XY / (count - 1);
        }
    }

    // (x - x_bar)^2
    double sumOfSquaredMeanDifferences(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double average = this->average(node);
        double sum = 0;
        auto *current = node;
        while (current != nullptr) {
            if (current->left == nullptr) {
                sum += pow(current->data - average, 2);
                current = current->right;
            } else {
                auto *pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    sum += pow(current->data - average, 2);
                    current = current->right;
                }
            }
        }
        return sum;
    }


    double skewness(t_treeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double average = this->average();
        double sum = 0;
        auto *current = node;
        while (current != nullptr) {
            if (current->left == nullptr) {
                sum += pow(current->data - average, 3);
                current = current->right;
            } else {
                auto *pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    sum += pow(current->data - average, 3);
                    current = current->right;
                }
            }
        }
        return sum / (count * pow(this->standardDeviation(), 3));
    }

    double kurtosis(t_treeNode<T> *node) {
        // the central moment of the distribution
        if (node == nullptr) {
            return 0;
        }
        int count = getCount(node);
        double average = this->average();
        double sum = 0;
        auto *current = node;
        while (current != nullptr) {
            if (current->left == nullptr) {
                sum += pow(current->data - average, 4);
                current = current->right;
            } else {
                auto *pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    sum += pow(current->data - average, 4);
                    current = current->right;
                }
            }
        }
        return sum / (count * pow(this->standardDeviation(), 4));
    }

    T mode(t_treeNode<T> *node) {
        // find the value that occurs most often and return it
        if (node == nullptr) {
            return 0;
        }
        unordered_map<T, int> count;
        queue<t_treeNode<T> *> q;
        q.push(node);
        int maxFreq = 0;
        while (!q.empty()) {
            auto *current = q.front();
            q.pop();
            if (current->left == nullptr && current->right == nullptr) {
                count[current->data]++;
                if (count[current->data] > maxFreq) {
                    maxFreq = count[current->data];
                }
            } else {
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
        }
        T mode;
        for (auto &i : count) {
            if (i.second == maxFreq) {
                mode = i.first;
            }
        }
        return mode;
    }

    double correlationCoefficient(t_treeNode<T> *root_, t_treeNode<T> *node) {
        if (root_ == nullptr || node == nullptr) {
            return 0;
        }
        double sum_XY = 0;
        double rootAvg = average(root);
        double nodeAvg = average(node);
        double squareSum_X = this->sumOfSquaredMeanDifferences(root);
        double squareSum_Y = this->sumOfSquaredMeanDifferences(node);
        vector<T> x;
        vector<T> y;
        // adding the root data to the vector x
        while (root_ != nullptr) {
            if (root_->left == nullptr) {
                x.push_back(root_->data);
                root_ = root_->right;
            } else {
                auto *pre = root_->left;
                while (pre->right != nullptr && pre->right != root_) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = root_;
                    root_ = root_->left;
                } else {
                    pre->right = nullptr;
                    x.push_back(root_->data);
                    root_ = root_->right;
                }
            }
        }
        // adding the node data to the vector y
        while (node != nullptr) {
            if (node->left == nullptr) {
                y.push_back(node->data);
                node = node->right;
            } else {
                auto *pre = node->left;
                while (pre->right != nullptr && pre->right != node) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = node;
                    node = node->left;
                } else {
                    pre->right = nullptr;
                    y.push_back(node->data);
                    node = node->right;
                }
            }
        }
        // sort the vectors
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        // calculate the sum of the x-xAvg * y-yAvg
        for (int i = 0; i < x.size(); i++) {
            sum_XY += (x[i] - rootAvg) * (y[i] - nodeAvg);
        }
        return sum_XY / sqrt(squareSum_X * squareSum_Y);
    }
    double zMultiplier(double alpha) {
        // calculate the z multiplier for the given alpha
        map<double, double> z;
        //read the values from the file where each line is a pair of values
        // separated by a space
        ifstream file("zscores.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            double x, y;
            ss >> x >> y;
            z[x] = y;
        }
        return z[alpha];
    }


    pair<double, double> confidenceInterval(t_treeNode<T> *node, double alpha) {
        // return the confidence interval of the data in the node
        // alpha is the significance level
        double average = this->average(node);
        double standardDeviation = this->standardDeviation(node);
        double z = this->zMultiplier(alpha);
        double confidenceInterval = z * standardDeviation / sqrt(getCount(node));
        double lowerBound = average - confidenceInterval;
        double upperBound = average + confidenceInterval;
        return make_pair(lowerBound, upperBound);
    }


    int keyCountUtil(t_treeNode<T>* root_, T key) {
        if (root_ == nullptr) {
            return 0;
        }
        int count = 0;
        if (root_->data == key) {
            count++;
        }
        count += keyCountUtil(root_->left, key);
        count += keyCountUtil(root_->right, key);
        return count;
    }

    bool isPresent(t_treeNode<T>* root_, T key) {
        if (root_ == nullptr) {
            return false;
        }
        if (root_->data == key) {
            return true;
        }
        if (root_->data < key) {
            return isPresent(root_->right, key);
        } else {
            return isPresent(root_->left, key);
        }
    }

public:
    // constructor
    t_BST() {
        root = nullptr;
        size = 0;
    }

    // copy constructor
    t_BST(const t_BST<T> &other) {
        root = copy(other.root);
    }
// move constructor
    t_BST(t_BST<T> &&other) noexcept {
        root = other.root;
        other.root = nullptr;
    }
// copy assignment operator
    t_BST<T> & operator=(const t_BST<T> &other) {
        if (this != &other) {
            destroy();
            copyTree(other.root, root);
        }
        return *this;
    }
// move assignment operator
    t_BST<T> & operator=(t_BST<T> &&other) noexcept {
        if (this != &other) {
            destroy();
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }
// constructor with initializer list
    explicit t_BST(vector<T> &data) {
        root = nullptr;
        size = 0;
        for (auto &i : data) {
            insert(i);
        }
    }
// constructor to create a BST from data in a file
    t_BST(const string& fileName, char delimiter) {
        root = nullptr;
        size = 0;
        this->fillTreeFromFile(fileName, delimiter);
    }

    t_BST(int totalElements, T min, T max) {
        // fill the tree with random numbers in the range [min, max]
        root = nullptr;
        size = 0;
        // seed the random number generator from the system clock and random library
        srand(time(nullptr));
        for (int i = 0; i < totalElements; i++) {
            insert(rand() % (max - min + 1) + min);
        }
    }

    /**
     * @brief insert data into the tree
     * @param data  data to be inserted
     */
    void insert(T data) {
        auto *node = new t_treeNode<T>(data);
        insert(root, node);
    }
    /**
     * @brief destroy tree
     */
    void destroy() {
        destroyTree(root);
        root = nullptr;
        size = 0;
    }
    /**
    * @brief find the node with the given data
    * @param data  the data to find
    * @return  the node with the given data
    */
    t_treeNode<T> *find(T data) {
        return find(root, data);
    }
    /**
     * @brief find the maximum node
     * @return  the maximum node
     */
    t_treeNode<T> *findMax() {
        return findMax(root);
    }
    T max() {
        return findMax()->data;
    }
    /**
     * @brief find the minimum node
     * @return  the minimum node
     */
    t_treeNode<T> *findMin() {
        return findMin(root);
    }
    T min() {
        return findMin()->data;
    }

    /**
     * @brief counts how many times a key appears in the tree
     * @param key  the key to count
     * @return  the number of times the key appears in the tree
     */
    int count(T key) {
        return keyCountUtil(root, key);
    }

    /**
     * @brief remove a node from the tree
     * @param data  the data of the node to remove
     */
    void remove(T data) {
        remove(root, data);
    }

    void removeAll(T data) {
        removeAll(root, data);
    }

    /**
     *  @brief prints the tree in order
     */
    void printTree() {
        printTree(root);
    }
    /**
     *  @brief print the tree in order
     */
    void inOrder() {
        inOrder(root);
    }
    /**
     *  @brief print the tree in pre order
     */
    void preOrder() {
        preOrder(root);
    }
    /**
     *  @brief print the tree in post order
     */
    void postOrder() {
        postOrder(root);
    }
    /**
     *  @brief print the tree in level order
     */
    void levelOrder() {
        levelOrder(root);
    }
    /**
     *  @brief prints the tree in a 2d fashion
     */
    void print2D() {
        print2DUtil(root, 0);
    }

    void printNodesAtDistanceK(t_treeNode<T> *node, int k) {
        if (node == nullptr) {
            return;
        }
        if (k == 0) {
            cout << node->data << " ";
        }
        printNodesAtDistanceK(node->left, k - 1);
        printNodesAtDistanceK(node->right, k - 1);
    }

    void verticalOrder() {
        map<int, vector<T>> m;
        verticalOrder(root, m, 0);
        for (auto &it : m) {
            for (auto &it2 : it.second) {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }

    // getters
    /**
     * @brief get the root of the tree
     *  @return the root of the tree
     */
    t_treeNode<T> *getRoot() {
        return root;
    }
    /**
     * @brief get the size of the tree
     * @return the size of the tree
     */
    int getSize() {
        return size;
    }
    /**
     *  @brief get the height of the tree
     * @return  the height of the tree from the node
     */
    int getHeight() {
        return getHeight(root);
    }

    /**
     * @brief get the diameter of the tree
     * @return  the diameter of the tree
     */
    int getDiameter() {
        return getDiameter(root);
    }

    /**
     *  @brief get the balance factor of the tree
     * @return  the balance factor of the tree from the node
     */
    int getBalanceFactor() {
        return getBalanceFactor(root);
    }

    /**
     *  @brief balance the tree
     */
    void balance() {
        balance(root);
    }
    /**
     * @brief replaces each node with the sum of its left and right subtrees
     */
    void replaceWithSums() {
        replaceWithSums(root);
    }
    /**
     * @brief counts the number of leaves in the tree
     * @return  the number of leaves in the tree
     */
    int countLeaves() {
        return getLeaves(root);
    }

    int getCount() {
        return getCount(root);
    }

    /**
     * @brief sums the nodes in the tree
     * @return  the sum of the nodes in the tree
     */
    double sum() {
        return sum(root);
    }

    // median
    /**
     * @brief finds the median of the tree
     * @return  the median of the tree
     */
    double median() {
        return median(root);
    }

    double mean() {
        return this->average();
    }
    /**
     * @brief finds the average of the tree
     * @return  the average of the tree
     */
    double average() {
        return average(root);
    }
    /**
     * @brief finds the standard deviation of the tree
     * @return  the standard deviation of the tree
     */
    double standardDeviation() {
        return standardDeviation(root);
    }

    double variance(const string& type = "population") {
        return variance(root, type);
    }
    double covariance(t_treeNode<T> *node, string type = "population") {
        return covariance(root, node, type);
    }

    /**
     * @brief finds the standard error of the tree
     * @return  the standard error of the tree
     */
    double standardError() {
        return standardError(root);
    }

    double sumOfSquaredMeanDifferences() {
        return sumOfSquaredMeanDifferences(root);
    }

    /**
     * @brief finds the mode of the tree
     * @return  the mode of the tree
     */
    T mode() {
        return mode(root);
    }
    /**
     * @brief finds the skewness, or the ratio of the difference between the
     * mean and the median to the standard deviation
     * @return
     */
    double skewness() {
        return skewness(root);
    }

    double kurtosis() {
        return kurtosis(root);
    }

    double range() {
        // difference between max and min
        return max() - min();
    }
    /**
     * @brief finds the correlation coefficient between two trees
     * @param node  the node to compare to
     * @return  the correlation coefficient between the two trees
     */
    double correlationCoefficient(t_treeNode<T> *node) {
        return correlationCoefficient(root, node);
    }

    /**
     * @brief finds the confidence interval of the tree
     * @param confidence  the confidence level as a decimal
     * @return  a pair of doubles that represent the lower and upper bounds
     * of the confidence interval
     */
    pair<double, double> confidenceInterval(double confidence) {
        return confidenceInterval(root, confidence);
    }
    /**
     * @brief checks to see if the tree is empty
     * @return true if tree is empty else false
     */
    bool isEmpty() {
        return root == nullptr;
    }
    bool isPresent(T value) {
        return isPresent(root, value);
    }

    void fillTreeFromFile(const string& filename, char delimiter) {
        ifstream file;
        file.open(filename);
        string line;
        vector<T> tokens;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            while (getline(ss, token, delimiter)) {
                tokens.push_back(stod(token));
            }
        }
        file.close();
        for (auto& token : tokens) {
            insert(token);
        }
    }

    /**
     * destructor
     */
    ~t_BST() {
        destroyTree(root);
    }

}; // end of t_BST class

#endif //LEETCODE_T_BST_H
