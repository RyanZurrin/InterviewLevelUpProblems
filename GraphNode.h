//
// Created by ryanz on 3/23/2023.
//

#ifndef LEETCODE_GRAPHNODE_H
#define LEETCODE_GRAPHNODE_H
#include <utility>
#include <vector>

class GraphNode {
public:
    int val;
    std::vector<GraphNode*> neighbors;
    GraphNode() : val(0), neighbors(std::vector<GraphNode*>()) {}
    explicit GraphNode(int x) : val(x), neighbors(std::vector<GraphNode*>()) {}
    GraphNode(int x, std::vector<GraphNode*> neighbors) : val(x), neighbors(std::move(neighbors)) {}
};


#endif //LEETCODE_GRAPHNODE_H
