////
//// Created by Ryan.Zurrin001 on 1/6/2022.
////
//
//#pragma ide diagnostic ignored "bugprone-branch-clone"
//#pragma ide diagnostic ignored "OCDFAInspection"
//#pragma ide diagnostic ignored "cert-err58-cpp"
//#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//#pragma ide diagnostic ignored "misc-no-recursion"
//#include<bits/stdc++.h>
//#include <string>
//#include <utility>
//#include <vector>
//#include <climits>
//#include <iostream>
//#include <ostream>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <queue>
//#include <bitset>
//#include <stack>
//#include <unordered_set>
//
//// A macro that defines the size of an integer
//#define INT_SIZE sizeof(int) * 8
//using namespace std;
//
//
//
//class  Point {
//public:
//     int x;
//     int y;
//    Point() : x(0), y(0) {}
//    Point(int a, int b) : x(a), y(b) {}
//};
//
//class  PointComparator {
//public:
//    bool operator()(const Point &a, const Point &b) const {
//        if (a.x == b.x) {
//            return a.y < b.y;
//        }
//        return a.x < b.x;
//    }
//};
//
//class  Car {
//public:
//     string id;
//    int x;
//    int y;
//    Car(string id, int x, int y) : id(std::move(id)), x(x), y(y) {}
//     [[nodiscard]] int dist() const {
//        return x*x + y*y;
//    }
//};
//
//class CarComparator {
//public:
//    bool operator()(const Car &a, const Car &b) const {
//        return a.dist() < b.dist(); // makes a min heap
//    }
//};
///*
//5 3
//c1 1 1
//c2 2 1
//c3 3 2
//c4 0 1
//c5 2 3
// */
// void printNearestCars(vector<Car> &cars, int k) {
//    priority_queue<Car, vector<Car>, CarComparator> pq;
//    for (auto &car : cars) {
//        pq.push(car);
//        if (pq.size() > k) {
//            pq.pop();
//        }
//    }
//    vector<Car> result;
//    while (!pq.empty()) {
//        result.push_back(pq.top());
//        pq.pop();
//    }
//    reverse(result.begin(), result.end());
//    for (auto &car : result) {
//        cout << car.id << endl;
//    }
//    cout << endl;
//}
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) :
//            val(x), left(left), right(right) {}
//};
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    explicit ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//struct LinkedList {
//    ListNode *head;
//    LinkedList() : head(nullptr) {}
//     explicit LinkedList(ListNode *head) : head(head) {}
//};
//
//class Node {
//public:
//     int val{};
//    Node* left;
//    Node* right;
//     Node* next;
//    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
//    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
//    Node(int _val, Node* _left, Node* _right, Node* _next)
//            : val(_val), left(_left), right(_right), next(_next) {}
//};
//
//class bt_node{
//
//public:
//    int data;
//    bt_node*left;
//    bt_node*right;
//
//     explicit bt_node(int d){
//        data = d;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
// int find(bt_node* root, int val, int level) {
//    if (root == nullptr) {
//        return -1;
//    }
//    if (root->data == val) {
//        return level;
//    }
//    int l = find(root->left, val, level + 1);
//    if (l != -1) {
//        return l;
//    }
//    return find(root->right, val, level + 1);
//}
//
// bt_node* lowestCommonAncestor(bt_node* root, int a, int b){
//    //Complete this function and return address of the node
//    //which is the lowest common ancestor of the two nodes
//    //HINT : Use the same logic as in the previous question
//    if(root == nullptr)
//        return nullptr;
//    if(root->data == a || root->data == b)
//        return root;
//    return root;
//    bt_node*left = lowestCommonAncestor(root->left, a, b);
//    bt_node*right = lowestCommonAncestor(root->right, a, b);
//    if(left != nullptr && right != nullptr)
//        return root;
//    if(left != nullptr)
//        return left;
//    return right;
//}
//
//
////here nodes a and b are the inputs
//  int shortestDist(bt_node * root,int a,int b){
//    //Complete this method
//    bt_node* lca = lowestCommonAncestor(root,a,b);
//    int dist_a = find(lca,a,0);
//    int dist_b = find(lca,b,0);
//    return dist_a + dist_b;}
//
//
//
//bt_node* findTarget(bt_node* root, bt_node* target, int& levFromRoot) {
//    if(root == nullptr) return nullptr;
//    if(root->data == target->data) return root;
//    bt_node* left = findTarget(root->left, target, levFromRoot);
//    if(left != nullptr) {
//        levFromRoot += 1;
//        return left;
//    }
//    bt_node* right = findTarget(root->right, target, levFromRoot);
//    if(right != nullptr) {
//        levFromRoot += 1;
//        return right;
//    }
//    return nullptr;
//}
//
//void nodesAtDistanceK(bt_node* root, int k, vector<int>& v) {
//    // k + levFromRoot is the distance from root to targets
//    if(root == nullptr) return;
//    if(k == 0) {
//        v.push_back(root->data);
//        return;
//    }
//    nodesAtDistanceK(root->left, k - 1, v);
//    nodesAtDistanceK(root->right, k - 1, v);
//    // sort the vector
//    sort(v.begin(), v.end());
//}
//
// vector<int> nodesAtDistanceK(bt_node *root, bt_node *target, int k){
//    vector<int> v;
//    int levFromRoot = 0;
//    bt_node* node = findTarget(root, target, levFromRoot);
//    int newK = k + levFromRoot;
//    if(node == nullptr) return v;
//    nodesAtDistanceK(root, newK, v);
//    return v;
//}
//
// vector<int> leftView(bt_node * root){
//    // visit all node in the left subtree
//
//    vector<int> v;
//    if(root == nullptr) return v;
//    queue<bt_node*> q;
//    q.push(root);
//    while(!q.empty()) {
//        int size = q.size();
//        for(int i = 0; i < size; i++) {
//            bt_node* node = q.front();
//            q.pop();
//            if(i == 0) v.push_back(node->data);
//            if(node->left != nullptr) q.push(node->left);
//            if(node->right != nullptr) q.push(node->right);
//        }
//    }
//    return v;
//}
///**
// * Determine if a binary tree can be converted to another by doing any number of
// * swaps of children.
// * @param root1  root of first tree
// * @param root2  root of second tree
// * @return     true if trees can  be converted, false otherwise
// */
//bool equal(bt_node * root1, bt_node * root2){
//    if(root1 == root2) return true;
//    return (root1 && root2) && (root1->data == root2->data) &&
//           (equal(root1->left, root2->left) && equal(root1->right, root2->right)) ||
//           (equal(root1->right, root2->left) && equal(root1->left, root2->right));
//
//}
//
// bool isBST(bt_node * root){
//    //complete this method using iterative approach
//    if(root == nullptr) return true;
//    stack<bt_node*> s;
//    bt_node* prev = nullptr;
//    while(!s.empty() || root != nullptr) {
//        while(root != nullptr) {
//            s.push(root);
//            root = root->left;
//        }
//        root = s.top();
//        s.pop();
//        if(prev != nullptr && root->data < prev->data) return false;
//        prev = root;
//        root = root->right;
//    }
//    return true;
//}
//
////_________________________template linked list_________________________________
//template <typename T>
//class t_node{
//    T data;
//    t_node* next;
//public:
//    explicit t_node(T data){
//        this->data = data;
//        this->next = nullptr;
//    }
//    t_node(T data, t_node* next){
//        this->data = data;
//        this->next = next;
//    }
//    T getData(){
//        return this->data;
//    }
//    t_node* getNext(){
//        return this->next;
//    }
//
//     void setData(T data_){
//        this->data = data_;
//    }
//    void setNext(t_node* newNext){
//        this->next = newNext;
//    }
//};
//template <typename T>
// bool isPresent(t_node<T> * head, T key){
//    //Complete this function
//    t_node<T> * temp = head;
//    while(temp != nullptr){
//        if(temp->getData() == key){
//            return true;
//        }
//        temp = temp->getNext();
//    }
//    return false;
//}
//template<typename T>
//void insertAtFront(t_node<T> ** head, T data){
//    if (*head == nullptr){
//        *head = new t_node<T>(data);
//    }
//    else{
//        auto * temp = new t_node<T>(data, *head);
//        *head = temp;
//    }
//}
//
//template<typename T>
//void insertAtEnd(t_node<T> ** head, T data){
//    if (*head == nullptr){
//        *head = new t_node<T>(data);
//    }
//    else{
//        t_node<T> * temp = *head;
//        while(temp->getNext() != nullptr){
//            temp = temp->getNext();
//        }
//        temp->setNext(new t_node<T>(data));
//    }
//}
//
//template<typename T>
// void insertAtPosition(t_node<T> ** head, T data, int position){
//    if (*head == nullptr){
//        *head = new t_node<T>(data);
//    }
//    else{
//        t_node<T> * temp = *head;
//        int count = 0;
//        while(temp->getNext() != nullptr){
//            temp = temp->getNext();
//            count++;
//        }
//        if(position == 0){
//            insertAtFront(head, data);
//        }
//        else if(position == count+1){
//            insertAtEnd(head, data);
//        }
//        else{
//            temp = *head;
//            count = 0;
//            while(count < position-1){
//                temp = temp->getNext();
//                count++;
//            }
//            t_node<T> * temp2 = temp->getNext();
//            temp->setNext(new t_node<T>(data, temp2));
//        }
//    }
//}
//
//template<typename T>
// void printAll(t_node<T> * head){
//    t_node<T> * temp = head;
//    while(temp != nullptr){
//        cout << temp->getData() << " ";
//        temp = temp->getNext();
//    }
//    cout << endl;
//}
//
//template<typename T>
//t_node<T>* findNode(t_node<T> * head, T key){
//    t_node<T> * temp = head;
//    while(temp != nullptr){
//        if(temp->getData() == key){
//            return temp;
//        }
//        temp = temp->getNext();
//    }
//    return nullptr;
//}
//
//template<typename T>
//void deleteNode(t_node<T> ** head, T data){
//    if (*head == nullptr){
//        return;
//    }
//    else{
//        t_node<T> * temp = *head;
//        if(temp->getData() == data){
//            *head = temp->getNext();
//            delete temp;
//        }
//        else{
//            while(temp->getNext() != nullptr){
//                if(temp->getNext()->getData() == data){
//                    t_node<T> * temp2 = temp->getNext();
//                    temp->setNext(temp2->getNext());
//                    delete temp2;
//                    break;
//                }
//                temp = temp->getNext();
//            }
//        }
//    }
//}
//
//template<typename T>
//int size(t_node<T> * head){
//    if(head == nullptr){
//        return 0;
//    }
//    else{
//        int count = 0;
//        t_node<T> * temp = head;
//        while(temp != nullptr){
//            count++;
//            temp = temp->getNext();
//        }
//        return count;
//    }
//}
//
//template<typename T>
//int keyCount(t_node<T> * head, T key){
//    if(head == nullptr){
//        return 0;
//    }
//    else{
//        int count = 0;
//        t_node<T> * temp = head;
//        while(temp != nullptr){
//            if(temp->getData() == key){
//                count++;
//            }
//            temp = temp->getNext();
//        }
//        return count;
//    }
//}
//
//template<typename T>
// void deleteAllNodesWIthKey(t_node<T>*& head, T key){
//    if (head == nullptr){
//        return;
//    }
//    else{
//        do {
//            t_node<T> * temp = findNode(head, key);
//            if(temp != nullptr){
//                deleteNode(&head, key);
//            }
//        } while (keyCount(head, key) > 0);
//    }
//}
//
//template<typename T>
// void deleteList(t_node<T> ** head){
//    if (*head == nullptr){
//        return;
//    }
//    else{
//        t_node<T> * temp = *head;
//        while(temp != nullptr){
//            t_node<T> * temp2 = temp;
//            temp = temp->getNext();
//            delete temp2;
//        }
//        *head = nullptr;
//    }
//}
//
//template<typename T>
// void reverseList(t_node<T> *& head){
//    if (*head == nullptr){
//        return;
//    }
//    else{
//        t_node<T> * temp = *head;
//        t_node<T> * prev = nullptr;
//        while(temp != nullptr){
//            t_node<T> * temp2 = temp->getNext();
//            temp->setNext(prev);
//            prev = temp;
//            temp = temp2;
//        }
//        *head = prev;
//    }
//}
//
//template<typename T>
// t_node<T>* sortList(t_node<T> * head){
//    if(head == nullptr){
//        return nullptr;
//    }
//    else {
//        t_node<T>* curr = head;
//        int count = size(head);
//        vector<t_node<T>*> v;
//        for (int i = 0; i < count; i++) {
//            v.push_back(curr);
//            curr = curr->getNext();
//        }
//        sort(v.begin(), v.end(), [](t_node<T>* a, t_node<T>* b) {
//            return a->getData() < b->getData();
//        });
//        t_node<T>* newHead = nullptr;
//        for (int i = 0; i < count; i++) {
//            insertAtEnd(&newHead, v[i]->getData());
//        }
//        return newHead;
//    }
//}
//
//template<typename T>
//t_node<T>* merge(t_node<T> * head1, t_node<T> * head2){
//    if(head1 == nullptr){
//        return head2;
//    }
//    else if(head2 == nullptr){
//        return head1;
//    }
//    else{
//        t_node<T> * newHead = nullptr;
//        while (head1 != nullptr && head2 != nullptr){
//            if(head1->getData() < head2->getData()){
//                insertAtEnd(&newHead, head1->getData());
//                head1 = head1->getNext();
//            }
//            else{
//                insertAtEnd(&newHead, head2->getData());
//                head2 = head2->getNext();
//            }
//        }
//        while(head1 != nullptr){
//            insertAtEnd(&newHead, head1->getData());
//            head1 = head1->getNext();
//        }
//        while(head2 != nullptr){
//            insertAtEnd(&newHead, head2->getData());
//            head2 = head2->getNext();
//        }
//        return newHead;
//    }
//}
//
//template<typename T>
//t_node<T>* findMiddleNode(t_node<T> * head){
//    if(head == nullptr){
//        return nullptr;
//    }
//    else{
//        t_node<T> * slow = head;
//        t_node<T> * fast = head->getNext();
//        while(fast != nullptr && fast->getNext() != nullptr){
//            slow = slow->getNext();
//            fast = fast->getNext()->getNext();
//        }
//        return slow;
//    }
//}
//
//template<typename T>
// T getMid(t_node<T> * head){
//    if(head == nullptr){
//        return nullptr;
//    }
//    else{
//        t_node<T> * slow = head;
//        t_node<T> * fast = head->getNext();
//        while(fast != nullptr && fast->getNext() != nullptr){
//            slow = slow->getNext();
//            fast = fast->getNext()->getNext();
//        }
//        return slow->getData();
//    }
//}
//
//template<typename T>
// T kthLastElement(t_node<T> * head, int k){
//    if(head == nullptr){
//        return nullptr;
//    }
//    else{
//        t_node<T> * slow = head;
//        t_node<T> * fast = head;
//        for(int i = 0; i < k; i++){
//            fast = fast->getNext();
//        }
//        while(fast != nullptr){
//            slow = slow->getNext();
//            fast = fast->getNext();
//        }
//        return slow->getData();
//    }
//}
//
//template<typename T>
// t_node<T>* partition(t_node<T> * head, T x){
//    if(head == nullptr){
//        return nullptr;
//    }
//    else{
//        t_node<T> * smallerHead = nullptr;
//        t_node<T> * largerHead = nullptr;
//        t_node<T> * smaller = nullptr;
//        t_node<T> * larger = nullptr;
//        while(head != nullptr){
//            if(head->getData() < x){
//                insertAtEnd(&smallerHead, head->getData());
//                head = head->getNext();
//            }
//            else{
//                insertAtEnd(&largerHead, head->getData());
//                head = head->getNext();
//            }
//        }
//        smaller = smallerHead;
//        larger = largerHead;
//        while(smaller != nullptr && larger != nullptr){
//            t_node<T> * temp = smaller->getNext();
//            smaller->setNext(larger);
//            smaller = temp;
//            temp = larger->getNext();
//            larger->setNext(smaller);
//            larger = temp;
//        }
//        if(smaller == nullptr){
//            return largerHead;
//        }
//        else{
//            return smallerHead;
//        }
//    }
//}
//
//template<typename T>
//t_node<T>* mergeSort(t_node<T> * head){
//    if(head == nullptr || head->getNext() == nullptr){
//        return head;
//    }
//    else{
//        t_node<T> * mid = findMiddleNode(head);
//        t_node<T> * left = head;
//        t_node<T> * right = mid->getNext();
//        mid->setNext(nullptr);
//        left = mergeSort(left);
//        right = mergeSort(right);
//        return merge(left, right);
//    }
//}
//
//template<typename T>
// bool hasCycle(t_node<T> * head){
//    if(head == nullptr){
//        return false;
//    }
//    else{
//        t_node<T> * slow = head;
//        t_node<T> * fast = head;
//        while(fast != nullptr && fast->getNext() != nullptr){
//            slow = slow->getNext();
//            fast = fast->getNext()->getNext();
//            if(slow == fast){
//                return true;
//            }
//        }
//        return false;
//    }
//}
//
////___________________________end template linked list __________________________
////______________________________________________________________________________
////___________________________Udemy course Linked List___________________________
//class node {
//public:
//    int data;
//    node* next;
//    explicit node(int data) {
//        this->data = data;
//        this->next = nullptr;
//    }
//};
//
// bool isPresent(node* head, int key){
//    node* temp = head;
//    while(temp != nullptr){
//        if(temp->data == key){
//            return true;
//        }
//        temp = temp->next;
//    }
//    return false;
//}
//
//void insertAtHead(node*& head, int data) {
//    if (head == nullptr) {
//        head = new node(data);
//    } else {
//        node* temp = new node(data);
//        temp->next = head;
//        head = temp;
//    }
//}
//
// void insertInMiddle(node*& head, int data, int pos) {
//    if (pos == 0) {
//        insertAtHead(head, data);
//    } else {
//        node* temp = head;
//        int count = 0;
//        while (temp != nullptr && count < pos - 1) {
//            temp = temp->next;
//            count++;
//        }
//        if (temp != nullptr) {
//            node* temp2 = temp->next;
//            temp->next = new node(data);
//            temp->next->next = temp2;
//        }
//    }
//}
//
//void insertAtEnd(node*& head, int data) {
//    if (head == nullptr) {
//        head = new node(data);
//    } else {
//        node* temp = head;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = new node(data);
//    }
//}
//
// void reverseList(node*& head) {
//    node* prev = nullptr;
//    node* curr = head;
//    node* next = nullptr;
//    while (curr != nullptr) {
//        next = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = next;
//    }
//    head = prev;
//}
//
//node* recReverse(node*& head) {
//    if (head == nullptr || head->next == nullptr) {
//        return head;
//    }
//    node* sHead = recReverse(head->next);
//    head->next->next = head;
//    head->next = nullptr;
//    return sHead;
//}
//
//node* kReverse(node* head, int k) {
//    if (head == nullptr) {
//        return nullptr;
//    }
//    node* curr = head;
//    node* prev = nullptr;
//    node* next = nullptr;
//    int count = 0;
//    while (curr != nullptr && count < k) {
//        next = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = next;
//        count++;
//    }
//    if (next != nullptr) {
//        head->next = kReverse(next, k);
//    }
//    return prev;
//}
//
// void printAll(node* head) {
//    node* temp = head;
//    while (temp != nullptr) {
//        cout << temp->data << "-->";
//        temp = temp->next;
//    }
//    cout << endl;
//}
//
// node* sortList(node* head) {
//    // store all the nodes in a vector and then sort it and add to a new list and
//    // return the new list
//    vector<node*> v;
//    node* temp = head;
//    int count = 0;
//    while (temp != nullptr) {
//        v.push_back(temp);
//        temp = temp->next;
//        count++;
//    }
//    sort(v.begin(), v.end(), [](node* a, node* b) {
//        return a->data < b->data;
//    });
//    node* newHead = nullptr;
//    for (int i = 0; i < count; i++) {
//        insertAtEnd(newHead, v[i]->data);
//    }
//    return newHead;
//}
//
//node* merge(node* a, node* b) {
//    if(a == nullptr){
//        return b;
//    }
//    if(b == nullptr){
//        return a;
//    }
//    node * c = nullptr;
//    while (a != nullptr && b != nullptr) {
//        if (a->data < b->data) {
//            insertAtEnd(c, a->data);
//            a = a->next;
//        } else {
//            insertAtEnd(c, b->data);
//            b = b->next;
//        }
//    }
//    while (a != nullptr) {
//        insertAtEnd(c, a->data);
//        a = a->next;
//    }
//    while (b != nullptr) {
//        insertAtEnd(c, b->data);
//        b = b->next;
//    }
//    return c;
//}
//// if 8 nodes 1,2,3,4,5,6,7,8 are given mid will return 4
// int getMid(node* head) {
//    if (head == nullptr) {
//        return -1;
//    }
//    node* slow = head;
//    // if even number of nodes return the node on the lesser side of the list
//    // for instance if there are 8 nodes return the 4th node
//    for (node* fast = head->next; fast != nullptr; fast = fast->next) {
//        if (fast->next == nullptr) {
//            return slow->data;
//        }
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow->data;
//}
//
// int kthLastElement(node *head, int k){
//    if(head == nullptr){
//        return -1;
//    }
//    node* slow = head;
//    node* fast = head;
//    for(int i = 0; i < k; i++){
//        if(fast == nullptr){
//            return -1;
//        }
//        fast = fast->next;
//    }
//    while(fast != nullptr){
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow->data;
//}
//
//node* midPoint(node* head){
//    if(head == nullptr){
//        return nullptr;
//    }
//    node* slow = head;
//    node* fast = head->next;
//    while(fast != nullptr && fast->next != nullptr){
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//node* mergeSort(node* head) {
//    if (head == nullptr || head->next == nullptr) {
//        return head;
//    }
//    node* mid = midPoint(head);
//    node* left = head;
//    node* right = mid->next;
//    mid->next = nullptr;
//    left = mergeSort(left);
//    right = mergeSort(right);
//    return merge(left, right);
//}
//
// bool containsCycle(node *head){
//    if(head == nullptr){
//        return false;
//    }
//    node* slow = head;
//    node* fast = head;
//    while(fast != nullptr && fast->next != nullptr){
//        slow = slow->next;
//        fast = fast->next->next;
//        if(slow == fast){
//            return true;
//        }
//    }
//    return false;
//}
//// given a linked list which contains a cycle, build a hashing algorithm to break
//// the cycle and return the head of the linked list, the last node should point
//// to NULL after breading the cycle. NOTE: it is not guaranteed that each element of
//// the linked list is unique.
// node * breakCycle(node * head){
//    if(head == nullptr){
//        return nullptr;
//    }
//    unordered_map<node*, bool> m;
//    node* temp = head;
//    // add values to the map until temp->next is already in the map
//    while(temp != nullptr && m.find(temp->next) == m.end()){
//        m[temp] = true;
//        temp = temp->next;
//    }
//    temp->next = nullptr;
//    return head;
//
//}
//
////___________________________end Udemy course Linked List_______________________
////______________________________________________________________________________
////_____________________________Udemy course Stack_______________________________
//template <class T>
//class stackNode {
//public:
//    T data;
//    stackNode<T> *next;
//    explicit stackNode(T data) {
//        this->data = data;
//        this->next = nullptr;
//    }
//};
//template <class T>
//class Stack {
//public:
//    stackNode<T> *top;
//    int size{};
//    Stack() {
//        top = nullptr;
//        size = 0;
//    }
//    void push(T data) {
//        auto *newNode = new stackNode<T>(data);
//        newNode->next = top;
//        top = newNode;
//        size++;
//    }
//    T pop() {
//        if (top == nullptr) {
//            // -1 or if pair then pair{-1,-1}
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        stackNode<T> *temp = top;
//        top = top->next;
//        size--;
//        return temp->data;
//    }
//    T peek() {
//        if (top == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        return top->data;
//    }
//    bool isEmpty() {
//        return top == nullptr;
//    }
//     int getSize() {
//        return size;
//    }
//     void printStack() {
//        stackNode<T> *temp = top;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//     void empty() {
//        stackNode<T> *temp = top;
//        while (temp != nullptr) {
//            top = top->next;
//            delete temp;
//            temp = top;
//        }
//        size = 0;
//    }
//
//}; // end of class Stack
//
//// reverse a stack
// void reverseStack(Stack<int> *s) {
//    auto *temp = new Stack<int>();
//    while (!s->isEmpty()) {
//        temp->push(s->pop());
//    }
//    while (!temp->isEmpty()) {
//        s->push(temp->pop());
//    }
//}
//
//// check if a string is palindrome
// bool palindrome(const string& str) {
//    auto *s = new Stack<char>();
//    for (char i : str) {
//        s->push(i);
//    }
//    for (char i : str) {
//        if (s->pop() != i) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// check if a string is an anagram
// bool isAnagram(const string& str1, const string& str2) {
//    if (str1.length() != str2.length()) {
//        return false;
//    }
//    auto *s1 = new Stack<char>();
//    auto *s2 = new Stack<char>();
//    for (char i : str1) {
//        s1->push(i);
//    }
//    for (char i : str2) {
//        s2->push(i);
//    }
//    for (int i = 0; i < str1.length(); i++) {
//        if (s1->pop() != s2->pop()) {
//            return false;
//        }
//    }
//    return true;
//}
//
//vector<int> getHashValue(string s, int i, int j) {
//    vector<int> freq(26, 0);
//    for (int k = i; k <= j; k++) {
//        char ch = s[k];
//        freq[ch - 'a']++;
//    }
//    return freq;
//}
//
//// given a string, find the number of pairs of substrings of the string that
//// are anagrams of each other
// int countAnagrams(const string& str) {
//    // generate all substrings
//    map<vector<int>, int> hashMap;
//    int anagramCount = 0;
//    for (int i = 0; i < str.length(); i++) {
//        for (int j = i; j < str.length(); j++) {
//            // get hash value of substring
//            vector<int> freq = getHashValue(str, i, j);
//            // check if hash value is present in hash table
//            hashMap[freq]++;
//        }
//    }
//    for (auto& it : hashMap) {
//        int freq = it.second;
//        if (freq > 1) {
//            anagramCount += freq * (freq - 1) / 2;
//        }
//    }
//    return anagramCount;
//}
//
// vector<vector<string>> groupAnagrams(const vector<string>& strs){
//    unordered_map<string, int> hashMap;
//    vector<vector<string>> result;
//    for (auto & str : strs) {
//        string s = str;
//        sort(s.begin(), s.end());
//        if (hashMap.find(s) == hashMap.end()) {
//            vector<string> temp;
//            temp.push_back(str);
//            result.push_back(temp);
//            hashMap[s] = result.size() - 1;
//        } else {
//            result[hashMap[s]].push_back(str);
//        }
//    }
//    return result;
//}
//
//// is balanced parenthesis
//bool isBalanced(const string& input) {
//    // use a stack and a switch case
//    Stack<char> s;
//    for (auto ch : input) {
//        switch (ch) {
//            case '(':
//            case '[':
//            case '{':
//                s.push(ch);
//                break;
//            case ')':
//                if (!s.isEmpty() && s.peek() == '(') {
//                    s.pop();
//                } else {
//                    return false;
//                }
//                break;
//            case ']':
//                if (!s.isEmpty() && s.peek() == '[') {
//                    s.pop();
//                } else {
//                    return false;
//                }
//                break;
//            case '}':
//                if (!s.isEmpty() && s.peek() == '{') {
//                    s.pop();
//                } else {
//                    return false;
//                }
//                break;
//            default:
//                continue;
//        }
//    }
//    return s.isEmpty();
//}
//
//// check if there is redundant parenthesis, brackets, or braces
// bool isRedundant(const string& input) {
//    // check that input is not empty
//    if (input.length() == 0) {
//        return false;
//    }
//    // make sure that the input has proper matching parenthesis, brackets, or braces
//    bool balanced = isBalanced(input);
//    if (!balanced) {
//        cout << "The input is not balanced" << endl;
//        return true;
//    }
//    Stack<char> s;
//    bool isRedundant = false;
//    for (auto ch : input) {
//        switch (ch) {
//            case ')':
//                isRedundant = true;
//                while (!s.isEmpty() && s.peek() != '(') {
//                    char temp = s.pop();
//                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
//                        isRedundant = false;
//                    }
//                }
//                s.pop();
//                if(isRedundant) {
//                    return true;
//                }
//                break;
//            case ']':
//                isRedundant = true;
//                while (!s.isEmpty() && s.peek() != '[') {
//                    char temp = s.pop();
//                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
//                        isRedundant = false;
//                    }
//                }
//                s.pop();
//                if(isRedundant) {
//                    return true;
//                }
//                break;
//            case '}':
//                isRedundant = true;
//                while (!s.isEmpty() && s.peek() != '{') {
//                    char temp = s.pop();
//                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
//                        isRedundant = false;
//                    }
//                }
//                s.pop();
//                if(isRedundant) {
//                    return true;
//                }
//                break;
//            default:
//                s.push(ch);
//        }
//    }
//    return isRedundant;
//}
//
//// ___________________________end Udemy course Stack____________________________
////______________________________________________________________________________
//// ___________________________Udemy course Queue________________________________
//template <class T>
//class queueNode {
//public:
//    T data;
//    queueNode<T> *next;
//    explicit queueNode(T data) {
//        this->data = data;
//        this->next = nullptr;
//    }
//};
//template <class T>
//class  Queue {
//public:
//    queueNode<T> *front{};
//    queueNode<T> *rear{};
//    int size{};
//    int capacity{};
//    Queue() {
//        this->front = nullptr;
//        this->rear = nullptr;
//        this->size = 0;
//        this->capacity = INT_MAX;
//    }
//
//     explicit Queue(int capacity) {
//        front = nullptr;
//        rear = nullptr;
//        size = 0;
//        this->capacity = capacity;
//    }
//     void enqueue(T data) {
//        if (size == capacity) {
//            return;
//        }
//        auto *newNode = new queueNode<T>(data);
//        if (front == nullptr) {
//            front = newNode;
//            rear = newNode;
//        } else {
//            rear->next = newNode;
//            rear = newNode;
//        }
//        size++;
//    }
//     T dequeue() {
//        if (front == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        queueNode<T> *temp = front;
//        front = front->next;
//        size--;
//        return temp->data;
//    }
//     T peek() {
//        if (front == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        return front->data;
//    }
//
//     void peek(T& val) {
//        if  (front == nullptr) {
//            return;
//        } else {
//            val = front->data;
//        }
//    }
//     bool isEmpty() {
//        return front == nullptr;
//    }
//     int getSize() {
//        return size;
//    }
//     void printQueue() {
//        queueNode<T> *temp = front;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//    void destroyQueue() {
//        queueNode<T> *temp = front;
//        while (temp != nullptr) {
//            front = front->next;
//            delete temp;
//            temp = front;
//        }
//        size = 0;
//    }
//     void resize() {
//        capacity = capacity * 2;
//    }
//     void resize(int newCapacity) {
//        if (newCapacity < size) {
//            cout << "New capacity is smaller than current size" << endl;
//            return;
//        } else {
//            capacity = newCapacity;
//        }
//    }
//    ~Queue() {
//        destroyQueue();
//    }
//}; // end of class Queue
//
///**
// * given a stream of characters (lowercase alphabets), find the first non-repeating
// * character from stream. you need to tell the first non-repeating character in O(1)
// * time at each index. if for a current index there is no such character return '0'
// * for that particular index.
// * @param S  a string of length N  containing lowercase alphabets
// * @return a vector of characters of length N where V[i] character represents first
// * non-repeating character from S[0] to S[i]
// */
//  vector<char> FindFirstNonRepeatingCharacter(const string& S){
//    queue<char> q;
//    vector<char> result;
//    int freq[26] = {0};
//    int index;
//    for (char ch : S) {
//        q.push(ch);
//        freq[ch - 'a']++;
//        while (!q.empty()) {
//            index = q.front() - 'a';
//            if (freq[index] > 1) {
//                q.pop();
//            } else {
//                result.push_back(q.front());
//                break;
//            }
//        }
//        if (q.empty()) {
//            result.push_back('0');
//        }
//    }
//    return result;
//}
//
//// ___________________________end Udemy course Queue____________________________
////______________________________________________________________________________
//// ____________________________Udemy course Deque_______________________________
//template <class T>
//class dequeNode {
//public:
//    T data;
//    dequeNode<T> *next;
//    dequeNode<T> *prev;
//    explicit dequeNode(T data) {
//        this->data = data;
//        this->next = nullptr;
//        this->prev = nullptr;
//    }
//};
//template <class T>
//class  Deque {
//public:
//    dequeNode<T> *front;
//    dequeNode<T> *rear;
//    int size{};
//    int capacity{};
//    Deque() {
//        front = nullptr;
//        rear = nullptr;
//        size = 0;
//        capacity = INT_MAX;
//    }
//
//     explicit Deque(int capacity) {
//        front = nullptr;
//        rear = nullptr;
//        size = 0;
//        this->capacity = capacity;
//    }
//     void pushFront(T data) {
//        if (size == capacity) {
//            cout << "Deque is full" << endl;
//            return;
//        }
//        auto *newNode = new dequeNode<T>(data);
//        if (front == nullptr) {
//            front = newNode;
//            rear = newNode;
//        } else {
//            newNode->next = front;
//            front->prev = newNode;
//            front = newNode;
//        }
//        size++;
//    }
//     void pushBack(T data) {
//        if (size == capacity) {
//            cout << "Deque is full" << endl;
//            return;
//        }
//        auto *newNode = new dequeNode<T>(data);
//        if (rear == nullptr) {
//            front = newNode;
//            rear = newNode;
//        } else {
//            newNode->prev = rear;
//            rear->next = newNode;
//            rear = newNode;
//        }
//        size++;
//    }
//     T popFront() {
//        if (front == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        dequeNode<T> *temp = front;
//        front = front->next;
//        size--;
//        return temp->data;
//    }
//     T popBack() {
//        if (rear == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        dequeNode<T> *temp = rear;
//        rear = rear->prev;
//        size--;
//        return temp->data;
//    }
//     T peekFront() {
//        if (front == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        return front->data;
//    }
//     T peekBack() {
//        if (rear == nullptr) {
//            if constexpr (is_same<T, pair<int, int>>::value) {
//                return pair<int, int>{-1, -1};
//            } else {
//                return -1;
//            }
//        }
//        return rear->data;
//    }
//     bool empty() {
//        return size == 0;
//    }
//     int getSize() {
//        return size;
//    }
//     int getCapacity() {
//        return capacity;
//    }
//     void printDeque() {
//        dequeNode<T> *temp = front;
//        while (temp != nullptr) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//    void destroyDeque() {
//        dequeNode<T> *temp = front;
//        while (temp != nullptr) {
//            front = front->next;
//            delete temp;
//            temp = front;
//        }
//        size = 0;
//    }
//     void resize() {
//        capacity = capacity * 2;
//    }
//     void resize(int newCapacity) {
//        if (size > capacity) {
//            capacity = size;
//        } else {
//            capacity = newCapacity;
//        }
//    }
//    ~Deque() {
//        destroyDeque();
//    }
//}; // end of class Deque
//
//
// int join_ropes(int ropes[], int n) {
//    priority_queue<int, vector<int>, greater<>> pq(ropes, ropes + n);
//
//    int cost = 0;
//
//    while (pq.size() > 1) {
//        int A = pq.top();
//        pq.pop();
//
//        int B = pq.top();
//        pq.pop();
//
//        int new_rope = (A + B);
//        cost += new_rope;
//        pq.push(new_rope);
//    }
//
//    return cost;
//}
//
//template<class T>
// void maxSubArray(vector<T> &A, int k) {
//    Deque<T> Q(k);
//    int n = A.size();
//    int i;
//    //1. process only the first k elements
//    for (i = 0; i < k; i++) {
//        // logic here
//        if(!Q.empty() && A[i] > Q.peekBack()) {
//            Q.popBack();
//        }
//        Q.pushBack(i);
//    }
//    //2. process the rest of the elements
//    for (; i<n; i++) {
//        cout << A[Q.peekFront()] << " ";
//        // logic here
//        while (!Q.empty() && Q.peekFront() <= i - k) {
//            Q.popFront();
//        }
//        while (!Q.empty() && A[i] >= A[Q.peekBack()]) {
//            Q.popBack();
//        }
//        Q.pushBack(i);
//    }
//}
//
//
//// ___________________________end Udemy course Deque____________________________
////______________________________________________________________________________
//
//template <typename T>
//class  Pair {
//     T inc;
//     T exc;
//public:
//    Pair() : inc(0), exc(0) {}
//     Pair(T inc, T exc) : inc(inc), exc(exc) {}
//     T getInc() {
//        return inc;
//    }
//     T getExc() {
//        return exc;
//    }
//
//     void setInc(T inc_) {
//        this->inc = inc_;
//    }
//     void setExc(T exc_) {
//        this->exc = exc_;
//    }
//};
//
//template <typename T>
//class BTNode {
//
//public:
//    T data;
//    BTNode<T> *left;
//    BTNode<T> *right;
//    BTNode() : data(0), left(nullptr), right(nullptr) {}
//    explicit BTNode(T data) : data(data), left(nullptr), right(nullptr) {}
//    T getData() {
//        return data;
//    }
//    BTNode<T> *getLeft() {
//        return left;
//    }
//    BTNode<T> *getRight() {
//        return right;
//    }
//    void setLeft(BTNode<T> *left_) {
//        this->left = left_;
//    }
//    void setRight(BTNode<T> *right_) {
//        this->right = right_;
//    }
//};
//
//template <typename T>
//class  BT {
//public:
//    BT() : root(nullptr) {}
//
//    // buildTree from stdin
//    BTNode<T> *buildTree() {
//        T data;
//        cin >> data;
//        if (data == -1) {
//            return nullptr;
//        }
//        auto *root_ = new BTNode<T>(data);
//        root_->left = buildTree();
//        root_->right = buildTree();
//        return root_;
//    }
//
//     BTNode<T> *getRoot() {
//        return root;
//    }
//
//     void setRoot(BTNode<T> *root_) {
//        this->root = root_;
//    }
//
//     void insert(T data) {
//        auto *newNode = new BTNode<T>(data);
//        if (root == nullptr) {
//            root = newNode;
//            return;
//        }
//        BTNode<T> *temp = root;
//        while (true) {
//            if (data < temp->getData()) {
//                if (temp->getLeft() == nullptr) {
//                    temp->setLeft(newNode);
//                    return;
//                }
//                temp = temp->getLeft();
//            } else {
//                if (temp->getRight() == nullptr) {
//                    temp->setRight(newNode);
//                    return;
//                }
//                temp = temp->getRight();
//            }
//        }
//    }
//    // insert in level order
//     void insertLevelOrder(T data) {
//        auto *newNode = new BTNode<T>(data);
//        if (root == nullptr) {
//            root = newNode;
//            return;
//        }
//        queue<BTNode<T> *> q;
//        q.push(root);
//        while (!q.empty()) {
//            auto *temp = q.front();
//            q.pop();
//            if (temp->getLeft() == nullptr) {
//                temp->setLeft(newNode);
//                return;
//            } else {
//                q.push(temp->getLeft());
//            }
//            if (temp->getRight() == nullptr) {
//                temp->setRight(newNode);
//                return;
//            } else {
//                q.push(temp->getRight());
//            }
//        }
//    }
//    //insert in pre order
//     void insertPreOrder(T data) {
//        auto *newNode = new BTNode<T>(data);
//        if (root == nullptr) {
//            root = newNode;
//            return;
//        }
//        stack<BTNode<T> *> s;
//        s.push(root);
//        while (!s.empty()) {
//            auto *temp = s.top();
//            s.pop();
//            if (temp->getRight() == nullptr) {
//                temp->setRight(newNode);
//                return;
//            } else {
//                s.push(temp->getRight());
//            }
//            if (temp->getLeft() == nullptr) {
//                temp->setLeft(newNode);
//                return;
//            } else {
//                s.push(temp->getLeft());
//            }
//        }
//    }
//    //insert in post order
//     void insertPostOrder(T data) {
//        auto *newNode = new BTNode<T>(data);
//        if (root == nullptr) {
//            root = newNode;
//            return;
//        }
//        stack<BTNode<T> *> s;
//        s.push(root);
//        BTNode<T> *prev = nullptr;
//        while (!s.empty()) {
//            auto *temp = s.top();
//            if ((temp->getLeft() == nullptr && temp->getRight() == nullptr) ||
//                (prev != nullptr && (prev == temp->getLeft() || prev == temp->getRight()))) {
//                s.pop();
//                prev = temp;
//                temp->setData(data);
//                return;
//            } else {
//                if (temp->getRight() != nullptr) {
//                    s.push(temp->getRight());
//                }
//                if (temp->getLeft() != nullptr) {
//                    s.push(temp->getLeft());
//                }
//            }
//        }
//    }
//
//     void inOrder(BTNode<T> *root_) {
//        if (root_ == nullptr) {
//            return;
//        }
//        inOrder(root_->getLeft());
//        cout << root_->getData() << " ";
//        inOrder(root_->getRight());
//    }
//
//     void preOrder(BTNode<T> *root_) {
//        if (root_ == nullptr) {
//            return;
//        }
//        cout << root_->getData() << " ";
//        preOrder(root_->getLeft());
//        preOrder(root_->getRight());
//    }
//
//     void postOrder(BTNode<T> *root_) {
//        if (root_ == nullptr) {
//            return;
//        }
//        postOrder(root_->getLeft());
//        postOrder(root_->getRight());
//        cout << root_->getData() << " ";
//    }
//
//     void levelOrder(BTNode<T> *root_) {
//        if (root_ == nullptr) {
//            return;
//        }
//        queue<BTNode<T> *> q;
//        q.push(root_);
//        q.push(nullptr);
//        while (!q.empty()) {
//            BTNode<T> *temp = q.front();
//            if (temp == nullptr) {
//                cout << endl;
//                q.pop();
//                if (!q.empty()) {
//                    q.push(nullptr);
//                }
//            } else {
//                q.pop();
//                cout << temp->getData() << " ";
//                if (temp->getLeft() != nullptr) {
//                    q.push(temp->getLeft());
//                }
//                if (temp->getRight() != nullptr) {
//                    q.push(temp->getRight());
//                }
//            }
//        }
//    }
//
//     void deleteTree(BTNode<T> *root_) {
//        if (root_ == nullptr) {
//            return;
//        }
//        deleteTree(root_->getLeft());
//        deleteTree(root_->getRight());
//        delete root_;
//    }
//
//    Pair<T> maxSubsetSum(BTNode<T> * root_) {
//        Pair<T> p;
//        if (root_ == nullptr) {
//            p.setInc(0);
//            p.setExc(0);
//            return p;
//        }
//        Pair<T> left = maxSubsetSum(root_->getLeft());
//        Pair<T> right = maxSubsetSum(root_->getRight());
//        p.setInc(root_->getData() + left.getExc() + right.getExc());
//        p.setExc(max(left.getInc(), left.getExc()) + max(right.getInc(), right.getExc()));
//        return p;
//    }
//
//    BTNode<T> *root;
//};
//
//
//// ____________________start Udemy course binary search tree ___________________
//template<class T>
//class t_treeNode {
//public:
//    T data;
//    t_treeNode<T> *left;
//    t_treeNode<T> *right;
//     t_treeNode<T> *parent;
//     explicit t_treeNode(T data) {
//        this->data = data;
//        left = nullptr;
//        right = nullptr;
//        parent = nullptr;
//    }
//}; // end of class t_treeNode
//
//template <class T>
//class  t_BST {
//private:
//    t_treeNode<T> *root;
//    int size{};
//    void insert(t_treeNode<T> *&root_, t_treeNode<T> *&newNode) {
//        if (root_ == nullptr) {
//            root_ = newNode;
//            size++;
//            return;
//        }
//        if (newNode->data < root_->data) {
//            insert(root_->left, newNode);
//        } else {
//            insert(root_->right, newNode);
//        }
//        balance(root_);
//    }
//    void remove(t_treeNode<T> *&node, T data) {
//        if (node == nullptr) {
//            return;
//        }
//        if (data < node->data) {
//            remove(node->left, data);
//        } else if (data > node->data) {
//            remove(node->right, data);
//        } else {
//            if (node->left == nullptr && node->right == nullptr) {
//                delete node;
//                node = nullptr;
//                size--;
//            } else if (node->left == nullptr) {
//                t_treeNode<T> *temp = node;
//                node = node->right;
//                delete temp;
//                size--;
//            } else if (node->right == nullptr) {
//                t_treeNode<T> *temp = node;
//                node = node->left;
//                delete temp;
//                size--;
//            } else {
//                t_treeNode<T> *temp = findMin(node->right);
//                node->data = temp->data;
//                remove(node->right, temp->data);
//            }
//        }
//        balance(node);
//    }
//
//    void removeAll(t_treeNode<T> *&node, T data) {
//        if (node == nullptr) {
//            return;
//        }
//        do {
//            remove(node, data);
//        }while(count(data) > 0);
//    }
//
//    void printTree(t_treeNode<T> *node) {
//        if (node != nullptr) {
//            printTree(node->left);
//            cout << node->data << " ";
//            printTree(node->right);
//        }
//    }
//    void inOrder(t_treeNode<T> *node) {
//        if (node != nullptr) {
//            inOrder(node->left);
//            cout << node->data << " ";
//            inOrder(node->right);
//        }
//    }
//    void preOrder(t_treeNode<T> *node) {
//        if (node != nullptr) {
//            cout << node->data << " ";
//            preOrder(node->left);
//            preOrder(node->right);
//        }
//    }
//    void postOrder(t_treeNode<T> *node) {
//        if (node != nullptr) {
//            postOrder(node->left);
//            postOrder(node->right);
//            cout << node->data << " ";
//        }
//    }
//    void levelOrder(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return;
//        }
//        queue<t_treeNode<T> *> q;
//        q.push(node);
//        q.push(nullptr);
//        while (!q.empty()) {
//            t_treeNode<T> *temp = q.front();
//            if (temp == nullptr) {
//                cout << endl;
//                q.pop();
//                if (!q.empty()) {
//                    q.push(nullptr);
//                }
//            } else {
//                q.pop();
//                cout << temp->data << " ";
//                if (temp->left != nullptr) {
//                    q.push(temp->left);
//                }
//                if (temp->right != nullptr) {
//                    q.push(temp->right);
//                }
//            }
//        }
//    }
//    // print the tree as a 2d tree
//    void print2DUtil(t_treeNode<T> *root_, int space) {
//        if (root_ == nullptr) {
//            return;
//        }
//        space += 10;
//        print2DUtil(root_->right, space);
//        cout << endl;
//        for (int i = 10; i < space; i++) {
//            cout << " ";
//        }
//        cout << root_->data << endl;
//        print2DUtil(root_->left, space);
//    }
//
//
//    void verticalOrder(t_treeNode<T> *node, map<int, vector<T>> &m, int level) {
//        if (node == nullptr) {
//            return;
//        }
//        m[level].push_back(node->data);
//        verticalOrder(node->left, m, level - 1);
//        verticalOrder(node->right, m, level + 1);
//    }
//
//    /**
// * @brief finds the parent of the node, if the node is not in the tree,
// * returns nullptr
// * @param node the node to find the parent of
// * @param data  the data of the node to find the parent of
// * @return  the parent of the node, if the node is not in the tree,
// *  returns nullptr
// */
//    t_treeNode<T> *findParent(t_treeNode<T> *node, T data) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        if (node->left != nullptr && node->left->data == data) {
//            return node;
//        } else if (node->right != nullptr && node->right->data == data) {
//            return node;
//        } else if (data < node->data) {
//            return findParent(node->left, data);
//        } else {
//            return findParent(node->right, data);
//        }
//    }
//    /**
//     * @brief finds the successor of a node, or the leftmost node of the right subtree
//     * @param node  the node to find the successor of
//     * @return the successor of the node
//     */
//     t_treeNode<T> *findSuccessor(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        if (node->right != nullptr) {
//            return findMin(node->right);
//        }
//        t_treeNode<T> *parent = findParent(root, node->data);
//        while (parent != nullptr && parent->right != nullptr &&
//               parent->right->data != node->data) {
//            node = parent;
//            parent = findParent(root, node->data);
//        }
//        return parent;
//    }
//    /**
//     * @brief finds the predecessor of a node, or the right most child of the
//     * left subtree of the node
//     * @param node  the node to find the predecessor of
//     * @return the predecessor of the node
//     */
//     t_treeNode<T> *findPredecessor(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        if (node->left != nullptr) {
//            return findMax(node->left);
//        }
//        t_treeNode<T> *parent = findParent(root, node->data);
//        while (parent != nullptr && parent->left != nullptr &&
//               parent->left->data != node->data) {
//            node = parent;
//            parent = findParent(root, node->data);
//        }
//        return parent;
//    }
//
//    // private balance methods
//    // right rotate
//    void rightRotate(t_treeNode<T> *&node) {
//        t_treeNode<T> *temp = node->left;
//        node->left = temp->right;
//        temp->right = node;
//        node = temp;
//    }
//    // left rotate
//    void leftRotate(t_treeNode<T> *&node) {
//        t_treeNode<T> *temp = node->right;
//        node->right = temp->left;
//        temp->left = node;
//        node = temp;
//    }
//    // rotate left right
//     void leftRightRotate(t_treeNode<T> *&node) {
//        leftRotate(node->left);
//        rightRotate(node);
//    }
//    // rotate right left
//     void rightLeftRotate(t_treeNode<T> *&node) {
//        rightRotate(node->right);
//        leftRotate(node);
//    }
//    // balance tree
//    void balance(t_treeNode<T> *&node) {
//        if (node == nullptr) {
//            return;
//        }
//        int balanceFactor = getBalanceFactor(node);
//        if (balanceFactor > 1) {
//            if (getBalanceFactor(node->left) < 0) {
//                leftRotate(node->left);
//            }
//            rightRotate(node);
//        } else if (balanceFactor < -1) {
//            if (getBalanceFactor(node->right) > 0) {
//                rightRotate(node->right);
//            }
//            leftRotate(node);
//        }
//    }
//    // get leaves
//    int getLeaves(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        if (node->left == nullptr && node->right == nullptr) {
//            return 1;
//        }
//        return getLeaves(node->left) + getLeaves(node->right);
//    }
//
//    t_treeNode<T> *find(t_treeNode<T> *node, T data) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        if (data == node->data) {
//            return node;
//        } else if (data < node->data) {
//            return find(node->left, data);
//        } else {
//            return find(node->right, data);
//        }
//    }
//    t_treeNode<T> *findMin(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        while (node->left != nullptr) {
//            node = node->left;
//        }
//        return node;
//    }
//    t_treeNode<T> *findMax(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        while (node->right != nullptr) {
//            node = node->right;
//        }
//        return node;
//    }
//    void destroyTree(t_treeNode<T> *node) {
//        if (node != nullptr) {
//            destroyTree(node->left);
//            destroyTree(node->right);
//            delete node;
//        }
//    }
//     int getBalanceFactor(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        return getHeight(node->left) - getHeight(node->right);
//    }
//    int getHeight(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int leftHeight = getHeight(node->left);
//        int rightHeight = getHeight(node->right);
//        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
//    }
//    int getDiameter(t_treeNode<T>* root_) {
//        if (root_ == nullptr) {
//            return 0;
//        }
//        int leftHeight = getHeight(root_->left);
//        int rightHeight = getHeight(root_->right);
//        int leftDiameter = getDiameter(root_->left);
//        int rightDiameter = getDiameter(root_->right);
//        return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
//    }
//
//    int getCount(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        return getCount(node->left) + getCount(node->right) + 1;
//    }
//
//    T replaceWithSums(t_treeNode<T> *&node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        if (node->left == nullptr && node->right == nullptr) {
//            return node->data;
//        }
//
//        T leftSum = replaceWithSums(node->left);
//        T rightSum = replaceWithSums(node->right);
//        T temp = node->data;
//        node->data = leftSum + rightSum;
//        return node->data + temp;
//    }
//
//     double sum(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        if (node->left == nullptr && node->right == nullptr) {
//            return node->data;
//        }
//
//        double leftSum = sum(node->left);
//        double rightSum = sum(node->right);
//        return node->data + leftSum + rightSum;
//    }
//
//     double median(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        int currCount = 0;
//        auto *current = node;
//        double median = 0;
//        t_treeNode<T> *pre = nullptr;
//        t_treeNode<T> *prev = nullptr;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                if (currCount == count / 2) {
//                    median = current->data;
//                }
//                currCount++;
//                current = current->right;
//            } else {
//                pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    if (currCount == count / 2) {
//                        median = current->data;
//                    }
//                    currCount++;
//                    current = current->right;
//                }
//            }
//        }
//        return median;
//    }
//
//     double average(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double sum = this->sum(node);
//        return sum / count;
//    }
//
//    double standardDeviation(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double average = this->average();
//        double sum = 0;
//        auto *current = node;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                sum += pow(current->data - average, 2);
//                current = current->right;
//            } else {
//                auto *pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    sum += pow(current->data - average, 2);
//                    current = current->right;
//                }
//            }
//        }
//        return sqrt(sum / count);
//    }
//
//    double standardError(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double standardDeviation = this->standardDeviation();
//        return standardDeviation / sqrt(count);
//    }
//
//     double variance(t_treeNode<T> *node, const string& type) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double average = this->average();
//        double sum = 0;
//        auto *current = node;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                sum += pow(current->data - average, 2);
//                current = current->right;
//            } else {
//                auto *pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    sum += pow(current->data - average, 2);
//                    current = current->right;
//                }
//            }
//        }
//        if (type == "population") {
//            return sum / count;
//        } else {
//            return sum / (count - 1);
//        }
//    }
//
//    double covariance(t_treeNode<T> *root_, t_treeNode<T> *node, const string& type) {
//        if (root_ == nullptr || node == nullptr) {
//            return 0;
//        }
//        int count = getCount(root_);
//        double sum_XY = 0;
//        double rootAvg = average(root);
//        double nodeAvg = average(node);
//        double squareSum_X = this->sumOfSquaredMeanDifferences(root);
//        double squareSum_Y = this->sumOfSquaredMeanDifferences(node);
//        vector<T> x;
//        vector<T> y;
//        // adding the root data to the vector x
//        while (root_ != nullptr) {
//            if (root_->left == nullptr) {
//                x.push_back(root_->data);
//                root_ = root_->right;
//            } else {
//                auto *pre = root_->left;
//                while (pre->right != nullptr && pre->right != root_) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = root_;
//                    root_ = root_->left;
//                } else {
//                    pre->right = nullptr;
//                    x.push_back(root_->data);
//                    root_ = root_->right;
//                }
//            }
//        }
//        // adding the node data to the vector y
//        while (node != nullptr) {
//            if (node->left == nullptr) {
//                y.push_back(node->data);
//                node = node->right;
//            } else {
//                auto *pre = node->left;
//                while (pre->right != nullptr && pre->right != node) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = node;
//                    node = node->left;
//                } else {
//                    pre->right = nullptr;
//                    y.push_back(node->data);
//                    node = node->right;
//                }
//            }
//        }
//        // sort the vectors
//        sort(x.begin(), x.end());
//        sort(y.begin(), y.end());
//        // calculate the sum of the x-xAvg * y-yAvg
//        for (int i = 0; i < x.size(); i++) {
//            sum_XY += (x[i] - rootAvg) * (y[i] - nodeAvg);
//        }
//        if (type == "population") {
//            return sum_XY / count;
//        } else {
//            return sum_XY / (count - 1);
//        }
//    }
//
//    // (x - x_bar)^2
//    double sumOfSquaredMeanDifferences(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double average = this->average(node);
//        double sum = 0;
//        auto *current = node;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                sum += pow(current->data - average, 2);
//                current = current->right;
//            } else {
//                auto *pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    sum += pow(current->data - average, 2);
//                    current = current->right;
//                }
//            }
//        }
//        return sum;
//    }
//
//
//     double skewness(t_treeNode<T> *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double average = this->average();
//        double sum = 0;
//        auto *current = node;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                sum += pow(current->data - average, 3);
//                current = current->right;
//            } else {
//                auto *pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    sum += pow(current->data - average, 3);
//                    current = current->right;
//                }
//            }
//        }
//        return sum / (count * pow(this->standardDeviation(), 3));
//    }
//
//     double kurtosis(t_treeNode<T> *node) {
//        // the central moment of the distribution
//        if (node == nullptr) {
//            return 0;
//        }
//        int count = getCount(node);
//        double average = this->average();
//        double sum = 0;
//        auto *current = node;
//        while (current != nullptr) {
//            if (current->left == nullptr) {
//                sum += pow(current->data - average, 4);
//                current = current->right;
//            } else {
//                auto *pre = current->left;
//                while (pre->right != nullptr && pre->right != current) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = current;
//                    current = current->left;
//                } else {
//                    pre->right = nullptr;
//                    sum += pow(current->data - average, 4);
//                    current = current->right;
//                }
//            }
//        }
//        return sum / (count * pow(this->standardDeviation(), 4));
//    }
//
//    T mode(t_treeNode<T> *node) {
//        // find the value that occurs most often and return it
//        if (node == nullptr) {
//            return 0;
//        }
//        unordered_map<T, int> count;
//        queue<t_treeNode<T> *> q;
//        q.push(node);
//        int maxFreq = 0;
//        while (!q.empty()) {
//            auto *current = q.front();
//            q.pop();
//            if (current->left == nullptr && current->right == nullptr) {
//                count[current->data]++;
//                if (count[current->data] > maxFreq) {
//                    maxFreq = count[current->data];
//                }
//            } else {
//                if (current->left != nullptr) {
//                    q.push(current->left);
//                }
//                if (current->right != nullptr) {
//                    q.push(current->right);
//                }
//            }
//        }
//        T mode;
//        for (auto &i : count) {
//            if (i.second == maxFreq) {
//                mode = i.first;
//            }
//        }
//        return mode;
//    }
//
//    double correlationCoefficient(t_treeNode<T> *root_, t_treeNode<T> *node) {
//        if (root_ == nullptr || node == nullptr) {
//            return 0;
//        }
//        double sum_XY = 0;
//        double rootAvg = average(root);
//        double nodeAvg = average(node);
//        double squareSum_X = this->sumOfSquaredMeanDifferences(root);
//        double squareSum_Y = this->sumOfSquaredMeanDifferences(node);
//        vector<T> x;
//        vector<T> y;
//        // adding the root data to the vector x
//        while (root_ != nullptr) {
//            if (root_->left == nullptr) {
//                x.push_back(root_->data);
//                root_ = root_->right;
//            } else {
//                auto *pre = root_->left;
//                while (pre->right != nullptr && pre->right != root_) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = root_;
//                    root_ = root_->left;
//                } else {
//                    pre->right = nullptr;
//                    x.push_back(root_->data);
//                    root_ = root_->right;
//                }
//            }
//        }
//        // adding the node data to the vector y
//        while (node != nullptr) {
//            if (node->left == nullptr) {
//                y.push_back(node->data);
//                node = node->right;
//            } else {
//                auto *pre = node->left;
//                while (pre->right != nullptr && pre->right != node) {
//                    pre = pre->right;
//                }
//                if (pre->right == nullptr) {
//                    pre->right = node;
//                    node = node->left;
//                } else {
//                    pre->right = nullptr;
//                    y.push_back(node->data);
//                    node = node->right;
//                }
//            }
//        }
//        // sort the vectors
//        sort(x.begin(), x.end());
//        sort(y.begin(), y.end());
//        // calculate the sum of the x-xAvg * y-yAvg
//        for (int i = 0; i < x.size(); i++) {
//            sum_XY += (x[i] - rootAvg) * (y[i] - nodeAvg);
//        }
//        return sum_XY / sqrt(squareSum_X * squareSum_Y);
//    }
//    double zMultiplier(double alpha) {
//        // calculate the z multiplier for the given alpha
//        map<double, double> z;
//        //read the values from the file where each line is a pair of values
//        // separated by a space
//        ifstream file("zscores.txt");
//        string line;
//        while (getline(file, line)) {
//            stringstream ss(line);
//            double x, y;
//            ss >> x >> y;
//            z[x] = y;
//        }
//        return z[alpha];
//    }
//
//
//    pair<double, double> confidenceInterval(t_treeNode<T> *node, double alpha) {
//        // return the confidence interval of the data in the node
//        // alpha is the significance level
//        double average = this->average(node);
//        double standardDeviation = this->standardDeviation(node);
//        double z = this->zMultiplier(alpha);
//        double confidenceInterval = z * standardDeviation / sqrt(getCount(node));
//        double lowerBound = average - confidenceInterval;
//        double upperBound = average + confidenceInterval;
//        return make_pair(lowerBound, upperBound);
//    }
//
//
//    int keyCountUtil(t_treeNode<T>* root_, T key) {
//        if (root_ == nullptr) {
//            return 0;
//        }
//        int count = 0;
//        if (root_->data == key) {
//            count++;
//        }
//        count += keyCountUtil(root_->left, key);
//        count += keyCountUtil(root_->right, key);
//        return count;
//    }
//
//    bool isPresent(t_treeNode<T>* root_, T key) {
//        if (root_ == nullptr) {
//            return false;
//        }
//        if (root_->data == key) {
//            return true;
//        }
//        if (root_->data < key) {
//            return isPresent(root_->right, key);
//        } else {
//            return isPresent(root_->left, key);
//        }
//    }
//
//public:
//    // constructor
//    t_BST() {
//        root = nullptr;
//        size = 0;
//    }
//
//    // copy constructor
//    t_BST(const t_BST<T> &other) {
//        root = copy(other.root);
//    }
//// move constructor
//    t_BST(t_BST<T> &&other) noexcept {
//        root = other.root;
//        other.root = nullptr;
//    }
//// copy assignment operator
//    t_BST<T> & operator=(const t_BST<T> &other) {
//        if (this != &other) {
//            destroy();
//            copyTree(other.root, root);
//        }
//        return *this;
//    }
//// move assignment operator
//    t_BST<T> & operator=(t_BST<T> &&other) noexcept {
//        if (this != &other) {
//            destroy();
//            root = other.root;
//            other.root = nullptr;
//        }
//        return *this;
//    }
//// constructor with initializer list
//     explicit t_BST( vector<T> &data) {
//        root = nullptr;
//        size = 0;
//        for ( auto &i : data) {
//            insert(i);
//        }
//    }
//// constructor to create a BST from data in a file
//     t_BST(const string& fileName, char delimiter) {
//        root = nullptr;
//        size = 0;
//        this->fillTreeFromFile(fileName, delimiter);
//    }
//
//     t_BST(int totalElements, T min, T max) {
//        // fill the tree with random numbers in the range [min, max]
//        root = nullptr;
//        size = 0;
//        // seed the random number generator from the system clock and random library
//        srand(time(nullptr));
//        for (int i = 0; i < totalElements; i++) {
//            insert(rand() % (max - min + 1) + min);
//        }
//    }
//
//    /**
//     * @brief insert data into the tree
//     * @param data  data to be inserted
//     */
//    void insert(T data) {
//        auto *node = new t_treeNode<T>(data);
//        insert(root, node);
//    }
//    /**
//     * @brief destroy tree
//     */
//     void destroy() {
//        destroyTree(root);
//        root = nullptr;
//        size = 0;
//    }
//    /**
//    * @brief find the node with the given data
//    * @param data  the data to find
//    * @return  the node with the given data
//    */
//    t_treeNode<T> *find(T data) {
//        return find(root, data);
//    }
//    /**
//     * @brief find the maximum node
//     * @return  the maximum node
//     */
//    t_treeNode<T> *findMax() {
//        return findMax(root);
//    }
//    T max() {
//        return findMax()->data;
//    }
//    /**
//     * @brief find the minimum node
//     * @return  the minimum node
//     */
//    t_treeNode<T> *findMin() {
//        return findMin(root);
//    }
//    T min() {
//        return findMin()->data;
//    }
//
//    /**
//     * @brief counts how many times a key appears in the tree
//     * @param key  the key to count
//     * @return  the number of times the key appears in the tree
//     */
//    int count(T key) {
//        return keyCountUtil(root, key);
//    }
//
//    /**
//     * @brief remove a node from the tree
//     * @param data  the data of the node to remove
//     */
//    void remove(T data) {
//        remove(root, data);
//    }
//
//     void removeAll(T data) {
//        removeAll(root, data);
//    }
//
//    /**
//     *  @brief prints the tree in order
//     */
//    void printTree() {
//        printTree(root);
//    }
//    /**
//     *  @brief print the tree in order
//     */
//    void inOrder() {
//        inOrder(root);
//    }
//    /**
//     *  @brief print the tree in pre order
//     */
//    void preOrder() {
//        preOrder(root);
//    }
//    /**
//     *  @brief print the tree in post order
//     */
//    void postOrder() {
//        postOrder(root);
//    }
//    /**
//     *  @brief print the tree in level order
//     */
//    void levelOrder() {
//        levelOrder(root);
//    }
//    /**
//     *  @brief prints the tree in a 2d fashion
//     */
//     void print2D() {
//        print2DUtil(root, 0);
//    }
//
//     void printNodesAtDistanceK(t_treeNode<T> *node, int k) {
//        if (node == nullptr) {
//            return;
//        }
//        if (k == 0) {
//            cout << node->data << " ";
//        }
//        printNodesAtDistanceK(node->left, k - 1);
//        printNodesAtDistanceK(node->right, k - 1);
//    }
//
//     void verticalOrder() {
//        map<int, vector<T>> m;
//        verticalOrder(root, m, 0);
//        for (auto &it : m) {
//            for (auto &it2 : it.second) {
//                cout << it2 << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // getters
//    /**
//     * @brief get the root of the tree
//     *  @return the root of the tree
//     */
//     t_treeNode<T> *getRoot() {
//        return root;
//    }
//    /**
//     * @brief get the size of the tree
//     * @return the size of the tree
//     */
//     int getSize() {
//        return size;
//    }
//    /**
//     *  @brief get the height of the tree
//     * @return  the height of the tree from the node
//     */
//    int getHeight() {
//        return getHeight(root);
//    }
//
//    /**
//     * @brief get the diameter of the tree
//     * @return  the diameter of the tree
//     */
//    int getDiameter() {
//        return getDiameter(root);
//    }
//
//    /**
//     *  @brief get the balance factor of the tree
//     * @return  the balance factor of the tree from the node
//     */
//    int getBalanceFactor() {
//        return getBalanceFactor(root);
//    }
//
//    /**
//     *  @brief balance the tree
//     */
//    void balance() {
//        balance(root);
//    }
//    /**
//     * @brief replaces each node with the sum of its left and right subtrees
//     */
//    void replaceWithSums() {
//        replaceWithSums(root);
//    }
//    /**
//     * @brief counts the number of leaves in the tree
//     * @return  the number of leaves in the tree
//     */
//     int countLeaves() {
//        return getLeaves(root);
//    }
//
//    int getCount() {
//        return getCount(root);
//    }
//
//    /**
//     * @brief sums the nodes in the tree
//     * @return  the sum of the nodes in the tree
//     */
//     double sum() {
//        return sum(root);
//    }
//
//    // median
//    /**
//     * @brief finds the median of the tree
//     * @return  the median of the tree
//     */
//     double median() {
//        return median(root);
//    }
//
//     double mean() {
//        return this->average();
//    }
//    /**
//     * @brief finds the average of the tree
//     * @return  the average of the tree
//     */
//     double average() {
//        return average(root);
//    }
//    /**
//     * @brief finds the standard deviation of the tree
//     * @return  the standard deviation of the tree
//     */
//     double standardDeviation() {
//        return standardDeviation(root);
//    }
//
//    double variance(const string& type = "population") {
//        return variance(root, type);
//    }
//    double covariance(t_treeNode<T> *node, string type = "population") {
//        return covariance(root, node, type);
//    }
//
//    /**
//     * @brief finds the standard error of the tree
//     * @return  the standard error of the tree
//     */
//    double standardError() {
//        return standardError(root);
//    }
//
//    double sumOfSquaredMeanDifferences() {
//        return sumOfSquaredMeanDifferences(root);
//    }
//
//    /**
//     * @brief finds the mode of the tree
//     * @return  the mode of the tree
//     */
//    T mode() {
//        return mode(root);
//    }
//    /**
//     * @brief finds the skewness, or the ratio of the difference between the
//     * mean and the median to the standard deviation
//     * @return
//     */
//    double skewness() {
//        return skewness(root);
//    }
//
//    double kurtosis() {
//        return kurtosis(root);
//    }
//
//     double range() {
//        // difference between max and min
//        return max() - min();
//    }
//    /**
//     * @brief finds the correlation coefficient between two trees
//     * @param node  the node to compare to
//     * @return  the correlation coefficient between the two trees
//     */
//     double correlationCoefficient(t_treeNode<T> *node) {
//        return correlationCoefficient(root, node);
//    }
//
//    /**
//     * @brief finds the confidence interval of the tree
//     * @param confidence  the confidence level as a decimal
//     * @return  a pair of doubles that represent the lower and upper bounds
//     * of the confidence interval
//     */
//    pair<double, double> confidenceInterval(double confidence) {
//        return confidenceInterval(root, confidence);
//    }
//    /**
//     * @brief checks to see if the tree is empty
//     * @return true if tree is empty else false
//     */
//     bool isEmpty() {
//        return root == nullptr;
//    }
//    bool isPresent(T value) {
//        return isPresent(root, value);
//    }
//
//     void fillTreeFromFile(const string& filename, char delimiter) {
//        ifstream file;
//        file.open(filename);
//        string line;
//        vector<T> tokens;
//        while (getline(file, line)) {
//            stringstream ss(line);
//            string token;
//            while (getline(ss, token, delimiter)) {
//                tokens.push_back(stod(token));
//            }
//        }
//        file.close();
//        for (auto& token : tokens) {
//            insert(token);
//        }
//    }
//
//    /**
//     * destructor
//     */
//    ~t_BST() {
//        destroyTree(root);
//    }
//
//}; // end of t_BST class
//
//
//// _____________________end Udemy binary search tree ___________________________
//// _____________________________________________________________________________
//
////______________________________________________________________________________
// void addNodeToList(LinkedList &list, int val) {
//    auto *newNode = new ListNode(val);
//    newNode->next = nullptr;
//    if (list.head == nullptr) {
//        list.head = newNode;
//    } else {
//        ListNode *curr = list.head;
//        while (curr->next != nullptr) {
//            curr = curr->next;
//        }
//        curr->next = newNode;
//    }
//}
//
// void printList(ListNode *head) {
//    while (head) {
//        std::cout << head->val << " ";
//        head = head->next;
//    }
//    std::cout << std::endl;
//}
//
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//    auto *result = new ListNode();
//    ListNode *curr = result;
//    int carry = 0;
//    while (l1 || l2) {
//        int sum = 0;
//        if (l1) {
//            sum += l1->val;
//            l1 = l1->next;
//        }
//        if (l2) {
//            sum += l2->val;
//            l2 = l2->next;
//        }
//        sum += carry;
//        carry = sum / 10;
//        sum = sum % 10;
//        curr->next = new ListNode(sum);
//        curr = curr->next;
//    }
//    if (carry > 0) {
//        curr->next = new ListNode(carry);
//    }
//    return result->next;
//}
//
// double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
//    auto m = nums1.size();
//    auto n = nums2.size();
//    if (m > n) {
//        return findMedianSortedArrays(nums2, nums1);
//    }
//    size_t min = 0, max = m;
//    while (min <= max) {
//        size_t i = (min + max) / 2;
//        size_t j = (m + n + 1) / 2 - i;
//        if (i < max && nums2[j - 1] > nums1[i]) {
//            min = i + 1;
//        } else if (i > min && nums1[i - 1] > nums2[j]) {
//            max = i - 1;
//        } else {
//            int maxLeft = 0;
//            if (i == 0) {
//                maxLeft = nums2[j - 1];
//            } else if (j == 0) {
//                maxLeft = nums1[i - 1];
//            } else {
//                maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
//            }
//            if ((m + n) % 2 == 1) {
//                return maxLeft;
//            }
//            int minRight = 0;
//            if (i == m) {
//                minRight = nums2[j];
//            } else if (j == n) {
//                minRight = nums1[i];
//            } else {
//                minRight = std::min(nums1[i], nums2[j]);
//            }
//            return (maxLeft + minRight) / 2.0;
//        }
//    }
//    return 0.0;
//}
//
//int expandAroundCenter(string basicString, int i, int i1) {
//    int left = i, right = i1;
//    while (left >= 0 && right < basicString.length() && basicString[left] == basicString[right]) {
//        left--;
//        right++;
//    }
//    return right - left - 1;
//}
//
// string longestPalindrome(const string& s) {
//    int start = 0, end = 0;
//    for (int i = 0; i < s.size(); i++) {
//        int len1 = expandAroundCenter(s, i, i);
//        int len2 = expandAroundCenter(s, i, i + 1);
//        int len = std::max(len1, len2);
//        if (len > end - start) {
//            start = i - (len - 1) / 2;
//            end = i + len / 2;
//        }
//    }
//    return s.substr(start, end - start + 1);
//}
//
// int search(vector<int>& nums, int target) {
//    int left = 0, right = (int)nums.size() - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (nums[mid] == target) {
//            return mid;
//        }
//        if (nums[left] <= nums[mid]) {
//            if (nums[left] <= target && target < nums[mid]) {
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        } else {
//            if (nums[mid] < target && target <= nums[right]) {
//                left = mid + 1;
//            } else {
//                right = mid - 1;
//            }
//        }
//    }
//    return -1;
//}
//
//bool isBadVersion(int version) {
//    return version >= 1702766719;
//}
//
// int firstBadVersion(int n) {
//    int left = 1, right = n;
//    while (left < right) {
//        int mid = (left + right) / 2;
//        if (isBadVersion(mid)) {
//            right = mid;
//        } else {
//            left = mid + 1;
//        }
//    }
//    return left;
//}
//
// int searchInsert(vector<int>& nums, int target) {
//    int left = 0, right = (int)nums.size() - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (nums[mid] == target) {
//            return mid;
//        }
//        if (nums[mid] < target) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    return left;
//}
//
// int maxArea(vector<int>& height) {
//    int left = 0, right = (int)height.size() - 1;
//    int maxArea = 0;
//    while (left < right) {
//        int area = std::min(height[left], height[right]) * (right - left);
//        maxArea = std::max(maxArea, area);
//        if (height[left] < height[right]) {
//            left++;
//        } else {
//            right--;
//        }
//    }
//    return maxArea;
//}
//
// int maxPower(string s) {
//    int max = 0;
//    int cur = 1;
//    for(int i = (int)s.size()-1; i > 0; i--) {
//        if(s[i] == s[i - 1]) {
//            cur++;
//        } else {
//            max = std::max(max, cur);
//            cur = 1;
//        }
//    }
//    return std::max(max, cur);
//}
//
// vector<int> sortedSquares(vector<int>& nums) {
//    vector<int> res;
//    unsigned long left = 0, right = nums.size() - 1;
//    while (left <= right) {
//        if (nums[left] * nums[left] > nums[right] * nums[right]) {
//            res.push_back(nums[left] * nums[left]);
//            left++;
//        } else {
//            res.push_back(nums[right] * nums[right]);
//            right--;
//        }
//    }
//    vector<int> ans;
//    for (size_t i = res.size() - 1; i >= 0; i--) {
//        ans.push_back(res[i]);
//    }
//    return ans;
//}
//
// void rotate(vector<int>& nums, size_t k) {
//    k = k % nums.size();
//    reverse(nums.begin(), nums.end());
//    reverse(nums.begin(), nums.begin() + k);
//    reverse(nums.begin() + k, nums.end());
//}
//
// string intToRoman(int num) {
//    string res;
//    int cur = 0;
//    while (num > 0) {
//        if (num >= 1000) {
//            res += "M";
//            num -= 1000;
//        } else if (num >= 900) {
//            res += "CM";
//            num -= 900;
//        } else if (num >= 500) {
//            res += "D";
//            num -= 500;
//        } else if (num >= 400) {
//            res += "CD";
//            num -= 400;
//        } else if (num >= 100) {
//            res += "C";
//            num -= 100;
//        } else if (num >= 90) {
//            res += "XC";
//            num -= 90;
//        } else if (num >= 50) {
//            res += "L";
//            num -= 50;
//        } else if (num >= 40) {
//            res += "XL";
//            num -= 40;
//        } else if (num >= 10) {
//            res += "X";
//            num -= 10;
//        } else if (num >= 9) {
//            res += "IX";
//            num -= 9;
//        } else if (num >= 5) {
//            res += "V";
//            num -= 5;
//        } else if (num >= 4) {
//            res += "IV";
//            num -= 4;
//        } else if (num >= 1) {
//            res += "I";
//            num -= 1;
//        }
//        cur++;
//    }
//    return res;
//}
//
// void moveZeroes(vector<int>& nums) {
//    for (int i = 0; i < nums.size(); i++) {
//        for (int j = 0; j < nums.size() - i - 1; j++) {
//            if (nums[j] == 0) {
//                int temp = nums[j];
//                nums[j] = nums[j+1];
//                nums[j+1] = temp;
//            }
//        }
//    }
//}
//
// int rangeSumBST(TreeNode* root, int low, int high) {
//    if (root == nullptr) {
//        return 0;
//    }
//    int sum = 0;
//    if (root->val >= low && root->val <= high) {
//        sum += root->val;
//    }
//    sum += rangeSumBST(root->left, low, high);
//    sum += rangeSumBST(root->right, low, high);
//    return sum;
//}
//
// vector<int> twoSum(vector<int>& numbers, int target) {
//    vector<int> res;
//    int left = 0, right = numbers.size() - 1;
//    while (left < right) {
//        int sum = numbers[left] + numbers[right];
//        if (sum == target) {
//            res.push_back(left + 1);
//            res.push_back(right + 1);
//            return res;
//        } else if (sum < target) {
//            left++;
//        } else {
//            right--;
//        }
//    }
//    return res;
//}
//
// void reverseString(vector<char>& s) {
//    int left = 0, right = s.size() - 1;
//    while (left < right) {
//        char temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        left++;
//        right--;
//    }
//}
//
// void reverseString(string& s) {
//    int left = 0, right = s.size() - 1;
//    while (left < right) {
//        char temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        left++;
//        right--;
//    }
//}
////method to print out the contents of a vector
//template <typename T>
// void printVector(vector<T> v) {
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//}
//
// string reverseLettersInEachWord(const string& s) {
//    vector<string> words;
//    string res;
//    string temp;
//    for (char i : s) {
//        if (i == ' ') {
//            words.push_back(temp);
//            temp = "";
//        } else {
//            temp += i;
//        }
//    }
//    words.push_back(temp);
//    for (int i = 0; i < words.size(); i++) {
//        temp = words[i];
//        reverseString(temp);
//        res += temp;
//        if (i != words.size() - 1) {
//            res += " ";
//        }
//    }
//    cout << res << endl;
//    return res;
//}
// ListNode* middleNode(ListNode* head) {
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast != nullptr && fast->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//    auto* dummy = new ListNode(0);
//    dummy->next = head;
//    ListNode* slow = dummy;
//    ListNode* fast = dummy;
//    for (int i = 0; i < n; i++) {
//        fast = fast->next;
//    }
//    while (fast->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    slow->next = slow->next->next;
//    return dummy->next;
//}
//
// vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//    vector<vector<int>> adj(n);
//    if (n == 1 && edges.empty()) {
//        vector<int> res;
//        res.push_back(0);
//        return res;
//    }
//    for (auto & edge : edges) {
//        adj[edge[0]].push_back(edge[1]);
//        adj[edge[1]].push_back(edge[0]);
//    }
//    vector<int> leaves;
//    for (int i = 0; i < n; i++) {
//        if (adj[i].size() == 1) {
//            leaves.push_back(i);
//        }
//    }
//    while (n > 2) {
//        n -= leaves.size();
//        vector<int> newLeaves;
//        for (int cur : leaves) {
//            for (int j = 0; j < adj[cur].size(); j++) {
//                int neighbor = adj[cur][j];
//                adj[neighbor].erase(find(adj[neighbor].begin(), adj[neighbor].end(), cur));
//                if (adj[neighbor].size() == 1) {
//                    newLeaves.push_back(neighbor);
//                }
//            }
//        }
//        leaves = newLeaves;
//    }
//    return leaves;
//}
//
// ListNode* insertionSortList(ListNode* head) {
//    if (head == nullptr || head->next == nullptr) {
//        return head;
//    }
//    auto* dummy = new ListNode(0);
//    dummy->next = head;
//    ListNode* cur = head;
//    while (cur->next != nullptr) {
//        if (cur->next->val < cur->val) {
//            ListNode* temp = cur->next;
//            cur->next = cur->next->next;
//            ListNode* prev = dummy;
//            while (prev->next->val < temp->val) {
//                prev = prev->next;
//            }
//            temp->next = prev->next;
//            prev->next = temp;
//        } else {
//            cur = cur->next;
//        }
//    }
//    return dummy->next;
//}
//
// int maxDistance(vector<vector<int>>& arrays) {
//    int n = arrays.size();
//    int res = 0;
//    int min = arrays[0][0];
//    int max = arrays[0][arrays[0].size() - 1];
//    for (int i = 1; i < n; i++) {
//        res = max - min > res ? max - min : res;
//        min = min > arrays[i][0] ? arrays[i][0] : min;
//        max = max < arrays[i][arrays[i].size() - 1] ? arrays[i][arrays[i].size() - 1] : max;
//    }
//    return res;
//}
//
// int lengthOfLongestSubstring(string s) {
//    auto n = s.size();
//    int res = 0;
//    int left = 0;
//    int right = 0;
//    unordered_map<char, int> map;
//    while (right < n) {
//        if (map.find(s[right]) != map.end()) {
//            left = max(map[s[right]], left);
//        }
//        map[s[right]] = right + 1;
//        res = max(res, right - left + 1);
//        right++;
//    }
//    return res;
//}
///*
// * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
// * or false otherwise. In other words, return true if one of s1's permutations
// * is the substring of s2.
// */
// bool checkInclusion(string s1, string s2) {
//    int n1 = s1.size();
//    int n2 = s2.size();
//    if (n1 > n2) {
//        return false;
//    }
//    vector<int> count(128, 0);
//    for (int i = 0; i < n1; i++) {
//        count[s1[i]]++;
//    }
//    for (int i = 0; i <= n2 - n1; i++) {
//        vector<int> temp(128, 0);
//        for (int j = 0; j < n1; j++) {
//            temp[s2[i + j]]++;
//        }
//        if (temp == count) {
//            return true;
//        }
//    }
//    return false;
//}
///**
// * An image is represented by an m x n integer grid image where image[i][j] represents
// * the pixel value of the image. You are also given three integers sr, sc, and newColor.
// * You should perform a flood fill on the image starting from the pixel image[sr][sc].
// * To perform a flood fill, consider the starting pixel, plus any pixels connected
// * 4-directionally to the starting pixel of the same color as the starting pixel,
// * plus any pixels connected 4-directionally to those pixels (also with the same color),
// * and so on. Replace the color of all of the aforementioned pixels with newColor.
// * @param image
// * @param sr
// * @param sc
// * @param newColor
// * @return the modified image after performing the flood fill.
// */
//
//vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//    int n = image.size();
//    int m = image[0].size();
//    int color = image[sr][sc];
//    if (color == newColor) {
//        return image;
//    }
//    queue<pair<int, int>> q;
//    q.push(make_pair(sr, sc));
//    while (!q.empty()) {
//        int r = q.front().first;
//        int c = q.front().second;
//        q.pop();
//        if (image[r][c] == color) {
//            image[r][c] = newColor;
//            if (r - 1 >= 0 && image[r - 1][c] == color) {
//                q.push(make_pair(r - 1, c));
//            }
//            if (r + 1 < n && image[r + 1][c] == color) {
//                q.push(make_pair(r + 1, c));
//            }
//            if (c - 1 >= 0 && image[r][c - 1] == color) {
//                q.push(make_pair(r, c - 1));
//            }
//            if (c + 1 < m && image[r][c + 1] == color) {
//                q.push(make_pair(r, c + 1));
//            }
//        }
//    }
//    return image;
//}
//
///**
// * You are given an m x n binary matrix grid. An island is a group of 1's
// * (representing land) connected 4-directionally (horizontal or vertical.)
// * You may assume all four edges of the grid are surrounded by water.
// * The area of an island is the number of cells with a value 1 in the island.
// * @return the maximum area of an island in grid. If there is no island, return 0.
// */
// int maxAreaOfIsland(vector<vector<int>>& grid) {
//    int n = grid.size();
//    int m = grid[0].size();
//    int res = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (grid[i][j] == 1) {
//                int area = 0;
//                queue<pair<int, int>> q;
//                q.push(make_pair(i, j));
//                while (!q.empty()) {
//                    int r = q.front().first;
//                    int c = q.front().second;
//                    q.pop();
//                    if (grid[r][c] == 1) {
//                        grid[r][c] = 0;
//                        area++;
//                        if (r - 1 >= 0 && grid[r - 1][c] == 1) {
//                            q.push(make_pair(r - 1, c));
//                        }
//                        if (r + 1 < n && grid[r + 1][c] == 1) {
//                            q.push(make_pair(r + 1, c));
//                        }
//                        if (c - 1 >= 0 && grid[r][c - 1] == 1) {
//                            q.push(make_pair(r, c - 1));
//                        }
//                        if (c + 1 < m && grid[r][c + 1] == 1) {
//                            q.push(make_pair(r, c + 1));
//                        }
//                    }
//                }
//                res = max(res, area);
//            }
//        }
//    }
//    return res;
//}
///**
// * You are given two binary trees root1 and root2. Imagine that when you put
// * one of them to cover the other, some nodes of the two trees are overlapped
// * while the others are not. You need to merge the two trees into a new binary
// * tree. The merge rule is that if two nodes overlap, then sum node values up
// * as the new value of the merged node. Otherwise, the NOT nullptr node will be
// * used as the node of the new tree.
// * @param root1
// * @param root2
// * @return the merged tree.
// */
// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//    if (root1 == nullptr) {
//        return root2;
//    }
//    if (root2 == nullptr) {
//        return root1;
//    }
//    root1->val += root2->val;
//    root1->left = mergeTrees(root1->left, root2->left);
//    root1->right = mergeTrees(root1->right, root2->right);
//    return root1;
//}
///**
// * Populate each next pointer to point to its next right node. If there is no
// * next right node, the next pointer should be set to nullptr.
// * Initially, all next pointers are set to nullptr.
// * @return
// */
// Node* connect(Node* root) {
//    if (root == nullptr) {
//        return nullptr;
//    }
//    queue<Node*> q;
//    q.push(root);
//    while (!q.empty()) {
//        int n = q.size();
//        for (int i = 0; i < n; i++) {
//            Node* cur = q.front();
//            q.pop();
//            if (i < n - 1) {
//                cur->next = q.front();
//            }
//            if (cur->left != nullptr) {
//                q.push(cur->left);
//            }
//            if (cur->right != nullptr) {
//                q.push(cur->right);
//            }
//        }
//    }
//    return root;
//}
///**
// * Given an m x n binary matrix mat, return the distance of the nearest 0 for
// * each cell. The distance between two adjacent cells is 1.
// * @param mat
// * @return
// */
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//    int n = mat.size();
//    int m = mat[0].size();
//    vector<vector<int>> res(n, vector<int>(m, 0));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (mat[i][j] == 0) {
//                res[i][j] = 0;
//            } else {
//                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + 1;
//            }
//        }
//    }
//    for (int i = n - 1; i >= 0; i--) {
//        for (int j = m - 1; j >= 0; j--) {
//            if (mat[i][j] == 0) {
//                res[i][j] = 0;
//            } else {
//                res[i][j] = min(res[i][j], min(res[i + 1][j], res[i][j + 1])) + 1;
//            }
//        }
//    }
//    return res;
//}
//
///**
// * You are given an m x n grid where each cell can have one of three values:
// * 0 representing an empty cell,
// * 1 representing a fresh orange, or
// * 2 representing a rotten orange.
// * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
// * orange becomes rotten.
// * @param grid
// * @return the minimum number of minutes that must elapse until no cell has a
// * fresh orange. If this is impossible, return -1.
// */
// int orangesRotting(vector<vector<int>>& grid) {
//    int n = grid.size();
//    int m = grid[0].size();
//    queue<pair<int, int>> q;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (grid[i][j] == 2) {
//                q.push(make_pair(i, j));
//            }
//        }
//    }
//    int res = 0;
//    while (!q.empty()) {
//        int n_ = q.size();
//        for (int i = 0; i < n_; i++) {
//            int r = q.front().first;
//            int c = q.front().second;
//            q.pop();
//            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
//                grid[r - 1][c] = 2;
//                q.push(make_pair(r - 1, c));
//            }
//            if (r + 1 < n_ && grid[r + 1][c] == 1) {
//                grid[r + 1][c] = 2;
//                q.push(make_pair(r + 1, c));
//            }
//            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
//                grid[r][c - 1] = 2;
//                q.push(make_pair(r, c - 1));
//            }
//            if (c + 1 < m && grid[r][c + 1] == 1) {
//                grid[r][c + 1] = 2;
//                q.push(make_pair(r, c + 1));
//            }
//        }
//        res++;
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (grid[i][j] == 1) {
//                return -1;
//            }
//        }
//    }
//    return res;
//}
//int absDifference(int a, int b) {
//    return abs(a - b);
//}
///**
// * Given an array of distinct integers arr, find all pairs of elements with the
// * minimum absolute difference of any two elements.
// * Return a list of pairs in ascending order(with respect to pairs), each pair
// * [a, b] follows
// * a, b are from arr
// * a < b
// * b - a equals to the minimum absolute difference of any two elements in arr
// * @param arr
// * @return  a list of pairs in ascending order(with respect to pairs)
// */
// vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//    sort(arr.begin(), arr.end());
//    int minDiff = INT_MAX;
//    vector<vector<int>> res;
//    for (int i = 0; i < arr.size() - 1; i++) {
//        minDiff = min(minDiff, absDifference(arr[i], arr[i + 1]));
//    }
//    for (int i = 0; i < arr.size() - 1; i++) {
//        if (absDifference(arr[i], arr[i + 1]) == minDiff) {
//            res.push_back({arr[i], arr[i + 1]});
//        }
//    }
//    return res;
//}
//// print data in binary format
// void printBinary(unsigned int  n) {
//    cout << n << " in binary is " << bitset<32>(n) << endl;
//}
// int reverseBits(int n){
//    int pos = INT_SIZE - 1;     // maintains shift
//    // store reversed bits of `n`. Initially, all bits are set to 0
//    int reverse = 0;
//    // do till all bits are processed
//    while (pos >= 0 && n)    {
//        // if the current bit is 1, then set the corresponding bit in the result
//        if (n & 1) {
//            reverse = reverse | (1 << pos);
//        }
//        n >>= 1;                // drop current bit (divide by 2)
//        pos--;                  // decrement shift by 1
//    }
//    return reverse;
//}
//
// vector<string> fizzbuzz(int n) {
//    vector<string> res;
//    for (int i = 1; i <= n; i++) {
//        if (i % 3 == 0 && i % 5 == 0) {
//            res.emplace_back("FizzBuzz");
//        } else if (i % 3 == 0) {
//            res.emplace_back("Fizz");
//        } else if (i % 5 == 0) {
//            res.emplace_back("Buzz");
//        } else {
//            res.push_back(to_string(i));
//        }
//    }
//    return res;
//}
//// finds the longest sequence of consecutive numbers in an array such as 1, 2, 3, 4, 5
//// which would be a band of length 5. The sequence can start from any index in the array.
//// and it must run in O(n) time.
// int longestBand(vector<int>& arr) {
//    int steps = 0;
//    // add array to unordered set
//    unordered_set<int> set;
//    for (auto i : arr) {
//        set.insert(i);
//    }
//    int max = 1;
//    for(auto i : set) {
//        int parent = i - 1;
//        int count = 1;
//        while (set.find(parent) != set.end()) {
//            count++;
//            parent--;
//            steps++;
//        }
//        max = max > count ? max : count;
//
//        steps++;
//    }
//    cout << "steps: " << steps << endl;
//    return max;
//}
//
// int trappedWater(vector<int> heights) {
//    int left = 0;
//    int right = heights.size() - 1;
//    int leftMax = 0;
//    int rightMax = 0;
//    int water = 0;
//    while (left < right) {
//        if (heights[left] < heights[right]) {
//            if (heights[left] > leftMax) {
//                leftMax = heights[left];
//            } else {
//                water += leftMax - heights[left];
//            }
//            left++;
//        } else {
//            if (heights[right] > rightMax) {
//                rightMax = heights[right];
//            } else {
//                water += rightMax - heights[right];
//            }
//            right--;
//        }
//    }
//    return water;
//}
//
// bool outOfOrder(vector<int>& arr, int i) {
//    if (i == 0) {
//        return arr[i] > arr[i + 1];
//    } else if (i == arr.size() - 1) {
//        return arr[i] < arr[i - 1];
//    } else {
//        return arr[i] < arr[i - 1] || arr[i] > arr[i + 1];
//    }
//}
//
// pair<int, int> subArraySort(vector<int> arr) {
//    int smallest = INT_MAX;
//    int largest = INT_MIN;
//    for (int i = 0; i < arr.size(); i++) {
//        int x = arr[i];
//        if (outOfOrder(arr, i)) {
//            smallest = min(smallest, x);
//            largest = max(largest, x);
//        }
//    }
//    if (smallest == INT_MAX) {
//        return {-1, -1};
//    }
//    int start = 0;
//    int end = arr.size() - 1;
//    while (arr[start] < smallest) {
//        start++;
//    }
//    while (arr[end] > largest) {
//        end--;
//    }
//    return {start, end};
//
//}
//
// int countMinSwaps(vector<int> arr) {
//    int n = arr.size();
//    int ans = 0;
//    pair<int, int> ap[n];
//    for (int i = 0; i < n; i++) {
//        ap[i].first = arr[i];
//        ap[i].second = i;
//    }
//
//    sort(ap, ap + n);
//    vector<bool> visited(n, false);
//    for (int i = 0; i < n; i++) {
//        int old_pos = ap[i].second;
//        if (visited[old_pos]) {
//            continue;
//        }
//        int node = i;
//        int cycle_size = 0;
//        while (!visited[node]) {
//            visited[node] = true;
//            node = ap[node].second;
//            cycle_size++;
//        }
//        if (cycle_size > 0) {
//            ans += (cycle_size - 1);
//        }
//    }
//    return ans;
//}
//
// int maxSubarraySum(vector<int> arr){
//    //Complete this function, your function should return the maximum subarray sum
//    int n = arr.size();
//    int max = INT_MIN;
//    int max_end = 0;
//    for (int i = 0; i < n; i++) {
//        max_end = max_end + arr[i];
//        if (max_end < 0) {
//            max_end = 0;
//        }
//        if (max < max_end) {
//            max = max_end;
//        }
//    }
//    return max;
//}
//
// pair<int,int> minDifference(vector<int> a,vector<int> b){
//    //Complete this method
//    int n = a.size();
//    int m = b.size();
//    int min_diff = INT_MAX;
//    int min_a = INT_MAX;
//    int min_b = INT_MAX;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            int diff = abs(a[i] - b[j]);
//            if (diff < min_diff) {
//                min_diff = diff;
//                min_a = a[i];
//                min_b = b[j];
//            }
//        }
//    }
//    return {min_a, min_b};
//}
//
// vector<int> productArray(vector<int> arr){
//    //Create an output Array
//    int n = arr.size();
//    vector<int> output(n,1);
//    for (int i = 0; i < arr.size(); i++) {
//        int index = arr.size() - 1;
//        while(index >= 0) {
//            if (index != i) {
//                output[i] *= arr[index];
//            }
//            index--;
//        }
//    }
//    return output;
//}
//// computes how many of the given activities can be done on the given day.
//// each pair represents the start and end time of an activity.
// int countActivities(vector<pair<int,int> > activities){
//    // Complete this method
//    // sort the activities by start time
//    sort(activities.begin(), activities.end(), [](pair<int,int> a, pair<int,int> b){
//        return a.second < b.second;
//    });
//    int count = 1;
//    int finish = activities[0].second;
//
//    for(int i = 1; i < activities.size(); i++){
//        if(activities[i].first >= finish){
//            count++;
//            finish = activities[i].second;
//        }
//    }
//    return count;
//}
//// find all starting indices of each substring small that is within the given string large.
//// and return the starting indices in a vector. uses the find method.
// vector<int> stringSearch(const string& big,const string& small){
//    //store the occurrences in the result vector
//    vector<int> result = {};
//    int curr_index = 0;
//    for(int i = 0; i < big.size(); i++){
//        curr_index = big.find(small,curr_index);
//        if(curr_index != string::npos){
//            result.push_back(curr_index);
//            curr_index++;
//        }
//    }
//    return result;
//}
//
//// write a function that replaces all the spaces in a string with '%20'.
// string urlify(char* str){
//    // Complete this method
//    string result;
//    auto len = strlen(str);
//    for(int i = 0; i < len; i++){
//        if(str[i] == ' '){
//            result += "%20";
//        }else{
//            result += str[i];
//        }
//    }
//    return result;
//}
//
// void printTokenizedString(){
//    string input;
//    cout << "Enter a string: ";
//    getline(cin,input);
//    stringstream ss(input);
//    string token;
//    vector<string> tokens;
//    while(getline(ss,token,' ')){
//        tokens.push_back(token);
//    }
//
//    for(const auto& t : tokens){
//        cout << t << ", ";
//    }
//    cout << endl;
//}
//
// void printTokenizedString_strtok() {
//    string input;
//    cout << "Enter a string: ";
//    getline(cin, input);
//    char* str = new char[input.length() + 1];
//    strcpy(str, input.c_str());
//    char* token = strtok(str, " ");
//    while (token != nullptr) {
//        cout << token << ", ";
//        token = strtok(nullptr, " ");
//    }
//    cout << endl;
//}
//
// char* my_strtok(char* str, char delim) {
//    static char* ptr = nullptr;
//    if (str != nullptr) {
//        ptr = str;
//    }
//    if (ptr == nullptr) {
//        return nullptr;
//    }
//    char* token = new char[strlen(ptr) + 1];
//    int i = 0;
//    for (;str[i] != '\0'; i++) {
//        if (str[i] != delim) {
//            token[i] = str[i];
//        } else {
//            token[i] = '\0';
//            ptr = ptr + i + 1;
//            return token;
//        }
//    }
//    token[i] = '\0';
//    ptr = nullptr;
//    return token;
//}
// int convertToInt(string s) {
//    int ans = 0;
//    int p = 1;
//    for (int i = s.length() - 1; i >= 0; i--) {
//        ans += (s[i] - '0') * p;
//        p *= 10;
//    }
//    return ans;
//}
//
//
//bool lexicoCompare(const pair<string,string>& s1, const pair<string,string>& s2){
//    string key1 = s1.second;
//    string key2 = s2.second;
//    return key1 < key2;
//}
//
//
//bool numericCompare(const pair<string,string>& s1, const pair<string,string>& s2){
//    string key1 = s1.second;
//    string key2 = s2.second;
//    return convertToInt(key1) < convertToInt(key2);
//}
//
//
//
// string extractStringAtKey(const string& str, int key) {
//    char *s = strtok((char *)str.c_str(), " ");
//    while(key > 1) {
//        s = strtok(nullptr, " ");
//        key--;
//    }
//    return s;
//}
///*
// * sample input:
// 3
// 92 022
// 82 12
// 77 13
// 2 false numeric
// * sample output:
// 82 12
// 77 13
// 92 022
// */
// vector<pair<string, string>> sortByKey() {
//    int n;
//    cin >> n;
//    cin.get();
//
//    string temp;
//    vector<string> v;
//    for (int i = 0; i < n; i++) {
//        getline(cin, temp);
//        v.push_back(temp);
//    }
//    int key;
//    string reversal, ordering;
//    cin >> key >> reversal >> ordering;
//    cin.get();
//    vector<pair<string, string>> vp;
//    vp.reserve(n);
//    for (int i = 0; i < n; i++) {
//        vp.emplace_back(v[i], extractStringAtKey(v[i], key));
//    }
//    if (ordering == "numeric") {
//        sort(vp.begin(), vp.end(), numericCompare);
//    } else {
//        sort(vp.begin(), vp.end(), lexicoCompare);
//    }
//    if (reversal == "true") {
//        reverse(vp.begin(), vp.end());
//    }
//    for (int i = 0; i < n; i++) {
//        cout << vp[i].first << endl;
//    }
//    return vp;
//}
//
// bool isSubset(string s1, string s2) {
//    auto i = s1.length() - 1;
//    auto j = s2.length() - 1;
//    while (i >= 0 && j >= 0) {
//        if (s1[i] == s2[j]) {
//            i--;
//            j--;
//        } else {
//            i--;
//        }
//    }
//    if (j == -1) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
// void subsequences(string s, const string& o, vector<string>& v) {
//    if (s.length() == 0) {
//        v.push_back(o);
//        return;
//    }
//    subsequences(s.substr(1), o + s[0], v);
//    subsequences(s.substr(1), o, v);
//    // sort by length and then lexicographically
//    sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
//        if (s1.length() == s2.length()) {
//            return s1 < s2;
//        } else {
//            return s1.length() < s2.length();
//        }
//    });
//}
//// has a leading 0 on hours if it is less than 10
// string convert_to_digital_time(int minutes){
//    //complete this function
//    int hours = minutes / 60;
//    int minute = minutes % 60;
//    string ans;
//    if(hours < 10){
//        ans += "0";
//    }
//    ans += to_string(hours) + ":";
//    if(minute < 10){
//        ans += "0";
//    }
//    ans += to_string(minute);
//    return ans;
//}
//// concatenate the two numbers in such a way that forms the largest number
// string concatenate(vector<int> numbers){
//    //complete this method and return the largest number you can form as a string
//    string ans;
//    // sort by largest first digit and if same use the one with fewer digits
//    // and then lexicographically
//    string s[numbers.size()];
//    for(int i = 0; i < numbers.size(); i++){
//        s[i] = to_string(numbers[i]);
//    }
//    sort(s, s + numbers.size(), [](string s1, string s2) {
//        if(s1[0] == s2[0]){
//            if (s1.length() == s2.length() && s1.length() > 1) {
//                return s1[1] > s2[1];
//            } else {
//                return s1.length() < s2.length();
//            }
//            return s1.length() < s2.length();
//        }
//        return s1[0] > s2[0];
//    });
//    for(int i = 0; i < numbers.size(); i++){
//        ans += s[i];
//    }
//
//    return ans;
//}
//
////str is the input the string to compress using run length encoding
// string compressString(const string &str){
//    //complete the function to return output string
//    string ans;
//    int count = 1;
//    for(int i = 0; i < str.length(); i++){
//        if(i == str.length() - 1){
//            ans += str[i];
//            ans += to_string(count);
//        }
//        else if(str[i] == str[i+1]){
//            count++;
//        }
//        else{
//            ans += str[i];
//            ans += to_string(count);
//            count = 1;
//        }
//    }
//    if(ans.length() >= str.length()){
//        return str;
//    }
//    return ans;
//}
//bool isPalindrome(string basicString) {
//    int i = 0;
//    int j = basicString.length() - 1;
//    while (i < j) {
//        if (basicString[i] != basicString[j]) {
//            return false;
//        }
//        i++;
//        j--;
//    }
//    return true;
//}
//// replace one character in the palindrome with another character in a way that is
//// lexicographically smallest
// string breakPalindrome(string palindrome) {
//    //complete this method and return the smallest string you can form
//    if (palindrome.length() == 1) {
//        return "";
//    }
//    int i = 0;
//    if (palindrome[0] != 'a') {
//        palindrome[0] = 'a';
//    } else {
//        while (palindrome[i] == 'a') {
//            i++;
//        }
//        char temp = palindrome[i];
//        palindrome[i] = 'a';
//        if (isPalindrome(palindrome)) {
//            palindrome[i] = temp;
//            palindrome[i + 1] = 'b';
//        }
//    }
//    return palindrome;
//}
//
//
//// given a sentence, return the sentence with the words so only the first letter
//// of each word is capitalized and the rest are lowercase.
// string normalize(const string &sentence) {
//    string copy = sentence;
//    //Make the changes in copy, and return it
//    // turn all the letters to lowercase except the first letter of each word
//    for (char & i : copy) {
//        if (i >= 'A' && i <= 'Z') {
//            i += 32;
//        }
//    }
//    // turn the first letter of each word to uppercase by looking for the word
//    // after each last blank space
//    int i = 0;
//    if (copy[0] >= 'a' && copy[0] <= 'z') {
//        copy[0] -= 32;
//    }
//    while (i < copy.length()) {
//        if (copy[i] == ' ') {
//            i++;
//            while (copy[i] == ' ') {
//                i++;
//            }
//            if (copy[i] >= 'a' && copy[i] <= 'z') {
//                copy[i] -= 32;
//            }
//        }
//        i++;
//    }
//    return copy;
//}
//
// void housing(const int* arr, int n, int k) {
//    //complete this method
//    int i = 0;
//    int j = 0;
//    int cs = 0;
//    while(j<n) {
//        cs+=arr[j];
//        j++;
//        while(cs > k && i < j) {
//            cs-=arr[i];
//            i++;
//        }
//        if(cs == k) {
//            cout << i << " - " << j-1 << endl;
//        }
//    }
//}
//
// string unique_substring(string str) {
//    //complete this method
//    int i = 0;
//    int j = 0;
//    int window_length = 0;
//    int max_window_length = 0;
//    int start_window = -1;
//    unordered_map<char, int> m;
//    while(j < str.length()) {
//        char ch = str[j];
//        if(m.count(ch) && m[ch] >= i) {
//            i = m[ch] + 1;
//            window_length = j - i;
//        }
//        m[ch] = j;
//        window_length++;
//        j++;
//        // update max_window_length
//        if(window_length > max_window_length) {
//            max_window_length = window_length;
//            start_window = i;
//        }
//    }
//    return str.substr(start_window, max_window_length);
//}
//
// string find_window(string s, const string& p) {
//    int FP[256] = {0};
//    int FS[256] = {0};
//    int count = 0;
//    int start = 0;
//    int start_index = -1;
//    int min_so_far = INT_MAX;
//    int window_size = 0;
//    for (char i : p) {
//        FP[i]++;
//    }
//
//    // sliding window algorithm
//    for(int i = 0; i < s.length(); i++) {
//        // expand the window
//        char ch = s[i];
//        FS[ch]++;
//        // count how many characters in the pattern are matched
//        if (FP[ch] != 0 && FS[ch] <= FP[ch]) {
//            count++;
//        }
//        // if all the characters in the pattern are matched, then start to
//        // shrink the window
//        if (count == p.length()) {
//            // start contracting from the left to remove unwanted characters
//            while (FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]) {
//                FS[s[start]]--;
//                start++;
//            }
//
//            // note the window size
//            window_size = i - start + 1;
//            // if the window size is the largest so far, then update the
//            // start and window size
//            if (window_size < min_so_far) {
//                min_so_far = window_size;
//                start_index = start;
//            }
//        }
//    }
//    if (start_index == -1) {
//        return "";
//    }
//    return s.substr(start_index, min_so_far);
//}
//
// string smallest_window(string str){
//    //Complete this method
//    int i = 0;
//    int j = 0;
//    int window_length = 0;
//    int max_window_length = 0;
//    int start_window = -1;
//    if (str.length() == 0) {
//        return "";
//    }
//    unordered_map<char, int> m;
//    while(j < str.length()) {
//        char ch = str[j];
//        if(m.count(ch) && m[ch] >= i) {
//            i = m[ch] + 1;
//            window_length = j - i;
//        }
//        m[ch] = j;
//        window_length++;
//        j++;
//        // update max_window_length
//        if(window_length > max_window_length) {
//            max_window_length = window_length;
//            start_window = i;
//        }
//    }
//    return str.substr(start_window, max_window_length);
//}
//
// vector<int> maxInWindow(vector<int> input,int k){
//    //complete this method
//    vector<int> result;
//    if (input.empty() || k == 0) {
//        return result;
//    }
//    // looks at every k elements sliding over one by one and finds the max of
//    // the k elements in each move adding it to the result vector, using a deque
//    deque<int> dq;
//    for (int i = 0; i < input.size(); ++i) {
//        while (!dq.empty() && dq.front() < i - k + 1) {
//            dq.pop_front();
//        }
//        while (!dq.empty() && input[dq.back()] < input[i]) {
//            dq.pop_back();
//        }
//        dq.push_back(i);
//        if (i >= k - 1) {
//            result.push_back(input[dq.front()]);
//        }
//    }
//    return result;
//}
//// given an unsorted array of integers, find the number of sub-arrays having a sum
//// exactly equal to the given number k. Use a HashMap.
// int cnt_sub_arrays(const vector<int>& arr,int k){
//    //complete this method
//    unordered_map<int, int> m;
//    int sum = 0;
//    int count = 0;
//    for (int i : arr) {
//        sum += i;
//        if (sum == k) {
//            count++;
//        }
//        if (m.count(sum - k)) {
//            count += m[sum - k];
//        }
//        m[sum]++;
//    }
//    return count;
//}
//
//template <typename T>
//void merge(vector<T> &arr, int l, int r) {
//    int mid = l + (r - l) / 2;
//    int i = l;
//    int j = mid + 1;
//    int k = l;
//    vector<T> temp(arr.size());
//    while (i <= mid && j <= r) {
//        if (arr[i] < arr[j]) {
//            temp[k++] = arr[i++];
//        } else {
//            temp[k++] = arr[j++];
//        }
//    }
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//    while (j <= r) {
//        temp[k++] = arr[j++];
//    }
//    for (i = l; i <= r; ++i) {
//        arr[i] = temp[i];
//    }
//}
//
//
//template <typename T>
//void mergesort(vector<T>& arr, int low, int high) {
//    if (low >= high) {
//        return;
//    }
//    int mid = (low + high) / 2;
//    mergesort(arr, low, mid);
//    mergesort(arr, mid + 1, high);
//    merge(arr, low, high);
//}
//
//template <typename T>
//int inversion_count(vector<T> &arr, int l, int r) {
//    if (l >= r) {
//        return 0;
//    }
//    int mid = (l + r) / 2;
//    int left_count = inversion_count(arr, l, mid);
//    int right_count = inversion_count(arr, mid + 1, r);
//    int count = left_count + right_count;
//    int i = l;
//    int j = mid + 1;
//    int k = l;
//    vector<T> temp(arr.size());
//    while (i <= mid && j <= r) {
//        if (arr[i] < arr[j]) {
//            temp[k++] = arr[i++];
//        } else {
//            temp[k++] = arr[j++];
//            count += mid - i + 1;
//        }
//    }
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//    while (j <= r) {
//        temp[k++] = arr[j++];
//    }
//    for (i = l; i <= r; ++i) {
//        arr[i] = temp[i];
//    }
//    return count;
//}
//
//template<typename T>
//int partition(vector<T> &arr, int l, int r) {
//    int i = l;
//    int j = r;
//    T pivot = arr[l];
//    while (i < j) {
//        while (i < j && arr[j] >= pivot) {
//            j--;
//        }
//        arr[i] = arr[j];
//        while (i < j && arr[i] <= pivot) {
//            i++;
//        }
//        arr[j] = arr[i];
//    }
//    arr[i] = pivot;
//    return i;
//}
//
//template <typename T>
//void quicksort(vector<T>& arr, int low, int high) {
//    if (low >= high) {
//        return;
//    }
//    int pivot = partition(arr, low, high);
//    quicksort(arr, low, pivot - 1);
//    quicksort(arr, pivot + 1, high);
//}
//
//template <typename T>
//T quick_select(vector<T>& arr,int start, int end, int k) {
//    if (start == end) {
//        return arr[start];
//    }
//    int pivot = partition(arr, start, end);
//    if (pivot == k) {
//        return arr[pivot];
//    } else if (pivot > k) {
//        return quick_select(arr, start, pivot - 1, k);
//    } else {
//        return quick_select(arr, pivot + 1, end, k);
//    }
//}
//
// bool compareStrings(const string& a, const string& b) {
//    return a + b < b + a;
//}
//// uses a modified binary search to search an array that has empty strings in it.
// int sparse_search(string a[], int n, const string& key) {
//    int low = 0;
//    int high = n - 1;
//    while (low <= high) {
//        cout << "low: " << low << " high: " << high << endl;
//        int mid = (high + low) / 2;
//        if (a[mid].empty()) {
//            cout << "mid == "" : " << mid << endl;
//            int left = mid - 1;
//            int right = mid + 1;
//            if (a[high] == key) {
//                return high;
//            } else if (a[low] == key) {
//                return low;
//            }
//            while (left >= 0 && a[left].empty()) {
//                cout << "left: " << left << endl;
//                left--;
//            }
//            while (right <= n-1 && a[right].empty()) {
//                cout << "right: " << right << endl;
//                right++;
//            }
//            if (left < 0) {
//                cout << "left < 0" << endl;
//                return right;
//            } else if (right >= n) {
//                cout << "right >= n" << endl;
//                return left;
//            } else {
//                cout << "left: " << left << " right: " << right << endl;
//                if (key < a[left]) {
//                    cout << "key < a[left]" << endl;
//                    high = left;
//                } else if (key > a[right]) {
//                    cout << "key > a[right]" << endl;
//                    low = right;
//                } else {
//                    cout << "key == a[left]" << endl;
//                    return key == a[left] ? left : right;
//                }
//            }
//        } else if (a[mid] < key) {
//            cout << "a[mid] < key" << endl;
//            low = mid + 1;
//        } else {
//            cout << "a[mid] > key" << endl;
//            high = mid - 1;
//        }
//    }
//    cout << "about to return -1 and low: " << low << " high: " << high << endl;
//    return -1;
//}
//// searches an unsorted matrix for a target and returns the row and column of the target.
//
//pair<int, int> searchMatrix(int rows, int cols, vector<vector<int>> matrix, int key) {
//    int row = 0;
//    int col = cols - 1;
//    while (row < rows && col >= 0) {
//        if (matrix[row][col] == key) {
//            return make_pair(row, col);
//        } else if (matrix[row][col] > key) {
//            col--;
//        } else {
//            row++;
//        }
//    }
//    return make_pair(-1, -1);
//}
//// implements in a way that is O(N).
// int badness(vector<pair<string,int> > teams){
//    vector<pair<string,int> > rankList;
//    rankList.emplace_back("WinOrBooze",1);
//    rankList.emplace_back("BallOfDuty",2);
//    rankList.emplace_back("WhoKnows",3);
//    rankList.emplace_back("BooleCreature",4);
//    rankList.emplace_back("DCECoders",5);
//    rankList.emplace_back("WhoKnows",6);
//    rankList.emplace_back("StrangeCase",7);
//
//
//    // initialize the badness to 0
//    int badness = 0;
//    // iterate through the teams
//    for (int i = 0; i < teams.size(); i++) {
//        // compute the distance between the teams preferred rank and the actual rank
//        int distance = abs(teams[i].second - rankList[i].second);
//        // add the distance to the badness
//        badness += distance;
//    }
//    return badness;
//}
//
////sort the balls in place in a single pass (O(N) time, O(1) space)
// vector<int> sortBalls(vector<int> balls){
//    //sort the balls in place in a single pass (O(N) time, O(1) space)
//    int n = balls.size();
//    for (int i = 0; i < n; i++) {
//        int j = i;
//        while (j > 0 && balls[j] < balls[j-1]) {
//            swap(balls[j], balls[j-1]);
//            j--;
//        }
//    }
//    return balls;
//}
//
//// find the smallest subarray that needs to be sorted to sort the entire array and
//// put the starting and ending indices in start and end respectively, and add to a
//// pair and return the pair.
// pair<int,int> subarraySorting(vector<int> a){
//    // find the starting index and ending index of the smallest subarray that needs to be sorted
//    // to sort the entire array and return {-1,-1} if the array is already sorted
//    int start = -1;
//    int end = -1;
//    int n = a.size();
//    for (int i = 0; i < n; i++) {
//        if (a[i] > a[i+1]) {
//            start = i;
//            break;
//        }
//    }
//    if (start == -1) {
//        return make_pair(-1, -1);
//    }
//    for (int i = n-1; i >= 0; i--) {
//        if (a[i] < a[i-1]) {
//            end = i;
//            break;
//        }
//    }
//    return make_pair(start, end + 1);
//}
//template<typename T>
//int lowerbound(vector<T> a, T key) {
//    int low = 0;
//    int high = a.size() - 1;
//    int index = -1;
//    while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (a[mid] == key) {
//            index = mid;
//            high = mid - 1;
//        } else if (a[mid] > key) {
//            high = mid - 1;
//        } else {
//            low = mid + 1;
//        }
//    }
//    return index;
//}
//
//template <typename T>
//int upperbound(vector<T> a, T key) {
//    int low = 0;
//    int high = a.size() - 1;
//    int index = -1;
//    while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (a[mid] == key) {
//            index = mid;
//            low = mid + 1;
//        } else if (a[mid] > key) {
//            high = mid - 1;
//        } else {
//            low = mid + 1;
//        }
//    }
//    return index;
//}
//
//template <typename T>
// int frequency(vector<T> a, T key) {
//    int low = lowerbound(a, key);
//    int high = upperbound(a, key);
//    if (low == -1 || high == -1) {
//        return 0;
//    }
//    return high - low + 1;
//}
//
//template <typename T>
// int rotated_search(vector<T> a, T key) {
//    int low = 0;
//    int high = a.size() - 1;
//    while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (a[mid] == key) {
//            return mid;
//        } else if (a[low] <= a[mid]) {
//            // left half is sorted
//            if (key >= a[low] && key <= a[mid]) {
//                high = mid - 1;
//            } else {
//                low = mid + 1;
//            }
//        } else {
//            // right half is sorted
//            if (key >= a[mid] && key <= a[high]) {
//                low = mid + 1;
//            } else {
//                high = mid - 1;
//            }
//        }
//    }
//    return -1;
//}
//
//// uses a binary search to find the square root of a number
// double square_root(int n, int p) {
//    int low = 0;
//    int high = n;
//    double ans = 0;
//    // binary search for the int part
//    while (low <= high) {
//        int mid = low + (high - low) / 2;
//        if (mid * mid == n) {
//            return (double) mid;
//        } else if (mid * mid < n) {
//            ans = (double) mid;
//            low = mid + 1;
//        } else {
//            high = mid - 1;
//        }
//    }
//    // linear search for the decimal part
//    double inc = 0.1;
//    for (int i = 1; i <= p; i++) {
//        while (ans * ans <= n) {
//            ans += inc;
//        }
//        ans = ans - inc;
//        inc = inc / 10.0;
//    }
//    return ans;
//}
//
// bool canPlaceBirds(int B, int N, vector<int> nests, int sep) {
//    int birds = 1;
//    int location = nests[0];
//
//    for(int i = 1; i <= N-1; i++) {
//        int current_location = nests[i];
//        if(current_location - location >= sep) {
//            birds++;
//            location = current_location;
//            if (birds == B) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
// int angryBirds(int B,vector<int> nests) {
//    // sorting the array if it is not sorted
//    sort(nests.begin(), nests.end());
//    int N = nests.size();
//    int s = 0;
//    int e = nests[N-1] - nests[0];
//    int ans = -1;
//    while(s<=e) {
//        int mid = (e+s)/2;
//        bool canPlace = canPlaceBirds(B,N,nests,mid);
//        if(canPlace) {
//            ans = mid;
//            s = mid + 1;
//        } else {
//            e = mid - 1;
//        }
//    }
//    return ans;
//}
//
//template <typename T>
// pair<T, T> min_pair(vector<T> a1, vector<T> a2) {
//    // sort a2 arrays
//    sort(a2.begin(), a2.end());
//    int p1, p2;
//    int diff = INT_MAX;
//    // iterate over a1 and look for closest elements in a2
//    for (T x : a1) {
//        auto lb = lowerbound(a2.begin(), a2.end(), x) - a2.begin();
//
//        if (lb >= 1 && x - a2[lb-1] < diff) {
//            diff = x - a2[lb-1];
//            p2 = x;
//            p1 = a2[lb-1];
//        }
//        // greater / right
//        if (lb != a2.size() && a2[lb] - x < diff) {
//            diff = a2[lb] - x;
//            p1 = x;
//            p2 = a2[lb];
//        }
//    }
//    return make_pair(p1, p2);
//}
//
//bool isDividableByK(vector<int> a,int n,int k,int l){
//    //return true if every partition gets at least limit no of coins
//    int count = 0;
//    int sum = 0;
//    for(int i = 0;i < n;i++){
//        if(sum + a[i] >= l){
//            count++;
//            sum = 0;
//        }
//        else {
//            sum += a[i];
//        }
//    }
//    return count >= k;
//
//}
//
// int getCoins(vector<int> arr,int k){
//    int n = arr.size();
//    int hi = 0;
//    int lo = 0;
//    for(int i=0;i<n;i++){
//        hi += arr[i];
//    }
//    int mid;
//    int ans;
//    while(lo<=hi){
//        mid = lo + (hi - lo)/2;
//        bool willWork = isDividableByK(arr,n,k,mid);
//        if(willWork){
//            lo = mid + 1;
//            ans = mid;
//        }
//        else{
//            hi = mid - 1;
//        }
//    }
//    return ans;
//}
//
//bool isDoable(vector<int>& books, int m, int l) {
//    int n = books.size();
//    int sum = 0;
//    int students = 1;
//    for (int i = 0; i < n; i++) {
//        if (sum + books[i] > l) {
//            students++;
//            sum = books[i];
//            if (students > m) {
//                return false;
//            }
//        } else {
//            sum += books[i];
//        }
//    }
//    return true;
//}
//
//// divide the array into m parts and find the maximum sum of a partition
// int minPages(vector<int> books, int m){
//    int n = books.size();
//    int lo = 0;
//    int hi = 0;
//    for (int i = 0; i < n; i++) {
//        hi += books[i];
//        lo = max(lo, books[i]);
//    }
//    int ans;
//    while (lo <= hi) {
//        int mid = lo + (hi - lo)/2;
//        if(isDoable(books, m, mid)) {
//            ans = min(ans, mid);
//            hi = mid - 1;
//        } else {
//            lo = mid + 1;
//        }
//    }
//    return ans;
//}
//
//int countWays(int n) {
//    if (n < 0) {
//        return 0;
//    }
//    if (n == 0) {
//        return 1;
//    }
//    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
//}
//
//// uses recursion to find if the subset sum is possible
//template <typename T>
//bool isSubsetSum(vector<T> a, T sum) {
//    // use recursion to find if the subset sum is possible
//    if (sum == 0) {
//        return true;
//    }
//    if (a.empty()) {
//        return false;
//    }
//    T head = a.back();
//    a.pop_back();
//    if (isSubsetSum(a, sum - head)) {
//        return true;
//    }
//    return isSubsetSum(a, sum);
//}
//
//template <typename T>
//int countSubsets(vector<T> a,int size, int i, T sum) {
//    // use recursion to find the number of subsets
//    if (i == size) {
//        if (sum == 0) {
//            return 1;
//        }
//        return 0;
//    }
//    int inc = countSubsets(a, size, i + 1, sum - a[i]);
//    int exc = countSubsets(a, size, i + 1, sum);
//    return inc + exc;
//}
//
//void generateBrackets(const string& output, int n, int open, int close, int i) {
//    // use recursion to generate all possible brackets
//    if (i == n * 2) {
//        cout << output << endl;
//        return;
//    }
//    if (open < n) { // open bracket
//        generateBrackets(output + "(", n, open + 1, close, i + 1);
//    }
//    if (close < open)  { // close bracket
//        generateBrackets(output + ")", n, open, close + 1, i + 1);
//    }
//}
//
// string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//void printKeypadOutput(string input, const string& output, int i = 0) {
//    // use recursion to generate all possible keypad outputs
//    if (input[i] == '\0') {
//        cout << output << endl;
//        return;
//    }
//    // rec case
//    int digit = input[i] - '0';
//    if (digit == 0 || digit == 1) {
//        printKeypadOutput(input, output, i + 1);
//    }
//    for (char k : keypad[digit]) {
//        printKeypadOutput(input, output + k, i + 1);
//    }
//}
//
//set<string> buildPermutations(string s) {
//    // use recursion to generate all possible permutations
//    set<string> ans;
//    if (s.empty()) {
//        ans.insert("");
//        return ans;
//    }
//    int i = 0;
//    char c = s[i];
//    string rest = s.substr(1);
//    set<string> words = buildPermutations(rest);
//    for (const string& word : words) {
//        for (int j = 0; j <= word.size(); j++) {
//            string new_word = word.substr(0, j) + c + word.substr(j);
//            ans.insert(new_word);
//        }
//    }
//    return ans;
//}
//
//// use recursion to generate all possible permutations of the string s using a set
//// to avoid duplicates
// vector<string> findSortedPermutations(string s){
//    // use helper function buildPermutations to generate all possible permutations
//    set<string> permutations = buildPermutations(std::move(s));
//    vector<string> ans;
//    ans.reserve(permutations.size());
//    for (const string& permutation : permutations) {
//        ans.push_back(permutation);
//    }
//    sort(ans.begin(), ans.end());
//    return ans;
//}
//
//void printBoard(int n, int board[][20]) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//bool isSafe(int board[][20], int n, int row, int col) {
//    // check column
//    for (int i = 0; i < n; i++) {
//        if (board[i][col] == 1) {
//            return false;
//        }
//    }
//    // left diagonal
//    int i = row;
//    int j = col;
//    while (i >= 0 && j >= 0) {
//        if (board[i][j] == 1) {
//            return false;
//        }
//        i--;
//        j--;
//    }
//    // right diagonal
//    i = row;
//    j = col;
//    while (i >= 0 && j < n) {
//        if (board[i][j] == 1) {
//            return false;
//        }
//        i--;
//        j++;
//    }
//    return true;
//}
//
//// N queens problem
// bool solveNQueen(int n, int board[][20], int i) {
//    // base case
//    if (i == n) {
//        printBoard(n, board);
//        return true;
//    }
//    for (int j = 0; j < n; j++) {
//        if (isSafe(board, n, i, j)) {
//            board[i][j] = 1;
//            if (solveNQueen(n, board, i + 1)) {
//                return true;
//            }
//            board[i][j] = 0;
//        }
//    }
//    return false;
//}
//
//void solveNQueen(int n, int board[][20], int row, int& count) {
//    // base case
//    if (row == n) {
//        count++;
//        printBoard(n, board);
//        return;
//    }
//    for (int col = 0; col < n; col++) {
//        if (isSafe(board, n, row, col)) {
//            board[row][col] = 1;
//            solveNQueen(n, board, row + 1, count);
//            board[row][col] = 0;
//        }
//    }
//}
//// prints how many ways there are to place n queens on a board of size n
// int nQueen(int n){
//    int board[20][20] = {0};
//    int count = 0;
//    solveNQueen(n, board, 0, count);
//    return count;
//}
//
//void printSudoBoard(int board[][9], int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//bool isValidSudokuMove(int mat[][9], int i, int j, int num, int n) {
//    // check row
//    for (int k = 0; k < n; k++) {
//        if (mat[i][k] == num) {
//            return false;
//        }
//    }
//    // check column
//    for (int k = 0; k < n; k++) {
//        if (mat[k][j] == num) {
//            return false;
//        }
//    }
//    // check 3x3 box
//    int box_i = i - i % 3;
//    int box_j = j - j % 3;
//    for (int k = 0; k < 3; k++) {
//        for (int l = 0; l < 3; l++) {
//            if (mat[box_i + k][box_j + l] == num) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool solveSudoku(int mat[0][9], int i, int j, int n) {
//    // base case
//    if (i == n) {
//        printSudoBoard(mat, n);
//        return true;
//    }
//    // rec case
//    if (j == n) {
//        return solveSudoku(mat, i + 1, 0, n);
//    }
//    // skip if already filled
//    if (mat[i][j] != 0) {
//        return solveSudoku(mat, i, j + 1, n);
//    }
//    // cell to be filled
//    for (int no = 1; no <= n; no++) {
//        if (isValidSudokuMove(mat, i, j, no, n)) {
//            mat[i][j] = no;
//            bool solveSubProblem = solveSudoku(mat, i, j + 1, n);
//            if (solveSubProblem) {
//                return true;
//            }
//        }
//    }
//    // if no option is found, backtrack
//    mat[i][j] = 0;
//    return false;
//}
//
// vector<vector<int> > solveSudoku(vector<vector<int> > input){
//    int n = input.size();
//    int board[9][9];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            board[i][j] = input[i][j];
//        }
//    }
//    solveSudoku(board, 0, 0, n);
//    vector<vector<int> > ans;
//    for (int i = 0; i < n; i++) {
//        vector<int> row;
//        row.reserve(n);
//        for (int j = 0; j < n; j++) {
//            row.push_back(board[i][j]);
//        }
//        ans.push_back(row);
//    }
//    return ans;
//}
//
//// given two numbers a and b, compute a raised to power of b. As this value can
//// be very large, compute it to modulo 10^9 + 7.
// long long int powerModulo(int a, int b){
//    long long int MOD = 1000000007;
//    long long int ans = 1;
//    while(b > 0){
//        if(b & 1){
//            ans = (ans * a) % MOD;
//        }
//        a = (a * a) % MOD;
//        b >>= 1;
//    }
//    return ans;
//}
//
////Oswald and Henry are playing a game of coins. They have a row of n coins [C1, C2, ..., Cn]
//// with values [V1, V2, ..., Vn]. where Ci coin has Vi value. They take turns alternatively.
//// In one turn the player can pick either the first or the last coin of the row. Given both
//// Oswald and Henry are very smart players, you need to find the maximum possible value Oswald
//// can earn if he plays first.
// int gameOfCoins(int n, vector<int> v){
//    int Henry = 0;
//    int Oswald = 0;
//
//    // Oswald goes first and picks the coin n from front or back
//    if (v[0] == n) {
//        Oswald += v[0];
//        v.erase(v.begin());
//    } else {
//        Oswald += v[v.size() - 1];
//        v.erase(v.begin() + v.size() - 1);
//    }
//
//    // look at front and back of the vector and pop off the highest value each time
//    // and add it to the sum of one of the player, Henry or Oswald
//    for (int i = 1; !v.empty(); i++) {
//        if (i%2 == 1) {
//            // Henry's turn, look at both ends of the vector and remove and add
//            // the highest value to the sum of Henry
//            if (v[0] > v[v.size() - 1]) {
//                Henry += v[0];
//                v.erase(v.begin());
//            } else {
//                Henry += v[v.size() - 1];
//                v.erase(v.begin() + v.size() - 1);
//            }
//        } else {
//            // Oswald's turn, look at both ends of the vector and remove and add
//            // the highest value to the sum of Oswald
//            if (v[0] > v[v.size() - 1]) {
//                Oswald += v[0];
//                v.erase(v.begin());
//            } else {
//                Oswald += v[v.size() - 1];
//                v.erase(v.begin() + v.size() - 1);
//            }
//        }
//    }
//    return Oswald;
//}
//
////Oswald and Henry are playing a game of coins. They have a row of n coins [C1, C2, ..., Cn]
//// with values [V1, V2, ..., Vn]. where Ci coin has Vi value. They take turns alternatively.
//// In one turn the player can pick either the first or last coin of the row, and he is
//// supposed to do it 'k' times. Given both Oswald and Henry are very smart players, you need
//// to find the maximum possible value Oswald can earn if he plays first.
// int gameOfCoinsAdvanced(int n, int k, vector<int> v){
//    int Oswald = 0;
//    // look at front and back of the vector and pop off the highest value each time
//    // and add it to the sum of one of the player, Henry or Oswald
//    for (int i = 0; !v.empty(); i++) {
//        if (i%2 == 1) {
//            // Henry's turn, look at both ends of the vector and remove and add
//            // the highest value to the sum of Henry
//            for (int j = 0; j < k; j++) {
//                if (v[0] > v[v.size() - 1]) {
//                    v.erase(v.begin());
//                } else {
//                    v.erase(v.begin() + v.size() - 1);
//                }
//            }
//        } else {
//            // Oswald's turn, look at both ends of the vector and remove and add
//            // the highest value to the sum of Oswald
//            for (int j = 0; j < k; j++) {
//                if (v[0] > v[v.size() - 1]) {
//                    Oswald += v[0];
//                    v.erase(v.begin());
//                } else {
//                    Oswald += v[v.size() - 1];
//                    v.erase(v.begin() + v.size() - 1);
//                }
//            }
//        }
//    }
//    return Oswald;
//}
//bool saveMove(int row, int col, vector<vector<char>> maze) {
//    if (row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size()) {
//        return false;
//    }
//    if (maze[row][col] == 'X') {
//        return false;
//    }
//    return true;
//}
//int encode(int row, int col, int n) {
//    return row * n + col + 1;
//}
///**
// * Given an integer N and a grid of size N x N. The cells of the grid are numbered
// * row wise from 1 to N^2. Rat wants to travel from cell number 1 to cell number N^2,
// * and it can move in only right and down directions from a particular cell. There
// * is exactly one path from the source to destination as some cells are blocked.
// * Help rat to find the path. Use backtracking to solve.
// * @param n  size of the grid
// * @param c  a 2D vector consisting of only 'O's and 'X's where 'O' represents a
// * open cell and 'X' represents a blocked cell.
// * @return the path from source to destination
// */
// vector<int> ratInAMaze(int n, vector<vector<char>> c){
//    vector<int> path;
//    int row = 0;
//    int col = 0;
//    c[row][col] = '*'; // mark the starting cell as visited
//    path.push_back(encode(row, col, n));
//    while (row < n - 1 || col < n - 1) {
//        if (saveMove(row + 1, col, c)) {
//            row++;
//            c[row][col] = '*';
//            path.push_back(encode(row, col, n));
//        } else if (saveMove(row, col + 1, c)) {
//            col++;
//            c[row][col] = '*';
//            path.push_back(encode(row, col, n));
//        } else {
//            // backtrack
//            row = path[path.size() - 1] / n;
//            col = path[path.size() - 1] % n;
//            path.pop_back();
//        }
//    }
//    return path;
//}
//pair<bool, int> seekPath(int m, int n, int i, int j, vector<vector<int>> v, bool visited[][100]) {
//    if (i == m - 1 && j == n - 1) {
//        pair <bool, int> maxPath={true, 0};
//        return maxPath;
//    }
//    if (i >= m || i < 0 || j >= n || j < 0) {
//        pair <bool, int> maxPath{false, -1};
//        return maxPath;
//    } else {
//        visited[i][j] = true;
//        pair <bool, int> mp{false, -1};
//        // check down
//        if (i < m-1 && v[i+1][j] == 1 && !visited[i+1][j]) {
//            pair <bool, int> down = seekPath(m, n, i+1, j, v, visited);
//            if (down.first) {
//                mp.first = true;
//                mp.second = max(mp.second, down.second);
//            }
//        }
//        // check right
//        if (j < n-1 && v[i][j+1] == 1 && !visited[i][j+1]) {
//            pair <bool, int> right = seekPath(m, n, i, j+1, v, visited);
//            if (right.first) {
//                mp.first = true;
//                mp.second = max(mp.second, right.second);
//            }
//        } // check up
//        if (i > 0 && v[i-1][j] == 1 && !visited[i-1][j]) {
//            pair <bool, int> up = seekPath(m, n, i-1, j, v, visited);
//            if (up.first) {
//                mp.first = true;
//                mp.second = max(mp.second, up.second);
//            }
//        }
//        // check left
//        if (i > 0 && v[i][j-1] == 1 && !visited[i][j-1]) {
//            pair <bool, int> left = seekPath(m, n, i, j-1, v, visited);
//            if (left.first) {
//                mp.first = true;
//                mp.second = max(mp.second, left.second);
//            }
//        }
//        visited[i][j] = false;
//        mp.second += 1;
//        return mp;
//    }
//}
///**
// * Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the longest
// * possible route possible from top left position (0,0) to bottom right position (M-1, N-1)
// * within the matrix. We are allowed to move to only adjacent cells which are not
// * hurdles. The route cannot contain any diagonal moves and a location once visited
// * in a particular path cannot be visited again.
// * @param m  is the number of rows in the matrix
// * @param n  is the number of columns in the matrix
// * @param v  is a 2D vector (m x n) where each element is either 0 or 1 and 0 represents
// * the hurdle and 1 represents the open cell.
// * @return a single integer which is the length of the longest path possible.
// */
// int findLongestPath(int m, int n, vector<vector<int>> v){
//    bool visited[100][100] = {{false}};
//    pair<bool, int> p = seekPath(m, n, 0, 0, std::move(v), visited);
//    return p.second;
//}
//
// vector<string> split(const string &basicString, char i) {
//    vector<string> result;
//    stringstream ss(basicString);
//    string intermediate;
//    while (getline(ss, intermediate, i)) {
//        result.push_back(intermediate);
//    }
//    return result;
//}
//
// string simplifyPath(const string& path){
//    istringstream iss(path);
//    string intermediate;
//    vector<string> result;
//    bool isRoot = path[0] == '/';
//
//    while (getline(iss, intermediate, '/')) {
//        if (intermediate != "." && !intermediate.empty()) {
//            result.push_back(intermediate);
//        }
//    }
//    vector<string> s;
//    if (isRoot) {
//        s.emplace_back("");
//    }
//    for (auto& i : result) {
//        if (i == "..") {
//            if (s.empty() || s.back() == "..") {
//                s.push_back(i);
//            }else if(!s[s.size()-1].empty()) {
//                s.pop_back();
//            }
//        } else {
//            s.push_back(i);
//        }
//    }
//    if (s.size() == 1 && s[0].empty()) {
//        return "/";
//    }
//    ostringstream oss;
//    int i = 0;
//    for (auto &j : s) {
//        if (i != 0) {
//            oss << "/";
//        }
//        i++;
//        oss << j;
//    }
//    return oss.str();
//}
//
///**
// * Given the price of a stock over the next n days, calculate the span of the
// * stocks price for all n days. The span of a stock's price today is defined as
// * the maximum number of consecutive days (starting from today) for which the
// * price of the stock was less than or equal to today's price.
// * @param v  is a vector of integers representing the price of the stock over the next n days.
// * @return  a vector of integers representing the span of the stock's price for all n days.
// */
// vector<int> stockSpan(vector<int> v) {
//    vector<int> result;
//    Stack<pair<int, int>> s;
//    for (int i = 0; i < v.size(); i++) {
//        while (!s.isEmpty() && s.peek().first <= v[i]) {
//            s.pop();
//        }
//        if (s.isEmpty()) {
//            result.push_back(i+1);
//        } else {
//            result.push_back(i - s.peek().second);
//        }
//        s.push({v[i], i});
//    }
//    return result;
//}
//// input is : 10 5 2 3 0 12 18 20 22 -1
// void runningMedian() {
//    priority_queue<int> left_heap;
//    priority_queue<int, vector<int>, greater<>> right_heap;
//
//    int d;
//    cin >> d;
//    left_heap.push(d);
//    double med = d;
//    cout << med << " ";
//    cin >> d;
//    while (d != -1) {
//        if(left_heap.size() > right_heap.size()) {
//            if (d < med) {
//                right_heap.push(left_heap.top());
//                left_heap.pop();
//                left_heap.push(d);
//            } else {
//                right_heap.push(d);
//            }
//            med = (left_heap.top() + right_heap.top()) / 2.0;
//        }
//        else if (left_heap.size() == right_heap.size()) {
//            if (d < med) {
//                left_heap.push(d);
//                med = left_heap.top();
//            } else {
//                right_heap.push(d);
//                med = right_heap.top();
//            }
//        } else {
//            if (d < med) {
//                left_heap.push(d);
//            } else {
//                left_heap.push(right_heap.top());
//                right_heap.pop();
//                right_heap.push(d);
//            }
//            med = (left_heap.top() + right_heap.top()) / 2.0;
//        }
//        cout << med << " ";
//        cin >> d;
//    }
//}
//class MedianHandler{
//public:
//    float median;
//    priority_queue<int, vector<int>, greater<>> right_heap;
//    priority_queue<int> left_heap;
//    MedianHandler() {
//        median = 0;
//    }
//
//    void push(int number){
//        //Complete this method to update median after every insertion
//        //of a new number
//        if(left_heap.size() > right_heap.size()) {
//            if (number < median) {
//                right_heap.push(left_heap.top());
//                left_heap.pop();
//                left_heap.push(number);
//            } else {
//                right_heap.push(number);
//            }
//            median = (left_heap.top() + right_heap.top()) / 2.0;
//        }
//        else if (left_heap.size() == right_heap.size()) {
//            if (number < median) {
//                left_heap.push(number);
//                median = left_heap.top();
//            } else {
//                right_heap.push(number);
//                median = right_heap.top();
//            }
//        } else {
//            if (number < median) {
//                left_heap.push(number);
//            } else {
//                left_heap.push(right_heap.top());
//                right_heap.pop();
//                right_heap.push(number);
//            }
//            median = (left_heap.top() + right_heap.top()) / 2.0;
//        }
//
//    }
//    [[nodiscard]] float getMedian() const{
//        //Complete this , Should return the median in O(1) time
//        return median;
//    }
//};
//
// void runningMedian2() {
//    MedianHandler m;
//    int d;
//    cin >> d;
//    m.push(d);
//    cout << m.getMedian() << " ";
//    cin >> d;
//    while (d != -1) {
//        m.push(d);
//        cout << m.getMedian() << " ";
//        cin >> d;
//    }
//}
//
// vector<int> mergeKArrays(const vector<vector<int> >& arrays){
//    //Complete this function
//    priority_queue<int, vector<int>, greater<>> pq;
//    // push all the elements from each vector of vectors using a double for loop
//    for(auto & array : arrays){
//        for(int j : array){
//            pq.push(j);
//        }
//    }
//    vector<int> result;
//    while(!pq.empty()){
//        result.push_back(pq.top());
//        pq.pop();
//    }
//    return result;
//}
//
//template<typename T>
// vector<T> commonElements(vector<T>& v1, vector<T>& v2){
//    //Complete this function using STL algorithms
//    vector<T> result;
//    set<T> s;
//    for(auto & i : v1){
//        s.insert(i);
//    }
//    for(auto & i : v2){
//        if(s.find(i) != s.end()){
//            result.push_back(i);
//        }
//    }
//    // sort the result vector
//    sort(result.begin(), result.end());
//    return result;
//}
//
//// Given a string, find the first repeating letter in a string in a single scan
//// of the string. Return '\0' if no repeating letter is found.
//
// char firstRepeatingChar(string input) {
//    // Complete this function
//    int n = input.length();
//    if(n == 0) return '\0';
//    unordered_map<char, int> m;
//    for(int i = 0; i < n; i++){
//        if(m.find(input[i]) != m.end()){
//            return input[i];
//        }
//        m[input[i]] = i;
//    }
//    return '\0';
//}
//
// int  count_triplets(const vector<int>& arr, int r) {
//    unordered_map<long, long> left;
//    unordered_map<long, long> right;
//    int count = 0;
//    int n = arr.size();
//    for(auto & i : arr){
//        right[i]++;
//        left[i] = 0;
//    }
//    for(int i = 0; i < n; i++){
//        right[arr[i]]--;
//        if (arr[i] % r == 0) {
//            long b = arr[i];
//            long a = arr[i] / r;
//            long c = arr[i] * r;
//            count += left[a] * right[c];
//        }
//
//        left[arr[i]]++;
//    }
//    return count;
//}
//
//// given N cartesian points in a 2D Plane, find the number of axis parallel
//// rectangles that are formed
// int countRectangles(const vector<Point>& points) {
//    // Complete this function
//    set<Point, PointComparator> s;
//    int count = 0;
//
//    for(auto & i : points){
//        s.insert(i);
//    }
//    for(auto it = s.begin(); it != prev(s.end()); it++){
//        for (auto jt = next(it); jt != s.end(); jt++){
//            Point p1 = *it;
//            Point p2 = *jt;
//            if (p2.x == p1.x || p2.y == p1.y){
//                continue;
//            }
//            Point p3(p1.x, p2.y);
//            Point p4(p2.x, p1.y);
//            if (s.find(p3) != s.end() && s.find(p4) != s.end()){
//                count++;
//            }
//        }
//    }
//    return count/2;
//}
//
//// Given N Cartesian Points in a 2D Plane, find the number of triangles such that
//// the base or perpendicular is parallel to the X or Y axis
// int countTriangles(const vector<Point>& points) {
//    // Complete this function
//    unordered_map<int, int> X; // {key, freq}
//    unordered_map<int, int> Y; // {key, freq}
//    int count = 0;
//    for (auto & i : points){ // count the frequency of each point
//        int x = i.x;
//        int y = i.y;
//        X[x]++;
//        Y[y]++;
//    }
//    for (auto & p : points){
//       int x = p.x;
//       int y = p.y;
//
//       int fx = X[x];
//       int fy = Y[y];
//
//       count += (fx - 1) * (fy - 1);
//    }
//    return count;
//}
//
//int min_bars_helper(
//        const string& s, vector<string>& words, int idx, unordered_set<string>& m){
//    // base case
//    if (s[idx] == '\0'){
//        return 0;
//    }
//    int min_bars = INT_MAX;
//    string current_string;
//    for (int j = idx; s[j] != '\0'; j++){
//        current_string += s[j];
//        if (m.find(current_string) != m.end()){
//            int bars = min_bars_helper(s, words, j + 1, m);
//            if (bars != -1){
//                min_bars = min(min_bars, bars + 1);
//            }
//        }
//    }
//    return min_bars == INT_MAX ? -1 : min_bars;
//}
//
//int min_bars_helper(
//        const string& s, string words[], int idx, unordered_set<string>& m){
//    // base case
//    if (s[idx] == '\0'){
//        return 0;
//    }
//    int min_bars = INT_MAX;
//    string current_string;
//    for (int j = idx; s[j] != '\0'; j++){
//        current_string += s[j];
//        if (m.find(current_string) != m.end()){
//            int bars = min_bars_helper(s, words, j + 1, m);
//            if (bars != -1){
//                min_bars = min(min_bars, bars + 1);
//            }
//        }
//    }
//    return min_bars == INT_MAX ? -1 : min_bars;
//}
//
// int min_bars(const string& s, vector<string>& words) {
//    unordered_set<string> m;
//    // get length of words array
//    int n = 0;
//
//
//    for (auto & word : words){
//        m.insert(word);
//    }
//    int output = min_bars_helper(s, words, 0, m);
//    return output - 1;
//}
//
// int min_bars(const string& s, string words[], int n){
//    //Complete this function return the min bars
//    // n is number of words
//    unordered_set<string> m;
//    for (int i = 0; i < n; i++){
//        m.insert(words[i]);
//    }
//    int output = min_bars_helper(s, words, 0, m);
//    return output - 1;
//}
//
// int longestSubarrayKSum(const vector<int>& arr,int k){
//    //Complete this function and return the length of the longest subarray
//    // such that sum of elements is k
//    // use prefix sums and an unordered_map
//    unordered_map<int, int> m;
//    int sum = 0;
//    int max_len = 0;
//    for (int i = 0; i < arr.size(); i++){
//        sum += arr[i];
//        if (sum == k){
//            max_len = i + 1;
//        }
//        if (m.find(sum - k) != m.end()){
//            max_len = max(max_len, i - m[sum - k]);
//        }
//        m[sum] = i;
//    }
//    return max_len;
//}
//
///*
// * Complete the 'subsetA' function below.
// *
// * The function is expected to return an INTEGER_ARRAY.
// * The function accepts INTEGER_ARRAY arr as parameter.
// * the intersection of A and B is null
// * the union A and B is equal to the original set
// * the number of elements in subset A is minimal
// * the sum of A's elements is greater than the sum of B's elements
// */
//
// vector<int> subsetA(const vector<int>& arr) {
//    // Complete this function
//    // use a priority queue
//    // get sum of elements in arr
//    long long sum = 0;
//    int sum2 = 0;
//    long long curSum = 0;
//    for (auto & i : arr){
//        sum += i;
//        sum2 += i;
//    }
//    // print out the sum
//    cout << sum << endl;
//    cout << sum2 << endl;
//    priority_queue<int> pq;
//    vector<int> output;
//    for (auto & i : arr){
//        pq.push(i);
//    }
//    // add one element to output and check that its sum is greater than sum/2
//    while (!pq.empty()){
//        int curr = pq.top();
//        pq.pop();
//        output.push_back(curr);
//        curSum += curr;
//        if (curSum > sum / 2){
//            break;
//        }
//    }
//    // sort the output
//    sort(output.begin(), output.end());
//    return output;
//
//}
//bool isTriangle(int a, int b, int c) {
//    cout << a << " " << b << " " << c << endl;
//    // Complete this function
//    // use the fact that a triangle is formed by the sum of two sides
//    // and the third side is the difference of the two sides
//    // if the sum of two sides is greater than the third side, then it is a triangle
//    return a + b > c && a + c > b && b + c > a;
//}
///**
// * Given 3 lines, find out if they can form a non-degenerate triangle. If the 3
// * lines are placed with tips joined such that they form a triangle with non-zero
// * angles at each vertex, then a non-degenerate triangle is formed.
// * @param a[n] an array where each index i describes the length of side a for triangle i
// * @param b[n] an array representing lengths of sides b[i] for triangle i
// * @param c[n] an array representing lengths of sides c[i] for triangle i
// * @return String arr[n]: an array where the value at each index i is "Yes" if a[i],
// * b[i], and c[i] can form a triangle with non-zero angles at each vertex, and "No"
// * if they cannot.
// */
//
//vector <string> triangleOrNot(
//        const vector <int>& a, const vector <int>& b, const vector <int>& c) {
//    // Complete this function
//    // check that all three sizes of vectors are equal
//    int n = a.size();
//    if (a.size() != b.size() || a.size() != c.size()){
//        return {};
//    }
//    vector<string> output;
//    for (int i = 1; i < n; i++){
//        if (isTriangle(a[i], b[i], c[i])){
//            output.emplace_back("Yes");
//        } else {
//            output.emplace_back("No");
//        }
//    }
//    return output;
//}
//int findStartingIndex(vector<int> arr, int k){
//    // start at front of unsorted array and count indexes until
//    // k is found
//    int n = arr.size();
//    int i = 0;
//    while (i < n && arr[i] != k){
//        i++;
//    }
//    return i;
//}
//
//int findEndingIndex(vector<int> arr, int k) {
//    // start at back of array and count indexes going backwards until
//    // k is found
//    int n = arr.size();
//    int i = n - 1;
//    while (i >= 0 && arr[i] != k){
//        i--;
//    }
//    return i;
//}
//
///*
// * Complete the 'degreeOfArray' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts INTEGER_ARRAY arr as parameter.
// */
//
// int degreeOfArray(const vector<int>& arr) {
//    // use a hashmap to store the number of times each element appears
//    unordered_map<int, int> m;
//    for (auto & i : arr){
//        m[i]++;
//    }
//    vector<int> valuesWithMaxDegree;
//    int maxDegree = 0;
//    for (auto & i : m){
//        if (i.second > maxDegree){
//            maxDegree = i.second;
//            valuesWithMaxDegree.clear();
//            valuesWithMaxDegree.push_back(i.first);
//        } else if (i.second == maxDegree){
//            valuesWithMaxDegree.push_back(i.first);
//        }
//    }
//    // find the smallest subarray from the values with max degree and return its size
//    int min;
//    int n = valuesWithMaxDegree.size();
//    for (int i = 0; i < n; i++){
//        int start = findStartingIndex(arr, valuesWithMaxDegree[i]);
//        int end = findEndingIndex(arr, valuesWithMaxDegree[i]);
//        if (i == 0){
//            min = end - start + 1;
//        } else {
//            if (end - start + 1 < min){
//                min = end - start + 1;
//            }
//        }
//    }
//    return min;
//}
//
///*
// * Complete the 'compressedString' function below.
// *
// * The function is expected to return a STRING.
// * The function accepts STRING message as parameter.
// */
//
// string compressWithRunLengthEncoding(string message) {
//    // message is the input string to compress using run length encoding
//    // use a string stream to store the compressed string as long as the character
//    // is repeated more than once
//    stringstream ss;
//    int n = message.size();
//    int i = 0;
//    while (i < n){
//        int count = 1;
//        while (i < n - 1 && message[i] == message[i + 1]){
//            count++;
//            i++;
//        }
//        // if count is greater than 1, then add the character and the count to the string stream
//        ss << message[i] << (count > 1 ? to_string(count) : "");
//        i++;
//    }
//    if (ss.str().size() < message.size()){
//        return ss.str();
//    } else {
//        return message;
//    }
//}
//
///**
// * Complete the 'circularArray' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// * @param INTEGER n is the length of the array
// * @param INTEGER_ARRAY endNode[m]: each element endNode[i] (where 0 <= i < m-1)
// * means when starting from position endNode[i], finish at position endNode[i+1]
// * @return INTEGER: the node number that is visited most; if there are multiple answers,
// * return the smallest one.
// */
//
// int circularArray(int n, const vector<int>& endNode) {
//    // use a hashmap to store the number of times each node is visited
//    unordered_map<int, int> m;
//    for (auto & i : endNode){
//        m[i]++;
//    }
//    int max = 0;
//    int maxNode = 0;
//    for (auto & i : m){
//        if (i.second > max){
//            max = i.second;
//            maxNode = i.first;
//        }
//    }
//    return maxNode;
//}
//
//bool canFlyWithMagicCarpet(int magic, int distance) {
//    return magic >= distance;
//}
///*
// * Complete the 'optimalPoint' function below. which represents Aladdin and
// * his magic carpet.
// *
// * The function is expected to return an INTEGER.
// * The function accepts following parameters:
// *  1. INTEGER_ARRAY magic
// *  2. INTEGER_ARRAY dist
// */
//int aladdinsStartingPoint(vector<int> magic, vector<int> dist) {
//    if (magic.size() != dist.size()) {
//        return -1;
//    }
//    int n = magic.size();
//    int sumMagic = accumulate(magic.begin(), magic.end(), 0);
//    int sumDist = accumulate(dist.begin(), dist.end(), 0);
//    if (sumMagic < sumDist) {
//        return -1;
//    }
//    int startPosition = 0;
//    do {
//        cout << "start position is " << startPosition << endl;
//        int count = 0;
//        int position = startPosition;
//        cout << "position is " << position << endl;
//        int magicPotion = magic[position];
//        cout << "magic is " << magicPotion << endl;
//        int distance = dist[position+1];
//        cout << "to next distance is " << distance;
//        while (canFlyWithMagicCarpet(magicPotion, distance)) {
//            if (count == n - 1) {
//                cout << "count == n - 1, returning start position";
//                return startPosition;
//            }
//            if (position == magic.size() - 1) {
//                cout << "position is resetting to 0" << endl;
//                position = 0;
//            }
//
//            cout << "position++" << position << endl;
//            magicPotion = magicPotion - dist[position] + magic[position];
//            cout << "magicPotion is now at " << magicPotion << endl;
//            position++;
//            distance = dist[position];
//            cout << "distance to next place is " << distance << endl;
//            if (position == startPosition) {
//                cout << "position == startPosition, returning startPosition of "
//                     << startPosition << endl;
//                return startPosition;
//            }
//            count++;
//            cout << "count++ is now at " << count << endl;
//        }
//        startPosition++;
//        cout << "starting position incremented is now " << startPosition
//             << endl;
//
//    } while (startPosition != n);
//    return -1;
//}
//
///**
// * N-K Ladders problem
// * @return  the number of ways to climb the ladder
// */
// int countWaysOpt(int n, int k) {
//     vector<int> dp(n+1, 0);
//     dp[0] = dp[1] = 1;
//     for (int i = 2; i <=k; i++) {
//         dp[i] = 2*dp[i-1];
//     }
//     for (int i = k+1; i <=n; i++) {
//         dp[i] = 2*dp[i-1] - dp[i-k-1];
//     }
//     return dp[n];
// }
//
// /**
//  * Coin change problem DP solution
//  */
//  int minNumberOfCoinsForChange(int m, vector<int> denoms) {
//      vector<int> dp(m+1, 0);
//      dp[0] = 0;
//      for (int i = 1; i <= m; i++) {
//          dp[i] = INT_MAX;
//          for (int c : denoms) {
//              if (i - c >= 0 and dp[i-c] != INT_MAX) {
//                  dp[i] = min(dp[i], dp[i-c] + 1);
//              }
//          }
//      }
//      return dp[m]==INT_MAX ? -1 : dp[m];
//  }
//
//  /**
//   * Cutting rods problem
//   * @return
//   */
//   int max_profit_dp(int *prices, int n) {
//       int dp[n+1];
//       dp[0] = 0;
//       for (int len=1; len<=n; len++) {
//           int ans = INT_MIN;
//           for (int i=0; i<len; i++) {
//               int cut = i + 1;
//               int cur_ans = prices[i] + dp[len-cut];
//               ans = max(ans, cur_ans);
//           }
//           dp[len] = ans;
//       }
//       return dp[n];
//   }
//
//   /**
//    * Min array jump problem using DP
//    * @return
//    */
//int min_jumps(vector<int> arr, int n, vector<int> dp, int i) {
//    if (i == n-1) {
//        return 0;
//    }
//    if (i>=n) {
//        return INT_MAX;
//    }
//    if (dp[i] != 0) {
//        return dp[i];
//    }
//    int steps = INT_MAX;
//    int max_jump = arr[i];
//
//    for (int jump = 1; jump<=max_jump; jump++) {
//        int next_cell = i + jump;
//        int subprob = min_jumps(arr, n, dp, next_cell);
//        if (subprob != INT_MAX) {
//            steps = min(steps, subprob + 1);
//        }
//    }
//    dp[i] = steps;
//
//    return dp[i];
//}
//
///**
// * frog jump problem using DP
// * @return
// */
// int getMinCost(vector<int> stones) {
//     int n = stones.size();
//     vector<int> dp(n, 0);
//     dp[0] = abs(stones[1] - stones[0]);
//     for (int i = 2; i < n; i++) {
//         int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
//         int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];
//         dp[i] = min(op1, op2);
//     }
//     return dp[n-1];
// }
//
// /**
//  * max subset sub no adjacent elements problem using DP
//  * @return
//  */
//  int maxSubsetSumNoAdjacent(vector<int> array) {
//      int n = array.size();
//      vector<int> dp(n+1, 0);
//      if (n==1) {
//          return max(array[0], 0);
//      }
//      else if (n==2) {
//          return max(0, max(array[0], array[1]));
//      }
//      // bottom up logic
//      dp[0] = max(array[0], 0);
//      dp[1] = max(0, max(array[0], array[1]));
//      for (int i = 2; i < n; i++) {
//          int inc = array[i] + dp[i-2];
//          int exc = dp[i-1];
//          dp[i] = max(inc, exc);
//      }
//      return dp[n-1];
//  }
//
///**
// * longes increasing subsequence problem using DP
// * @return
// */
// int lis(vector<int> array) {
//     int n = array.size();
//     vector<int> dp(n, 1);
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (array[i] > array[j]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     int max_len = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         max_len = max(max_len, dp[i]);
//     }
//     return max_len;
// }
//
// /**
//  * box stacking problem using DP
//  */
//  bool compareBoxes(vector<int> b1, vector<int> b2) {
//      return b1[2] < b2[2];
//  }
//  bool canPlace(vector<int> b1, vector<int> b2) {
//      if (b1[0]>b2[0] and b1[1]>b2[1] and b1[2]>b2[2]) {
//          return true;
//      }
//      return false;
//  }
//  int boxStacking(vector<vector<int>> boxes) {
//      int n = boxes.size();
//      sort(boxes.begin(), boxes.end(), compareBoxes);
//      vector<int> dp(n, 0);
//      for (int i = 0; i < n; i++) {
//          dp[i] = boxes[i][2];
//          for (int j = 0; j < i; j++) {
//              if (canPlace(boxes[i], boxes[j])) {
//                  dp[i] = max(dp[i], dp[j] + boxes[i][2]);
//              }
//          }
//      }
//      int max_height = INT_MIN;
//      for (int i = 0; i < n; i++) {
//          max_height = max(max_height, dp[i]);
//      }
//      return max_height;
//  }
//
//  /**
//   * knapsack problem using DP
//   * @return
//   */
//  int knapsack(vector<int> weights, vector<int> values, int capacity) {
//      int n = weights.size();
//      vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
//      for (int i = 1; i <= n; i++) {
//          for (int j = 1; j <= capacity; j++) {
//              if (weights[i-1] <= j) {
//                  dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
//              }
//              else {
//                  dp[i][j] = dp[i-1][j];
//              }
//          }
//      }
//      return dp[n][capacity];
//  }
//
//  /**
//   * counting trees problem using DP
//   * @return
//   */
//  int countTrees(int n) {
//      vector<int> dp(n+1, 0);
//      dp[0] = 1;
//      dp[1] = 1;
//      for (int i = 2; i <= n; i++) {
//          for (int j = 1; j <= i; j++) {
//              dp[i] += dp[j-1] * dp[i-j];
//          }
//      }
//      return dp[n];
//  }
//
//
///**
// * frog jump2
// * @param stones
// * @param k
// * @return
// */
//long long minimumCost(vector<int> stones, int k){
//    int n = stones.size();
//    vector<long long> dp(n);
//    for (int i = 1; i < n; i++) {
//        dp[i] = std::numeric_limits<long long>::max();
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = i+1; j <= i+k; j++) {
//            if (j < n) {
//                dp[j] = min(dp[j], dp[i] + abs(stones[j] - stones[i]));
//            }
//        }
//    }
//    return dp[n - 1];
//}
//
///**
// * selling wines problem using DP
// * @return
// */
//int wines_bottom_up(vector<int> prices, int n) {
//    vector<vector<int>> dp(n, vector<int>(n+1, 0));
//    for (int i=n-1; i>=0; i--) {
//        for (int j=0; j<n; j++) {
//            if (j <= i) {
//                int y = n - (j - 1);
//                int pick_left = prices[i]*y + dp[i+1][j];
//                int pick_right = prices[j]*(y) + dp[i][j-1];
//                dp[i][j] = max(pick_left, pick_right);
//            }
//        }
//    }
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<n; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return dp[0][n-1];
//}
//
///**
// * Longest common subsequence problem using DP
// * @return
// */
// int lcs(string s1, string s2) {
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s1[i-1] == s2[j-1]) {
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             }
//             else {
//                 int op1 = dp[i-1][j];
//                 int op2 = dp[i][j-1];
//                 dp[i][j] = max(op1, op2);
//             }
//         }
//     }
//     vector<char> result;
//     int i = n;
//     int j = m;
//     while (i != 0 && j != 0) {
//         if (dp[i][j] == dp[i][j-1]) {
//             result.push_back(s1[i-1]);
//             j--;
//         } else if (dp[i][j] == dp[i-1][j]) {
//             i--;
//         } else {
//             result.push_back(s1[i-1]);
//             i--;
//             j--;
//         }
//     }
//     reverse(result.begin(), result.end());
//     for (auto c : result) {
//         cout << c << ", ";
//     }
//     return dp[n][m];
// }
//
///**
// * Counting subsequences problem using DP
// * @return
// */
// int countingSubsequencesBU(string a, string b) {
//     int m = a.size();
//     int n = b.size();
//     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//     for (int i=0; i<m;i++) {
//         dp[i][0] = 1;
//     }
//     //1,1 ... m,n
//     for(int i=1; i<=m; i++) {
//         for(int j=1; j<=n; j++) {
//             if (a[i-1] == b[j-1]) {
//                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//             } else {
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[m][n];
// }
//
// /**
//  * Knapsack problem using DP bottom up
//  * @return
//  */
//  int knapsackDP(int wt[], int price[], int N, int W) {
//      vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
//
//      for (int n=1; n<=N; n++) {
//          for (int w=1; w<=W; w++) {
//              int inc = 0, exc = 0;
//              if (wt[n-1] <= w) {
//                  inc = price[n-1] + dp[n-1][w-wt[n-1]];
//              }
//              exc = dp[n-1][w];
//              dp[n][w] = max(inc, exc);
//          }
//      }
//      return dp[N][W];
//  }
//
///**
// * coin change problem, given a value N and an interger vector COINS representing
// * the denominations of the coins,
// * your task is to find total number of comintantions of these coins that
// * make a sum of N.
// * @param n
// * @param coins
// * @return
// */
//long long findCombinations(int n, vector<int> coins){
//    vector<vector<int>> dp(n + 1, vector<int>(coins.size(), 0));
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < coins.size(); j++) {
//            if (i == 0) {
//                dp[i][j] = 1;
//            } else if (i < coins[j]) {
//                dp[i][j] = dp[i][j - 1];
//            } else {
//                dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j];
//            }
//        }
//    }
//    return dp[n][coins.size() - 1];
//}
//
///**
// * palindrome partitioning problem, given a string S,
// */
//int palindromicPartitioningUtil(string s){
//    // min cuts to make s palindromic
//    int n = s.length();
//    vector<vector<bool> > isPalin(n+1,vector<bool>(n,false));
//
//    for(int i=0;i<n;i++){
//        isPalin[i][i] = true;
//    }
//
//    //2d dp palindromic grid for helper
//    // tell whether a string i...j is a palindrome or not
//    for(int len=2;len<=n;len++){
//        for(int i=0;i<=n-len;i++){
//            //substring i to j
//            int j = i + len - 1;
//            if(len==2){
//                isPalin[i][j] = (s[i]==s[j]);
//            }
//            else{
//                isPalin[i][j] = (s[i]==s[j] and isPalin[i+1][j-1]);
//            }
//        }
//    }
//
//    //min cut logic
//    vector<int> cuts(n+1,INT_MAX);
//
//    for(int i=0;i<n;i++){
//        if(isPalin[0][i]){
//            cuts[i] = 0;
//        }
//        else{
//            cuts[i]  = cuts[i-1] + 1;
//            for(int j=1;j<i;j++){
//                if(isPalin[j][i] and cuts[j-1] + 1 < cuts[i]){
//                    cuts[i] = cuts[j-1] + 1;
//                }
//            }
//        }
//    }
//    return cuts[n-1];
//}
//int partitioning(string str){
//    int res = palindromicPartitioningUtil(str);
//    return res;
//}
//
///**
// * edit distance problem, given two strings s1 and s2,
// * @param a  string 1
// * @param b  string 2
// * @param na  length of string 1
// * @param nb  length of string 2
// * @param dp  2d dp array
// * @return
// */
//int minDistance(string a, string b, int na, int nb, vector<vector<int>>&dp){
//    if (na == 0) {
//        return nb;
//    }
//    if (nb == 0) {
//        return na;
//    }
//    if (dp[na][nb] != -1) {
//        return dp[na][nb];
//    }
//    int res = std::numeric_limits<int>::max();
//    if (a[na - 1] == b[nb - 1]) {
//        res = minDistance(a, b, na - 1, nb - 1, dp);
//    } else {
//        int op1 = minDistance(a, b, na - 1, nb, dp);
//        int op2 = minDistance(a, b, na, nb - 1, dp);
//        int ob3 = minDistance(a, b, na - 1, nb - 1, dp);
//        res = min(op1, min(op2, ob3)) + 1;
//    }
//    return dp[na][nb] = res;
//}
//
//
//int editDistance(string str1, string str2){
//    int n = str1.size();
//    int m = str2.size();
//    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//    int res = minDistance(str1, str2, n, m, dp);
//    return res;
//}
//
//int main()
//{
//    vector<int> magic = {10, 6, 3, 8, 1};
//    vector<int> dist = {1, 3, 8, 4, 3};
//    cout << aladdinsStartingPoint(magic, dist) << endl;
//}
