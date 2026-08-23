// N-Queens II

#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<string>& board, int row, int column) {
    int size = (int)board.size();

    for (int previousRow = 0; previousRow < row; ++previousRow) {
        for (int previousColumn = 0; previousColumn < size; ++previousColumn) {
            if (board[previousRow][previousColumn] == 'Q' &&
                abs(previousRow - row) == abs(previousColumn - column)) {
                return false;
            }
        }
    }

    return true;
}

void countSolutions(vector<string>& board, int row, int& solutions) {
    int size = (int)board.size();
    if (row == size) {
        ++solutions;
        return;
    }

    for (int column = 0; column < size; ++column) {
        if (isSafe(board, row, column)) {
            board[row][column] = 'Q';
            countSolutions(board, row + 1, solutions);
            board[row][column] = '.';
        }
    }
}

int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    int solutions = 0;
    countSolutions(board, 0, solutions);
    return solutions;
}

int main() {
    int n;
    cin >> n;

    cout << totalNQueens(n);
    return 0;
}

