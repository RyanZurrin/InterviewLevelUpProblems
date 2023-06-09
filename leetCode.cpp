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

    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<vector<int>> coordinates2 = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    vector<vector<int>> coordinates3 = {{0,0},{0,1},{0,-1}};
    vector<vector<int>> coordinates4 = {{0,0},{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    cout << S::checkStraightLine(coordinates) << endl;
    cout << S::checkStraightLine(coordinates2) << endl;
    cout << S::checkStraightLine(coordinates3) << endl;
    cout << S::checkStraightLine(coordinates4) << endl;



    return 0;
}
