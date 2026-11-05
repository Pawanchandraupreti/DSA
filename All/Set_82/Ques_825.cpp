// Minimum Swaps to Group Ones

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int &x : a) { cin >> x; ones += x; }
    int zeros = 0, answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) zeros++;
        if (i >= ones && a[i - ones] == 0) zeros--;
        if (i >= ones - 1) answer = min(answer, zeros);
    }
    cout << (ones ? answer : 0) << '\n';
    return 0;
}
