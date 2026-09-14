// Minimum Number of Refueling Stops

#include <bits/stdc++.h>
using namespace std;

int main() {
    int target, n;
    cin >> target >> n;
    vector<int> dist(n), fuel(n);
    for (int i = 0; i < n; i++) cin >> dist[i] >> fuel[i];

    int curr = 0, ans = 0;
    priority_queue<int> pq;
    int i = 0;
    while (curr < target) {
        while (i < n && dist[i] <= curr) {
            pq.push(fuel[i]);
            i++;
        }
        if (pq.empty()) break;
        curr += pq.top();
        pq.pop();
        ans++;
    }

    cout << (curr >= target ? ans : -1) << '\n';
    return 0;
}
