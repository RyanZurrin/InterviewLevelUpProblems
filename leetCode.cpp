//
// Created by Ryan.Zurrin001 on 1/6/2022.
//
#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "misc-no-recursion"

#include "Solutions.h"
#include "Utils.h"
typedef Solutions S;


int main()
{
    string expression = "T?2:3";
    printf("%s\n", S::parseTernary(expression).c_str());

    expression = "F?1:T?4:5";
    printf("%s\n", S::parseTernary(expression).c_str());

    expression = "T?T?F:5:3";
    printf("%s\n", S::parseTernary(expression).c_str());



    return 0;
}
