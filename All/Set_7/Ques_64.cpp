// N-Queens (Core Backtracking Idea – Count Solutions)

#include <iostream>
using namespace std;

bool isSafe(int board[4][4], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; j >= 0 && i < 4; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solve(int board[4][4], int col) {
    if (col >= 4) return true;

    for (int i = 0; i < 4; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solve(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[4][4] = {0};
    cout << (solve(board, 0) ? "Solution Exists" : "No Solution");
    return 0;
}
