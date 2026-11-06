// Maximum Employees Invited

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> favorite(n), degree(n);
    for (int &x : favorite) cin >> x;
    for (int x : favorite) degree[x]++;
    queue<int> q;
    vector<int> depth(n, 1);
    for (int i = 0; i < n; i++) if (!degree[i]) q.push(i);
    while (!q.empty()) { int node = q.front(); q.pop(); int next = favorite[node]; depth[next] = max(depth[next], depth[node] + 1); if (!--degree[next]) q.push(next); }
    int cycle = 0, pairs = 0;
    for (int i = 0; i < n; i++) if (degree[i]) {
        int length = 0, node = i;
        do { degree[node] = 0; node = favorite[node]; length++; } while (node != i);
        cycle = max(cycle, length);
        if (length == 2) pairs += depth[i] + depth[favorite[i]];
    }
    cout << max(cycle, pairs) << '\n';
    return 0;
}
