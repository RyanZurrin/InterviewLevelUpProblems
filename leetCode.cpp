//
// Created by Ryan.Zurrin001 on 1/6/2022.
//
#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "misc-no-recursion"
#include "Solutions.h"
typedef Solutions S;

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
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;

    cout << S::countGoodStrings(low, high, zero, one) << endl;



    return 0;
}
