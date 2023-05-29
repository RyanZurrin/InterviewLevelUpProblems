//
// Created by ryanz on 5/29/2023.
//

#ifndef LEETCODE_TICTACTOE_H
#define LEETCODE_TICTACTOE_H

#include <vector>

/*
 * 348. Design Tic-Tac-Toe
 * Assume the following rules are for the tic-tac-toe game on an n x n board between two players:
 * A move is guaranteed to be valid and is placed on an empty block.
 * Once a winning condition is reached, no more moves are allowed.
 * A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 * Implement the TicTacToe class:
 * - TicTacToe(int n) Initializes the object the size of the board n.
 * - int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the board.
 *   The move is guaranteed to be a valid move, and the two players alternate
 *   in making moves. Return:
 *   - 0 if there is no winner after the move,
 *   - 1 if player 1 is the winner after the move, or
 *   - 2 if player 2 is the winner after the move.
 *
 * Example 1:
 * Input
 * ["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
 * [[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
 * Output
 * [null, 0, 0, 0, 0, 0, 0, 1]
 * Explanation
 * TicTacToe ticTacToe = new TicTacToe(3);
 * Assume that player 1 is "X" and player 2 is "O" in the board.
 * ticTacToe.move(0, 0, 1); // return 0 (no one wins)
 * |X| | |
 * | | | |    // Player 1 makes a move at (0, 0).
 * | | | |
 *
 * ticTacToe.move(0, 2, 2); // return 0 (no one wins)
 * |X| |O|
 * | | | |    // Player 2 makes a move at (0, 2).
 * | | | |
 *
 * ticTacToe.move(2, 2, 1); // return 0 (no one wins)
 * |X| |O|
 * | | | |    // Player 1 makes a move at (2, 2).
 * | | |X|
 *
 * ticTacToe.move(1, 1, 2); // return 0 (no one wins)
 * |X| |O|
 * | |O| |    // Player 2 makes a move at (1, 1).
 * | | |X|
 *
 * ticTacToe.move(2, 0, 1); // return 0 (no one wins)
 * |X| |O|
 * | |O| |    // Player 1 makes a move at (2, 0).
 * |X| |X|
 *
 * ticTacToe.move(1, 0, 2); // return 0 (no one wins)
 * |X| |O|
 * |O|O| |    // Player 2 makes a move at (1, 0).
 * |X| |X|
 *
 * ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
 * |X| |O|
 * |O|O| |    // Player 1 makes a move at (2, 1).
 * |X|X|X|
 */

class TicTacToe {
public:
    TicTacToe(int n) {
        board.resize(n, std::vector<int>(n, 0));
        size = n;
    }

    int move(int row, int col, int player) {
        board[row][col] = player;
        displayBoard();

        if (checkRow(row, player) || checkCol(col, player) || checkDiagonal
        (row, col, player)) {
            std::cout << "Player " << player << " wins!" << std::endl;
            return player;
        }
        return 0;
    }

    bool checkRow(int row, int player) {
        for (int i = 0; i < size; ++i)
            if (board[row][i] != player)
                return false;
        return true;
    }

    bool checkCol(int col, int player) {
        for (int i = 0; i < size; ++i)
            if (board[i][col] != player)
                return false;
        return true;
    }

    bool checkDiagonal(int row, int col, int player) {
        if (row != col && row + col != size - 1)
            return false;
        bool flag = true;
        for (int i = 0; i < size; ++i) {
            if (board[i][i] != player) {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
        flag = true;
        for (int i = 0; i < size; ++i) {
            if (board[i][size - 1 - i] != player) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void displayBoard() {
        // display the 1's as X's and 2's as O's
        for (int i = 0; i < size; ++i) {
            std::cout << "|";
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == 1)
                    std::cout << "X";
                else if (board[i][j] == 2)
                    std::cout << "O";
                else
                    std::cout << " ";
                std::cout << "|";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> board;
    int size;

};


#endif //LEETCODE_TICTACTOE_H
