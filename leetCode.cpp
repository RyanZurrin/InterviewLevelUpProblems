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
//    Input
//    ["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
//    [[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
//    Output
//    [null, 0, 0, 0, 0, 0, 0, 1]

    auto ttt = TicTacToe(3);
    std::cout << ttt.move(0, 0, 1) << std::endl;
    std::cout << ttt.move(0, 2, 2) << std::endl;
    std::cout << ttt.move(2, 2, 1) << std::endl;
    std::cout << ttt.move(1, 1, 2) << std::endl;
    std::cout << ttt.move(2, 0, 1) << std::endl;
    std::cout << ttt.move(1, 0, 2) << std::endl;
    std::cout << ttt.move(2, 1, 1) << std::endl;



    return 0;
}
