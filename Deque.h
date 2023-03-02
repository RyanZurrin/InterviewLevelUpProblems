//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_DEQUE_H
#define LEETCODE_DEQUE_H
#include <climits>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

template <class T>
class dequeNode {
public:
    T data;
    dequeNode<T> *next;
    dequeNode<T> *prev;
    explicit dequeNode(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <class T>
class Deque {
public:
    dequeNode<T> *front;
    dequeNode<T> *rear;
    int size{};
    int capacity{};
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
        capacity = INT_MAX;
    }

    explicit Deque(int capacity) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        this->capacity = capacity;
    }
    void pushFront(T data) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        auto *newNode = new dequeNode<T>(data);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }
    void pushBack(T data) {
        if (size == capacity) {
            cout << "Deque is full" << endl;
            return;
        }
        auto *newNode = new dequeNode<T>(data);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    T popFront() {
        if (front == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        dequeNode<T> *temp = front;
        front = front->next;
        size--;
        return temp->data;
    }
    T popBack() {
        if (rear == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        dequeNode<T> *temp = rear;
        rear = rear->prev;
        size--;
        return temp->data;
    }
    T peekFront() {
        if (front == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        return front->data;
    }
    T peekBack() {
        if (rear == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        return rear->data;
    }
    bool empty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    int getCapacity() {
        return capacity;
    }
    void printDeque() {
        dequeNode<T> *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void destroyDeque() {
        dequeNode<T> *temp = front;
        while (temp != nullptr) {
            front = front->next;
            delete temp;
            temp = front;
        }
        size = 0;
    }
    void resize() {
        capacity = capacity * 2;
    }
    void resize(int newCapacity) {
        if (size > capacity) {
            capacity = size;
        } else {
            capacity = newCapacity;
        }
    }
    ~Deque() {
        destroyDeque();
    }
}; // end of class Deque

#endif //LEETCODE_DEQUE_H

template<class T>
void maxSubArray(vector<T> &A, int k) {
    Deque<T> Q(k);
    int n = A.size();
    int i;
    //1. process only the first k elements
    for (i = 0; i < k; i++) {
        // logic here
        if(!Q.empty() && A[i] > Q.peekBack()) {
            Q.popBack();
        }
        Q.pushBack(i);
    }
    //2. process the rest of the elements
    for (; i<n; i++) {
        cout << A[Q.peekFront()] << " ";
        // logic here
        while (!Q.empty() && Q.peekFront() <= i - k) {
            Q.popFront();
        }
        while (!Q.empty() && A[i] >= A[Q.peekBack()]) {
            Q.popBack();
        }
        Q.pushBack(i);
    }
}
