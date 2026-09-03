// Range Minimum Query with Sparse Table

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<int> numbers(n);
    for (int& number : numbers) cin >> number;

    int levels = 1;
    while ((1 << levels) <= n) ++levels;
    vector<vector<int>> table(levels, vector<int>(n));
    table[0] = numbers;
    for (int level = 1; level < levels; ++level) {
        for (int index = 0; index + (1 << level) <= n; ++index) {
            table[level][index] = min(table[level - 1][index], table[level - 1][index + (1 << (level - 1))]);
        }
    }

    while (queries--) {
        int left, right;
        cin >> left >> right;
        int length = right - left + 1;
        int level = 31 - __builtin_clz(length);
        cout << min(table[level][left], table[level][right - (1 << level) + 1]) << '\n';
    }
    return 0;
}
