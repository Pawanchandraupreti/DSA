// Course Schedule

#include <bits/stdc++.h>
using namespace std;

int main() {
    int courses, edges;
    cin >> courses >> edges;
    vector<vector<int>> graph(courses);
    vector<int> indegree(courses);
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to]++;
    }
    queue<int> ready;
    for (int course = 0; course < courses; course++) {
        if (indegree[course] == 0) ready.push(course);
    }
    int completed = 0;
    while (!ready.empty()) {
        int course = ready.front();
        ready.pop();
        completed++;
        for (int next : graph[course]) {
            if (--indegree[next] == 0) ready.push(next);
        }
    }
    cout << (completed == courses ? "true" : "false") << '\n';
    return 0;
}

