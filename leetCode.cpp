//
// Created by Ryan.Zurrin001 on 1/6/2022.
//
#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "misc-no-recursion"
#include "Solutions.h"

void printVector(const vector<int>& vec)
{
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void printMatrix(const vector<vector<int>>& mat)
{
    for (auto i : mat)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int main()
{
    vector<vector<int>> mat1 = {{1,0,0}, {-1, 0, 3}};
    vector<vector<int>> mat2 = {{7,0,0}, {0,0,0}, {0,0,1}};

    printMatrix(Solutions::multiply(mat1, mat2));


    return 0;
}
