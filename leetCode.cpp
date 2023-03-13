//
// Created by Ryan.Zurrin001 on 1/6/2022.
//

#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "misc-no-recursion"
#include "Solutions.h"


int main()
{
    string s = "aa";
    string p1 = "a";
    string p2 = "a*";
    string p3 = ".*";
    cout <<  Solutions::isMatch(s, p1) << endl;
    cout <<  Solutions::isMatch(s, p2) << endl;
    cout <<  Solutions::isMatch(s, p3) << endl;

    return 0;
}
