//
// Created by ryanz on 7/19/2023.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <iostream>
#include <vector>


void printVector(const std::vector<int>& vec)
{
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<int>>& mat)
{
    for (auto i : mat)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif //LEETCODE_UTILS_H
