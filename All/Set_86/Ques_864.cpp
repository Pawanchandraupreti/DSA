// Longest Subarray with Equal Zeroes and Ones

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> first;
    first[0] = -1;
    int balance = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        balance += x ? 1 : -1;
        if (first.count(balance)) answer = max(answer, i - first[balance]);
        else first[balance] = i;
    }
    cout << answer << '\n';
    return 0;
}
