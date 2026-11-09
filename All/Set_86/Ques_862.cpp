// Make Array Strictly Increasing

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(b.begin(), b.end());
    map<int, int> dp;
    dp[-1] = 0;
    for (int value : a) {
        map<int, int> next = dp;
        for (auto [last, changes] : dp) {
            auto it = upper_bound(b.begin(), b.end(), last);
            if (it != b.end()) next[*it] = min(next.count(*it) ? next[*it] : INT_MAX, changes + 1);
            if (value > last) next[value] = min(next.count(value) ? next[value] : INT_MAX, changes);
        }
        dp = next;
    }
    int answer = INT_MAX;
    for (auto [last, changes] : dp) answer = min(answer, changes);
    cout << (answer == INT_MAX ? -1 : answer) << '\n';
    return 0;
}
