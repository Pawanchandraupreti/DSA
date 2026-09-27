// Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), answer;
    deque<int> dq;
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) answer.push_back(a[dq.front()]);
    }

    for (int x : answer) cout << x << ' ';
    cout << '\n';
    return 0;
}
