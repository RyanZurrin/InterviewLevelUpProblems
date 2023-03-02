//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_SLL_NODE_H
#define LEETCODE_SLL_NODE_H
#include <vector>
#include <iostream>
using namespace std;

class sll_node {
public:
    int data;
    sll_node* next;
    explicit sll_node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    bool isPresent(sll_node* head, int key){
        sll_node* temp = head;
        while(temp != nullptr){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void insertAtHead(sll_node*& head, int data) {
        if (head == nullptr) {
            head = new sll_node(data);
        } else {
            sll_node* temp = new sll_node(data);
            temp->next = head;
            head = temp;
        }
    }

    void insertInMiddle(sll_node*& head, int data, int pos) {
        if (pos == 0) {
            insertAtHead(head, data);
        } else {
            sll_node* temp = head;
            int count = 0;
            while (temp != nullptr && count < pos - 1) {
                temp = temp->next;
                count++;
            }
            if (temp != nullptr) {
                sll_node* temp2 = temp->next;
                temp->next = new sll_node(data);
                temp->next->next = temp2;
            }
        }
    }

    void insertAtEnd(sll_node*& head, int data) {
        if (head == nullptr) {
            head = new sll_node(data);
        } else {
            sll_node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new sll_node(data);
        }
    }

    void reverseList(sll_node*& head) {
        sll_node* prev = nullptr;
        sll_node* curr = head;
        sll_node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    sll_node* recReverse(sll_node*& head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        sll_node* sHead = recReverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return sHead;
    }

    sll_node* kReverse(sll_node* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        sll_node* curr = head;
        sll_node* prev = nullptr;
        sll_node* next = nullptr;
        int count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != nullptr) {
            head->next = kReverse(next, k);
        }
        return prev;
    }

    void printAll(sll_node* head) {
        sll_node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }

    sll_node* sortList(sll_node* head) {
        // store all the nodes in a vector and then sort it and add to a new list and
        // return the new list
        vector<sll_node*> v;
        sll_node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            v.push_back(temp);
            temp = temp->next;
            count++;
        }
        sort(v.begin(), v.end(), [](sll_node* a, sll_node* b) {
            return a->data < b->data;
        });
        sll_node* newHead = nullptr;
        for (int i = 0; i < count; i++) {
            insertAtEnd(newHead, v[i]->data);
        }
        return newHead;
    }

    sll_node* merge(sll_node* a, sll_node* b) {
        if(a == nullptr){
            return b;
        }
        if(b == nullptr){
            return a;
        }
        sll_node * c = nullptr;
        while (a != nullptr && b != nullptr) {
            if (a->data < b->data) {
                insertAtEnd(c, a->data);
                a = a->next;
            } else {
                insertAtEnd(c, b->data);
                b = b->next;
            }
        }
        while (a != nullptr) {
            insertAtEnd(c, a->data);
            a = a->next;
        }
        while (b != nullptr) {
            insertAtEnd(c, b->data);
            b = b->next;
        }
        return c;
    }
// if 8 nodes 1,2,3,4,5,6,7,8 are given mid will return 4
    int getMid(sll_node* head) {
        if (head == nullptr) {
            return -1;
        }
        sll_node* slow = head;
        // if even number of nodes return the node on the lesser side of the list
        // for instance if there are 8 nodes return the 4th node
        for (sll_node* fast = head->next; fast != nullptr; fast = fast->next) {
            if (fast->next == nullptr) {
                return slow->data;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }

    int kthLastElement(sll_node *head, int k){
        if(head == nullptr){
            return -1;
        }
        sll_node* slow = head;
        sll_node* fast = head;
        for(int i = 0; i < k; i++){
            if(fast == nullptr){
                return -1;
            }
            fast = fast->next;
        }
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }

    sll_node* midPoint(sll_node* head){
        if(head == nullptr){
            return nullptr;
        }
        sll_node* slow = head;
        sll_node* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    sll_node* mergeSort(sll_node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        sll_node* mid = midPoint(head);
        sll_node* left = head;
        sll_node* right = mid->next;
        mid->next = nullptr;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }

    bool containsCycle(sll_node *head){
        if(head == nullptr){
            return false;
        }
        sll_node* slow = head;
        sll_node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }



};

#endif //LEETCODE_SLL_NODE_H
