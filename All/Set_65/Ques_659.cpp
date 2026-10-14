// Course Schedule Feasibility

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        int course, prerequisite;
        cin >> course >> prerequisite;
        graph[prerequisite].push_back(course);
        degree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (degree[i] == 0) q.push(i);
    int completed = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        completed++;
        for (int next : graph[current]) if (--degree[next] == 0) q.push(next);
    }
    cout << (completed == n ? "YES" : "NO") << '\n';
    return 0;
}
