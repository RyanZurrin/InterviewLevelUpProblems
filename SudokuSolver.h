//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_SUDOKUSOLVER_H
#define LEETCODE_SUDOKUSOLVER_H
#include <vector>
#include <iostream>
using namespace std;


class SudokuSolver {

    bool solve(std::vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    static bool isValid(std::vector<vector<char> >& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.' && board[i][col] == c) {
                return false;
            }
            if (board[row][i] != '.' && board[row][i] == c) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }

    static void display(std::vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

public:
    void solveSudoku(std::vector<vector<char> >& board) {
        solve(board);
        display(board);
    }
};

#endif //LEETCODE_SUDOKUSOLVER_H
