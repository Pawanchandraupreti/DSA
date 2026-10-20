// Word Search

#include <bits/stdc++.h>
using namespace std;

bool search(vector<string> &board, string &word, int row, int column, int index) {
    if (index == (int)word.size()) return true;
    if (row < 0 || row >= (int)board.size() || column < 0 || column >= (int)board[0].size() || board[row][column] != word[index]) return false;
    char saved = board[row][column];
    board[row][column] = '#';
    bool found = search(board, word, row + 1, column, index + 1) ||
                 search(board, word, row - 1, column, index + 1) ||
                 search(board, word, row, column + 1, index + 1) ||
                 search(board, word, row, column - 1, index + 1);
    board[row][column] = saved;
    return found;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (string &row : board) cin >> row;
    string word;
    cin >> word;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (search(board, word, i, j, 0)) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
