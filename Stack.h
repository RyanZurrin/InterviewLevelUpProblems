//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_STACK_H
#define LEETCODE_STACK_H
#include <iostream>
#include <utility>
using namespace std;


template <class T>
class stackNode {
public:
    T data;
    stackNode<T> *next;
    explicit stackNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Stack {
public:
    stackNode<T> *top;
    int size{};
    Stack() {
        top = nullptr;
        size = 0;
    }
    void push(T data) {
        auto *newNode = new stackNode<T>(data);
        newNode->next = top;
        top = newNode;
        size++;
    }
    T pop() {
        if (top == nullptr) {
            // -1 or if pair then pair{-1,-1}
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        stackNode<T> *temp = top;
        top = top->next;
        size--;
        return temp->data;
    }
    T peek() {
        if (top == nullptr) {
            if constexpr (is_same<T, pair<int, int>>::value) {
                return pair<int, int>{-1, -1};
            } else {
                return -1;
            }
        }
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    int getSize() {
        return size;
    }
    void printStack() {
        stackNode<T> *temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void empty() {
        stackNode<T> *temp = top;
        while (temp != nullptr) {
            top = top->next;
            delete temp;
            temp = top;
        }
        size = 0;
    }
    // reverse a stack
    void reverseStack(Stack<T> *s) {
        auto *temp = new Stack<T>();
        while (!s->isEmpty()) {
            temp->push(s->pop());
        }
        while (!temp->isEmpty()) {
            s->push(temp->pop());
        }
    }

    // check if a string is palindrome
    bool palindrome(const string& str) {
        auto *s = new Stack<char>();
        for (char i : str) {
            s->push(i);
        }
        for (char i : str) {
            if (s->pop() != i) {
                return false;
            }
        }
        return true;
    }

    // check if a string is an anagram
    bool isAnagram(string& str1, string& str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
        auto *s1 = new Stack<char>();
        auto *s2 = new Stack<char>();
        for (char i : str1) {
            s1->push(i);
        }
        for (char i : str2) {
            s2->push(i);
        }
        for (int i = 0; i < str1.length(); i++) {
            if (s1->pop() != s2->pop()) {
                return false;
            }
        }
        return true;
    }
    // is balanced parenthesis
    bool isBalanced(const string& input) {
        // use a stack and a switch case
        Stack<char> s;
        for (auto ch : input) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    s.push(ch);
                    break;
                case ')':
                    if (!s.isEmpty() && s.peek() == '(') {
                        s.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!s.isEmpty() && s.peek() == '[') {
                        s.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!s.isEmpty() && s.peek() == '{') {
                        s.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    continue;
            }
        }
        return s.isEmpty();
    }

    // check if there is redundant parenthesis, brackets, or braces
    bool isRedundant(const string& input) {
        // check that input is not empty
        if (input.length() == 0) {
            return false;
        }
        // make sure that the input has proper matching parenthesis, brackets, or braces
        bool balanced = isBalanced(input);
        if (!balanced) {
            cout << "The input is not balanced" << endl;
            return true;
        }
        Stack<char> s;
        bool isRedundant = false;
        for (auto ch : input) {
            switch (ch) {
                case ')':
                    isRedundant = true;
                    while (!s.isEmpty() && s.peek() != '(') {
                        char temp = s.pop();
                        if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                            isRedundant = false;
                        }
                    }
                    s.pop();
                    if(isRedundant) {
                        return true;
                    }
                    break;
                case ']':
                    isRedundant = true;
                    while (!s.isEmpty() && s.peek() != '[') {
                        char temp = s.pop();
                        if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                            isRedundant = false;
                        }
                    }
                    s.pop();
                    if(isRedundant) {
                        return true;
                    }
                    break;
                case '}':
                    isRedundant = true;
                    while (!s.isEmpty() && s.peek() != '{') {
                        char temp = s.pop();
                        if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                            isRedundant = false;
                        }
                    }
                    s.pop();
                    if(isRedundant) {
                        return true;
                    }
                    break;
                default:
                    s.push(ch);
            }
        }
        return isRedundant;
    }



}; // end of class Stack

#endif //LEETCODE_STACK_H
