// Shortest Subarray with Sum at Least K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> prefix(n + 1);
    for (int i = 1; i <= n; i++) { int x; cin >> x; prefix[i] = prefix[i - 1] + x; }
    deque<int> q;
    int answer = n + 1;
    for (int i = 0; i <= n; i++) {
        while (!q.empty() && prefix[i] - prefix[q.front()] >= k) answer = min(answer, i - q.front()), q.pop_front();
        while (!q.empty() && prefix[q.back()] >= prefix[i]) q.pop_back();
        q.push_back(i);
    }
    cout << (answer == n + 1 ? -1 : answer) << '\n';
    return 0;
}
