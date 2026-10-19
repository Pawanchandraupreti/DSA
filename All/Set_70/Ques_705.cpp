// Count N Queens Solutions

#include <bits/stdc++.h>
using namespace std;

int solve(int row, int n, vector<int> &column, vector<int> &diagonal, vector<int> &reverseDiagonal) {
    if (row == n) return 1;
    int answer = 0;
    for (int col = 0; col < n; col++) {
        if (column[col] || diagonal[row + col] || reverseDiagonal[row - col + n - 1]) continue;
        column[col] = diagonal[row + col] = reverseDiagonal[row - col + n - 1] = 1;
        answer += solve(row + 1, n, column, diagonal, reverseDiagonal);
        column[col] = diagonal[row + col] = reverseDiagonal[row - col + n - 1] = 0;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> column(n), diagonal(2 * n - 1), reverseDiagonal(2 * n - 1);
    cout << solve(0, n, column, diagonal, reverseDiagonal) << '\n';
    return 0;
}
