// Minimum Vertex Cover in a Bipartite Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int leftSize, rightSize, edges;
    cin >> leftSize >> rightSize >> edges;
    vector<vector<int>> graph(leftSize);
    while (edges--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> matchRight(rightSize, -1), seen;
    function<bool(int)> augment = [&](int left) {
        for (int right : graph[left]) if (!seen[right]) {
            seen[right] = 1;
            if (matchRight[right] == -1 || augment(matchRight[right])) {
                matchRight[right] = left;
                return true;
            }
        }
        return false;
    };
    int matching = 0;
    for (int left = 0; left < leftSize; left++) {
        seen.assign(rightSize, 0);
        matching += augment(left);
    }
    vector<int> matchLeft(leftSize, -1);
    for (int right = 0; right < rightSize; right++)
        if (matchRight[right] != -1) matchLeft[matchRight[right]] = right;
    vector<bool> reachableLeft(leftSize), reachableRight(rightSize);
    queue<int> pending;
    for (int left = 0; left < leftSize; left++) if (matchLeft[left] == -1)
        reachableLeft[left] = true, pending.push(left);
    while (!pending.empty()) {
        int left = pending.front();
        pending.pop();
        for (int right : graph[left]) if (matchLeft[left] != right && !reachableRight[right]) {
            reachableRight[right] = true;
            if (matchRight[right] != -1 && !reachableLeft[matchRight[right]]) {
                reachableLeft[matchRight[right]] = true;
                pending.push(matchRight[right]);
            }
        }
    }
    cout << matching << '\n';
    for (int left = 0; left < leftSize; left++) if (!reachableLeft[left]) cout << "L " << left << '\n';
    for (int right = 0; right < rightSize; right++) if (reachableRight[right]) cout << "R " << right << '\n';
    return 0;
}
