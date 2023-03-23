//
// Created by ryanz on 3/23/2023.
//

#ifndef LEETCODE_GRAPH_H
#define LEETCODE_GRAPH_H

#include "GraphNode.h"
#include <iostream>

class Graph {
public:
    Graph() : head(nullptr) {}
    explicit Graph(GraphNode *head) : head(head) {}

    void addNodeToGraph(Graph &graph, int val) {
        auto *newNode = new GraphNode(val);
        if (graph.head == nullptr) {
            graph.head = newNode;
        } else {
            GraphNode *curr = graph.head;
            while (curr->neighbors.size() > 0) {
                curr = curr->neighbors[0];
            }
            curr->neighbors.push_back(newNode);
        }
    }


    static void printGraph(GraphNode *head) {
        while (head) {
            std::cout << head->val << " ";
            head = head->neighbors[0];
        }
        std::cout << std::endl;
    }

    GraphNode *head;

};


#endif //LEETCODE_GRAPH_H
