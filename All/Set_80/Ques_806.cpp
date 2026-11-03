// Minimum Semesters to Finish Courses

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        degree[to]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (!degree[i]) q.push(i);
    int semesters = 0, completed = 0;
    while (!q.empty()) {
        int size = q.size();
        semesters++;
        while (size--) {
            int course = q.front();
            q.pop();
            completed++;
            for (int next : graph[course]) if (!--degree[next]) q.push(next);
        }
    }
    cout << (completed == n ? semesters : -1) << '\n';
    return 0;
}
