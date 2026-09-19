// Course Schedule

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) {
        int course, prerequisite;
        cin >> course >> prerequisite;
        graph[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int done = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        done++;
        for (int next : graph[course]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    cout << (done == n ? "true" : "false") << '\n';
    return 0;
}


