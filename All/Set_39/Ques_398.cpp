// Maximum Bipartite Matching

#include <bits/stdc++.h>
using namespace std;

bool findAugmentingPath(int applicant, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& assigned) {
    for (int job : graph[applicant]) {
        if (visited[job]) continue;
        visited[job] = true;

        if (assigned[job] == -1 || findAugmentingPath(assigned[job], graph, visited, assigned)) {
            assigned[job] = applicant;
            return true;
        }
    }
    return false;
}

int maximumMatching(const vector<vector<int>>& graph, int jobs) {
    vector<int> assigned(jobs, -1);
    int matches = 0;

    for (int applicant = 0; applicant < (int)graph.size(); ++applicant) {
        vector<bool> visited(jobs, false);
        if (findAugmentingPath(applicant, graph, visited, assigned)) {
            ++matches;
        }
    }

    return matches;
}

int main() {
    int applicants, jobs;
    cin >> applicants >> jobs;

    vector<vector<int>> graph(applicants);
    for (auto& options : graph) {
        int count;
        cin >> count;
        options.resize(count);
        for (int& job : options) cin >> job;
    }

    cout << maximumMatching(graph, jobs);
    return 0;
}


