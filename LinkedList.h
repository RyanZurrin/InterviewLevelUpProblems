//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_LINKEDLIST_H
#define LEETCODE_LINKEDLIST_H
#include "ListNode.h"

struct LinkedList {
    ListNode *head;
    LinkedList() : head(nullptr) {}
    explicit LinkedList(ListNode *head) : head(head) {}

    void addNodeToList(LinkedList &list, int val) {
        auto *newNode = new ListNode(val);
        newNode->next = nullptr;
        if (list.head == nullptr) {
            list.head = newNode;
        } else {
            ListNode *curr = list.head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    static void printList(ListNode *head) {
        while (head) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }


    static ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

    static ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->val < cur->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                ListNode* prev = dummy;
                while (prev->next->val < temp->val) {
                    prev = prev->next;
                }
                temp->next = prev->next;
                prev->next = temp;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

#endif //LEETCODE_LINKEDLIST_H
