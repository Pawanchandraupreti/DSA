// Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), answer;
    deque<int> window;
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        while (!window.empty() && window.front() <= i - k) window.pop_front();
        while (!window.empty() && a[window.back()] <= a[i]) window.pop_back();
        window.push_back(i);
        if (i >= k - 1) answer.push_back(a[window.front()]);
    }
    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
