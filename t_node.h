//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_T_NODE_H
#define LEETCODE_T_NODE_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class t_node{
    T data;
    t_node* next;
public:
    explicit t_node(T data){
        this->data = data;
        this->next = nullptr;
    }
    t_node(T data, t_node* next){
        this->data = data;
        this->next = next;
    }
    T getData(){
        return this->data;
    }
    t_node* getNext(){
        return this->next;
    }

    void setData(T data_){
        this->data = data_;
    }
    void setNext(t_node* newNext){
        this->next = newNext;
    }



    bool isPresent(t_node<T> * head, T key){
        //Complete this function
        t_node<T> * temp = head;
        while(temp != nullptr){
            if(temp->getData() == key){
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    void insertAtFront(t_node<T> ** head, T data){
        if (*head == nullptr){
            *head = new t_node<T>(data);
        }
        else{
            auto * temp = new t_node<T>(data, *head);
            *head = temp;
        }
    }


    void insertAtEnd(t_node<T> ** head, T data){
        if (*head == nullptr){
            *head = new t_node<T>(data);
        }
        else{
            t_node<T> * temp = *head;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
            }
            temp->setNext(new t_node<T>(data));
        }
    }


    void insertAtPosition(t_node<T> ** head, T data, int position){
        if (*head == nullptr){
            *head = new t_node<T>(data);
        }
        else{
            t_node<T> * temp = *head;
            int count = 0;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
                count++;
            }
            if(position == 0){
                insertAtFront(head, data);
            }
            else if(position == count+1){
                insertAtEnd(head, data);
            }
            else{
                temp = *head;
                count = 0;
                while(count < position-1){
                    temp = temp->getNext();
                    count++;
                }
                t_node<T> * temp2 = temp->getNext();
                temp->setNext(new t_node<T>(data, temp2));
            }
        }
    }


    void printAll(t_node<T> * head){
        t_node<T> * temp = head;
        while(temp != nullptr){
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }


    t_node<T>* findNode(t_node<T> * head, T key){
        t_node<T> * temp = head;
        while(temp != nullptr){
            if(temp->getData() == key){
                return temp;
            }
            temp = temp->getNext();
        }
        return nullptr;
    }


    void deleteNode(t_node<T> ** head, T data){
        if (*head == nullptr){
            return;
        }
        else{
            t_node<T> * temp = *head;
            if(temp->getData() == data){
                *head = temp->getNext();
                delete temp;
            }
            else{
                while(temp->getNext() != nullptr){
                    if(temp->getNext()->getData() == data){
                        t_node<T> * temp2 = temp->getNext();
                        temp->setNext(temp2->getNext());
                        delete temp2;
                        break;
                    }
                    temp = temp->getNext();
                }
            }
        }
    }


    int size(t_node<T> * head){
        if(head == nullptr){
            return 0;
        }
        else{
            int count = 0;
            t_node<T> * temp = head;
            while(temp != nullptr){
                count++;
                temp = temp->getNext();
            }
            return count;
        }
    }


    int keyCount(t_node<T> * head, T key){
        if(head == nullptr){
            return 0;
        }
        else{
            int count = 0;
            t_node<T> * temp = head;
            while(temp != nullptr){
                if(temp->getData() == key){
                    count++;
                }
                temp = temp->getNext();
            }
            return count;
        }
    }


    void deleteAllNodesWIthKey(t_node<T>*& head, T key){
        if (head == nullptr){
            return;
        }
        else{
            do {
                t_node<T> * temp = findNode(head, key);
                if(temp != nullptr){
                    deleteNode(&head, key);
                }
            } while (keyCount(head, key) > 0);
        }
    }


    void deleteList(t_node<T> ** head){
        if (*head == nullptr){
            return;
        }
        else{
            t_node<T> * temp = *head;
            while(temp != nullptr){
                t_node<T> * temp2 = temp;
                temp = temp->getNext();
                delete temp2;
            }
            *head = nullptr;
        }
    }


    void reverseList(t_node<T> *& head){
        if (*head == nullptr){
            return;
        }
        else{
            t_node<T> * temp = *head;
            t_node<T> * prev = nullptr;
            while(temp != nullptr){
                t_node<T> * temp2 = temp->getNext();
                temp->setNext(prev);
                prev = temp;
                temp = temp2;
            }
            *head = prev;
        }
    }


    t_node<T>* sortList(t_node<T> * head){
        if(head == nullptr){
            return nullptr;
        }
        else {
            t_node<T>* curr = head;
            int count = size(head);
            vector<t_node<T>*> v;
            for (int i = 0; i < count; i++) {
                v.push_back(curr);
                curr = curr->getNext();
            }
            sort(v.begin(), v.end(), [](t_node<T>* a, t_node<T>* b) {
                return a->getData() < b->getData();
            });
            t_node<T>* newHead = nullptr;
            for (int i = 0; i < count; i++) {
                insertAtEnd(&newHead, v[i]->getData());
            }
            return newHead;
        }
    }


    t_node<T>* merge(t_node<T> * head1, t_node<T> * head2){
        if(head1 == nullptr){
            return head2;
        }
        else if(head2 == nullptr){
            return head1;
        }
        else{
            t_node<T> * newHead = nullptr;
            while (head1 != nullptr && head2 != nullptr){
                if(head1->getData() < head2->getData()){
                    insertAtEnd(&newHead, head1->getData());
                    head1 = head1->getNext();
                }
                else{
                    insertAtEnd(&newHead, head2->getData());
                    head2 = head2->getNext();
                }
            }
            while(head1 != nullptr){
                insertAtEnd(&newHead, head1->getData());
                head1 = head1->getNext();
            }
            while(head2 != nullptr){
                insertAtEnd(&newHead, head2->getData());
                head2 = head2->getNext();
            }
            return newHead;
        }
    }


    t_node<T>* findMiddleNode(t_node<T> * head){
        if(head == nullptr){
            return nullptr;
        }
        else{
            t_node<T> * slow = head;
            t_node<T> * fast = head->getNext();
            while(fast != nullptr && fast->getNext() != nullptr){
                slow = slow->getNext();
                fast = fast->getNext()->getNext();
            }
            return slow;
        }
    }


    T getMid(t_node<T> * head){
        if(head == nullptr){
            return nullptr;
        }
        else{
            t_node<T> * slow = head;
            t_node<T> * fast = head->getNext();
            while(fast != nullptr && fast->getNext() != nullptr){
                slow = slow->getNext();
                fast = fast->getNext()->getNext();
            }
            return slow->getData();
        }
    }


    T kthLastElement(t_node<T> * head, int k){
        if(head == nullptr){
            return nullptr;
        }
        else{
            t_node<T> * slow = head;
            t_node<T> * fast = head;
            for(int i = 0; i < k; i++){
                fast = fast->getNext();
            }
            while(fast != nullptr){
                slow = slow->getNext();
                fast = fast->getNext();
            }
            return slow->getData();
        }
    }


    t_node<T>* partition(t_node<T> * head, T x){
        if(head == nullptr){
            return nullptr;
        }
        else{
            t_node<T> * smallerHead = nullptr;
            t_node<T> * largerHead = nullptr;
            t_node<T> * smaller = nullptr;
            t_node<T> * larger = nullptr;
            while(head != nullptr){
                if(head->getData() < x){
                    insertAtEnd(&smallerHead, head->getData());
                    head = head->getNext();
                }
                else{
                    insertAtEnd(&largerHead, head->getData());
                    head = head->getNext();
                }
            }
            smaller = smallerHead;
            larger = largerHead;
            while(smaller != nullptr && larger != nullptr){
                t_node<T> * temp = smaller->getNext();
                smaller->setNext(larger);
                smaller = temp;
                temp = larger->getNext();
                larger->setNext(smaller);
                larger = temp;
            }
            if(smaller == nullptr){
                return largerHead;
            }
            else{
                return smallerHead;
            }
        }
    }


    t_node<T>* mergeSort(t_node<T> * head){
        if(head == nullptr || head->getNext() == nullptr){
            return head;
        }
        else{
            t_node<T> * mid = findMiddleNode(head);
            t_node<T> * left = head;
            t_node<T> * right = mid->getNext();
            mid->setNext(nullptr);
            left = mergeSort(left);
            right = mergeSort(right);
            return merge(left, right);
        }
    }


    bool hasCycle(t_node<T> * head){
        if(head == nullptr){
            return false;
        }
        else{
            t_node<T> * slow = head;
            t_node<T> * fast = head;
            while(fast != nullptr && fast->getNext() != nullptr){
                slow = slow->getNext();
                fast = fast->getNext()->getNext();
                if(slow == fast){
                    return true;
                }
            }
            return false;
        }
    }

};

#endif //LEETCODE_T_NODE_H
