//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_QUEUE_H
#define LEETCODE_QUEUE_H
#include <climits>
#include <iostream>
#include <utility>
using namespace std;


template <class T>
class queueNode {
public:
    T data;
    queueNode<T> *next;
    explicit queueNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};



template <class T>
class Queue {
public:
    queueNode<T> *front{};
    queueNode<T> *rear{};
    int size{};
    int capacity{};
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
        this->capacity = INT_MAX;
    }

    explicit Queue(int capacity) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        this->capacity = capacity;
    }
    void enqueue(T data) {
        if (size == capacity) {
            return;
        }
        auto *newNode = new queueNode<T>(data);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    T dequeue() {
        if (front == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        queueNode<T> *temp = front;
        front = front->next;
        size--;
        return temp->data;
    }
    T peek() {
        if (front == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        return front->data;
    }

    void peek(T& val) {
        if  (front == nullptr) {
            return;
        } else {
            val = front->data;
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
    int getSize() {
        return size;
    }
    void printQueue() {
        queueNode<T> *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void destroyQueue() {
        queueNode<T> *temp = front;
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
        if (newCapacity < size) {
            cout << "New capacity is smaller than current size" << endl;
            return;
        } else {
            capacity = newCapacity;
        }
    }
    ~Queue() {
        destroyQueue();
    }
}; // end of class Queue
#endif //LEETCODE_QUEUE_H
